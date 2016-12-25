# include "UI.h"

void UI::mouseMoveEvent(QMouseEvent *event) {
  int nowStatus = GetTrace(event); 

  cout << event->x() << " " << event->y() << "  direction " << nowStatus <<  endl ;
  if ( seasonNum == 0 ) { // 選季節以前
    if ( pageAt.compare("brand") == 0 ) {
      if ( pressAt.x != -1 ) // 有點
        brandPage->setGeometry( -1280+(event->x()-pressAt.x),0,3840, 720 );

    } // if
    else if ( pageAt.compare("season") == 0 ) {
      static int atX1 = 100, atX2 = 370, atX3 = 640, atX4 = 910, atX5 = 1180, atY1 = 75, atY2 = 630 ;
      if ( event->y() >= atY1 && atY2 >= event->y() && event->x() >= atX1 && event->x() <= atX5 ) {
        if ( event->x() <= atX2 ) 
          palette.setBrush( seasonPage->backgroundRole(), QBrush( QPixmap("../Images/background/bg3-2.png") ) );
        else if ( event->x() <= atX3 ) 
          palette.setBrush( seasonPage->backgroundRole(), QBrush( QPixmap("../Images/background/bg3-3.png") ) );
        else if ( event->x() <= atX4 ) 
          palette.setBrush( seasonPage->backgroundRole(), QBrush( QPixmap("../Images/background/bg3-4.png") ) );
        else 
          palette.setBrush( seasonPage->backgroundRole(), QBrush( QPixmap("../Images/background/bg3-5.png") ) );
      
        seasonPage->setPalette( palette );
      } // if
      else {
        palette.setBrush( seasonPage->backgroundRole(), QBrush( QPixmap("../Images/background/bg3-1.png") ) );
        seasonPage->setPalette( palette );

      } // else 
    } // else if
  } // if 
  else if ( seasonNum == 1 ) { // 春天
    if ( pageAt.compare("foodImformation") == 0 ) {
      if ( pressAt.x != -1 ) // 有點
        foodPage->setGeometry( -1280+(event->x()-pressAt.x),0,3840, 720 );
    } // if
    else if ( pageAt.compare("SpringPage1PickingMeterial") == 0 ) {
      if ( materialNum == 1 ) 
        s1c1material1->setGeometry(event->x()-100,event->y()-100,150,150);
      else if ( materialNum == 2 ) 
        s1c1material2->setGeometry(event->x()-100,event->y()-100,150,150);
      else if ( materialNum == 3 ) 
        s1c1material3->setGeometry(event->x()-100,event->y()-100,150,150);
      else if ( materialNum == 4 ) 
        s1c1material4->setGeometry(event->x()-100,event->y()-100,150,150);
      else if ( materialNum == 5 )
        s1c1material5->setGeometry(event->x()-100,event->y()-100,150,150);
    
      if ( s1c1material1->underMouse()  ) {
        s1c1material1->setFixedSize( buttonSize200 ) ;
        s1c1material1->setIconSize(buttonSize200);
      } // if
      else if ( s1c1material2->underMouse() ) {
        s1c1material2->setFixedSize( buttonSize200 ) ;
        s1c1material2->setIconSize(buttonSize200);
      } // else if
      else if ( s1c1material3->underMouse() ) {
        s1c1material3->setFixedSize( buttonSize200 ) ;
        s1c1material3->setIconSize(buttonSize200);
      } // else if
      else if ( s1c1material4->underMouse() ) {
        s1c1material4->setFixedSize( buttonSize200 ) ;
        s1c1material4->setIconSize(buttonSize200);
      } // else if
      else if ( s1c1material5->underMouse() ) {
        s1c1material5->setFixedSize( buttonSize200 ) ;
        s1c1material5->setIconSize(buttonSize200);
      } // else if
      else {
        s1c1material1->setFixedSize( buttonSize150 ) ;
        s1c1material1->setIconSize(buttonSize150);
        s1c1material2->setFixedSize( buttonSize150 ) ;
        s1c1material2->setIconSize(buttonSize150);
        s1c1material3->setFixedSize( buttonSize150 ) ;
        s1c1material3->setIconSize(buttonSize150);
        s1c1material4->setFixedSize( buttonSize150 ) ;
        s1c1material4->setIconSize(buttonSize150);
        s1c1material5->setFixedSize( buttonSize150 ) ;
        s1c1material5->setIconSize(buttonSize150);
      } // else 

      if ( ( c1SizeX1 <  event->x()-100 &&  event->x()-100 < c1SizeX2 )  &&  ( c1SizeY1 < event->y()-100 && event->y()-100 < c1SizeY2 ) ) 
          if ( S1c1materialInDish() ) 
          s1c1finished->show();
    } // else if
    else {
      if ( pageAt.compare("SpringPage2WashMaterial") == 0 ) {
        POINT pause ;
	      if ( IsLeftAndRightWashDown( nowStatus ) ) // 分析圖形
          counterForAll++ ;
        cout << counterForAll << endl ;
		    Sleep(30);
        if ( counterForAll == 1 && counterForAll2 == 1 ) {
          palette.setBrush( cookPageSpring2->backgroundRole(), QBrush( QPixmap("../images/background/bgS1C2P2.png") ) );
          cookPageSpring2->setPalette( palette );
          counterForAll2 = 2 ;
		      Sleep(80);
		      GetCursorPos(&pause);
          SetCursorPos(pause.x,pause.y);
        } // if
        else if ( counterForAll == 2  && counterForAll2 == 2 ) {
          palette.setBrush( cookPageSpring2->backgroundRole(), QBrush( QPixmap("../images/background/bgS1C2P3.png") ) );
          cookPageSpring2->setPalette( palette );
          counterForAll2 = 3 ;
		      Sleep(80);
		      GetCursorPos(&pause);
          SetCursorPos(pause.x,pause.y);
        } // else if 
        else if ( counterForAll == 3 && counterForAll2 == 3) {
          palette.setBrush( cookPageSpring2->backgroundRole(), QBrush( QPixmap("../images/background/bgS1C2P4.png") ) );
          cookPageSpring2->setPalette( palette );
          counterForAll2 = 4 ;
		      Sleep(80);
		      GetCursorPos(&pause);
          SetCursorPos(pause.x,pause.y);
          s1c2finished->show();
        } // else if 
      } // if
      else if ( pageAt.compare("SpringPage3CutWhiteFungus") == 0 ) {
        
        POINT nowPoint ;
        nowPoint.x = event->x();
        nowPoint.y = event->y();
        bool restart = counterForAll2 == 1   ;
        if ( IsPassThePoints( p1_c2 ,p2_c2,p3_c2, nowPoint, restart  ) ) {// 分析圖形(經過圓)
          s1c3finished->show() ;
          palette.setBrush( cookPageSpring3->backgroundRole(), QBrush( QPixmap("../images/background/bgS1C3P2.png") ) );
          cookPageSpring3->setPalette( palette );
          this->setCursor(QCursor(QPixmap("../Images/cursor/hand1Cursor.png")));
        } // if
      } // else if
      else if ( pageAt.compare("SpringPage4TearWhiteFungus") == 0 ) { //  撕銀耳

        if ( nowStatus == 7 && counterForAll2 == 1 ) { 
          counterForAll2 = 2 ;
          palette.setBrush( cookPageSpring4->backgroundRole(), QBrush( QPixmap("../images/background/bgS1C4P2.png") ) );
          cookPageSpring4->setPalette( palette );
		      Sleep(10);
          
        } // if
        else if ( nowStatus == 8 && counterForAll2 == 2 ) { 
          counterForAll2 = 3 ;
          palette.setBrush( cookPageSpring4->backgroundRole(), QBrush( QPixmap("../images/background/bgS1C4P3.png") ) );
          cookPageSpring4->setPalette( palette );
		      Sleep(10);
        } // else if
        else if ( nowStatus == 1 && counterForAll2 == 3 ) { 
          counterForAll2 = 4 ;
          palette.setBrush( cookPageSpring4->backgroundRole(), QBrush( QPixmap("../images/background/bgS1C4P4.png") ) );
          cookPageSpring4->setPalette( palette );
		      Sleep(10);
        } // else if
        else if ( nowStatus == 2 && counterForAll2 == 4 ) { 
          counterForAll2 = 5 ;
          palette.setBrush( cookPageSpring4->backgroundRole(), QBrush( QPixmap("../images/background/bgS1C4P5.png") ) );
          cookPageSpring4->setPalette( palette );
		      Sleep(10);
        } // else if
        else if ( nowStatus == 3 && counterForAll2 == 5 ) { 
          counterForAll2 = 6 ;
          palette.setBrush( cookPageSpring4->backgroundRole(), QBrush( QPixmap("../images/background/bgS1C4P6.png") ) );
          cookPageSpring4->setPalette( palette );
		      Sleep(10);
        } // else if
        else if ( nowStatus == 4 && counterForAll2 == 6 ) { 
          counterForAll2 = 7 ;
          palette.setBrush( cookPageSpring4->backgroundRole(), QBrush( QPixmap("../images/background/bgS1C4P7.png") ) );
          cookPageSpring4->setPalette( palette );
		      Sleep(10);
        } // else if
        else if ( nowStatus == 5 && counterForAll2 == 7 ) { 
          counterForAll2 = 8 ;
          palette.setBrush( cookPageSpring4->backgroundRole(), QBrush( QPixmap("../images/background/bgS1C4P8.png") ) );
          cookPageSpring4->setPalette( palette );
		      Sleep(10);
        } // else if
        else if ( nowStatus == 6 && counterForAll2 == 8 ) { 
          counterForAll2 = 0 ;
          palette.setBrush( cookPageSpring4->backgroundRole(), QBrush( QPixmap("../images/background/bgS1C4P9.png") ) );
          cookPageSpring4->setPalette( palette );
          s1c4finished->show();
		      Sleep(10);
        } // else if
        this->show();
		    Sleep(70);
      } // else if
      else if ( pageAt.compare("SpringPage5AddToPot") == 0 ) { // 加料
      
        if ( materialNum == 1 ) 
          s1c5material1->setGeometry(event->x()-50,event->y()-50,130,160);
        else if ( materialNum == 2 ) 
          s1c5material2->setGeometry(event->x()-50,event->y()-50,130,160);
        else if ( materialNum == 3 ) 
          s1c5material3->setGeometry(event->x()-50,event->y()-50,130,160);
        else if ( materialNum == 4 ) 
          s1c5material4->setGeometry(event->x()-50,event->y()-50,130,160);
        else if ( materialNum == 5 ) 
          s1c5material5->setGeometry(event->x()-50,event->y()-50,130,160);

        if ( ( potSizeX1 <  event->x()-50 &&  event->x()-50 < potSizeX2 )  &&  ( potSizeY1 < event->y()-50 && event->y()-50 < potSizeY2 ) ) 
          if ( S1c5materialInPot() ) 
            s1c5finished->show();

      } // else if
    
      else if (  pageAt.compare("SpringPage6StirSoup") == 0 ) {
        if ( useKinect )
          kinectThread->stirring = true ;
        this->setCursor(QCursor(QPixmap("../Images/cursor/spoonCursor.png")));
        static int beStatus = 0 ;
        if ( isClockwiseCircle( beStatus, nowStatus ) ) { // 分析圖形
          counterForAll++ ;
          
          if ( counterForAll == 1 ) {
            palette.setBrush( cookPageSpring6->backgroundRole(), QBrush( QPixmap("../images/background/bgS1C6P2.png") ) );
            cookPageSpring6->setPalette( palette );
          } // if
          else if ( counterForAll == 2 ) {
            palette.setBrush( cookPageSpring6->backgroundRole(), QBrush( QPixmap("../images/background/bgS1C6P3.png") ) );
            cookPageSpring6->setPalette( palette );
          } // if
          else if ( counterForAll == 3 ) {
            palette.setBrush( cookPageSpring6->backgroundRole(), QBrush( QPixmap("../images/background/bgS1C6P4.png") ) );
            cookPageSpring6->setPalette( palette );
            s1c6finished->show();
            if ( useKinect ) 
              kinectThread->stirring = false ;
            this->setCursor(QCursor(QPixmap("../Images/cursor/hand1Cursor.png")));
          } // if
        } // if
        cout << "direction" << nowStatus << endl ;
		    Sleep(80);
      } // else if 
    } // else 
  } // else if 春天
  else if ( seasonNum == 2 ) { // 夏天
    
    if ( pageAt.compare("foodImformation") == 0 ) {
      if ( pressAt.x != -1 ) // 有點
        foodPage->setGeometry( -1280+(event->x()-pressAt.x),0,3840, 720 );
    } // if
    else if ( pageAt.compare("SummerPage1PickingMeterial") == 0 ) {
      if ( materialNum == 1 ) 
        s2c1material1->setGeometry(event->x()-100,event->y()-100,150,150);
      else if ( materialNum == 2 ) 
        s2c1material2->setGeometry(event->x()-100,event->y()-100,150,150);
      else if ( materialNum == 3 ) 
        s2c1material3->setGeometry(event->x()-100,event->y()-100,150,150);
      else if ( materialNum == 4 ) 
        s2c1material4->setGeometry(event->x()-100,event->y()-100,150,150);
      else if ( materialNum == 5 ) 
        s2c1material5->setGeometry(event->x()-100,event->y()-100,150,150);
      
      if ( s2c1material1->underMouse()  ) {
        s2c1material1->setFixedSize( buttonSize200 ) ;
        s2c1material1->setIconSize(buttonSize200);
      } // if
      else if ( s2c1material2->underMouse() ) {
        s2c1material2->setFixedSize( buttonSize200 ) ;
        s2c1material2->setIconSize(buttonSize200);
      } // else if
      else if ( s2c1material3->underMouse() ) {
        s2c1material3->setFixedSize( buttonSize200 ) ;
        s2c1material3->setIconSize(buttonSize200);
      } // else if
      else if ( s2c1material4->underMouse() ) {
        s2c1material4->setFixedSize( buttonSize200 ) ;
        s2c1material4->setIconSize(buttonSize200);
      } // else if
      else if ( s2c1material5->underMouse() ) {
        s2c1material5->setFixedSize( buttonSize200 ) ;
        s2c1material5->setIconSize(buttonSize200);
      } // else if
      else {
        s2c1material1->setFixedSize( buttonSize150 ) ;
        s2c1material1->setIconSize(buttonSize150);
        s2c1material2->setFixedSize( buttonSize150 ) ;
        s2c1material2->setIconSize(buttonSize150);
        s2c1material3->setFixedSize( buttonSize150 ) ;
        s2c1material3->setIconSize(buttonSize150);
        s2c1material4->setFixedSize( buttonSize150 ) ;
        s2c1material4->setIconSize(buttonSize150);
        s2c1material5->setFixedSize( buttonSize150 ) ;
        s2c1material5->setIconSize(buttonSize150);
      } // else 

      if ( ( c1SizeX1 <  event->x()-100 &&  event->x()-100 < c1SizeX2 )  &&  ( c1SizeY1 < event->y()-100 && event->y()-100 < c1SizeY2 ) ) 
        if ( S2c1materialInDish() ) 
          s2c1finished->show();
    } // else if 2-1
    else if ( pageAt.compare("SummerPage2CutWaterMelon") == 0 ) {
        
      this->setCursor(QCursor(QPixmap("../Images/cursor/knifeCursor.png")));
      POINT nowPoint ;
      bool restart = counterForAll2 == 1 ;
      nowPoint.x = event->x();
      nowPoint.y = event->y();
      if ( IsPassThePoints( s2c2Point1, s2c2Point2, s2c2Point3, nowPoint,restart ) ) {// 分析圖形(經過圓)
        counterForAll2 = 0 ;
        palette.setBrush( cookPageSummer2->backgroundRole(), QBrush(QPixmap("../images/background/bgS2C2P2.png") ) );
        cookPageSummer2->setPalette( palette );
        s2c2finished->show(); 
      } // if

    } // else if
    else if ( pageAt.compare("SummerPage3CutWatermelonToPiece") == 0 ) {
      this->setCursor(QCursor(QPixmap("../Images/cursor/knifeCursor.png")));
      static bool downing = false ;
      if (  counterForAll == 0 ) 
        downing = false ;
      Sleep(30);

      if ( nowStatus == 3 && !downing) { //向下
        if ( counterForAll == 0 ) 
          palette.setBrush( cookPageSummer3->backgroundRole(), QBrush(QPixmap("../images/background/bgS2C3P2.png") ) );
        else if ( counterForAll == 1 ) 
          palette.setBrush( cookPageSummer3->backgroundRole(), QBrush(QPixmap("../images/background/bgS2C3P4.png") ) );
        else if ( counterForAll == 2 ) 
          palette.setBrush( cookPageSummer3->backgroundRole(), QBrush(QPixmap("../images/background/bgS2C3P6.png") ) );
        else if ( counterForAll == 3 ) 
          palette.setBrush( cookPageSummer3->backgroundRole(), QBrush(QPixmap("../images/background/bgS2C3P8.png") ) );
        else if ( counterForAll == 4 ) {
          palette.setBrush( cookPageSummer3->backgroundRole(), QBrush(QPixmap("../images/background/bgS2C3P10.png") ) );
          s2c3finished->show();
        } // else if
        cookPageSummer3->setPalette( palette );
        counterForAll++ ;
        downing = true ;
      } // if
      else if ( nowStatus == 7 && downing ) { // 向上
        if ( counterForAll == 1 ) 
          palette.setBrush( cookPageSummer3->backgroundRole(), QBrush(QPixmap("../images/background/bgS2C3P3.png") ) );
        else if ( counterForAll == 2 ) 
          palette.setBrush( cookPageSummer3->backgroundRole(), QBrush(QPixmap("../images/background/bgS2C3P5.png") ) );
        else if ( counterForAll == 3 ) 
          palette.setBrush( cookPageSummer3->backgroundRole(), QBrush(QPixmap("../images/background/bgS2C3P7.png") ) );
        else if ( counterForAll == 4 ) 
          palette.setBrush( cookPageSummer3->backgroundRole(), QBrush(QPixmap("../images/background/bgS2C3P9.png") ) );
        cookPageSummer3->setPalette( palette );
        downing = false ;
      } // else if
    } // else if
    else if ( pageAt.compare("SummerPage4CutPineappleToPiece") == 0 ) {

      static bool downing = false ;
      this->setCursor(QCursor(QPixmap("../Images/cursor/knifeCursor.png")));
      Sleep(30);
      if (  counterForAll == 0 ) 
        downing = false ;

      if ( nowStatus == 3 && !downing) { //向下
        if ( counterForAll == 0 ) 
          palette.setBrush( cookPageSummer4->backgroundRole(), QBrush(QPixmap("../images/background/bgS2C4P2.png") ) );
        else if ( counterForAll == 1 ) 
          palette.setBrush( cookPageSummer4->backgroundRole(), QBrush(QPixmap("../images/background/bgS2C4P4.png") ) );
        else if ( counterForAll == 2 ) 
          palette.setBrush( cookPageSummer4->backgroundRole(), QBrush(QPixmap("../images/background/bgS2C4P6.png") ) );
        else if ( counterForAll == 3 ) {
          palette.setBrush( cookPageSummer4->backgroundRole(), QBrush(QPixmap("../images/background/bgS2C4P8.png") ) );
          s2c4finished->show();
        } // else if
        cookPageSummer4->setPalette( palette );
        counterForAll++ ;
        downing = true ;
      } // if
      else if ( nowStatus == 7 && downing ) { // 向sun
        if ( counterForAll == 1 ) 
          palette.setBrush( cookPageSummer4->backgroundRole(), QBrush(QPixmap("../images/background/bgS2C4P3.png") ) );
        else if ( counterForAll == 2 ) 
          palette.setBrush( cookPageSummer4->backgroundRole(), QBrush(QPixmap("../images/background/bgS2C4P5.png") ) );
        else if ( counterForAll == 3 ) 
          palette.setBrush( cookPageSummer4->backgroundRole(), QBrush(QPixmap("../images/background/bgS2C4P7.png") ) );
        cookPageSummer4->setPalette( palette );
        downing = false ;
      } // else if
    } // else if 
    else if ( pageAt.compare("SummerPage5WashPeas") == 0 ) {
      
		  Sleep(30);
	    if ( IsLeftAndRightWashDown( nowStatus ) ) // 分析圖形
        counterForAll++ ;

      if ( counterForAll == 1 ) {
        palette.setBrush( cookPageSummer5->backgroundRole(), QBrush(QPixmap("../images/background/bgS2C5P2.png") ) );
        cookPageSummer5->setPalette( palette );
      } // if
      else if ( counterForAll == 2 ) {
        palette.setBrush( cookPageSummer5->backgroundRole(), QBrush(QPixmap("../images/background/bgS2C5P3.png") ) );
        cookPageSummer5->setPalette( palette );
      } // else if
      else if ( counterForAll == 3 ) {
        palette.setBrush( cookPageSummer5->backgroundRole(), QBrush(QPixmap("../images/background/bgS2C5P4.png") ) );
        cookPageSummer5->setPalette( palette );
        s2c5finished->show();
      } // else if

    } // else if 
    else if ( pageAt.compare("SummerPage7PutAll") == 0 ) {
      
      if ( materialNum == 1 ) 
        s2c7material1->setGeometry(event->x()-80,event->y()-80,138,227);
      else if ( materialNum == 2 ) 
        s2c7material2->setGeometry(event->x()-80,event->y()-80,188,178);
      else if ( materialNum == 3 ) 
        s2c7material3->setGeometry(event->x()-80,event->y()-80,165,176);
      else if ( materialNum == 4 ) 
        s2c7material4->setGeometry(event->x()-80,event->y()-80,155,196);

      if ( ( s2c7SizeX1 <  event->x()-80 &&  event->x()-80 < s2c7SizeX2 )  &&  ( s2c7SizeY1 < event->y()-80 && event->y()-80 < s2c7SizeY2 ) )  {
        if ( S2c7materialInBowl() ) 
          s2c7finished->show();
      
      } // if
    } // else if 
  } // else if 夏天
  else if ( seasonNum == 3 ) { // 秋天
    
    if ( pageAt.compare("foodImformation") == 0 ) {
      if ( pressAt.x != -1 ) // 有點
        foodPage->setGeometry( -1280+(event->x()-pressAt.x),0,3840, 720 );
    } // if
    else if ( pageAt.compare("AutumnPage1PickMeterial") == 0 ) {
       if ( materialNum == 1 ) 
        s3c1material1->setGeometry(event->x()-100,event->y()-100,150,150);
      else if ( materialNum == 2 ) 
        s3c1material2->setGeometry(event->x()-100,event->y()-100,150,150);
      else if ( materialNum == 3 ) 
        s3c1material3->setGeometry(event->x()-100,event->y()-100,150,150);
      else if ( materialNum == 4 ) 
        s3c1material4->setGeometry(event->x()-100,event->y()-100,150,150);
      else if ( materialNum == 5 )
        s3c1material5->setGeometry(event->x()-100,event->y()-100,150,150);
    
      if ( s3c1material1->underMouse()  ) {
        s3c1material1->setFixedSize( buttonSize200 ) ;
        s3c1material1->setIconSize(buttonSize200);
      } // if
      else if ( s3c1material2->underMouse() ) {
        s3c1material2->setFixedSize( buttonSize200 ) ;
        s3c1material2->setIconSize(buttonSize200);
      } // else if
      else if ( s3c1material3->underMouse() ) {
        s3c1material3->setFixedSize( buttonSize200 ) ;
        s3c1material3->setIconSize(buttonSize200);
      } // else if
      else if ( s3c1material4->underMouse() ) {
        s3c1material4->setFixedSize( buttonSize200 ) ;
        s3c1material4->setIconSize(buttonSize200);
      } // else if
      else if ( s3c1material5->underMouse() ) {
        s3c1material5->setFixedSize( buttonSize200 ) ;
        s3c1material5->setIconSize(buttonSize200);
      } // else if
      else {
        s3c1material1->setFixedSize( buttonSize150 ) ;
        s3c1material1->setIconSize(buttonSize150);
        s3c1material2->setFixedSize( buttonSize150 ) ;
        s3c1material2->setIconSize(buttonSize150);
        s3c1material3->setFixedSize( buttonSize150 ) ;
        s3c1material3->setIconSize(buttonSize150);
        s3c1material4->setFixedSize( buttonSize150 ) ;
        s3c1material4->setIconSize(buttonSize150);
        s3c1material5->setFixedSize( buttonSize150 ) ;
        s3c1material5->setIconSize(buttonSize150);
      } // else 

      if ( ( c1SizeX1 <  event->x()-100 &&  event->x()-100 < c1SizeX2 )  &&  ( c1SizeY1 < event->y()-100 && event->y()-100 < c1SizeY2 ) ) 
        if ( S3c1materialInDish() ) {
          s3c1finished->show();
          this->setCursor(QCursor(QPixmap("../Images/cursor/hand1Cursor.png")));
        } // if
    } // else if 3-1
    else if ( pageAt.compare("AutumnPage4TearLily") == 0 ) {
      Sleep(40);
      if ( counterForAll == 0 && nowStatus == 5 ) {
        palette.setBrush( cookPageAutumn4->backgroundRole(), QBrush(QPixmap("../images/background/bgS3C4P2.png") ) );
        cookPageAutumn4->setPalette( palette );
        counterForAll = 1 ;
        Sleep(40);
      } // if
      else if ( counterForAll == 1 && nowStatus == 4 ) {
        palette.setBrush( cookPageAutumn4->backgroundRole(), QBrush(QPixmap("../images/background/bgS3C4P3.png") ) );
        cookPageAutumn4->setPalette( palette );
        counterForAll = 2 ;
        Sleep(40);
      } // if
      else if ( counterForAll == 2 && nowStatus == 2 ) {
        palette.setBrush( cookPageAutumn4->backgroundRole(), QBrush(QPixmap("../images/background/bgS3C4P4.png") ) );
        cookPageAutumn4->setPalette( palette );
        counterForAll = 3 ;
        Sleep(40);
      } // if
      else if ( counterForAll == 3 && nowStatus == 1 ) {
        palette.setBrush( cookPageAutumn4->backgroundRole(), QBrush(QPixmap("../images/background/bgS3C4P5.png") ) );
        cookPageAutumn4->setPalette( palette );
        counterForAll = 4 ;
        s3c4finished->show();
      } // if

    } // else if 
    else if ( pageAt.compare("AutumnPage5WashRedBean") == 0 ) {
      

		  Sleep(30);
	    if ( IsLeftAndRightWashDown( nowStatus ) ) // 分析圖形
        counterForAll++ ;

      if ( counterForAll == 1 ) {
        palette.setBrush( cookPageAutumn5->backgroundRole(), QBrush(QPixmap("../images/background/bgS3C5P2.png") ) );
        cookPageAutumn5->setPalette( palette );
      } // if
      else if ( counterForAll == 3 ) {
        palette.setBrush( cookPageAutumn5->backgroundRole(), QBrush(QPixmap("../images/background/bgS3C5P3.png") ) );
        cookPageAutumn5->setPalette( palette );
        s3c5finished->show();
      } // else if
    } // else if 
    else if ( pageAt.compare("AutumnPage6CookAll") == 0 ) {
      
      if ( materialNum == 1 ) 
        s3c6material1->setGeometry(event->x()-100,event->y()-100,200,200);
      else if ( materialNum == 2 ) 
        s3c6material2->setGeometry(event->x()-100,event->y()-100,200,200);
      else if ( materialNum == 3 ) 
        s3c6material3->setGeometry(event->x()-100,event->y()-100,200,200);
      
      if ( s3c6material1->underMouse()  ) {
        s3c6material1->setFixedSize( buttonSize200 ) ;
        s3c6material1->setIconSize(buttonSize200);
      } // if
      else if ( s3c6material2->underMouse() ) {
        s3c6material2->setFixedSize( buttonSize200 ) ;
        s3c6material2->setIconSize(buttonSize200);
      } // else if
      else if ( s3c6material3->underMouse() ) {
        s3c6material3->setFixedSize( buttonSize200 ) ;
        s3c6material3->setIconSize(buttonSize200);
      } // else if
      else {
        s3c6material1->setFixedSize( buttonSize100 ) ;
        s3c6material1->setIconSize(buttonSize100);
        s3c6material2->setFixedSize( buttonSize100 ) ;
        s3c6material2->setIconSize(buttonSize100);
        s3c6material3->setFixedSize( buttonSize100 ) ;
        s3c6material3->setIconSize(buttonSize100);
      } // else 
      
      // cout << event->x() << " " << event->y() << endl ;
      if ( ( s2c7SizeX1 <  event->x()-100 &&  event->x()-100 < s2c7SizeX2 )  &&  ( s2c7SizeY1 < event->y()-100 && event->y()-100 < s2c7SizeY2 ) )  {
         if ( S3c6materialInPot() )
           s3c6finished->show();
      
      } // if
    } // else if 
    else if ( pageAt.compare("AutumnPage8CookAll") == 0 ) {
      
      if ( materialNum == 1 ) 
        s3c8material1->setGeometry(event->x()-100,event->y()-100,200,200);
      else if ( materialNum == 2 ) 
        s3c8material2->setGeometry(event->x()-100,event->y()-100,200,200);
      
      if ( s3c8material1->underMouse()  ) {
        s3c8material1->setFixedSize( buttonSize200 ) ;
        s3c8material1->setIconSize(buttonSize200);
      } // if
      else if ( s3c8material2->underMouse() ) {
        s3c8material2->setFixedSize( buttonSize200 ) ;
        s3c8material2->setIconSize(buttonSize200);
      } // else if
      else {
        s3c8material1->setFixedSize( buttonSize100 ) ;
        s3c8material1->setIconSize(buttonSize100);
        s3c8material2->setFixedSize( buttonSize100 ) ;
        s3c8material2->setIconSize(buttonSize100);
      } // else 
      
      // cout << event->x() << " " << event->y() << endl ;
      if ( ( s2c7SizeX1 <  event->x()-100 &&  event->x()-100 < s2c7SizeX2 )  &&  ( s2c7SizeY1 < event->y()-100 && event->y()-100 < s2c7SizeY2 ) )  {
        if ( S3c8materialInPot() )
          s3c8finished->show();
      
      } // if
    } // else if 
  } // else if 秋天
  else if ( seasonNum == 4 ) {
    
    if ( pageAt.compare("foodImformation") == 0 ) {
      if ( pressAt.x != -1 ) // 有點
        foodPage->setGeometry( -1280+(event->x()-pressAt.x),0,3840, 720 );
    } // if
    else if ( pageAt.compare("WinterPage1PickMeterial") == 0 ) {
      if ( materialNum == 1 ) 
        s4c1material1->setGeometry(event->x()-125,event->y()-125,250,250);
      else if ( materialNum == 2 ) 
        s4c1material2->setGeometry(event->x()-125,event->y()-125,250,250);
      else if ( materialNum == 3 ) 
        s4c1material3->setGeometry(event->x()-125,event->y()-125,250,250);
      else if ( materialNum == 4 ) 
        s4c1material4->setGeometry(event->x()-150,event->y()-125,250,250);
      
      if ( s4c1material1->underMouse()  ) {
        s4c1material1->resize(buttonSize250);
        s4c1material1->setIconSize(buttonSize250);
      } // if
      else if ( s4c1material2->underMouse() ) {
        s4c1material2->resize(buttonSize250);
        s4c1material2->setIconSize(buttonSize250);
      } // else if
      else if ( s4c1material3->underMouse() ) {
        s4c1material3->resize(buttonSize250);
        s4c1material3->setIconSize(buttonSize250);
      } // else if
      else if ( s4c1material4->underMouse() ) {
        s4c1material4->resize(buttonSize250);
        s4c1material4->setIconSize(buttonSize250);
      } // else if
      else {
        s4c1material1->resize(buttonSize150);
        s4c1material1->setIconSize(buttonSize150);
        s4c1material2->resize(buttonSize150);
        s4c1material2->setIconSize(buttonSize150);
        s4c1material3->resize(buttonSize150);
        s4c1material3->setIconSize(buttonSize150);
        s4c1material4->resize(buttonSize150);
        s4c1material4->setIconSize(buttonSize150);
      } // else 

      if ( ( c1SizeX1 <  event->x()-125 &&  event->x()-125 < c1SizeX2 )  &&  ( c1SizeY1 < event->y()-125 && event->y()-125 < c1SizeY2 ) ) 
        if ( S4c1materialInDish() ) 
          s4c1finished->show();
    } // else if 4-1
    else if (pageAt.compare("WinterPage2LonganShell") == 0) {
      static bool leftOk = false, rightOk = false ;
      if ( counterForAll == 0 ) {
        leftOk = false ;
        rightOk = false ;
        counterForAll = 1 ;
      } // if
      if ( counterForAll2 == 1 ) { 
        if ( nowStatus == 1 ) 
          rightOk = true ;
        else if ( nowStatus == 5 )
          leftOk = true ;
        if ( leftOk && rightOk ) {
          counterForAll2 = 2 ;
          leftOk = rightOk = false ;
          palette.setBrush( cookPageWinter2->backgroundRole(), QBrush( QPixmap("../images/background/bgS4C2P2.png") ));
          cookPageWinter2->setPalette( palette );
          cookPageWinter2->setMask( QPixmap("../images/background/bgS4C2P2.png").mask() );
          cookPageWinter2->setAutoFillBackground( true );
        } // if
      } // if
      else if ( counterForAll2 == 2 ) {
        if ( nowStatus == 1 ) 
          rightOk = true ;
        else if ( nowStatus == 5 )
          leftOk = true ;
        if ( leftOk && rightOk ) { // 大成功!
          counterForAll2 = 0 ;
          leftOk = rightOk = false ;
          palette.setBrush( cookPageWinter2->backgroundRole(), QBrush( QPixmap("../images/background/bgS4C2P3.png") ));
          cookPageWinter2->setPalette( palette );
          cookPageWinter2->setMask( QPixmap("../images/background/bgS4C2P3.png").mask() );
          cookPageWinter2->setAutoFillBackground( true );
          s4c2finished->show() ;
        } // if
      } // else if 
    } // else if 4-2
    else if (pageAt.compare("WinterPage3WashLongan") == 0) {

		  Sleep(30);
	    if ( IsLeftAndRightWash( nowStatus ) ) {// 分析圖形
        counterForAll++ ;
        if ( counterForAll == 1 ) {
          palette.setBrush( cookPageWinter3->backgroundRole(), QBrush( QPixmap("../images/background/bgS4C3P2") ));
          cookPageWinter3->setPalette( palette );
        } // if
        else if ( counterForAll == 2 ) {
          palette.setBrush( cookPageWinter3->backgroundRole(), QBrush( QPixmap("../images/background/bgS4C3P3") ));
          cookPageWinter3->setPalette( palette );
        } // else if
        else if ( counterForAll == 3 ) {
          palette.setBrush( cookPageWinter3->backgroundRole(), QBrush( QPixmap("../images/background/bgS4C3P4") ));
          cookPageWinter3->setPalette( palette );
          s4c3finished->show();
        } // else if
      } // if
    } // else if 4-3
    else if (pageAt.compare("WinterPage4CutNewYearCake") == 0) {
      static bool upOk = true;
      if ( counterForAll == 0 ) {
        upOk = true ;
        counterForAll = 1 ;
      } // if
      if ( nowStatus == 7 )
        upOk = true ;
      if ( nowStatus == 3 && upOk ) {
        if ( counterForAll2 == 1 ) {
          upOk = false ;
          palette.setBrush( cookPageWinter4->backgroundRole(), QBrush( QPixmap("../images/background/bgS4C4P2") ));
          cookPageWinter4->setPalette( palette );
          counterForAll2 = 2 ;
        } // if
        else if ( counterForAll2 == 2 ) {
          upOk = false ;
          palette.setBrush( cookPageWinter4->backgroundRole(), QBrush( QPixmap("../images/background/bgS4C4P3") ));
          cookPageWinter4->setPalette( palette );
          counterForAll2 = 3 ;

        } // else if 
        else if ( counterForAll2 == 3 ) {
          palette.setBrush( cookPageWinter4->backgroundRole(), QBrush( QPixmap("../images/background/bgS4C4P4") ));
          cookPageWinter4->setPalette( palette );
          counterForAll2 = 4 ;
          upOk  = false ;
          s4c4finished->show();
        } // else if 
      } // if
      Sleep(50);
    } // else if 4-4
    else if (pageAt.compare("WinterPage5PutAll") == 0) {
      
      if ( materialNum == 1 ) 
        s4c5material1->setGeometry(event->x()-75,event->y()-75,150,150);
      else if ( materialNum == 2 ) 
        s4c5material2->setGeometry(event->x()-75,event->y()-75,150,150);
      else if ( materialNum == 3 ) 
        s4c5material3->setGeometry(event->x()-75,event->y()-75,150,150);
      else if ( materialNum == 4 ) 
        s4c5material4->setGeometry(event->x()-75,event->y()-75,150,150);

      if ( ( potSizeX1 <  event->x()-75 &&  event->x()-75 < potSizeX2 )  &&  ( potSizeY1 < event->y()-75 && event->y()-75 < potSizeY2 ) ) 
        if ( S4c5materialInPot() ) 
          s4c5finished->show();

    } // else if 4-5
    else if ( pageAt.compare("WinterPage6CookAll") == 0) {

    } // else if 4-6
    else if ( pageAt.compare("WinterPage7End") == 0) {

    } // else if 4-7
  } // else if 冬天
} // mouseMoveEvent()

