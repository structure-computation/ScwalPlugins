#ifndef JOBLIST_H
#define JOBLIST_H
#include <Soca/Com/SodaClient.h>
#include <Soca/Updater.h>
#include <QtCore/QThread>
#include "UnvReader2DLauncher.h"


class Job : public QObject {
    Q_OBJECT
  public:
    MP model;
    SodaClient *sc;
    quint64 model_id;
    quint64 model_ready_state;
    quint64 model_computation_state;
    quint64 model_pending_state;
    quint64 model_processing_state;
    quint64 model_finish_state;
    quint64 model_stop_state;
    
    
    bool run;
    bool pending;
    bool processing;
    bool finish;
    bool stop;
    bool as_been_killed;
    
    bool nothing_to_compute;
    bool waiting_something_to_compute;
    
    Launcher *launcher;
    QThread *thread;
    bool launcher_exists;
    bool thread_exists;
    typedef enum { ET_Success, ET_Info, ET_Error } ErrorType;
    
    Job(){};
    
    Job(MP model_, SodaClient &sc_){
        model           = model_;
        sc              = &sc_;
        launcher_exists = false;
        thread_exists   = false;
        as_been_killed  = false;
        
        nothing_to_compute= false;
        waiting_something_to_compute= false;
        
        model_id = model_.get_server_id();
//         qDebug() << "model : " << model;
    }
    
    ~Job(){
        thread->quit();
        delete thread;
        delete launcher;
    };
    
    void initialize(MP &model_){
        launcher_exists = false;
        thread_exists   = false;
        
        nothing_to_compute= false;
        waiting_something_to_compute= false;
        
        model_id = model_.get_server_id();
        model.reassign(model_);
//         qDebug() << "model_ : " << model_;
//         qDebug() << "model : " << model;
    }
    
    void get_model_server_id(){
        model_id = model.get_server_id();
    }
    
    bool find_job_model(MP model_test){
        bool find = false;
        quint64 model_test_id = model_test.get_server_id();
//         qDebug() << "model_test_id : " << model_test_id << "  model_id : " << model_id;
        if (model_test_id == model_id){
            model = model_test;
            find = true;
        }
        return find;
    }
    
    bool job_to_kill(){
        bool find = false;
        if(thread->isFinished())          { find = true;}
        else if(not thread)               { find = true;}
        //else if(as_been_killed)         { find = true;}
        return find;
    }
    
    void clear_error_list( ) {
        model[ "_messages" ].clear();
    }
    
    bool model_add_message( ErrorType type, QString title ) {
        MP msg = MP::new_obj( "Model" );
        msg[ "title" ] = title;
        switch ( type ) {
          case ET_Success: msg[ "type" ] = "msg_success"; break;
          case ET_Info: msg[ "type" ] = "msg_info"; break;
          case ET_Error: msg[ "type" ] = "msg_error"; break;
        }

        model[ "_messages" ] << msg;
        return false;
    }
    
    bool model_set_state(MP model_test){
        // model state
        model_ready_state               = model_test[ "_ready_state" ];
        model_computation_state         = model_test[ "_computation_state" ];
        model_pending_state             = model_test[ "_pending_state" ];
        model_processing_state          = model_test[ "_processing_state" ];
        model_finish_state              = model_test[ "_finish_state" ];
        model_stop_state                = model_test[ "_stop_state" ];
        
//         qDebug() << "--------------------------------------------------------------- ";
//         qDebug() << "model_ready_state : " << model_ready_state;
//         qDebug() << "model_computation_state : " << model_computation_state;
//         qDebug() << "model_pending_state : " << model_pending_state;
//         qDebug() << "model_processing_state : " << model_processing_state;
//         qDebug() << "model_finish_state : " << model_finish_state;
//         qDebug() << "model_stop_state : " << model_stop_state;
        
        //thread state
        run             = false;
        pending         = false;
        processing      = false;
        finish          = false;
        stop            = false;
        
        if ( model_computation_state == true ){
            run = true;
        }
        if ( model_pending_state == true ){
            pending = true;
        }
        if ( model_processing_state == true ){
            processing = true;
        }
        if ( model_finish_state == true ){
            finish = true;
        }
        if ( model_stop_state == true ){
            stop = true;
        }
    }
    
    bool has_something_to_compute_else_than( Model *m, Model *a ) {
        if ( m == 0 or m->_op_id == Model::_cur_op_id )
            return false;
        m->_op_id = Model::_cur_op_id;

        quint64 req = 0, rep = 0;
        for( int i = 0; i < m->size(); ++i ) {
            if ( Model *t = m->attr( i ) ) {
                if ( m->key( i ) == "_computation_req_date" )
                    req = t->operator quint64();
                else if ( m->key( i ) == "_computation_rep_date" )
                    rep = t->operator quint64();
                else if ( has_something_to_compute_else_than( t, a ) )
                    return true;
            }

        }

        return req > rep and m != a;
    }

