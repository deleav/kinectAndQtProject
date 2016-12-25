#include "KinectThread.h"
#define offset 10

KinectThread::KinectThread() {
    this->stopped = false;
    stirring = false ;
    motionNum = 0 ;
    successed = 0 ;
} // KinectThread constructor

int KinectThread::GetTrace( POINT point ) {
	static POINT last_point = point ;

	int nowStatus ;
	int x = point.x - last_point.x, y = point.y - last_point.y ;
	// 狀態為米字 不動為0 向右為1 右下2 下3 左下4 左5 左上6 上7 右上8
	if ( x <= offset && y <= offset && x >= -offset && y >= -offset ) nowStatus = 0 ; // 沒有動       狀態0
	else if  ( x > offset && y <= offset && y >= -offset )  nowStatus = 1 ;			  // 為向右移動   狀態1
	else if  ( x > offset && y > offset )  nowStatus = 2 ;									// 為向右下移動 狀態2
	else if  ( x <= offset && x >= -offset && y > offset ) nowStatus = 3 ;				// 為向下移動   狀態3
	else if  ( x < -offset && y > offset ) nowStatus = 4 ;                  // 為向左下移動 狀態4
	else if  ( y <= offset && x < -offset && y >= -offset ) nowStatus = 5 ;      // 為向左移動   狀態5
	else if  ( x < -offset && y < -offset ) nowStatus = 6 ;                 // 為向左上移動 狀態6
	else if  ( x <= offset && x >= -offset && y < -offset ) nowStatus = 7 ;      // 為向上移動   狀態7
	else if  ( x > offset && y < -offset ) nowStatus = 8 ;                  // 為向右上移動 狀態8
    
	last_point = point ; // 舊點更新
  return nowStatus ;
} // GetTrace()