void UI::mousePressEvent(QMouseEvent * event) {
  mousePressing = true ;
  this->setCursor(QCursor(QPixmap("../Images/cursor/hand2Cursor.png")));
  
  if ( pageAt.compare("brand") == 0 && pressAt.x == -1 ) {
    pressAt.x = event->x();
    pressAt.y = event->y();
  } // if
  
  if ( pageAt.compare("foodImformation") == 0 && pressAt.x == -1 ) {
      pressAt.x = event->x();
      pressAt.y = event->y();

  } //  if
  else if (explainPageUp) {
    stepPage->hide();
    this->setCursor(QCursor(QPixmap("../Images/cursor/hand1Cursor.png")));
    
    if ( seasonNum == 1 ) {
      if ( pageAt.compare("SpringPage1PickingMeterial") == 0 ) 
        cookPageSpring1->show() ;
      else if ( pageAt.compare("SpringPage2WashMaterial") == 0 ) 
        cookPageSpring2->show() ;
      else if ( pageAt.compare("SpringPage3CutWhiteFungus") == 0 ) {
        cookPageSpring3->show() ;
        this->setCursor(QCursor(QPixmap("../Images/cursor/scissorCursor.png")));
      } // if
      else if ( pageAt.compare("SpringPage4TearWhiteFungus") == 0 ) 
        cookPageSpring4->show() ;
      else if ( pageAt.compare("SpringPage5AddToPot") == 0 ) 
        cookPageSpring5->show() ;
      else if ( pageAt.compare("SpringPage6StirSoup") == 0 ) 
        cookPageSpring6->show() ;
      else if ( pageAt.compare("SpringPage7Fire") == 0 ) {
        cookPageSpring7->show() ;
        if ( useKinect )
          kinectThread-> motionNum = 1 ;
      } // else if
    } // else if
    else if ( seasonNum == 2 ) {
      if ( pageAt.compare("SummerPage1PickingMeterial" )  == 0 )
        cookPageSummer1->show();
      else if ( pageAt.compare("SummerPage2CutWaterMelon" )  == 0 )
        cookPageSummer2->show();
      else if ( pageAt.compare("SummerPage3CutWatermelonToPiece" )  == 0 )
        cookPageSummer3->show();
      else if ( pageAt.compare("SummerPage4CutPineappleToPiece" )  == 0 )
        cookPageSummer4->show();
      else if ( pageAt.compare("SummerPage5WashPeas" )  == 0 )
        cookPageSummer5->show();
      else if ( pageAt.compare("SummerPage6BoilPeas" )  == 0 ) {
        cookPageSummer6->show();
        if ( useKinect )
          kinectThread-> motionNum = 1 ;
      } // else if 
      else if ( pageAt.compare("SummerPage7PutAll" )  == 0 )
        cookPageSummer7->show();
      
    } // else if
    else if ( seasonNum == 3 ) {
      if ( pageAt.compare("AutumnPage1PickMeterial" )  == 0 )
        cookPageAutumn1->show();
      else if ( pageAt.compare("AutumnPage2CrashGingo" )  == 0 ) {
        cookPageAutumn2->show();
        this->setCursor(QCursor(QPixmap("../Images/cursor/hammerCursor.png")));
      } // else if
      else if ( pageAt.compare("AutumnPage3TickGingo" )  == 0 ) {
        cookPageAutumn3->show();
        this->setCursor(QCursor(QPixmap("../Images/cursor/toothPick.png")));
      } // else if 
      else if ( pageAt.compare("AutumnPage4TearLily" )  == 0 )
        cookPageAutumn4->show();
      else if ( pageAt.compare("AutumnPage5WashRedBean" )  == 0 )
        cookPageAutumn5->show();
      else if ( pageAt.compare("AutumnPage6CookAll" )  == 0 )
        cookPageAutumn6->show();
      else if ( pageAt.compare("AutumnPage7CookAll" )  == 0 )
        cookPageAutumn7->show();
      else if ( pageAt.compare("AutumnPage8CookAll" )  == 0 )
        cookPageAutumn8->show();
      else if ( pageAt.compare("AutumnPage9CookAll" )  == 0 ) {
        cookPageAutumn9->show();
        
        if ( useKinect )
          kinectThread-> motionNum = 1 ;
      } // else if
      
    } // else if
    else if ( seasonNum == 4 ) {
      if ( pageAt.compare("WinterPage1PickMeterial" )  == 0 )
        cookPageWinter1->show();
      else if ( pageAt.compare("WinterPage2LonganShell" )  == 0 )
        cookPageWinter2->show();
      else if ( pageAt.compare("WinterPage3WashLongan" )  == 0 )
        cookPageWinter3->show();
      else if ( pageAt.compare("WinterPage4CutNewYearCake" )  == 0 )
        cookPageWinter4->show();
      else if ( pageAt.compare("WinterPage5PutAll" )  == 0 )
        cookPageWinter5->show();
      else if ( pageAt.compare("WinterPage6CookAll" )  == 0 ) {
        cookPageWinter6->show();
        
        if ( useKinect )
          kinectThread-> motionNum = 1 ;
      } // else if
      
    } // else if
    explainPageUp = false ;
    mousePressing = false ;
  } // else if
  else {
    
    if ( pageAt.compare("AutumnPage2CrashGingo") == 0 || pageAt.compare("AutumnPage3TickGingo") == 0 ) 
      mouseDown = true ;

  } // else 
} // mousePressEvent()

