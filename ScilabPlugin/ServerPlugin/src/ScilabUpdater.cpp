#pragma lib_path ../../../software_library/scilab-5.4.1/lib/scilab 
#pragma lib_path ../../../software_library/scilab-5.4.1/lib/thirdparty 
#pragma inc_path ../../../software_library/scilab-5.4.1/include/scilab

#pragma lib_name scilab
#pragma lib_name scicall_scilab 
#pragma lib_name tk8.5 
#pragma lib_name tcl8.5 
#pragma lib_name fftw3 
#pragma lib_name scigraphic_objects  
#pragma lib_name scilab-cli 
#pragma lib_name QtGui 


#include <Soca/Com/SodaClient.h>
#include <Soca/Model/TypedArray.h>
#include <QtCore/QFile>
#include <QtGui/QImage>
#include <QtCore/QBuffer>
#include <QtCore/QTemporaryFile>
#include <QtCore/QDataStream>
#include <containers/vec.h>
#include "ScilabUpdater.h"
#include <api_scilab.h>


/*--------------------------------------------------------------------------*/
/* See routines/system/call_scilab.h */
extern "C" int StartScilab(char *SCIpath, char *ScilabStartup, int *Stacksize);
extern "C" int TerminateScilab(char *ScilabQuit);
extern "C" int SendScilabJob(char *job);
/*--------------------------------------------------------------------------*/

typedef LMT::Vec<double,3> Pvec;




inline void _save_img( MP outputImage, const QImage &res ) {
    // -> png
    QByteArray ba;
    QBuffer buffer( &ba );
    buffer.open( QIODevice::WriteOnly );
    res.save( &buffer, "PNG" );

    // -> base64
    QByteArray b6;
    b6.append( "data:image/png;base64," );
    b6.append( ba.toBase64() );

    outputImage[ "src" ] = QString::fromAscii( b6.data(), b6.size() );
}



struct AutoRm {
    AutoRm( QString f ) : f( f ) {}
    ~AutoRm() { QFile::remove( f ); }
    QString f;
};

bool ScilabUpdater::run( MP mp ) {
    MP ch = mp[ "_children[ 0 ]" ]; //on recupere l'image
    if ( ch.ok() ) {
        // check if a image item has been provided
        QString name = ch["_name"];
        bool test_img = (ch.type() == "ImgItem");
        
        // retrieve img file
        QFile* img = 0;
        if(test_img){
            MP file_img = mp["_children[0]"];
            quint64 ptr = file_img[ "_ptr" ];
            PRINT(file_img.type().toStdString());
            QString name = file_img[ "_name" ];
	    PRINT(name.toStdString());

	    
	    // src original file on server
	    QString name2 = file_img[ "img.src" ];
	    PRINT(name2.toStdString());
	    
	    //something to get img on compute server ?
	    
	    
	    
	    
	    
	    //start scilab
 	    if ( StartScilab(getenv("SCI"), NULL, NULL) == FALSE ) printf("Error : StartScilab \n");
	    
	    //open Scilab script file
	    QFile file("script_scilab.sce");
	         if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            return false;

            QTextStream out(&file);
	    
	    QString tmp = "im=imread(\'" + name2 + "\');";
	    PRINT(tmp.toStdString());
	    
	    out << tmp.toStdString().c_str() << "\n";
	    
	    QString type_action = mp["cell_type.lst"][(int) mp["cell_type.num"]];
	    PRINT((type_action.toStdString()));
	    
	    bool OK=true;
	    if (type_action == "filter : sobel"){ ///sobel filter
		//do something
		out << "filtersc = fspecial('sobel');\n";
		out << "imf = imfilter(im, filtersc);\n";
		
	    }
	    else if (type_action == "detectfaces"){ ///detection des visages
		//do something
		out << "faces = detectfaces(im);\n";
		out << "[m,n] = size(faces);\n";
		out << "for i=1:m,\n";
		out << "     im = rectangle(im, faces(i,:), [0,255,0]);\n";
		out << "end;\n";
		out << "imf=im;\n";
	    } 
	    else {
		PRINT("unknow action");
		OK=false;

	    }
	    
	    if (OK) {
		// save result
		tmp = "imwrite(imf,\'" + name2 + "result.png\');"; //on pourrait choisir l'extension dans l'interface ? 
		
	        out << tmp.toStdString().c_str() << "\n";
		file.close();
		
		///execution du script in Scilab
		SendScilabJob((char*)"exec('script_scilab.sce')");	//put exec('script_scilab.sce',-1) to avoid all message in terminal      
                
                
                // outputImage
                MP outputImage = mp["_output[0].img"];
                QString fileName =  name2 + "result.png";
                QImage Image;
                bool test = Image.load(fileName,"png");
                _save_img( outputImage, Image );
                
	    } else file.close();
	      
 	    if ( TerminateScilab(NULL) == FALSE ) printf("Error : TerminateScilab \n");

	    
	    
	    
	    
        }
        else {
	    add_message( mp, ET_Error, "Unable to find image file in tree" );
            return false;
	}
	
	
    }

    add_message( mp, ET_Info, "Scilab -> OK" );
    qDebug() << "Scilab just finish";
}

