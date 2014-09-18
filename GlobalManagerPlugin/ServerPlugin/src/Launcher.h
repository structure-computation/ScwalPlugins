#ifndef LAUNCHER_H
#define LAUNCHER_H
#include <Soca/Updater.h>
#include <QtCore/QProcess>
#include <sstream>
#include <string.h>
#include <sys/mman.h>
#include <sys/time.h>

#include "HttpClientRuby.h"

class SodaClient;

struct TicToc {
    TicToc(){}
    void start() { gettimeofday( &start1,&toto); }
    void stop() {
        gettimeofday( &stop1,&toto);
        res = ((double)stop1.tv_sec-(double)start1.tv_sec)+((double)stop1.tv_usec-(double)start1.tv_usec) / 1e6;
    }
    void print() { printf("%f\n",res); }
    struct timeval start1, stop1;
    struct timezone toto;
    double res;
};


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
      
      int run_app_2(){   //fonction à définir dans chaque launcher         
          int mp_server_id = mp.get_server_id();
          std::stringstream strs;
          strs << mp_server_id;
          std::string temp_str = strs.str();
          std::string commande;
          int output;
          
          if(mp.type() == "CsvReaderItem" ){
              commande = "../CsvReaderPlugin/ServerPlugin/src/compilations/ServerPlugin_src_main_cpp.exe " + temp_str ;
              output = std::system(commande.c_str());
          }
          
          if(mp.type() == "UnvReaderItem2D" ){
              commande = "../UnvReaderPlugin2D/ServerPlugin/src/compilations/ServerPlugin_src_main_cpp.exe " + temp_str ;
              output = std::system(commande.c_str());
          }
          else if(mp.type() == "UnvReaderItem3D" ){
              commande = "../UnvReaderPlugin3D/ServerPlugin/src/compilations/ServerPlugin_src_main_cpp.exe " + temp_str ;
              output = std::system(commande.c_str());
          }
          else if(mp.type() == "FieldsComparatorItem" ){
              commande = "../FieldsComparatorPlugin/ServerPlugin/src/compilations/ServerPlugin_src_main_cpp.exe " + temp_str ;
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
              //* Modification pour lancement MPI (ne devrait pas etre gere ici...)
              int nb_proc = mp["nb_proc"];
              qDebug() << "Nb processors : " << nb_proc;
              if(nb_proc > 1){
                  qDebug() << "**************************************************************************************************";
                  qDebug() << "**************************************** LAUNCHING MPI *******************************************";
                  qDebug() << "**************************************************************************************************";
                  std::stringstream strs;
                  strs << nb_proc;
                  std::string nb_proc_str = strs.str();
                  commande = "mpirun.openmpi -np " + nb_proc_str + " ../Scills3DPlugin/ServerPlugin/src/compilations/ServerPlugin_src_main2D_cpp.exe " + temp_str + " mpi";
              }
              else {
                  commande = "../Scills3DPlugin/ServerPlugin/src/compilations/ServerPlugin_src_main2D_cpp.exe " + temp_str ;
              }
              output = std::system(commande.c_str());
          }
          else if(mp.type() == "Scills3DItem" ){
              //* Modification pour lancement MPI (ne devrait pas etre gere ici...)
              int nb_proc = mp["nb_proc"];
              qDebug() << "Nb processors : " << nb_proc;
              if(nb_proc > 1){
                  qDebug() << "**************************************************************************************************";
                  qDebug() << "**************************************** LAUNCHING MPI *******************************************";
                  qDebug() << "**************************************************************************************************";
                  std::stringstream strs;
                  strs << nb_proc;
                  std::string nb_proc_str = strs.str();
                  commande = "mpirun.openmpi -np " + nb_proc_str + " ../Scills3DPlugin/ServerPlugin/src/compilations/ServerPlugin_src_main3D_cpp.exe " + temp_str + " mpi";
              }
              else {
                  commande = "../Scills3DPlugin/ServerPlugin/src/compilations/ServerPlugin_src_main3D_cpp.exe " + temp_str ;
              }
              output = std::system(commande.c_str());
          }
          else if(mp.type() == "GmshItem" ){
              commande = "../GmshPlugin/ServerPlugin/src/compilations/ServerPlugin_src_main_cpp.exe " + temp_str ;
              output = std::system(commande.c_str());
          }
          else if(mp.type() == "StepReaderItem" ){
              commande = "../StepReaderPlugin/ServerPlugin/src/compilations/ServerPlugin_src_main_cpp.exe " + temp_str ;
              output = std::system(commande.c_str());
          }
          else if(mp.type() == "ScilabItem" ){
              commande = "../ScilabPlugin/ServerPlugin/src/compilations/ServerPlugin_src_main_cpp.exe " + temp_str ;
              output = std::system(commande.c_str());
          }
          else if(mp.type() == "CorrelationItem" ){
              commande = "../CorreliPlugin/ServerPlugin/src/compilations/ServerPlugin_src_main_cpp.exe " + temp_str ;
              output = std::system(commande.c_str());
          }
          else if(mp.type() == "AcquisitionItem" ){
              commande = "../AcquisitionPlugin/ServerPlugin/src/compilations/ServerPlugin_src_main_cpp.exe " + temp_str ;
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
          
          return output;
      }; 
      
      void log_tool(TicToc tic, int output_launcher){
          qDebug() << "requette log_tool-----------" ;
//           Client http_client;
//           http_client.connexion();
          int sc_model_id = -1;
          QString  mp_type = mp.type(); 
          QByteArray byteArray = mp_type.toUtf8();
          const char* c_string = byteArray.constData();
          int duration =  int(tic.res)+1 ;
          int nb_processus = mp[ "_sc_nb_proc" ];
          
          
          
          
          std::stringstream strs;
          strs << sc_model_id;                  // project_id
          strs << " " << c_string;              // app_type
          strs << " " << duration;              // app_time
          strs << " " << nb_processus;          // app_cpu
          
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
          TicToc tic;
          tic.start();
          
          int output = run_app_2();

          tic.stop();
//           log_tool(tic, output);
          
          
          
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
