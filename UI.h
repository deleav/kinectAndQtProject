# ifndef UI_H
# define UI_H

# include "KinectThread.h"
# include <QTime>
# include <QLabel>
# include <QObject>
# include <QWidget>
# include <QBitmap>
# include <iostream>
# include <QSpinBox>
# include <QCursor.h>
# include <windows.h>
# include <QTextCodec>
# include <QPushButton>
# include <QVBoxLayout>
# include <QMouseEvent>
# include <QCheckbox.h>
# include <QMessageBox>
# include <QProgressbar.h>

#define offset 30

class UI : public QWidget {
  Q_OBJECT
    public slots:
      void KinectThreadOpen();
      
      void MainPageLayout();
      void BrandPageLayout();
      void SeasonPageLayout();
      void FoodPageLayout();
     
      void CookPageLayoutSpring1();
      void CookPageLayoutSpring2();
      void CookPageLayoutSpring3();
      void CookPageLayoutSpring4();
      void CookPageLayoutSpring5();
      void CookPageLayoutSpring6();
      void CookPageLayoutSpring7();
      void CookPageLayoutSpring8();
      
      void CookPageLayoutSummer1();
      void CookPageLayoutSummer2();
      void CookPageLayoutSummer3();
      void CookPageLayoutSummer4();
      void CookPageLayoutSummer5();
      void CookPageLayoutSummer6();
      void CookPageLayoutSummer7();
      void CookPageLayoutSummer8();
      
      void CookPageLayoutAutumn1();
      void CookPageLayoutAutumn2();
      void CookPageLayoutAutumn3();
      void CookPageLayoutAutumn4();
      void CookPageLayoutAutumn5();
      void CookPageLayoutAutumn6();
      void CookPageLayoutAutumn7();
      void CookPageLayoutAutumn8();
      void CookPageLayoutAutumn9();
      void CookPageLayoutAutumn10();

      void CookPageLayoutWinter1();
      void CookPageLayoutWinter2();
      void CookPageLayoutWinter3();
      void CookPageLayoutWinter4();
      void CookPageLayoutWinter5();
      void CookPageLayoutWinter6();
      void CookPageLayoutWinter7();
      // Layout

      void FinishButtonSet(  QPushButton * finish, QWidget * parentWidget );
      void IconButtonSet( QPushButton * button, QWidget * parentWidget,  QString picPath, int xAt, int yAt, int buttonSizeX, int buttonSizeY );
      void PageDefaultSet( QWidget * widget,  QString picPath, QPushButton * finishButton ) ;
      void CoverWidgetSet( QWidget * cover,  QString picPath, QWidget * parentWidget ) ;
      void PictureLabelSet( QLabel * label, QWidget * parentWidget, QString picPath, int xAt, int yAt, int buttonSizeX, int buttonSizeY  ) ;
      void GoToCook();
      void GoToNextCook();
      
      void S1Material1();
      void S1Material2();
      void S1Material3();
      void S1Material4();
      void S1Material5();

      void S2Material1();
      void S2Material2();
      void S2Material3();
      void S2Material4();
      void S2Material5();
      
      void S3Material1();
      void S3Material2();
      void S3Material3();
      void S3Material4();
      void S3Material5();
      
      void S4Material1();
      void S4Material2();
      void S4Material3();
      void S4Material4();

protected:
  void HideAllPage();

  void mouseMoveEvent(QMouseEvent *event);
  void mousePressEvent(QMouseEvent *event);
  void mouseReleaseEvent(QMouseEvent *event);
  void mouseDoubleClickEvent(QMouseEvent * event);
  void StepPageLayout();
  bool IsLeftAndRightWash( int nowStatus );
  bool IsLeftAndRightWashDown( int nowStatus );
  bool IsPassThePoints( POINT point1, POINT point2, POINT point3, POINT now, bool  restart );
  bool IsPassThePoints2( POINT point1, POINT point2, POINT point3 , POINT now, int which );
  bool isClockwiseCircle( int &beStatus, int nowStatus );
  bool S1c1materialInDish();
  bool S1c5materialInPot();
  bool S2c1materialInDish();
  bool S2c7materialInBowl();
  bool S3c1materialInDish();
  bool S3c6materialInPot();
  bool S3c8materialInPot();
  bool S4c1materialInDish();
  bool S4c5materialInPot();
  int GetTrace( QMouseEvent *event );
  bool mouseDown ;
public:
  
