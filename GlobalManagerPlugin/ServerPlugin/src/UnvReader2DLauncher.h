#ifndef UNVREADER2DLAUNCHER_H
#define UNVREADER2DLAUNCHER_H
#include "Launcher.h"

class SodaClient;

class UnvReader2DLauncher : public Launcher {
  Q_OBJECT
  public slots:
     void run_app() {
//           system(./src/compila);
        
          qDebug() << "Executing in new independant thread, GUI is NOT blocked";
          for(int i=0;i<10;i++){
              qDebug() << "Time: " << 10-i;    
              int t=1;
              t = t * 1;
              //sleep(t);
          }
          qDebug() << "Execution done";
      }
};

#endif // UNVREADER2DLAUNCHER_H