void UI::mouseReleaseEvent(QMouseEvent *event) {
  mousePressing = false ;
  this->setCursor(QCursor(QPixmap("../Images/cursor/hand1Cursor.png")));
  
  if ( pageAt.compare("season") == 0 ) {
    static int atX1 = 100, atX2 = 370, atX3 = 640, atX4 = 910, atX5 = 1180, atY1 = 75, atY2 = 630 ;
    if ( event->y() >= atY1 && atY2 >= event->y() && event->x() >= atX1 && event->x() <= atX5 ) {
      if ( event->x() <= atX2 ) 
        seasonNum = 1 ;
      else if ( event->x() <= atX3 ) 
        seasonNum = 2 ;
      else if ( event->x() <= atX4 ) 
        seasonNum = 3 ;
      else 
        seasonNum = 4 ;
          
      this->setCursor(QCursor(QPixmap("../Images/cursor/hand1Cursor.png")));
      mousePressing = false ;
      FoodPageLayout();
    } // if
  } // if
  else if ( pageAt.compare("brand") == 0 ) {
    if ( ( event->x()-pressAt.x ) <= -640 )
      SeasonPageLayout();
    else if ( (event->x()-pressAt.x ) >= 640 )
      MainPageLayout();
    else
      BrandPageLayout();
    pressAt.x = -1;
  } // else if
  else if ( pageAt.compare("season") == 0 ) {

  } // else if
  else if ( pageAt.compare("foodImformation") == 0 ) {
     if ( ( event->x()-pressAt.x ) <= -640 )
       GoToCook();
    else if ( (event->x()-pressAt.x ) >= 640 ) {
      SeasonPageLayout();
      seasonNum = 0 ;
    } // else if
    else
      FoodPageLayout();
    pressAt.x = -1;

  } // else if
  else if ( pageAt.compare("AutumnPage2CrashGingo") == 0 ) {
    if ( mouseDown ) {
      mouseDown = false;
      counterForAll++ ;
      if ( counterForAll == 1 ) {
        palette.setBrush( cookPageAutumn2->backgroundRole(), QBrush( QPixmap("../images/background/bgS3C2P2") ));
        cookPageAutumn2->setPalette( palette );
      } // if
      else if ( counterForAll == 3 ) {
        palette.setBrush( cookPageAutumn2->backgroundRole(), QBrush( QPixmap("../images/background/bgS3C2P3") ));
        cookPageAutumn2->setPalette( palette );
        s3c2finished->show();
        this->setCursor(QCursor(QPixmap("../Images/cursor/hand1Cursor.png")));
      } // else if
    } // if
  } // else if
  else if ( pageAt.compare("AutumnPage3TickGingo") == 0 ) {
    if ( mouseDown ) {
      mouseDown = false;
      counterForAll++ ;
      if ( counterForAll == 1 ) {
        palette.setBrush( cookPageAutumn3->backgroundRole(), QBrush( QPixmap("../images/background/bgS3C3P2") ));
        cookPageAutumn3->setPalette( palette );
      } // if
      else if ( counterForAll == 3 ) {
        palette.setBrush( cookPageAutumn3->backgroundRole(), QBrush( QPixmap("../images/background/bgS3C3P3") ));
        cookPageAutumn3->setPalette( palette );
        s3c3finished->show();
        this->setCursor(QCursor(QPixmap("../Images/cursor/hand1Cursor.png")));
      } // else if
    } // if

  } // else if 
} // mouseReleaseEvent

