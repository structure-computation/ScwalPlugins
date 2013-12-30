#include <Soca/Com/SodaClient.h>
#include "JobList.h"
#include "ServerAssistedVisualizationUpdater.h"
#include "FileUpdater.h"
#include "ImgUpdater.h"

int main( int argc, char **argv ) {
    // connection
    SodaClient sc( QHostAddress::Any, 8890 );
    if ( not sc.connected() ) return 1;

    // type d'item observé
    sc.reg_type( "CsvReaderItem" );
    sc.reg_type( "UnvReaderItem2D" );
    sc.reg_type( "UnvReaderItem3D" );
    sc.reg_type( "Scult2DItem" );
    sc.reg_type( "Scult3DItem" );
    sc.reg_type( "Scills2DItem" );
    sc.reg_type( "Scills3DItem" );
    sc.reg_type( "FieldsComparatorItem" );
    sc.reg_type( "CorrelationItem" );
    sc.reg_type( "GmshItem" );
    sc.reg_type( "StepReaderItem" );
    sc.reg_type( "ScilabItem" );
    sc.reg_type( "AcquisitionItem" );    
    sc.reg_type( "File" );
    sc.reg_type( "Img" );
    sc.reg_type( "ServerAssistedVisualization" );
    
    //liste des job en cours
    JobList job_list;
    
    // attente
    while ( SodaClient::Event event = sc.event() ) {
        MP mp = event.mp();
        //test : verification de l'existance d'un job, ou création du job si necessaire

        // qDebug() << "model : " << mp;
        // qDebug() << "recu ";
        if ( mp.type() == "ServerAssistedVisualization" ) {
            ServerAssistedVisualizationUpdater mu;
            mu.sc = &sc;
            mu.exec( mp );
        } else if ( mp.type() == "File" ) {
            FileUpdater fu;
            fu.sc = &sc;
            fu.exec( mp );
        } else if ( mp.type() == "Img" ) {
            ImgUpdater iu;
            iu.sc = &sc;
            iu.exec( mp );
        } else{
            job_list.kill_jobs();
            int i_job = job_list.find_job_index(mp, sc);
            
//             qDebug() << "i_job : " << i_job ;
            if(i_job >= 0){
//                 qDebug() << "recu 1 ";
                qDebug() << "job_list.jobs.size() : " << job_list.jobs.size();
                Job *current_job;
                current_job = job_list.jobs[i_job];
                current_job->putLauncherInAThread(mp);
                
    //             mp[ "_computation_mode" ] = false;
            }else if(i_job == -1 ){
                qDebug() << "something to compute !";   
            }else if(i_job == -2 ){
                mp[ "_computation_mode" ]   = false;
                mp[ "_ready_state" ]        = false;
                mp[ "_computation_state" ]  = false;
                mp[ "_pending_state" ]      = false;
                mp[ "_processing_state" ]   = false;
                mp[ "_finish_state" ]       = false;
                mp[ "_stop_state" ]         = true;
                mp.flush();
            }
        }
        
    }
}