  QCursor * myCursor ;
  QTextCodec *codec;
  int sizeX, sizeY;
  int picNum;
  int seasonNum;
  int materialNum;
  bool takingState;
  int cSizeX1,cSizeX2;
  int cSizeY1,cSizeY2;
  int materialOrder ;
  int c4SizeX1,c4SizeX2;
  int c4SizeY1,c4SizeY2;
  int materialTaking_c4 ;
  bool explainPageUp ;
  bool mousePressing ;
  int c1SizeX1,c1SizeX2;
  int c1SizeY1,c1SizeY2;
  int counterForAll ;
  int counterForAll2 ;
  int counterForAll3 ;
  QTime * time;
  string pageAt ;
  KinectThread * kinectThread ;
  POINT pressAt ; // season 0 按下去時的點

  POINT p1_c2 ;
  POINT p2_c2 ;
  POINT p3_c2 ;

  
  QPixmap bg0;
  QPixmap bg1;
  QPixmap bg2;
  QPixmap bg3;
  QPixmap bg4_1;
  QPixmap bg4_2;
  QPixmap bg4_3;
  QPixmap bg4_4;
  QPixmap bg5;
  // 所有背景圖片
  QPalette palette;

  QWidget *mainPage;
  QWidget *brandPage;
  QWidget *seasonPage;
  QWidget *foodPage;
  QWidget *stepPage;

  QWidget *cookPageSpring1;
  QWidget *cookPageSpring2;
  QWidget *cookPageSpring3;
  QWidget *cookPageSpring4;
  QWidget *cookPageSpring5;
  QWidget *cookPageSpring6;
  QWidget *cookPageSpring7;
  QWidget *cookPageSpring8;

  QWidget *cookPageSummer1;
  QWidget *cookPageSummer2;
  QWidget *cookPageSummer3;
  QWidget *cookPageSummer4;
  QWidget *cookPageSummer5;
  QWidget *cookPageSummer6;
  QWidget *cookPageSummer7;
  QWidget *cookPageSummer8;
  
  QWidget *cookPageAutumn1;
  QWidget *cookPageAutumn2;
  QWidget *cookPageAutumn3;
  QWidget *cookPageAutumn4;
  QWidget *cookPageAutumn5;
  QWidget *cookPageAutumn6;
  QWidget *cookPageAutumn7;
  QWidget *cookPageAutumn8;
  QWidget *cookPageAutumn9;
  QWidget *cookPageAutumn10;
  
  QWidget *cookPageWinter1;
  QWidget *cookPageWinter2;
  QWidget *cookPageWinter3;
  QWidget *cookPageWinter4;
  QWidget *cookPageWinter5;
  QWidget *cookPageWinter6;
  QWidget *cookPageWinter7;
  // 所有頁面
  
  QPushButton *startButton;
  QCheckBox *useKinect;
  // 首頁UI
  
  QPushButton *backToSeasonFromCookPageButton;
  QSize buttonSize100;
  QSize buttonSize150;
  QSize buttonSize200;
  QSize buttonSize250;
  QLabel *stepExplain ;
  QPixmap * nextPic ;
  QIcon * nextIcon ;
  int potSizeX1,potSizeX2;
  int potSizeY1,potSizeY2;
  //cook頁UI_共用
  
  //~~~~~~~~~~春天~~~~~~~~~~~~~
  QPushButton * s1c1material1;
	QPushButton * s1c1material2;
	QPushButton * s1c1material3;
	QPushButton * s1c1material4;
	QPushButton * s1c1material5;
  QPushButton * s1c1finished ;
  QLabel * s1c1OrderList1 ;
  QLabel * s1c1OrderList2 ;
  QLabel * s1c1OrderList3 ;
  QLabel * s1c1OrderList4 ;

  QPushButton * s1c2finished ;
  
