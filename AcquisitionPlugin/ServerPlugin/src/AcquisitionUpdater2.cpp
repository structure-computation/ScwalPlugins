#include <containers/vec.h>
#include "AcquisitionUpdater2.h"

bool AcquisitionUpdater::run( MP mp ) {
	qDebug() << mp.type();
    MP configuration = mp[ "_children[ 0 ]" ]; //on recupere la configuration
    int nb_measures = mp[ "_children" ].size();
	 qDebug() << nb_measures;
	 MP cur_measure = mp[ "_children" ][nb_measures-1];
    if ( cur_measure.ok() ) {
		  QString name = cur_measure["_name"];
		  qDebug() << name;
		  PRINT(name.toStdString());
	 }
//         // check if a image item has been provided
//         QString name = ch["_name"];
//         bool test_img = (ch.type() == "ImgItem");
//         
//         // retrieve img file
//         QFile* img = 0;
//         if(test_img){
//             MP file_img = mp["_children[0]"];
//             quint64 ptr = file_img[ "_ptr" ];
//             PRINT(file_img.type().toStdString());
//             QString name = file_img[ "_name" ];
// 	    PRINT(name.toStdString());
// 
// 	    
// 	    // src original file on server
// 	    QString name2 = file_img[ "img.src" ];
// 	    PRINT(name2.toStdString());
// 	    
// 	    //something to get img on compute server ?
// 	    
// 	    
// 	    
// 	    
// 	    
// 	    //start scilab
//  	    if ( StartScilab(getenv("SCI"), NULL, NULL) == FALSE ) printf("Error : StartScilab \n");
// 	    
// 	    //open Scilab script file
// 	    QFile file("script_scilab.sce");
// 	         if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
//             return false;
// 
//             QTextStream out(&file);
// 	    
// 	    QString tmp = "im=imread(\'" + name2 + "\');";
// 	    PRINT(tmp.toStdString());
// 	    
// 	    out << tmp.toStdString().c_str() << "\n";
// 	    
// 	    QString type_action = mp["cell_type.lst"][(int) mp["cell_type.num"]];
// 	    PRINT((type_action.toStdString()));
// 	    
// 	    bool OK=true;
// 	    if (type_action == "filter : sobel"){ ///sobel filter
// 		//do something
// 		out << "filtersc = fspecial('sobel');\n";
// 		out << "imf = imfilter(im, filtersc);\n";
// 		
// 	    }
// 	    else if (type_action == "detectfaces"){ ///detection des visages
// 		//do something
// 		out << "faces = detectfaces(im);\n";
// 		out << "[m,n] = size(faces);\n";
// 		out << "for i=1:m,\n";
// 		out << "     im = rectangle(im, faces(i,:), [0,255,0]);\n";
// 		out << "end;\n";
// 		out << "imf=im;\n";
// 	    } 
// 	    else {
// 		PRINT("unknow action");
// 		OK=false;
// 
// 	    }
// 	    
// 	    if (OK) {
// 		// save result
// 		tmp = "imwrite(imf,\'" + name2 + "result.png\');"; //on pourrait choisir l'extension dans l'interface ? 
// 		
// 	        out << tmp.toStdString().c_str() << "\n";
// 		file.close();
// 		
// 		///execution du script in Scilab
// 		SendScilabJob((char*)"exec('script_scilab.sce')");	//put exec('script_scilab.sce',-1) to avoid all message in terminal      
//                 
//                 
//                 // outputImage
//                 MP outputImage = mp["_output[0].img"];
//                 QString fileName =  name2 + "result.png";
//                 QImage Image;
//                 bool test = Image.load(fileName,"png");
//                 _save_img( outputImage, Image );
//                 
// 	    } else file.close();
// 	      
//  	    if ( TerminateScilab(NULL) == FALSE ) printf("Error : TerminateScilab \n");
// 
// 	    
// 	    
// 	    
// 	    
//         }
//         else {
// 	    add_message( mp, ET_Error, "Unable to find image file in tree" );
//             return false;
// 	}
// 	
// 	
//     }

    add_message( mp, ET_Info, "Acquisition -> OK" );
    qDebug() << "Acquisition is finished";
}