void UI::mouseDoubleClickEvent(QMouseEvent * event) {
  if (pageAt.compare("SpringPage7Fire") == 0 ) {
    counterForAll++ ;
    if ( counterForAll == 2 ) {
      
      palette.setBrush( cookPageSpring7->backgroundRole(), QBrush( QPixmap("../images/background/bgS1C7P2.png") ) );
      cookPageSpring7->setPalette( palette );
    } // if
    else if ( counterForAll == 4 ) {
      palette.setBrush( cookPageSpring7->backgroundRole(), QBrush( QPixmap("../images/background/bgS1C7P3.png") ) );
      cookPageSpring7->setPalette( palette );
      kinectThread->motionNum = 0 ;
      s1c7finished->show();
    } // if
  } // if
  else if ( pageAt.compare("SummerPage6BoilPeas") == 0 ) {
    counterForAll++ ;
    if ( counterForAll == 1 ) 
      palette.setBrush( cookPageSummer6->backgroundRole(), QBrush(QPixmap("../images/background/bgS2C6P2.png") ) );
    else if ( counterForAll == 2 ) 
      palette.setBrush( cookPageSummer6->backgroundRole(), QBrush(QPixmap("../images/background/bgS2C6P3.png") ) );
    else if ( counterForAll == 3 ) 
      palette.setBrush( cookPageSummer6->backgroundRole(), QBrush(QPixmap("../images/background/bgS2C6P4.png") ) );
    else if ( counterForAll == 4 ) 
      palette.setBrush( cookPageSummer6->backgroundRole(), QBrush(QPixmap("../images/background/bgS2C6P5.png") ) );
    else if ( counterForAll == 5 ) {
      palette.setBrush( cookPageSummer6->backgroundRole(), QBrush(QPixmap("../images/background/bgS2C6P6.png") ) );
      kinectThread-> motionNum = 0;
      s2c6finished->show();
    } // else if
    cookPageSummer6->setPalette( palette );
    Sleep(30);
  } // else if
  else if ( pageAt.compare( "AutumnPage7CookAll" ) == 0 ) {

    counterForAll++ ;
    if ( counterForAll == 3 ) {
      palette.setBrush( cookPageAutumn7->backgroundRole(), QBrush(QPixmap("../images/background/bgS3C7P2.png") ) );
      cookPageAutumn7->setPalette( palette );
      kinectThread-> motionNum = 0;
      s3c7finished->show();
    } // if
  } // else if 
  else if ( pageAt.compare( "AutumnPage9CookAll" ) == 0 ) {

    counterForAll++ ;
    if ( counterForAll == 3 ) {
      palette.setBrush( cookPageAutumn9->backgroundRole(), QBrush(QPixmap("../images/background/bgS3C9P2.png") ) );
      cookPageAutumn9->setPalette( palette );
      kinectThread-> motionNum = 0;
      s3c9finished->show();
    } // if

  } // else if 
  else if ( pageAt.compare( "WinterPage6CookAll" ) == 0 ) {
    if ( counterForAll2 == 1 ) {
      palette.setBrush( cookPageWinter6->backgroundRole(), QBrush( QPixmap("../images/background/bgS4C6P2") ));
      cookPageWinter6->setPalette( palette );
      counterForAll2 = 2 ;
    } // if
    else if ( counterForAll2 == 2 ) {
      palette.setBrush( cookPageWinter6->backgroundRole(), QBrush( QPixmap("../images/background/bgS4C6P3") ));
      cookPageWinter6->setPalette( palette );
      counterForAll2 = 3 ;
    } // else if
    else if ( counterForAll2 == 3 ) {
      palette.setBrush( cookPageWinter6->backgroundRole(), QBrush( QPixmap("../images/background/bgS4C6P4") ));
      cookPageWinter6->setPalette( palette );
      counterForAll2 = 4 ;
    } // else if
    else if ( counterForAll2 == 4 ) {
      palette.setBrush( cookPageWinter6->backgroundRole(), QBrush( QPixmap("../images/background/bgS4C6P5") ));
      cookPageWinter6->setPalette( palette );
      counterForAll2 = 5 ;
    } // else if
    else if ( counterForAll2 == 5 ) {
      palette.setBrush( cookPageWinter6->backgroundRole(), QBrush( QPixmap("../images/background/bgS4C6P6") ));
      cookPageWinter6->setPalette( palette );
      counterForAll2 = 6 ;
      s4c6finished->show();
      kinectThread->motionNum = 0;
    } // else if
  } // else if 
} // mouseDoubleClickEvent()

