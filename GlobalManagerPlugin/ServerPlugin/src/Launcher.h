#ifndef LAUNCHER_H
#define LAUNCHER_H
#include <Soca/Updater.h>
#include <QtCore/QProcess>
#include <sstream>
#include <string.h>
#include "HttpClientRuby.h"

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
          else if(mp.type() == "Scills2DItem" ){
              commande = "../Scills3DPlugin/ServerPlugin/src/compilations/ServerPlugin_src_main2D_cpp.exe " + temp_str ;
              output = std::system(commande.c_str());
          }
          else if(mp.type() == "Scills3DItem" ){
              commande = "../Scills3DPlugin/ServerPlugin/src/compilations/ServerPlugin_src_main3D_cpp.exe " + temp_str ;
              output = std::system(commande.c_str());
          }
          else if(mp.type() == "GmshItem" ){
              commande = "../GmshPlugin/ServerPlugin/src/compilations/ServerPlugin_src_main_cpp.exe " + temp_str ;
              output = std::system(commande.c_str());
          }
          else if(mp.type() == "CorrelationItem" ){
              commande = "../CorreliPlugin/ServerPlugin/src/compilations/ServerPlugin_src_main_cpp.exe " + temp_str ;
              output = std::system(commande.c_str());
          }
//           else if(mp.type() == "CorrelationItem" or mp.type() == "File" or mp.type() == "Img" or mp.type() == "ServerAssistedVisualization" ){
//               commande = "../CorreliPlugin/ServerPlugin/src/compilations/ServerPlugin_src_main_cpp.exe " + temp_str ;
//               output = std::system(commande.c_str());
//           }   

          qDebug() << "----------------- output : " << output;
          if(output){
              mp[ "_computation_mode" ]   = false;
              mp[ "_ready_state" ]        = false;
              mp[ "_computation_state" ]  = false;
              mp[ "_pending_state" ]      = false;
              mp[ "_processing_state" ]   = false;
              mp[ "_finish_state" ]       = false;
              mp[ "_stop_state" ]         = true;
              mp.flush();
          }
      }; 
      
      void log_tool(){
          qDebug() << "requette log_tool-----------" ;
//           Client http_client;
//           http_client.connexion();
          int sc_model_id = mp[ "_computation_mode" ];
          QString  mp_type = mp.type(); 
          QByteArray byteArray = mp_type.toUtf8();
          const char* c_string = byteArray.constData();
          
          
          std::stringstream strs;
          strs << 200;                          // sc_model_id
          strs << " " << c_string;       // app_type
          strs << " " << 10;                    // app_time
          strs << " " << 2;                     // app_cpu
          
          std::string temp_str = strs.str();
          std::string commande;
          int output;
          commande = "python ./ServerPlugin/src/log_tool.py " + temp_str;
          output = std::system(commande.c_str());
          
          qDebug() << "----------------- log output : " << output;
      };
              
      void launch(){ 
          qDebug() << "###############   launch tool ###############" ;
          mp[ "_ready_state" ]        = false;
          mp[ "_computation_state" ]  = true;
          mp[ "_pending_state" ]      = false;
          mp[ "_processing_state" ]   = true;
          mp[ "_finish_state" ]       = false;
          mp[ "_stop_state" ]         = false;
          mp.flush();
          run_app_2();

          log_tool();
          
          
          
          emit finished();
          qDebug() << "###############   finish tool ###############" ;
      };
 signals:  
      void finished();  
 public:      
      SodaClient *sc;
      MP mp;
};



#endif // LAUNCHER_H