  QPushButton * s1c3finished ;
  
  QPushButton * s1c4finished;

  QPushButton * s1c5finished ;
  QPushButton * s1c5material1 ;
  QPushButton * s1c5material2 ;
  QPushButton * s1c5material3 ;
  QPushButton * s1c5material4 ;
  QPushButton * s1c5material5 ;
  QWidget * s1c5cover1 ;
  QWidget * s1c5cover2 ;
  QWidget * s1c5cover3 ;
  QWidget * s1c5cover4 ;
  QWidget * s1c5cover5 ;
  QPalette s1c5coverPalette;
  
  QPushButton * s1c6finished ;
  
  QPushButton * s1c7finished ;
  
  QPushButton * s1c8GoNext ;
  QLabel * s1c8Score ;
  // cook頁UI_7
  //~~~~~~~~~~春天~~~~~~~~~~~~~
  //~~~~~~~~~~夏天~~~~~~~~~~~~~
  QPushButton * s2c1material1 ;
  QPushButton * s2c1material2 ;
  QPushButton * s2c1material3 ;
  QPushButton * s2c1material4 ;
  QPushButton * s2c1material5 ;
  QPushButton * s2c1finished ;
  QLabel * s2c1OrderList1 ;
  QLabel * s2c1OrderList2 ;
  QLabel * s2c1OrderList3 ;
  QLabel * s2c1OrderList4 ;

  QPushButton * s2c2finished ;
  POINT s2c2Point1 ;
  POINT s2c2Point2 ;
  POINT s2c2Point3 ;

  QPushButton * s2c3finished ;
  
  QPushButton * s2c4finished ;

  QPushButton * s2c5finished ;

  QPushButton * s2c6finished ;
  
  QPushButton * s2c7finished ;
  QPushButton * s2c7material1 ;
  QPushButton * s2c7material2 ;
  QPushButton * s2c7material3 ;
  QPushButton * s2c7material4 ;
  QPushButton * s2c7material5 ;
  QWidget * s2c7cover1 ;
  QWidget * s2c7cover2 ;
  QWidget * s2c7cover3 ;
  QWidget * s2c7cover4 ;
  int s2c7SizeX1,s2c7SizeX2;
  int s2c7SizeY1,s2c7SizeY2;
  

  QPushButton * s2c8GoNext ;
  QLabel * s2c8Score ;

  //~~~~~~~~~~夏天~~~~~~~~~~~~~
  //~~~~~~~~~~秋天~~~~~~~~~~~~~
    
  QPushButton * s3c1finished ;
  QPushButton * s3c1material1 ;
  QPushButton * s3c1material2 ;
  QPushButton * s3c1material3 ;
  QPushButton * s3c1material4 ;
  QPushButton * s3c1material5 ;
  QLabel * s3c1Dish ;
  QLabel * s3c1OrderList1 ;
  QLabel * s3c1OrderList2 ;
  QLabel * s3c1OrderList3 ;
  QLabel * s3c1OrderList4 ;

  QPushButton * s3c2finished ;

  QPushButton * s3c3finished ;

  QPushButton * s3c4finished ;

  QPushButton * s3c5finished ;

  QPushButton * s3c6finished ;
  QPushButton * s3c6material1 ;
  QPushButton * s3c6material2 ;
  QPushButton * s3c6material3 ;
  QWidget * s3c6cover1 ;
  QWidget * s3c6cover2 ;
  QWidget * s3c6cover3 ;
  QPalette s3c6coverPalette;
  
  QPushButton * s3c7finished ;
  
  QPushButton * s3c8finished ;
  QPushButton * s3c8material1 ;
  QPushButton * s3c8material2 ;
  QWidget * s3c8cover1 ;
  QWidget * s3c8cover2 ;
  QPalette s3c8coverPalette;
  
  QPushButton * s3c9finished ;

  QLabel * s3c10Score ;
  QPushButton * s3c10GoNext ;
  //~~~~~~~~~~秋天~~~~~~~~~~~~~
  //~~~~~~~~~~冬天~~~~~~~~~~~~~
 