int UI::GetTrace(QMouseEvent *event) {
  
    POINT now_point ;
    now_point.x = event->x() ;
    now_point.y = event->y() ;
    static POINT last_point = now_point  ;

	  int nowStatus ;
	  int direction_x = now_point.x - last_point.x, direction_y = now_point.y - last_point.y ;
	  // 狀態為米字 不動為0 向右為1 右下2 下3 左下4 左5 左上6 上7 右上8
	  if ( direction_x <= offset && direction_y <= offset && direction_x >= -offset && direction_y >= -offset ) nowStatus = 0 ; // 沒有動       狀態0
	  else if  ( direction_x > offset && direction_y <= offset && direction_y >= -offset )  nowStatus = 1 ;			  // 為向右移動   狀態1
	  else if  ( direction_x > offset && direction_y > offset )  nowStatus = 2 ;									// 為向右下移動 狀態2
	  else if  ( direction_x <= offset && direction_x >= -offset && direction_y > offset ) nowStatus = 3 ;				// 為向下移動   狀態3
	  else if  ( direction_x < -offset && direction_y > offset ) nowStatus = 4 ;                  // 為向左下移動 狀態4
	  else if  ( direction_y <= offset && direction_x < -offset && direction_y >= -offset ) nowStatus = 5 ;      // 為向左移動   狀態5
	  else if  ( direction_x < -offset && direction_y < -offset ) nowStatus = 6 ;                 // 為向左上移動 狀態6
	  else if  ( direction_x <= offset && direction_x >= -offset && direction_y < -offset ) nowStatus = 7 ;      // 為向上移動   狀態7
	  else if  ( direction_x > offset && direction_y < -offset ) nowStatus = 8 ;                  // 為向右上移動 狀態8
    
    last_point = now_point ; // 舊點更新
    return nowStatus ;
    
} // GetTrace()

