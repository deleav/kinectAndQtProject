#ifndef LINECTTHREAD_H
#define LINECTTHREAD_H

#include <QThread>
#include <windows.h>
#include <iostream> 
#include <NuiApi.h>

using namespace std;

class QLabel;
class QPixmap;

class KinectThread : public QThread {
  Q_OBJECT

public:
  KinectThread();
  bool stopped;
  int GetTrace( POINT point ) ;
  void UpMoon( POINT * at, int state );
  
  bool stirring ;
  int motionNum ;
  int successed ;
protected:
  void run();

} ; // KinectThread
#endif