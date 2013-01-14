#include <Soca/Com/SodaClient.h>
#include <QtGui/QImageReader>
#include <QtCore/QByteArray>
#include <QtCore/QBuffer>
#include <QtGui/QImage>
#include "FileUpdater.h"

static bool is_an_image( QString name ) {
    QList<QByteArray> l = QImageReader::supportedImageFormats();
    foreach( QString t, l )
        if ( name.endsWith( '.' + t ) )
            return true;
    return false;
}

void FileUpdater::exec( MP mp ) {
    quint64 ptr = mp[ "_ptr" ];
    QString name = mp[ "name" ];

    if ( is_an_image( name ) and not mp[ "_info.img" ].ok() ) {
        MP data = sc->load_ptr( ptr );
        if ( data.ok() and data.type() == "Path" ) {
            int rem = mp[ "_info.remaining" ];
            if ( not rem ) {
                // read
                QString p = data;
                QImage tmp( p );
                QImage res( tmp.scaled( QSize( 128, 128 ), Qt::KeepAspectRatio ) );
                if ( not res.width() )
                    return;

                // -> png
                QByteArray ba;
                QBuffer buffer( &ba );
                buffer.open( QIODevice::WriteOnly );
                res.save( &buffer, "PNG" );

                // -> base64
                QByteArray b6;
                b6.append( "data:image/png;base64," );
                b6.append( ba.toBase64() );

                mp[ "_info.img" ] = QString::fromAscii( b6.data(), b6.size() );
            }
        }
    }
}
