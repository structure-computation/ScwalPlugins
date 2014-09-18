#include <Soca/Com/SodaClient.h>
#include <QtCore/QFile>
#include <QtGui/QImageReader>
#include <QtCore/QByteArray>
#include <QtCore/QBuffer>
#include <QtGui/QImage>

#include "TestUpdater.h"


static bool is_an_image( QString name ) {
    QList<QByteArray> l = QImageReader::supportedImageFormats();
    foreach( QString t, l )
        if ( name.endsWith( '.' + t ) )
            return true;
    return false;
}

bool TestUpdater::run( MP mp ) {
    MP image_dir = mp[ "_children[0]" ];
    MP ch = image_dir[ "_children" ];

    for( int i = 0; i < ch.size(); ++i ) {
        MP c = ch[ i ];
        MP file = c["_file"];

        quint64 ptr = file[ "_ptr" ];
        QString name = file[ "name" ];

        if ( is_an_image( name ) ) {
            MP data = sc->load_ptr( ptr );
            if ( data.ok() and data.type() == "Path" ) {
                int rem = file[ "_info.remaining" ];
                if ( not rem ) {
                    // read
                    QString p = data;
                    QImage tmp( p );
                    qDebug() << tmp.size();
                    

//                     // -> png
//                     QByteArray ba;
//                     QBuffer buffer( &ba );
//                     buffer.open( QIODevice::WriteOnly );
//                     tmp.save( &buffer, "PNG" );
// 
//                     // -> base64
//                     QByteArray b6;
//                     b6.append( "data:image/png;base64," );
//                     b6.append( ba.toBase64() );
// 
//                     file[ "_info.img" ] = QString::fromAscii( b6.data(), b6.size() );
                }
            } 
            
        }
    }
    
}