    bool run_model_test(MP model_test){
        bool run_app = false;
        model_set_state(model_test);

        quint64 model_computation_mode          = model_test[ "_computation_mode" ]; 
        quint64 model_computation_req_date      = model_test[ "_computation_req_date" ];
        quint64 model_computation_rep_date      = model_test[ "_computation_rep_date" ];
        
//         qDebug() << "model_computation_mode : " << model_computation_mode << "  model_computation_state : " << model_computation_state;
        if ( model_computation_state == true ){
            run_app = true;
        }
        if ( model_computation_req_date <= model_computation_rep_date ){
            run_app = false;
            nothing_to_compute= true;
            
        }
        // waiting for another computation ?
        ++Model::_cur_op_id;
        if ( has_something_to_compute_else_than( model_test.model(), model_test.model() ) ) {
            qDebug() << "something to compute !";
            run_app = false;
            waiting_something_to_compute= true; 
        }
        
        
//         qDebug() << "run_app : " << run_app;
        
        return run_app;
    }
    
    bool run_thread_test(){
        if(thread_exists){
            //thread state
            model_set_state(model);
            bool thread_is_runing = thread->isRunning();
            bool thread_is_finished = thread->isFinished();
//             qDebug() << "thread_is_runing : " << thread_is_runing << "  thread_is_finished : " << thread_is_finished;
            
            if(thread_is_runing){
                run             = false;
                processing      = true;
            }
            else if(thread_is_finished){
                run             = false;
                finish          = true;
            }
        }
    }
    
    void run_state(){        
        // model state
        run = run_model_test(model);
        run_thread_test();
    }
    
    void putLauncherInAThread(MP mp){
//         qDebug() << "model.type() : " << model;
//         qDebug() << "launcher_exists : " << launcher_exists << ", thread_exists : " << thread_exists << ", run : " << run;

        if(not launcher_exists){
            launcher = new Launcher();
            launcher_exists  = true;
        }
        
//         qDebug() << "launcher_exists : " << launcher_exists << ", thread_exists : " << thread_exists << ", run : " << run;
        if(not thread_exists){
            thread = new QThread(this);
            thread_exists    = true;
        }
        
        run_state();
        
        qDebug() << "launcher_exists : " << launcher_exists << ", thread_exists : " << thread_exists << ", run : " << run << ", stop : " << stop;
        if(launcher_exists and thread_exists and run){
            qDebug() << "job lance model------------------------- : " << model_id;
            mp[ "_ready_state" ]        = false;
            mp[ "_computation_state" ]  = true;
            mp[ "_pending_state" ]      = true;
            mp[ "_processing_state" ]   = false;
            mp[ "_finish_state" ]       = false;
            mp[ "_stop_state" ]         = false;
            mp.flush();
            launcher->sc = sc;
            launcher->mp.reassign(model);
            connect(thread, SIGNAL(started()), launcher, SLOT(launch()));
            //connect(launcher, SIGNAL(finished()), thread, SLOT(quit()));
            connect(launcher, SIGNAL(finished()), thread, SIGNAL(finished()));
            connect(launcher, SIGNAL(finished()), launcher, SLOT(deleteLater()));
            //connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
            connect(thread, SIGNAL(finished()), this, SLOT(finish_thread()));
            launcher->moveToThread(thread);

            // Starts an event loop, and emits thread->started()
            thread->start();
        }
        if(launcher_exists and thread_exists and finish){
            qDebug() << "job quit thread------------------------- : " << model_id;
            mp[ "_ready_state" ]        = false;
            mp[ "_computation_state" ]  = false;
            mp[ "_pending_state" ]      = false;
            mp[ "_processing_state" ]   = false;
            mp[ "_finish_state" ]       = false;
            mp[ "_stop_state" ]         = true;
            mp.flush();
            thread->quit();
            //as_been_killed = true;
        }
        
    }
  public slots: 
    void finish_thread(){
//         model[ "_ready_state" ]        = true;
//         model[ "_computation_state" ]  = false;
//         model[ "_pending_state" ]      = false;
//         model[ "_processing_state" ]   = false;
//         model[ "_finish_state" ]       = false;
//         model[ "_stop_state" ]         = false;
//         model.flush();
        thread->quit();
    };
};  

class JobList : public QObject{
  Q_OBJECT
  
public slots: 
    void kill_jobs(){
//         qDebug() << "kill_jobs " ;
        bool find_kill = true;
        while(find_kill){
            find_kill = false;
            int index_to_kill = -1;
            for (int i = 0; i < jobs.size(); ++i) {
                if (jobs[i]->job_to_kill()){
                    index_to_kill = i;
                    find_kill = true;
                    break;
                }
            }
            if(find_kill){
                qDebug() << "delete job : " << index_to_kill;
                //delete jobs[index_to_kill];
                jobs.removeAt( index_to_kill );
                //qDebug() << "delete job : " << index_to_kill;
            }
        } 
        
    }
public:
    QList<Job*> jobs;
    int find_job_index( MP mp_test, SodaClient &sc ){
//         qDebug() << "find_job_index " ;
//         qDebug() << "model : " << mp_test;
        for (int i = 0; i < jobs.size(); ++i) {
            if (jobs[i]->find_job_model(mp_test)){
                
                jobs[i]->model = mp_test;
                jobs[i]->sc = &sc;
                //return &(jobs[i]);
                return i;
            }
        }
        Job *new_job = new Job();
        if(new_job->run_model_test(mp_test)){
            
            new_job->model = mp_test;
            new_job->sc = &sc;
            new_job->initialize(mp_test);
            jobs.append(new_job);
            //return &(jobs.last());
            qDebug() << "run_model_test";
            return (jobs.size()-1);
        }
        if(new_job->waiting_something_to_compute){
            return (-1);
        }
        return (-2);
    }
    
};

#endif // JOBLIST_H