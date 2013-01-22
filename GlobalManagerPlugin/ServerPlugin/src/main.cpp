#include <Soca/Com/SodaClient.h>
#include "JobList.h"

int main( int argc, char **argv ) {
    // connection
    SodaClient sc( QHostAddress::Any, 8890 );
    if ( not sc.connected() ) return 1;

    // type d'item observé
    sc.reg_type( "UnvReaderItem2D" );
    sc.reg_type( "UnvReaderItem3D" );
    sc.reg_type( "Scult2DItem" );
    sc.reg_type( "Scult3DItem" );
    sc.reg_type( "Scills3DItem" );
    sc.reg_type( "CorrelationItem" );
    sc.reg_type( "MesherItem" );
    sc.reg_type( "File" );
    sc.reg_type( "Img" );
    sc.reg_type( "ServerAssistedVisualization" );
    
    //liste des job en cours
    JobList job_list;
    
    // attente
    while ( SodaClient::Event event = sc.event() ) {
        MP mp = event.mp();
        //test : verification de l'existance d'un job, ou création du job si necessaire
//         qDebug() << "model : " << mp;
        job_list.kill_jobs();
        int i_job = job_list.find_job_index(mp, sc);
        
        if(i_job != -1){
            qDebug() << "job_list.jobs.size() : " << job_list.jobs.size();
            Job *current_job;
            current_job = job_list.jobs[i_job];
            current_job->putLauncherInAThread(mp);
            
//             mp[ "_computation_mode" ] = false;
            
        }
    }
}