void KinectThread::run() {
  int radius = 300 ;

  POINT skeletonPoint[NUI_SKELETON_COUNT][NUI_SKELETON_POSITION_COUNT];// 6個骨架 每個骨架20個點的點宣告
  
  bool tracked[NUI_SKELETON_COUNT]={FALSE};  // 6個骨架的boolean是否有追查到
	int theOne = -1 ; // 現在的骨架是
  POINT pos_right_wrist, pos_left_wrist; // 滑鼠的點座標
	bool pressing = false ;
	bool kinCtrl = true ;
  bool leftKneeUp = false ;
	bool rightKneeUp = false ;
  float fx, fy;
  float fx2, fy2;
  int wantFind[4] = {NUI_SKELETON_POSITION_WRIST_RIGHT,NUI_SKELETON_POSITION_WRIST_LEFT,NUI_SKELETON_POSITION_KNEE_LEFT,NUI_SKELETON_POSITION_KNEE_RIGHT};
  HRESULT hr = NuiInitialize(NUI_INITIALIZE_FLAG_USES_SKELETON); // 初始化
  NUI_SKELETON_TRACKING_STATE trackingState ;
  if (FAILED(hr)) { 
      cout<<"NuiInitialize failed"<<endl; 
      kinCtrl = false ;
  } // if 失敗退出 

  HANDLE skeletonEvent = CreateEvent( NULL, TRUE, FALSE, NULL ); // 定義骨架
 
  hr = NuiSkeletonTrackingEnable( skeletonEvent, 0 ); //開啟骨架事件追蹤
  if( FAILED( hr ) ) { 
      cout<<"Could not open color image stream video"<<endl; 
      NuiShutdown(); 
      kinCtrl = false ;
  } // if 失敗退出
  
  NUI_SKELETON_FRAME skeletonFrame = {0};  //骨架偵
 	NUI_TRANSFORM_SMOOTH_PARAMETERS p ;
  if ( stirring )
    p.fSmoothing = (float)0.85, p.fCorrection = (float)0.2, p.fPrediction = (float)0.4 ,p.fJitterRadius = (float)0.6, p.fMaxDeviationRadius = (float)0.5;
  else
    p.fSmoothing = (float)0.85, p.fCorrection = (float)0.0, p.fPrediction = (float)0.0 ,p.fJitterRadius = (float)0.4, p.fMaxDeviationRadius = (float)0.3;
  
  bool bFoundSkeleton = false; 
	if ( kinCtrl ) { // 使用kinect操控
    while(1) { // 讀取骨架數據
		  bFoundSkeleton = false; 

			//4.1、无限等待新的数据，等到后返回
		  if (WaitForSingleObject(skeletonEvent, INFINITE)==0) { //4.2、从刚才打开数据流的流句柄中得到该帧数据，读取到的数据地址存于skeletonFrame
        hr = NuiSkeletonGetNextFrame( 0, &skeletonFrame); 

    	  if (SUCCEEDED(hr)) //NUI_SKELETON_COUNT是检测到的骨骼数（即，跟踪到的人数）
          if ( !( theOne != -1 && ( skeletonFrame.SkeletonData[theOne].eTrackingState == NUI_SKELETON_TRACKED ) ) )
	          for( int i = 0 ; i < NUI_SKELETON_COUNT ; i++ ) { 
		          trackingState = skeletonFrame.SkeletonData[i].eTrackingState;
		      	  //4.3、Kinect最多检测六个人，但只能跟踪两个人的骨骼，再检查每个“人”（有可能是空，不是人）
		      	  //是否跟踪到了 
              if ( trackingState == NUI_SKELETON_TRACKED ) {
                bFoundSkeleton = true;
				  	    if ( theOne == -1 ) {
                  theOne = i ;
                  break ;
                } // if
              } // if
              else {
                if ( theOne == i ) // 原本的theOne消失了
                  theOne = -1 ;
              } // else
            } // for 

 		    //4.4、平滑骨骼帧，消除抖动
        NuiTransformSmooth(&skeletonFrame, &p );
        if( skeletonFrame.SkeletonData[theOne].eTrackingState == NUI_SKELETON_TRACKED &&   
				    skeletonFrame.SkeletonData[theOne].eSkeletonPositionTrackingState[NUI_SKELETON_POSITION_SHOULDER_CENTER] != NUI_SKELETON_POSITION_NOT_TRACKED) {   
	
				  	//拿到所有跟踪到的关节点的坐标，并转换为我们的深度空间的坐标，因为我们是在深度图像中
				  	//把这些关节点标记出来的
				  	//NUI_SKELETON_POSITION_COUNT为跟踪到的一个骨骼的关节点的数目，为20 

				  	for (int j = 0; j < 4; j++)  {   
					  	NuiTransformSkeletonToDepthImage(skeletonFrame.SkeletonData[theOne].SkeletonPositions[wantFind[j]], &fx, &fy );   // 空間轉換
					  	skeletonPoint[theOne][wantFind[j]].x = (int)( fx  ) ;   // 轉換出來的值進行設定
					  	skeletonPoint[theOne][wantFind[j]].y = (int)( fy );
              if ( wantFind[j] == NUI_SKELETON_POSITION_WRIST_RIGHT ) {
                fx2 = fx ;
                fy2 = fy ;
              } // if
			  		}  // for
            if ( motionNum == 0 ) {
				    	// 右手腕 滑鼠位置
				      // printf( "(%d,%d)\n", skeletonPoint[theOne][NUI_SKELETON_POSITION_WRIST_RIGHT].x,  skeletonPoint[theOne][NUI_SKELETON_POSITION_WRIST_RIGHT].y ) ;
					  
							pos_right_wrist.x = (fx2-100.0) * 6.5 ;
              pos_right_wrist.y = fy2 *6.8 ;
								
							// SetCursorPos ( (pos_right_wrist.x - 60 )* 7.2 ,pos_right_wrist.y  * 6.5  );
							SetCursorPos ( pos_right_wrist.x ,pos_right_wrist.y  ); 
                  
              // 左手腕 滑鼠左鍵
                  
							pos_left_wrist.x = skeletonPoint[theOne][NUI_SKELETON_POSITION_WRIST_LEFT].x ;
              pos_left_wrist.y = skeletonPoint[theOne][NUI_SKELETON_POSITION_WRIST_LEFT].y ;
                
							if ( !pressing && pos_left_wrist.y < 85 )
							  mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0 ), pressing = true; 
							else if ( pressing && pos_left_wrist.y > 85 )
							  mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0 ), pressing = false ; 
                  
            } // if 
            else if ( motionNum == 1 ) {
              // 雙手上舉
              static bool up = false ;
              if ( !up && skeletonPoint[theOne][NUI_SKELETON_POSITION_WRIST_LEFT].y <= 40 && skeletonPoint[theOne][NUI_SKELETON_POSITION_WRIST_RIGHT].y <= 40 )
                up = true ;
              else if ( up && skeletonPoint[theOne][NUI_SKELETON_POSITION_WRIST_LEFT].y > 40 && skeletonPoint[theOne][NUI_SKELETON_POSITION_WRIST_RIGHT].y > 40 ) {
                up = false ;
                // 雙擊
							  mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0 ) ;
							  mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0 ) ; 
							  mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0 ) ;
							  mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0 ) ; 
              } // else if 
                
              // 左膝蓋 雙擊
                  
              if (  skeletonPoint[theOne][NUI_SKELETON_POSITION_KNEE_LEFT].y < 130 )
                leftKneeUp = true ;
              if ( leftKneeUp && rightKneeUp ) {
							  mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0 ) ;
							  mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0 ) ; 
							  mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0 ) ;
							  mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0 ) ; 
                leftKneeUp = rightKneeUp = false ;
              } // if
                // 右膝蓋 雙擊
              if (  skeletonPoint[theOne][NUI_SKELETON_POSITION_KNEE_RIGHT].y < 130 )
                rightKneeUp = true ;
              if ( leftKneeUp && rightKneeUp ) {
							  mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0 ) ;
							  mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0 ) ; 
							  mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0 ) ;
							  mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0 ) ; 
                leftKneeUp = rightKneeUp = false ;
              } // if
            } // else if
		  		} // if 
      }  // if
      else cout<<"Buffer length of received texture is bogus\r\n"<<endl; 
    }  // while
    //5、关闭NUI链接 
    NuiShutdown(); 
	} // if
}