bool UI::IsLeftAndRightWash( int nowStatus ) {
	static int previousMove = -1 ;
	static int moveMentNum = 0 ;
	static int faultNum = 3 ;

	bool successed = false ;

	if ( ( previousMove == -1 ) && ( nowStatus == 2 || nowStatus == 4 || nowStatus == 6 || nowStatus == 8 ) ) {
		previousMove = nowStatus ;
		moveMentNum++;
	} // if 首次動作
	else if ( nowStatus != 0 && nowStatus != previousMove ) {
		if ( ( previousMove == 8 && nowStatus == 2 ) ||
             ( previousMove == 2 && nowStatus == 6 ) ||
             ( previousMove == 6 && nowStatus == 4 ) ||
             ( previousMove == 4 && nowStatus == 8 ) ) { // 成功動作
			previousMove = nowStatus ;
			moveMentNum++ ;
		} // if
    else if ( nowStatus == 1 || nowStatus == 5 || nowStatus == 7 || nowStatus == 3 )
      faultNum-- ;
		else { 
			previousMove = -1 ;
			moveMentNum = 0 ;
      faultNum = 2 ;
		} // else 失敗動作歸零
	} // else if

	if ( moveMentNum >= 5 ) {
		successed = true ;
		previousMove = -1 ;
		moveMentNum = 0 ;
    faultNum = 2 ;
	} // if

	return successed ;
} // IsLeftAndRightWash() 

bool UI::IsLeftAndRightWashDown( int nowStatus ) {
	static int previousMove = -1 ;
	static int moveMentNum = 0 ;
	static int faultNum = 3 ;

	bool successed = false ;

	if ( ( previousMove == -1 ) && ( nowStatus == 2 || nowStatus == 4 || nowStatus == 6 || nowStatus == 8 ) ) {
		previousMove = nowStatus ;
		moveMentNum++;
	} // if 首次動作
	else if ( nowStatus != 0 && nowStatus != previousMove ) {
		if ( ( previousMove == 8 && nowStatus == 4 ) ||
             ( previousMove == 4 && nowStatus == 6 ) ||
             ( previousMove == 6 && nowStatus == 2 ) ||
             ( previousMove == 2 && nowStatus == 8 ) ) { // 成功動作
			previousMove = nowStatus ;
			moveMentNum++ ;
		} // if
    else if ( nowStatus == 1 || nowStatus == 5 || nowStatus == 7 || nowStatus == 3 )
      faultNum-- ;
		else { 
			previousMove = -1 ;
			moveMentNum = 0 ;
      faultNum = 2 ;
		} // else 失敗動作歸零
	} // else if

	if ( moveMentNum >= 5 ) {
		successed = true ;
		previousMove = -1 ;
		moveMentNum = 0 ;
    faultNum = 2 ;
	} // if

	return successed ;
} // IsLeftAndRightWash() 

bool UI::IsPassThePoints( POINT point1, POINT point2, POINT point3 , POINT now, bool restart ) {
  static bool passed[4] = { false } ;
  if ( restart ) {
    for ( int i = 0 ; i < 4 ; i++ )
      passed[i] = false ;
    counterForAll2 = 0 ;
  } // if
  passed[0] = true ;
  if ( now.x < point1.x + 30 &&  now.x > point1.x - 30 &&
       now.y < point1.y + 30 &&  now.y > point1.y - 30 )
    passed[1] = true ;
  if ( now.x < point2.x + 30 &&  now.x > point2.x - 30 &&
       now.y < point2.y + 30 &&  now.y > point2.y - 30 )
    passed[2] = true ;
  if ( now.x < point3.x + 30 &&  now.x > point3.x - 30 &&
       now.y < point3.y + 30 &&  now.y > point3.y - 30 )
    passed[3] = true ;
  
  for ( int i = 1 ; i < 4 ; i++ )
    if ( !passed[i] )
      passed[0] = false ;

  if ( passed[0] ) {
    for ( int i = 4 ; i < 4 ; i++ )
      passed[i] = false ;
    return true ;
  } // if 
  
  return false ;
} // IsPassThePointsOrdering()

bool UI::IsPassThePoints2( POINT point1, POINT point2, POINT point3 , POINT now, int which ) {
  static bool passed[3][4] = { false } ;
  passed[which][0] = true ;
  if ( now.x < point1.x + 30 &&  now.x > point1.x - 30 &&
       now.y < point1.y + 30 &&  now.y > point1.y - 30 )
    passed[which][1] = true ;
  if ( now.x < point2.x + 30 &&  now.x > point2.x - 30 &&
       now.y < point2.y + 30 &&  now.y > point2.y - 30 )
    passed[which][2] = true ;
  if ( now.x < point3.x + 30 &&  now.x > point3.x - 30 &&
       now.y < point3.y + 30 &&  now.y > point3.y - 30 )
    passed[which][3] = true ;
  
  for ( int i = 1 ; i < 4 ; i++ )
    if ( !passed[which][i] )
      passed[which][0] = false ;

  return passed[which][0] ;
} // IsPassThePoints2()

