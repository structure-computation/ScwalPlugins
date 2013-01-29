#ifndef LAUNCHER_H
#define LAUNCHER_H
#include <Soca/Updater.h>
#include <QtCore/QProcess>
#include <sstream>
#include <string.h>

class SodaClient;

class Launcher : public QObject {
 Q_OBJECT
 public slots:
      void run_app(){   //fonction à définir dans chaque launcher
          //qDebug() << mp;
      
          int mp_server_id = mp.get_server_id();
          std::stringstream strs;
          strs << mp_server_id;
          std::string temp_str = strs.str();
          std::string commande;
          commande = "./ServerPlugin/src/compilations/ServerPlugin_src_exec_updater_cpp.exe " + temp_str ;
          qDebug() << "run_application-----------" ;
          int output;
          output = std::system(commande.c_str());
      }; 
      
      void run_app_2(){   //fonction à définir dans chaque launcher
          //qDebug() << mp;
      
//           int mp_server_id = mp.get_server_id();
//           std::stringstream strs;
//           strs << mp_server_id;
//           std::string temp_str = strs.str();
//           
//           QProcess *myProcess = new QProcess(this);
//           
//           if(mp.type() == "UnvReaderItem2D" ){
//               QString program = "../UnvReaderPlugin2D/ServerPlugin/src/compilations/ServerPlugin_src_main_cpp.exe";
//               QStringList arguments;
//               arguments << temp_str.c_str();
//               myProcess->start(program, arguments);
//           }
//           else if(mp.type() == "UnvReaderItem3D" ){
//               QString program = "../UnvReaderPlugin3D/ServerPlugin/src/compilations/ServerPlugin_src_main_cpp.exe";
//               qDebug() << program;
//               QStringList arguments;
//               arguments << temp_str.c_str();
//               myProcess->start(program, arguments);
//           }
//           else if(mp.type() == "Scult2DItem" ){
//               QString program = "../Scult2DPlugin/ServerPlugin/src/compilations/ServerPlugin_src_main_cpp.exe";
//               QStringList arguments;
//               arguments << temp_str.c_str();
//               myProcess->start(program, arguments);
//           }
//           else if(mp.type() == "Scult3DItem" ){
//               QString program = "../Scult3DPlugin/ServerPlugin/src/compilations/ServerPlugin_src_main_cpp.exe";
//               QStringList arguments;
//               arguments << temp_str.c_str();
//               myProcess->start(program, arguments);
//           }
//           else if(mp.type() == "Scills3DItem" ){
//               QString program = "../Scills3DPlugin/ServerPlugin/src/compilations/ServerPlugin_src_main_cpp.exe";
//               QStringList arguments;
//               arguments << temp_str.c_str();
//               myProcess->start(program, arguments);
//           }
//           else if(mp.type() == "CorrelationItem" or mp.type() == "MesherItem" or mp.type() == "File" or mp.type() == "Img" or mp.type() == "ServerAssistedVisualization" ){
//               QString program = "../CorreliPlugin/ServerPlugin/src/compilations/ServerPlugin_src_main_cpp.exe";
//               QStringList arguments;
//               arguments << temp_str.c_str();
//               myProcess->start(program, arguments);
//           }
//           myProcess->waitForFinished();
          
          int mp_server_id = mp.get_server_id();
          std::stringstream strs;
          strs << mp_server_id;
          std::string temp_str = strs.str();
          std::string commande;
          int output;

          if(mp.type() == "UnvReaderItem2D" ){
              commande = "../UnvReaderPlugin2D/ServerPlugin/src/compilations/ServerPlugin_src_main_cpp.exe " + temp_str ;
              output = std::system(commande.c_str());
          }
          else if(mp.type() == "UnvReaderItem3D" ){
              commande = "../UnvReaderPlugin3D/ServerPlugin/src/compilations/ServerPlugin_src_main_cpp.exe " + temp_str ;
              output = std::system(commande.c_str());
          }
          else if(mp.type() == "Scult2DItem" ){
              commande = "../Scult2DPlugin/ServerPlugin/src/compilations/ServerPlugin_src_main_cpp.exe " + temp_str ;
              output = std::system(commande.c_str());
          }
          else if(mp.type() == "Scult3DItem" ){
              commande = "../Scult3DPlugin/ServerPlugin/src/compilations/ServerPlugin_src_main_cpp.exe " + temp_str ;
              output = std::system(commande.c_str());
          }
          else if(mp.type() == "Scills3DItem" ){
              commande = "../Scills3DPlugin/ServerPlugin/src/compilations/ServerPlugin_src_main_cpp.exe " + temp_str ;
              output = std::system(commande.c_str());
          }
          else if(mp.type() == "MesherItem" ){
              qDebug() << "run_mesher-----------" ;
              commande = "../CorreliPlugin/ServerPlugin/src/compilations/ServerPlugin_src_main_gmsh_cpp.exe " + temp_str ;
              output = std::system(commande.c_str());
              qDebug() << "quit_mesher-----------" ;
          }
          else if(mp.type() == "CorrelationItem" or mp.type() == "File" or mp.type() == "Img" or mp.type() == "ServerAssistedVisualization" ){
              commande = "../CorreliPlugin/ServerPlugin/src/compilations/ServerPlugin_src_main_cpp.exe " + temp_str ;
              output = std::system(commande.c_str());
          }
          
          mp[ "_computation_mode" ] = false;
          mp[ "_computation_state" ] = false;
          mp[ "_processing_state" ] = false;
          mp.flush();
      }; 
              
      void launch(){
          run_app_2();
          
          emit finished();
      };
 signals:  
      void finished();  
 public:      
      SodaClient *sc;
      MP mp;
};



#endif // LAUNCHER_H