  QPushButton * s4c1finished ;
  QPushButton * s4c1material1 ;
  QPushButton * s4c1material2 ;
  QPushButton * s4c1material3 ;
  QPushButton * s4c1material4 ;
  QLabel * s4c1OrderList1 ;
  QLabel * s4c1OrderList2 ;
  QLabel * s4c1OrderList3 ;
  
  QPushButton * s4c2finished ;
  
  QPushButton * s4c3finished ;
  
  QPushButton * s4c4finished ;
  
  QPushButton * s4c5finished ;
  QPushButton * s4c5material1 ;
  QPushButton * s4c5material2 ;
  QPushButton * s4c5material3 ;
  QPushButton * s4c5material4 ;
  QWidget * s4c5cover1 ;
  QWidget * s4c5cover2 ;
  QWidget * s4c5cover3 ;
  QWidget * s4c5cover4 ;
  QPalette s4c5coverPalette;

  QPushButton * s4c6finished ;
  
  QPushButton * s4c7GoNext ;
  QLabel * s4c7Score ;
  //~~~~~~~~~~冬天~~~~~~~~~~~~~
  UI() {  
    myCursor = new QCursor ;
    codec = QTextCodec::codecForName("Big5-ETen");
    sizeX = 1280;
    sizeY = 720;
    picNum = 1;
    seasonNum = 0;
    takingState = false ;
	  cSizeX1 = 520;
	  cSizeX2 = 1120;
	  cSizeY1 = 290;
	  cSizeY2 = 660;
    materialOrder = 1 ;
    materialTaking_c4 = 0;
    pageAt = "" ;
    explainPageUp = false ;
    mousePressing = false ;
    mouseDown = false ;
    kinectThread = new KinectThread ;
    pressAt.x = -1;
    pressAt.y = -1;
    counterForAll = 0 ;
    counterForAll2 = 1 ;
    counterForAll3 = 1 ;


    p1_c2.x = 620 ;
    p1_c2.y = 200 ;
    p2_c2.x = 550 ;
    p2_c2.y = 365 ;
    p3_c2.x = 720 ;
    p3_c2.y = 330 ;
    
	  c4SizeX1 = 650;
	  c4SizeX2 = 1000;
	  c4SizeY1 = 200;
	  c4SizeY2 = 550;
    
	  c1SizeX1 = 430;
	  c1SizeX2 = 820;
	  c1SizeY1 = 300;
	  c1SizeY2 = 650;

    bg0 = QPixmap( "../images/background/bg0.png" );
    bg1 = QPixmap( "../images/background/bg1.png" );
    bg2 = QPixmap( "../images/background/bg2.png" );
    bg3 = QPixmap( "../images/background/bg3-1.png" );
    bg4_1 = QPixmap( "../images/background/bg4-1.png" );
    bg4_2 = QPixmap( "../images/background/bg4-2.png" );
    bg4_3 = QPixmap( "../images/background/bg4-3.png" );
    bg4_4 = QPixmap( "../images/background/bg4-4.png" );
    bg5 = QPixmap( "../images/background/bg5.png" );

    // 所有背景圖片

    mainPage = new QWidget( this );
    brandPage = new QWidget( this );
    seasonPage = new QWidget( this );
    foodPage = new QWidget( this );
    stepPage = new QWidget( this );
    cookPageSpring1 = new QWidget( this );
    cookPageSpring2 = new QWidget( this );
    cookPageSpring3 = new QWidget( this );
    cookPageSpring4 = new QWidget( this );
    cookPageSpring5 = new QWidget( this );
    cookPageSpring6 = new QWidget( this );
    cookPageSpring7 = new QWidget( this );
    cookPageSpring8 = new QWidget( this );
    
    cookPageSummer1 = new QWidget( this );
    cookPageSummer2 = new QWidget( this );
    cookPageSummer3 = new QWidget( this );
    cookPageSummer4 = new QWidget( this );
    cookPageSummer5 = new QWidget( this );
    cookPageSummer6 = new QWidget( this );
    cookPageSummer7 = new QWidget( this );
    cookPageSummer8 = new QWidget( this );
    
    cookPageAutumn1 = new QWidget( this );
    cookPageAutumn2 = new QWidget( this );
    cookPageAutumn3 = new QWidget( this );
    cookPageAutumn4 = new QWidget( this );
    cookPageAutumn5 = new QWidget( this );
    cookPageAutumn6 = new QWidget( this );
    cookPageAutumn7 = new QWidget( this );
    cookPageAutumn8 = new QWidget( this );
    cookPageAutumn9 = new QWidget( this );
    cookPageAutumn10 = new QWidget( this );
    
    cookPageWinter1 = new QWidget( this );
    cookPageWinter2 = new QWidget( this );
    cookPageWinter3 = new QWidget( this );
    cookPageWinter4 = new QWidget( this );
    cookPageWinter5 = new QWidget( this );
    cookPageWinter6 = new QWidget( this );
    cookPageWinter7 = new QWidget( this );
    // 所有頁面

    startButton = new QPushButton; 
    useKinect = new QCheckBox ;
    // 首頁UI

    
    stepExplain  = new QLabel;
    backToSeasonFromCookPageButton = new QPushButton;
    
    buttonSize100.setHeight(100);
    buttonSize100.setWidth(100);
    buttonSize150.setHeight(150);
    buttonSize150.setWidth(150);
    buttonSize200.setHeight(200);
    buttonSize200.setWidth(200);
    buttonSize250.setHeight(250);
    buttonSize250.setWidth(250);

    QPixmap * pic = new QPixmap("../images/button/backToMain.png");
    QIcon * icon = new QIcon(*pic); 
    backToSeasonFromCookPageButton->setIcon(*icon);
    backToSeasonFromCookPageButton->setIconSize( buttonSize100 );
    backToSeasonFromCookPageButton->setFixedSize( buttonSize100 );  
    backToSeasonFromCookPageButton->setMouseTracking(true);
    backToSeasonFromCookPageButton->setFlat(true);
    backToSeasonFromCookPageButton->setGeometry( 1110,600,100,100);
    
    nextPic = new QPixmap("../images/button/next.png");
    nextIcon = new QIcon(*nextPic); 
    
    potSizeX1 = 630 ;
    potSizeX2 = 980 ;
    potSizeY1 = 280 ;
    potSizeY2 = 600 ;
    //cook頁UI
    
    //~~~~~~~~~~春天~~~~~~~~~~~~~
	  s1c1material1 = new QPushButton;
	  s1c1material2 = new QPushButton;
	  s1c1material3 = new QPushButton;
	  s1c1material4 = new QPushButton;
	  s1c1material5 = new QPushButton;
	  s1c1finished = new QPushButton;
	  s1c1OrderList1 = new QLabel;
	  s1c1OrderList2 = new QLabel;
	  s1c1OrderList3 = new QLabel;
	  s1c1OrderList4 = new QLabel;
    
	  s1c2finished = new QPushButton;

	  s1c3finished = new QPushButton;
    
	  s1c4finished = new QPushButton;
    
	  s1c5finished = new QPushButton;
    s1c5material1 = new QPushButton;
    s1c5material2 = new QPushButton;
    s1c5material3 = new QPushButton;
    s1c5material4 = new QPushButton;
    s1c5material5 = new QPushButton;
    s1c5cover1 = new QWidget ;
    s1c5cover2 = new QWidget ;
    s1c5cover3 = new QWidget ;
    s1c5cover4 = new QWidget ;
    s1c5cover5 = new QWidget ;
    
	  s1c6finished = new QPushButton;

	  s1c7finished = new QPushButton;
    
	  s1c8Score = new QLabel;
    s1c8GoNext = new QPushButton ;
    // cook頁UI_7
    //~~~~~~~~~~春天~~~~~~~~~~~~~
    //~~~~~~~~~~夏天~~~~~~~~~~~~~
    
	  s2c1finished = new QPushButton;
	  s2c1material1 = new QPushButton;
	  s2c1material2 = new QPushButton;
	  s2c1material3 = new QPushButton;
	  s2c1material4 = new QPushButton;
	  s2c1material5 = new QPushButton;
	  s2c1OrderList1 = new QLabel;
	  s2c1OrderList2 = new QLabel;
	  s2c1OrderList3 = new QLabel;
	  s2c1OrderList4 = new QLabel;
    
	  s2c2finished = new QPushButton;
    s2c2Point1.x = 455 ;
    s2c2Point1.y = 234 ;
    s2c2Point2.x = 637 ;
    s2c2Point2.y = 368 ;
    s2c2Point3.x = 860 ;
    s2c2Point3.y = 285 ;

	  s2c3finished = new QPushButton;
    
	  s2c4finished = new QPushButton;

	  s2c5finished = new QPushButton;
    
	  s2c6finished = new QPushButton;

	  s2c7finished = new QPushButton;
	  s2c7material1 = new QPushButton;
	  s2c7material2 = new QPushButton;
	  s2c7material3 = new QPushButton;
	  s2c7material4 = new QPushButton;
	  s2c7material5 = new QPushButton;
    s2c7cover1 = new QWidget ;
    s2c7cover2 = new QWidget ;
    s2c7cover3 = new QWidget ;
    s2c7cover4 = new QWidget ;
    s2c7SizeX1 = 830 ;
    s2c7SizeX2 = 1130;
    s2c7SizeY1 = 230 ;
    s2c7SizeY2 = 550;
    
	  s2c8Score = new QLabel;
    s2c8GoNext = new QPushButton ;

    //~~~~~~~~~~夏天~~~~~~~~~~~~~
    //~~~~~~~~~~秋天~~~~~~~~~~~~~
	  s3c1material1 = new QPushButton;
	  s3c1material2 = new QPushButton;
	  s3c1material3 = new QPushButton;
	  s3c1material4 = new QPushButton;
	  s3c1material5 = new QPushButton;
	  s3c1finished = new QPushButton;
	  s3c1OrderList1 = new QLabel;
	  s3c1OrderList2 = new QLabel;
	  s3c1OrderList3 = new QLabel;
	  s3c1OrderList4 = new QLabel;

    s3c2finished = new QPushButton;

    s3c3finished = new QPushButton;

    s3c4finished = new QPushButton;

    s3c5finished = new QPushButton;

    s3c6finished = new QPushButton;
    s3c6material1 = new QPushButton;
    s3c6material2 = new QPushButton;
    s3c6material3 = new QPushButton;
    s3c6cover1 = new QWidget ;
    s3c6cover2 = new QWidget ;
    s3c6cover3 = new QWidget ;
  
    s3c7finished = new QPushButton;
    
    s3c8finished = new QPushButton;
    s3c8material1 = new QPushButton;
    s3c8material2 = new QPushButton;
    s3c8cover1 = new QWidget ;
    s3c8cover2 = new QWidget ;
    
    s3c9finished = new QPushButton;

    s3c10Score = new QLabel ;
    s3c10GoNext = new QPushButton ;
    //~~~~~~~~~~秋天~~~~~~~~~~~~~
    //~~~~~~~~~~冬天~~~~~~~~~~~~~
    
    s4c1finished = new QPushButton;
    s4c1material1 = new QPushButton;
    s4c1material2 = new QPushButton;
    s4c1material3 = new QPushButton;
    s4c1material4 = new QPushButton;
    s4c1OrderList1 = new QLabel;
    s4c1OrderList2 = new QLabel;
    s4c1OrderList3 = new QLabel;
    
    s4c2finished = new QPushButton;
    
    s4c3finished = new QPushButton;
    
    s4c4finished = new QPushButton;
    
    s4c5finished = new QPushButton;
    s4c5material1 = new QPushButton;
    s4c5material2 = new QPushButton;
    s4c5material3 = new QPushButton;
    s4c5material4 = new QPushButton;
    s4c5cover1 = new QWidget ;
    s4c5cover2 = new QWidget ;
    s4c5cover3 = new QWidget ;
    s4c5cover4 = new QWidget ;

    s4c6finished = new QPushButton;
    
    s4c7GoNext = new QPushButton ;
    s4c7Score = new QLabel ;
    //~~~~~~~~~~冬天~~~~~~~~~~~~~
  } // UI
}; // class UI

# endif