bool UI::isClockwiseCircle( int &beStatus, int nowStatus ) {
		// 判斷是否為順時鐘動作
	static bool isAllWalk[8] = { false };
	bool Success = false;

	if ( beStatus == 0 && beStatus != nowStatus ) { // 第一個動作設置
		beStatus = nowStatus;
		if ( beStatus == 8 )
			isAllWalk[0] = true;
		else
			isAllWalk[ beStatus ] = true;
		return false ;
	} // if

	int num1 = beStatus + 1, num2 = beStatus + 2; 
  bool isAllComplete = true, youCanFalseOne = true ;

	if ( num1 > 8 ) // 太小繞圈圈回去
		num1 -= 8;
	if ( num2 > 8 )
		num2 -= 8;

	if ( nowStatus == num1 || nowStatus == num2 ) { // 如果現在動作符合順序
		if ( nowStatus == num1 ) { // 符合只差一個的順序
			if ( num1 == 8 )
				num1 = 0;
			isAllWalk[ num1 ] = true;
		} // if
		else if ( nowStatus == num2 ) { // 符合只差兩個的順序
			if ( num2 == 8 )
				num2 = 0;
			isAllWalk[ num2 ] = true;
		} // else if

		beStatus = nowStatus;// 給下次進來的上一個點

		for ( int i = 0 ; i < 8 ; i++ ) // 檢查是否都走訪過
			if ( !isAllWalk[i] ) {
				if ( youCanFalseOne ) // second chance
					youCanFalseOne = false;
				else
					isAllComplete = false;
			} // if
			else if ( !youCanFalseOne )
					youCanFalseOne = true;
			
		if ( isAllComplete ) { // 已完成
			Success = true;
			for ( int i = 0 ; i < 8 ; i++ ) // 初始歸零
			  isAllWalk[i] = false;

		  beStatus = 0 ; // 初始歸零
		} // if 成功走訪完成
	} // if
	else { // 錯誤走訪 初始歸零
		for ( int i = 0 ; i < 8 ; i++ )
			isAllWalk[i] = false;

		beStatus = 0;
	} // else

	return Success;
} // isCircle()

bool UI::S1c1materialInDish() {
  if ( ( materialOrder == 1 ) && ( materialNum == 1 ) ) {
    materialNum = 0 ;
    materialOrder = 2 ;
    s1c1OrderList1->setPixmap(QPixmap("../images/Spring/whiteFungusLabelOff.png"));
    s1c1OrderList2->setPixmap(QPixmap("../images/Spring/walnutLabelOn.png"));
    s1c1material1->setEnabled(false);
    s1c1material1->setGeometry( 550,350,100,100);
    takingState = false ;
    this->setCursor(QCursor(QPixmap("../Images/cursor/hand1Cursor.png")));
  } // if
  else if ( ( materialOrder == 2 ) && ( materialNum == 2 ) ) {
    materialNum = 0 ;
    materialOrder++ ;
    s1c1OrderList2->setPixmap(QPixmap("../images/Spring/walnutLabelOff.png"));
    s1c1OrderList3->setPixmap(QPixmap("../images/Spring/WolfberryLabelOn.png"));
    s1c1material2->setEnabled(false);
    s1c1material2->setGeometry( 470,470,100,100);
    takingState = false ;
    this->setCursor(QCursor(QPixmap("../Images/cursor/hand1Cursor.png")));

  } // else if
  else if ( ( materialOrder == 3 ) && ( materialNum == 3 ) ) {
    materialNum = 0 ;
    materialOrder++ ;
    s1c1OrderList3->setPixmap(QPixmap("../images/Spring/WolfberryLabelOff.png"));
    s1c1OrderList4->setPixmap(QPixmap("../images/Spring/sugarLabelOn.png"));
    s1c1material3->setEnabled(false);
    s1c1material3->setGeometry( 600,500,100,100);
    takingState = false ;
    this->setCursor(QCursor(QPixmap("../Images/cursor/hand1Cursor.png")));
  } // else if
  else if ( ( materialOrder == 4 ) && ( materialNum == 4 ) ) {
    materialNum = 0 ;
    materialOrder++ ;
    s1c1OrderList4->setPixmap(QPixmap("../images/Spring/sugarLabelOff.png"));
    s1c1material4->setEnabled(false);
    s1c1material4->setGeometry( 650,450,100,100);
    takingState = false ;
    this->setCursor(QCursor(QPixmap("../Images/cursor/hand1Cursor.png")));
    return true ;
  } // else if
  else {
    if ( materialNum == 5 ) {
      s1c1material5->setEnabled(false) ;
      s1c1material5->setGeometry( 1050,50,150,150);
    } // if
    else {
      if ( materialNum == 2 )
        s1c1material2->setGeometry( 450,50,150,150);
      else if ( materialNum == 3 )
        s1c1material3->setGeometry( 650,50,150,150);
      else if ( materialNum == 4 )
        s1c1material4->setGeometry( 850,50,150,150);
    } // 錯誤食材

    materialNum = 0 ;
    takingState = false ;
    this->setCursor(QCursor(QPixmap("../Images/cursor/hand1Cursor.png")));
  } // 選錯
  return false;
} // S1c1materialInDish()

bool UI::S1c5materialInPot() {
  static int num = 0 ;
  if ( materialNum == 1 ) {
    s1c5cover1->show();
    s1c5cover1->raise();
    s1c5material1->hide();
    takingState = false ;
    this->setCursor(QCursor(QPixmap("../Images/cursor/hand1Cursor.png")));
    num++ ;
  } // if
  else if ( materialNum == 2 ) {
    s1c5cover2->show();
    s1c5cover2->raise();
    s1c5material2->hide();
    takingState = false ;
    this->setCursor(QCursor(QPixmap("../Images/cursor/hand1Cursor.png")));
    num++ ;
  } // else if
  else if ( materialNum == 3 ) {
    s1c5cover3->show();
    s1c5cover3->raise();
    s1c5material3->hide();
    takingState = false ;
    this->setCursor(QCursor(QPixmap("../Images/cursor/hand1Cursor.png")));
    num++ ;
  } // else if
  else if ( materialNum == 4 ) {
    s1c5cover4->show();
    s1c5cover4->raise();
    s1c5material4->hide();
    takingState = false ;
    this->setCursor(QCursor(QPixmap("../Images/cursor/hand1Cursor.png")));
    num++ ;
  } // else if
  else if ( materialNum == 5 ) {
    s1c5cover5->show();
    s1c5cover5->raise();
    s1c5material5->hide();
    s1c5material5->setEnabled(false);
    takingState = false ;
    this->setCursor(QCursor(QPixmap("../Images/cursor/hand1Cursor.png")));
    num++ ;
  } // else if

  if ( !s1c5material5->isEnabled() ) 
    return true ;

  return false ;

} // S1c5materialInPot()

bool UI::S2c1materialInDish() {
  QPixmap pix ;
  if ( ( materialOrder == 1 ) && ( materialNum == 1 ) ) {
    materialNum = 0 ;
    materialOrder = 2 ;
    s2c1OrderList1->setPixmap(QPixmap("../images/Summer/pineappleLabelOff.png"));
    s2c1OrderList2->setPixmap(QPixmap("../images/Summer/peasLabelOn.png"));
    s2c1material1->setEnabled(false);
    s2c1material1->setGeometry( 550,350,100,100);
    takingState = false ;
    this->setCursor(QCursor(QPixmap("../Images/cursor/hand1Cursor.png")));

  } // if
  else if ( ( materialOrder == 2 ) && ( materialNum == 2 ) ) {
    materialNum = 0 ;
    materialOrder = 3 ;
    s2c1OrderList2->setPixmap(QPixmap("../images/Summer/peasLabelOff.png"));
    s2c1OrderList3->setPixmap(QPixmap("../images/Summer/watermelonLabelOn.png"));
    s2c1material2->setEnabled(false);
    s2c1material2->setGeometry( 470,470,100,100);
    takingState = false ;
    this->setCursor(QCursor(QPixmap("../Images/cursor/hand1Cursor.png")));

  } // else if
  else if ( ( materialOrder == 3 ) && ( materialNum == 3 ) ) {
    materialNum = 0 ;
    materialOrder = 4 ;
    s2c1OrderList3->setPixmap(QPixmap("../images/Summer/watermelonLabelOff.png"));
    s2c1OrderList4->setPixmap(QPixmap("../images/Summer/yogurtLabelOn.png"));
    s2c1material3->setEnabled(false);
    s2c1material3->setGeometry( 600,500,100,100);
    takingState = false ;
    this->setCursor(QCursor(QPixmap("../Images/cursor/hand1Cursor.png")));

  } // else if
  else if ( ( materialOrder == 4 ) && ( materialNum == 4 ) ) {
    materialNum = 0 ;
    materialOrder = 5 ;
    s2c1OrderList4->setPixmap(QPixmap("../images/Summer/yogurtLabelOff.png"));
    s2c1material4->setEnabled(false);
    s2c1material4->setGeometry( 650,450,100,100);
    takingState = false ;
    this->setCursor(QCursor(QPixmap("../Images/cursor/hand1Cursor.png")));
    return true;
  } // else if
  else {
    if ( materialNum == 5 ) {
      s2c1material5->setEnabled(false);
      s2c1material5->setGeometry( 450,50,150,150);
    } // if
    else {
      if ( materialNum == 2 )
        s2c1material2->setGeometry( 250,50,150,150);
      else if ( materialNum == 3 )
        s2c1material3->setGeometry( 1050,50,150,150);
      else if ( materialNum == 4 )
        s2c1material4->setGeometry( 650,50,150,150);
    } // 錯誤食材

    materialNum = 0 ;
    takingState = false ;
    this->setCursor(QCursor(QPixmap("../Images/cursor/hand1Cursor.png")));
  } // 選錯
  return false;
} // materialInDish()

bool UI::S2c7materialInBowl() {
  static bool in[5] = {false} ;
  if ( counterForAll == 0 ) {
    for ( int i = 1 ; i < 5 ; i++ ) 
      in[i] = false ;
    counterForAll = 1 ;
  } // if
  if ( materialNum == 1 ) {
    s2c7cover1->show();
    s2c7cover1->raise();
    s2c7material1->hide();
    takingState = false ;
    this->setCursor(QCursor(QPixmap("../Images/cursor/hand1Cursor.png")));
    in[1] = true ;
  } // if
  else if ( materialNum == 2 ) {
    s2c7cover2->show();
    s2c7cover2->raise();
    s2c7material2->hide();
    takingState = false ;
    this->setCursor(QCursor(QPixmap("../Images/cursor/hand1Cursor.png")));
    in[2] = true ;
  } // else if
  else if ( materialNum == 3 ) {
    s2c7cover3->show();
    s2c7cover3->raise();
    s2c7material3->hide();
    takingState = false ;
    this->setCursor(QCursor(QPixmap("../Images/cursor/hand1Cursor.png")));
    in[3] = true ;
  } // else if
  else if ( materialNum == 4 ) {
    s2c7cover4->show();
    s2c7cover4->raise();
    s2c7material4->hide();
    s2c7material5->show();
    takingState = false ;
    this->setCursor(QCursor(QPixmap("../Images/cursor/hand1Cursor.png")));
    in[4] = true ;
  } // else if
  in[0] = true ;
  for ( int i = 1 ; i < 5 ; i++ ) {
    if ( !in[i])
      in[0] = false ;
  } // for
  return in[0] ;

} // S2C7materialInBowl()

bool UI::S3c1materialInDish() {
  QPixmap pix ;
  if ( ( materialOrder == 1 ) && ( materialNum == 1 ) ) {
    materialNum = 0 ;
    materialOrder = 2 ;

    s3c1OrderList1->setPixmap(QPixmap("../images/Autumn/ginkgoLabelOff.png"));
    s3c1OrderList2->setPixmap(QPixmap("../images/Autumn/lilyBulbLabelOn.png"));
    s3c1material1->setEnabled(false);
    s3c1material1->setGeometry( 550,350,100,100);
    takingState = false ;
    this->setCursor(QCursor(QPixmap("../Images/cursor/hand1Cursor.png")));
  } // if
  else if ( ( materialOrder == 2 ) && ( materialNum == 2 ) ) {
    materialNum = 0 ;
    materialOrder++ ;
    s3c1OrderList2->setPixmap(QPixmap("../images/Autumn/lilyBulbLabelOff.png"));
    s3c1OrderList3->setPixmap(QPixmap("../images/Autumn/redKindeyBeanLabelOn.png"));
    s3c1material2->setEnabled(false);
    s3c1material2->setGeometry( 470,470,100,100);
    takingState = false ;
    this->setCursor(QCursor(QPixmap("../Images/cursor/hand1Cursor.png")));

  } // else if
  else if ( ( materialOrder == 3 ) && ( materialNum == 3 ) ) {
    materialNum = 0 ;
    materialOrder++ ;
    
    s3c1OrderList3->setPixmap(QPixmap("../images/Autumn/redKindeyBeanLabelOff.png"));
    s3c1OrderList4->setPixmap(QPixmap("../images/Autumn/sugarLabelOn.png"));
    s3c1material3->setEnabled(false);
    s3c1material3->setGeometry( 650,450,100,100);
    takingState = false ;
    this->setCursor(QCursor(QPixmap("../Images/cursor/hand1Cursor.png")));

  } // else if
  else if ( ( materialOrder == 4 ) && ( materialNum == 4 ) ) {
    materialNum = 0 ;
    materialOrder++ ; 
    s3c1OrderList4->setPixmap(QPixmap("../images/Autumn/sugarLabelOff.png"));
    s3c1material4->setEnabled(false);
    s3c1material4->setGeometry( 650,450,100,100);
    takingState = false ;
    this->setCursor(QCursor(QPixmap("../Images/cursor/hand1Cursor.png")));
    return true;
  } // else if
  else {
    if ( materialNum == 5 ) {
      s3c1material5->setEnabled(false);
      s3c1material5->setGeometry( 1050,50,150,150);
    } // if
    else {
      if ( materialNum == 2 )
        s3c1material2->setGeometry( 250,50,150,150);
      else if ( materialNum == 3 )
        s3c1material3->setGeometry( 1050,50,150,150);
      else if ( materialNum == 4 )
        s3c1material4->setGeometry( 650,50,150,150);
    } // 錯誤食材

    materialNum = 0 ;
    takingState = false ;
    this->setCursor(QCursor(QPixmap("../Images/cursor/hand1Cursor.png")));
  } // 選錯
  return false;
} // S3c1materialInDish()

bool UI::S3c6materialInPot() {
  static int num = 0 ;
  if ( counterForAll == 0 ) {
    num = 0 ;
    counterForAll = 1 ;
  } // if
  if ( materialNum == 1 ) {
    s3c6cover1->show();
    s3c6cover1->raise();
    s3c6material1->hide();
    takingState = false ;
    this->setCursor(QCursor(QPixmap("../Images/cursor/hand1Cursor.png")));
    num++ ;
  } // if
  else if ( materialNum == 2 ) {
    s3c6cover2->show();
    s3c6cover2->raise();
    s3c6material2->hide();
    takingState = false ;
    this->setCursor(QCursor(QPixmap("../Images/cursor/hand1Cursor.png")));
    num++ ;
  } // else if
  else if ( materialNum == 3 ) {
    s3c6cover3->show();
    s3c6cover3->raise();
    s3c6material3->hide();
    s3c6material3->setEnabled(false);
    takingState = false ;
    this->setCursor(QCursor(QPixmap("../Images/cursor/hand1Cursor.png")));
    num++ ;
  } // else if

  if ( !s3c6material3->isEnabled() ) 
    return true ;

  return false ;

} // S3c6materialInPot()

bool UI::S3c8materialInPot() {
  static int num = 0 ;
  if ( counterForAll == 0 ) {
    num = 0 ;
    counterForAll = 1 ;
  } // if
  if ( materialNum == 1 ) {
    s3c8cover1->show();
    s3c8cover1->raise();
    s3c8material1->hide();
    takingState = false ;
    this->setCursor(QCursor(QPixmap("../Images/cursor/hand1Cursor.png")));
    num++ ;
  } // if
  else if ( materialNum == 2 ) {
    s3c8cover2->show();
    s3c8cover2->raise();
    s3c8material2->hide();
    s3c8material2->setEnabled(false);
    takingState = false ;
    this->setCursor(QCursor(QPixmap("../Images/cursor/hand1Cursor.png")));
    num++ ;
  } // else if

  if ( !s3c8material2->isEnabled() ) 
    return true ;

  return false ;

} // S3c8materialInPot()

bool UI::S4c1materialInDish() {
  if ( ( materialOrder == 1 ) && ( materialNum == 1 ) ) {
    materialNum = 0 ;
    materialOrder = 2 ;
    s4c1OrderList1->setPixmap(QPixmap("../images/Winter/NewYearCakeLabelOff.png"));
    s4c1OrderList2->setPixmap(QPixmap("../images/Winter/LonganLabelOn.png"));
    s4c1material1->setEnabled(false);
    s4c1material1->setGeometry( 550,350,100,100);
    takingState = false ;
    this->setCursor(QCursor(QPixmap("../Images/cursor/hand1Cursor.png")));
  } // if
  else if ( ( materialOrder == 2 ) && ( materialNum == 2 ) ) {
    materialNum = 0 ;
    materialOrder++ ;
    s4c1OrderList2->setPixmap(QPixmap("../images/Winter/LonganLabelOff.png"));
    s4c1OrderList3->setPixmap(QPixmap("../images/Winter/RedSugarLabelOn.png"));
    s4c1material2->setEnabled(false);
    s4c1material2->setGeometry( 470,470,100,100);
    takingState = false ;
    this->setCursor(QCursor(QPixmap("../Images/cursor/hand1Cursor.png")));

  } // else if
  else if ( ( materialOrder == 3 ) && ( materialNum == 3 ) ) {
    materialNum = 0 ;
    materialOrder++ ;
    s4c1OrderList3->setPixmap(QPixmap("../images/Winter/RedSugarLabelOff.png"));
    s4c1material3->setEnabled(false);
    s4c1material3->setGeometry( 600,500,100,100);
    takingState = false ;
    this->setCursor(QCursor(QPixmap("../Images/cursor/hand1Cursor.png")));
    return true ;
  } // else if
  else {
    if ( materialNum == 4 ) {
      s4c1material4->setEnabled(false) ;
      s4c1material4->setGeometry( 550,50,150,150 );
    } // if
    else {
      if ( materialNum == 2 )
        s4c1material2->setGeometry( 800,50,150,150);
      else if ( materialNum == 3 )
        s4c1material3->setGeometry( 1050,50,150,150);
    } // 錯誤食材

    materialNum = 0 ;
    takingState = false ;
    this->setCursor(QCursor(QPixmap("../Images/cursor/hand1Cursor.png")));
  } // 選錯
  return false;
} // S4c1materialInDish()

bool UI::S4c5materialInPot() {
  static int num = 0 ;
  if ( counterForAll == 0 ) {
    num = 0 ;
    counterForAll = 1 ;
  } // if
  if ( materialNum == 1 ) {
    s4c5cover1->show();
    s4c5cover1->raise();
    s4c5material1->hide();
    takingState = false ;
    this->setCursor(QCursor(QPixmap("../Images/cursor/hand1Cursor.png")));
    num++ ;
  } // if
  else if ( materialNum == 2 ) {
    s4c5cover2->show();
    s4c5cover2->raise();
    s4c5material2->hide();
    takingState = false ;
    this->setCursor(QCursor(QPixmap("../Images/cursor/hand1Cursor.png")));
    num++ ;
  } // else if
  else if ( materialNum == 3 ) {
    s4c5cover3->show();
    s4c5cover3->raise();
    s4c5material3->hide();
    takingState = false ;
    this->setCursor(QCursor(QPixmap("../Images/cursor/hand1Cursor.png")));
    num++ ;
  } // else if
  else if ( materialNum == 4 ) {
    s4c5cover4->show();
    s4c5cover4->raise();
    s4c5material4->hide();
    s4c5material4->setEnabled(false) ;
    takingState = false ;
    this->setCursor(QCursor(QPixmap("../Images/cursor/hand1Cursor.png")));
    num++ ;
  } // else if

  if ( !s4c5material4->isEnabled() ) 
    return true ;

  return false ;

} // S4c5materialInPot()

