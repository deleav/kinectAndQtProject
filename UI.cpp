# include "UI.h"

void UI::HideAllPage() {
  mainPage->hide();
  brandPage->hide();
  seasonPage->hide();
  foodPage->hide();
  cookPageSpring1->hide();
  cookPageSpring2->hide();
  cookPageSpring3->hide();
  cookPageSpring4->hide();
  cookPageSpring5->hide();
  cookPageSpring6->hide();
  cookPageSpring7->hide();
  cookPageSpring8->hide();
  cookPageSummer1->hide();
  cookPageSummer2->hide();
  cookPageSummer3->hide();
  cookPageSummer4->hide();
  cookPageSummer5->hide();
  cookPageSummer6->hide();
  cookPageSummer7->hide();
  cookPageSummer8->hide();
  cookPageAutumn1->hide();
  cookPageAutumn2->hide();
  cookPageAutumn3->hide();
  cookPageAutumn4->hide();
  cookPageAutumn5->hide();
  cookPageAutumn6->hide();
  cookPageAutumn7->hide();
  cookPageAutumn8->hide();
  cookPageAutumn9->hide();
  cookPageAutumn10->hide();
  cookPageWinter1->hide();
  cookPageWinter2->hide();
  cookPageWinter3->hide();
  cookPageWinter4->hide();
  cookPageWinter5->hide();
  cookPageWinter6->hide();
  cookPageWinter7->hide();
  
} // HideAllPage()

void UI::MainPageLayout() {

  HideAllPage();
  mainPage->show(); // show
  pageAt = "HowDoYouTurnThisOn" ;
  static bool first = true ;
  mainPage->resize( sizeX, sizeY );
  mainPage->setAutoFillBackground( true );
  palette.setBrush( mainPage->backgroundRole(), QBrush( bg1 ) );
  mainPage->setPalette( palette );
  mainPage->setMask( bg1.mask() );
  mainPage->setMouseTracking( true );
   

  QPixmap *pic = new QPixmap( "../Images/button/startButton.png" );
  QIcon *icon = new QIcon(*pic);
  startButton->setIcon(*pic);
  startButton->setIconSize(QSize(200,200)); 

  startButton->setParent(mainPage);
  startButton->setGeometry(545,450,200,200 ) ;
  startButton->setFlat(true );

  useKinect->setParent(mainPage);
  useKinect->setGeometry(580,600,100,100 ) ;
  useKinect->setText("Kinect") ;
  useKinect->setFont( QFont(codec->toUnicode("地眃ㄠ砰W4"), 20) );
} // MainPageLayout()

void UI::BrandPageLayout() {
   
  HideAllPage();
  pageAt = "brand" ;
  brandPage->show(); // show
  static bool first = true ;
  brandPage->resize( 3840, 720 );
  brandPage->setAutoFillBackground( true );
  palette.setBrush( brandPage->backgroundRole(), QBrush( bg2 ) );
  brandPage->setPalette( palette );
  brandPage->setMask( bg2.mask() );
  brandPage->setMouseTracking( true );
  brandPage->setGeometry( -1280,0,3840, 720 );
} // BrandPageLayout()

void UI::SeasonPageLayout() {
  seasonNum = 0 ;
  HideAllPage();
  pageAt = "season" ;
  seasonPage->show();
  static bool first = true ;
  seasonPage->resize( sizeX, sizeY );
  palette.setBrush( seasonPage->backgroundRole(), QBrush( bg3 ) );
  seasonPage->setPalette( palette );
  seasonPage->setMask( bg3.mask() );
  seasonPage->setAutoFillBackground( true );
  seasonPage->setMouseTracking( true );
  
} // SeasonPageLayout()

void UI::FoodPageLayout() {
  HideAllPage();
  foodPage->show(); // show
  static bool first = true ;
  pageAt = "foodImformation" ;
  pressAt.x = -1;

  foodPage->resize( sizeX, sizeY );
  if ( seasonNum == 1 ) {
    palette.setBrush( foodPage->backgroundRole(), QBrush( bg4_1 ) );
    foodPage->setMask( bg4_1.mask() );
  } // if
  else if ( seasonNum == 2 ) {
    palette.setBrush( foodPage->backgroundRole(), QBrush( bg4_2 ) );
    foodPage->setMask( bg4_2.mask() );
  } // if
  else if ( seasonNum == 3 ) {
    palette.setBrush( foodPage->backgroundRole(), QBrush( bg4_3 ) );
    foodPage->setMask( bg4_3.mask() );
  } // if
  else if ( seasonNum == 4 ) {
    palette.setBrush( foodPage->backgroundRole(), QBrush( bg4_4 ) );
    foodPage->setMask( bg4_4.mask() );
  } // if
  foodPage->setPalette( palette );
  foodPage->setAutoFillBackground( true );
  foodPage->setMouseTracking( true );
  foodPage->setGeometry(-1280,0,3840,720);

} // FoodPageLayout()

void UI::StepPageLayout() {
  explainPageUp = true ;
  stepPage->show(); // show
  stepPage->raise();
  stepPage->resize( sizeX, sizeY );
	QPixmap pix;
 
  pix.load(("../images/background/maskBlack.jpg"));
  if ( seasonNum == 1 ) {
    if ( pageAt.compare("SpringPage1PickingMeterial") == 0 )
      pix.load(("../images/background/bgS1C1P0.png"));
    else if ( pageAt.compare("SpringPage2WashMaterial") == 0 ) 
      pix.load(("../images/background/bgS1C2P0.png"));
    else if ( pageAt.compare("SpringPage3CutWhiteFungus") == 0 ) 
      pix.load(("../images/background/bgS1C3P0.png"));
    else if ( pageAt.compare("SpringPage4TearWhiteFungus") == 0 )
      pix.load(("../images/background/bgS1C4P0.png"));
    else if ( pageAt.compare("SpringPage5AddToPot") == 0 ) 
      pix.load(("../images/background/bgS1C5P0.png"));
    else if ( pageAt.compare("SpringPage6StirSoup") == 0 ) 
      pix.load(("../images/background/bgS1C6P0.png"));
    else if ( pageAt.compare("SpringPage7Fire") == 0 ) 
      pix.load(("../images/background/bgS1C7P0.png"));


  } // if
  else if ( seasonNum == 2 ) {
    if ( pageAt.compare("SummerPage1PickingMeterial") == 0 ) 
      pix.load(("../images/background/bgS2C1P0.png"));
    else if  (pageAt.compare("SummerPage2CutWaterMelon") == 0 ) 
      pix.load(("../images/background/bgS2C2P0.png"));
    else if  (pageAt.compare("SummerPage3CutWatermelonToPiece") == 0 ) 
      pix.load(("../images/background/bgS2C3P0.png"));
    else if  (pageAt.compare("SummerPage4CutPineappleToPiece") == 0 ) 
      pix.load(("../images/background/bgS2C4P0.png"));
    else if  (pageAt.compare("SummerPage5WashPeas") == 0 ) 
      pix.load(("../images/background/bgS2C5P0.png"));
    else if  (pageAt.compare("SummerPage6BoilPeas") == 0 ) 
      pix.load(("../images/background/bgS2C6P0.png"));
    else if  (pageAt.compare("SummerPage7PutAll") == 0 ) 
      pix.load(("../images/background/bgS2C7P0.png"));
    
  } // else  if 
  else if ( seasonNum == 3 ) { // ぱ
    if ( pageAt.compare("AutumnPage1PickMeterial") == 0 )
      pix.load(("../images/background/bgS3C1P0.png"));
    else if  (pageAt.compare("AutumnPage2CrashGingo") == 0 ) 
      pix.load(("../images/background/bgS3C2P0.png"));
    else if  (pageAt.compare("AutumnPage3TickGingo") == 0 ) 
      pix.load(("../images/background/bgS3C3P0.png"));
    else if  (pageAt.compare("AutumnPage4TearLily") == 0 ) 
      pix.load(("../images/background/bgS3C4P0.png"));
    else if  (pageAt.compare("AutumnPage5WashRedBean") == 0 ) 
      pix.load(("../images/background/bgS3C5P0.png"));
    else if  (pageAt.compare("AutumnPage6CookAll") == 0 ) 
      pix.load(("../images/background/bgS3C6P0.png"));
    else if  (pageAt.compare("AutumnPage7CookAll") == 0 ) 
      pix.load(("../images/background/bgS3C7P0.png"));
    else if  (pageAt.compare("AutumnPage8CookAll") == 0 ) 
      pix.load(("../images/background/bgS3C8P0.png"));
    else if  (pageAt.compare("AutumnPage9CookAll") == 0 ) 
      pix.load(("../images/background/bgS3C9P0.png"));

  } // else if 
  else if ( seasonNum == 4 ) {
    if ( pageAt.compare("WinterPage1PickMeterial") == 0 )
      pix.load(("../images/background/bgS4C1P0.png"));
    else if  (pageAt.compare("WinterPage2LonganShell") == 0 ) 
      pix.load(("../images/background/bgS4C2P0.png"));
    else if  (pageAt.compare("WinterPage3WashLongan") == 0 ) 
      pix.load(("../images/background/bgS4C3P0.png"));
    else if  (pageAt.compare("WinterPage4CutNewYearCake") == 0 ) 
      pix.load(("../images/background/bgS4C4P0.png"));
    else if  (pageAt.compare("WinterPage5PutAll") == 0 ) 
      pix.load(("../images/background/bgS4C5P0.png"));
    else if  (pageAt.compare("WinterPage6CookAll") == 0 ) 
      pix.load(("../images/background/bgS4C6P0.png"));
    
  } // else  if 
  palette.setBrush( stepPage->backgroundRole(), QBrush( pix ) );
  stepPage->setPalette( palette );
  stepPage->setMask( pix.mask() );
  stepPage->setAutoFillBackground( true );

} // StepPageLayout()

void UI::GoToCook() {
  if ( seasonNum == 1 ) // 琄ぱ
    CookPageLayoutSpring1();
  else if ( seasonNum == 2 ) // 甃ぱ
    CookPageLayoutSummer1(); 
  else if ( seasonNum == 3 ) // ぱ
    CookPageLayoutAutumn1(); 
  else if ( seasonNum == 4 ) // ぱ
    CookPageLayoutWinter1(); 

} // GoToCook()

void UI::GoToNextCook() {
  if ( seasonNum == 1 ) // 琄ぱ
    seasonNum = 2; 
  else if ( seasonNum == 2 ) // 甃ぱ
    seasonNum = 3 ; 
  else if ( seasonNum == 3 ) // ぱ
    seasonNum = 4 ; 
  FoodPageLayout();
} // GoToCook()

void UI::FinishButtonSet( QPushButton * finish, QWidget * parentWidget ) {
  
  finish->setIcon(*nextIcon);
  finish->setIconSize(QSize(100,100));
  finish->setGeometry( 955,600,100,100);
  finish->setParent(parentWidget);
  finish->setMouseTracking(true);
  finish->setFlat(true);
  finish->hide();

} // FinishButtonSet()

void UI::IconButtonSet( QPushButton * button, QWidget * parentWidget,  QString picPath, int xAt, int yAt, int buttonSizeX, int buttonSizeY ) {
  
  QPixmap *pic = new QPixmap(picPath);
  QIcon *icon = new QIcon(*pic);
  button->setIcon(*icon);
  button->setParent(parentWidget);
  button->setIconSize(QSize(buttonSizeX,buttonSizeY));
  button->setGeometry( xAt,yAt,buttonSizeX,buttonSizeY);
  button->setMouseTracking(true);
  button->setFlat(true);
  button->setEnabled(true);
  button->show();

} // IconButtonSet

void UI::CoverWidgetSet( QWidget * cover,  QString picPath, QWidget * parentWidget ) {
  QPixmap pix(picPath) ;
  cover->resize( sizeX, sizeY );
  palette.setBrush( cover->backgroundRole(), QBrush( pix) );
  cover->setPalette( palette );
  cover->setMask( pix.mask() );
  cover->setAutoFillBackground( true );
	cover->setMouseTracking(true);
  cover->setParent(parentWidget);
  cover->hide();

} // CoverWidgetSet()

void UI::PageDefaultSet( QWidget * widget,  QString picPath, QPushButton * finishButton ) {
  counterForAll = 0 ;

  widget->resize( sizeX, sizeY );
  QPixmap pix(picPath) ;
  palette.setBrush( widget->backgroundRole(), QBrush(pix ) );
  widget->setPalette( palette );
  widget->setMask( pix.mask() );
  widget->setAutoFillBackground( true );
	widget->setMouseTracking(true);
  FinishButtonSet(finishButton,widget) ;
  backToSeasonFromCookPageButton->setParent(widget);
} // PageBackgroundSet

void UI::PictureLabelSet( QLabel * label, QWidget * parentWidget, QString picPath, int xAt, int yAt, int buttonSizeX, int buttonSizeY  ) {
  
  label->setPixmap(QPixmap(picPath));
  label->setMouseTracking(true);
  label->setParent(parentWidget);
  label->setGeometry( xAt,yAt,buttonSizeX,buttonSizeY);

} // PictureLabelSet()

void UI::CookPageLayoutSpring1() {
  pageAt = "SpringPage1PickingMeterial";
  time = new QTime ;
  time -> start();
  
  materialOrder = 1 ;
  materialNum = 0 ;
  PictureLabelSet(s1c1OrderList1, cookPageSpring1, "../images/Spring/whiteFungusLabelOn.png", 35 ,320,160,90) ;
  PictureLabelSet(s1c1OrderList2, cookPageSpring1, "../images/Spring/walnutLabelOff.png", 35,430,160,90) ;
  PictureLabelSet(s1c1OrderList3, cookPageSpring1, "../images/Spring/WolfberryLabelOff.png", 35,540,160,90) ;
  PictureLabelSet(s1c1OrderList4, cookPageSpring1, "../images/Spring/sugarLabelOff.png", 200,320,160,90) ;
  
  IconButtonSet(s1c1material1,cookPageSpring1,"../images/Spring/whiteFungusM1.png",250,50,150,150);
  IconButtonSet(s1c1material2,cookPageSpring1,"../images/Spring/walnutM2.png",450,50,150,150);
  IconButtonSet(s1c1material3,cookPageSpring1,"../images/Spring/WolfberryM3.png",650,50,150,150);
  IconButtonSet(s1c1material4,cookPageSpring1,"../images/Spring/CrystalSugarM4.png",850,50,150,150);
  IconButtonSet(s1c1material5,cookPageSpring1,"../images/Spring/fakeM5.png",1050,50,150,150);
  
  backToSeasonFromCookPageButton->setGeometry( 1110,600,100,100);
  PageDefaultSet( cookPageSpring1, "../images/background/bg5.png",s1c1finished ) ;
  StepPageLayout();
} // CookPageLayoutSpring1()

void UI::CookPageLayoutSpring2() {
  counterForAll2 = 1 ;
  pageAt = "SpringPage2WashMaterial";
  PageDefaultSet( cookPageSpring2, "../images/background/bgS1C2P1.png", s1c2finished ) ;
  StepPageLayout();

} // CookPageLayoutSpring2()

void UI::CookPageLayoutSpring3() {
  counterForAll2 = 1 ;
  pageAt = "SpringPage3CutWhiteFungus";
  PageDefaultSet( cookPageSpring3, "../images/background/bgS1C3P1.png",s1c3finished ) ;
  StepPageLayout();

} // CookPageLayoutSpring3()

void UI::CookPageLayoutSpring4() {
  counterForAll2 = 1 ;
  pageAt = "SpringPage4TearWhiteFungus";
  PageDefaultSet( cookPageSpring4, "../images/background/bgS1C4P1.png",s1c4finished ) ;
  StepPageLayout();

} // CookPageLayoutSpring4()

void UI::CookPageLayoutSpring5() {
  pageAt = "SpringPage5AddToPot";
  
  IconButtonSet(s1c5material1,cookPageSpring5,"../images/Spring/whiteFungusC5.png",75,120,130,160);
  IconButtonSet(s1c5material2,cookPageSpring5,"../images/Spring/walnutC5.png",75,300,130,160);
  IconButtonSet(s1c5material3,cookPageSpring5,"../images/Spring/WolfberryC5.png",75,480,130,160);
  IconButtonSet(s1c5material4,cookPageSpring5,"../images/Spring/CrystalSugarC5.png",220,200,130,160);
  IconButtonSet(s1c5material5,cookPageSpring5,"../images/Spring/WaterC5.png",220,380,130,160);
  
  CoverWidgetSet(s1c5cover1,"../images/Spring/whiteFungusCover.png", cookPageSpring5) ;
  CoverWidgetSet(s1c5cover2,"../images/Spring/walnutCover.png", cookPageSpring5) ;
  CoverWidgetSet(s1c5cover3,"../images/Spring/WolfberryCover.png", cookPageSpring5) ;
  CoverWidgetSet(s1c5cover4,"../images/Spring/CrystalSugarCover.png", cookPageSpring5) ;
  CoverWidgetSet(s1c5cover5,"../images/Spring/waterCover.png", cookPageSpring5) ;

  PageDefaultSet( cookPageSpring5, "../images/background/bgS1C5P1.png",s1c5finished ) ;
  StepPageLayout();

} // CookPageLayoutSpring5()

void UI::CookPageLayoutSpring6() {
  pageAt = "SpringPage6StirSoup";
  PageDefaultSet( cookPageSpring6, "../images/background/bgS1C6P1.png",s1c6finished ) ;
  StepPageLayout();

} // CookPageLayoutSpring6()

void UI::CookPageLayoutSpring7() {
  pageAt = "SpringPage7Fire";
  PageDefaultSet( cookPageSpring7, "../images/background/bgS1C7P1.png",s1c7finished ) ;
  StepPageLayout();

} // CookPageLayoutSpring7()

void UI::CookPageLayoutSpring8() {

  pageAt = "SpringPage8Finish";
  HideAllPage();
  cookPageSpring8->show();
  float timeGap = time -> elapsed()/1000.0;
  cookPageSpring8->resize( sizeX, sizeY );
  palette.setBrush( cookPageSpring8->backgroundRole(), QBrush(QPixmap("../images/background/bgS1C8P0.png") ) );
  cookPageSpring8->setPalette( palette );
  cookPageSpring8->setMask( QPixmap("../images/background/bgS1C8P0.png").mask() );
  cookPageSpring8->setAutoFillBackground( true );
  cookPageSpring8->setMouseTracking(true);
  if ( timeGap < 120 )
    s1c8Score->setText(codec->toUnicode( "100だ" ) );
  else if ( timeGap < 180 )
    s1c8Score->setText(codec->toUnicode( "90だ" ) );
  else
    s1c8Score->setText(codec->toUnicode( "80だ" ) );
  s1c8Score->setFont( QFont(codec->toUnicode("地眃ㄠ砰W4"), 60) );
  s1c8Score->setMouseTracking(true);
  s1c8Score->setParent(cookPageSpring8);
  s1c8Score->setGeometry( 750,250,400,300);
  s1c8Score->show();

  QPixmap * pic = new QPixmap("../images/button/nextStage.png");
  QIcon * icon = new QIcon(*pic); 
  s1c8GoNext->setIcon(*icon);
  s1c8GoNext->setIconSize(buttonSize100);
  s1c8GoNext->setParent(cookPageSpring8);
  s1c8GoNext->setGeometry( 915,550,100,100);
  s1c8GoNext->setMouseTracking(true);
  s1c8GoNext->setFlat(true);
  s1c8GoNext->show();
  
  backToSeasonFromCookPageButton->setParent(cookPageSpring8);
  backToSeasonFromCookPageButton->setGeometry( 1035,550,100,100);
  backToSeasonFromCookPageButton->show();
} // CookPageLayoutSpring8

void UI::CookPageLayoutSummer1() {
 
  pageAt = "SummerPage1PickingMeterial";
  time = new QTime ;
  time ->start() ;  
  materialOrder = 1 ;
  materialNum = 0 ;

  PictureLabelSet(s2c1OrderList1, cookPageSummer1, "../images/Summer/pineappleLabelOn.png", 48,385,140,90) ;
  PictureLabelSet(s2c1OrderList2, cookPageSummer1, "../images/Summer/peasLabelOff.png", 48,488,140,90) ;
  PictureLabelSet(s2c1OrderList3, cookPageSummer1, "../images/Summer/watermelonLabelOff.png", 210,385,140,90) ;
  PictureLabelSet(s2c1OrderList4, cookPageSummer1, "../images/Summer/yogurtLabelOff.png",210,488,140,90) ;
   
  IconButtonSet(s2c1material2,cookPageSummer1,"../images/Summer/peasM2.png",250,50,150,150);
  IconButtonSet(s2c1material5,cookPageSummer1,"../images/Summer/cantaloupeFakeMaterial.png",450,50,150,150);
  IconButtonSet(s2c1material4,cookPageSummer1,"../images/Summer/yogurtM4.png",650,50,150,150);
  IconButtonSet(s2c1material1,cookPageSummer1,"../images/Summer/pineappleM1.png",850,50,150,150);
  IconButtonSet(s2c1material3,cookPageSummer1,"../images/Summer/watermelonM3.png",1050,50,150,150);
  
  backToSeasonFromCookPageButton->setGeometry( 1110,600,100,100);
  PageDefaultSet( cookPageSummer1, "../images/background/bg5.png",s2c1finished ) ;
  StepPageLayout();

} // CookPageLayoutSummer1()

void UI::CookPageLayoutSummer2() {
  counterForAll2 = 1 ;
  pageAt = "SummerPage2CutWaterMelon";
  PageDefaultSet( cookPageSummer2, "../images/background/bgS2C2P1.png",s2c2finished ) ;
  StepPageLayout();

} // CookPageLayoutSummer2()

void UI::CookPageLayoutSummer3() {

  pageAt = "SummerPage3CutWatermelonToPiece";
  PageDefaultSet( cookPageSummer3, "../images/background/bgS2C3P1.png",s2c3finished ) ;
  StepPageLayout();
  
} // CookPageLayoutSummer3

void UI::CookPageLayoutSummer4() {
  pageAt = "SummerPage4CutPineappleToPiece" ;
  PageDefaultSet( cookPageSummer4, "../images/background/bgS2C4P1.png",s2c4finished ) ;
  StepPageLayout();
  
} // CookPageLayoutSummer4

void UI::CookPageLayoutSummer5() {
  pageAt = "SummerPage5WashPeas";
  PageDefaultSet( cookPageSummer5, "../images/background/bgS2C5P1.png",s2c5finished ) ;
  StepPageLayout();
  
} // CookPageLayoutSummer5

void UI::CookPageLayoutSummer6() {
  if ( useKinect )
    kinectThread-> motionNum = 1 ;
  pageAt = "SummerPage6BoilPeas";
  PageDefaultSet( cookPageSummer6, "../images/background/bgS2C6P1.png",s2c6finished ) ;
  StepPageLayout();
  
} // CookPageLayoutSummer6

void UI::CookPageLayoutSummer7() {
  
  pageAt = "SummerPage7PutAll";
  
  IconButtonSet(s2c7material1,cookPageSummer7,"../images/Summer/watermelonC7.png",155,165,130,220);
  IconButtonSet(s2c7material2,cookPageSummer7,"../images/Summer/pineappleC7.png",385,185,198,188);
  IconButtonSet(s2c7material3,cookPageSummer7,"../images/Summer/peasC7.png",145,453,165,176);
  IconButtonSet(s2c7material4,cookPageSummer7,"../images/Summer/yogurtC7.png",410,425,155,196);
  IconButtonSet(s2c7material5,cookPageSummer7,"../images/Summer/yogurtC7-2.png",410,425,144,194);
  s2c7material5->hide();

  CoverWidgetSet(s2c7cover1,"../images/Summer/watermelonCover.png", cookPageSummer7) ;
  CoverWidgetSet(s2c7cover2,"../images/Summer/pineappleCover.png", cookPageSummer7) ;
  CoverWidgetSet(s2c7cover3,"../images/Summer/peasCover.png", cookPageSummer7) ;
  CoverWidgetSet(s2c7cover4,"../images/Summer/yogurtCover.png", cookPageSummer7) ;

  PageDefaultSet( cookPageSummer7, "../images/background/bgS2C7P1.png",s2c7finished ) ;

  StepPageLayout();
} // CookPageLayoutSummer7

void UI::CookPageLayoutSummer8() {
  pageAt = "SummerPage8Finish";
  HideAllPage();
  cookPageSummer8->show();
  float timeGap = time -> elapsed()/1000.0;
  cookPageSummer8->resize( sizeX, sizeY );
  palette.setBrush( cookPageSummer8->backgroundRole(), QBrush(QPixmap("../images/background/bgS2C8.png") ) );
  cookPageSummer8->setPalette( palette );
  cookPageSummer8->setMask( QPixmap("../images/background/bgS2C8.png").mask() );
  cookPageSummer8->setAutoFillBackground( true );
	cookPageSummer8->setMouseTracking(true);
  
  if ( timeGap < 120 )
    s2c8Score->setText(codec->toUnicode( "100だ" ) );
  else if ( timeGap < 180 )
    s2c8Score->setText(codec->toUnicode( "90だ" ) );
  else
    s2c8Score->setText(codec->toUnicode( "80だ" ) );
  s2c8Score->setFont( QFont(codec->toUnicode("地眃ㄠ砰W4"), 60) );
  s2c8Score->setMouseTracking(true);
  s2c8Score->setParent(cookPageSummer8);
  s2c8Score->setGeometry( 750,250,400,300);
  s2c8Score->show();

  QPixmap * pic = new QPixmap("../images/button/nextStage.png");
  QIcon * icon = new QIcon(*pic); 
  s2c8GoNext->setIcon(*icon);
  s2c8GoNext->setIconSize(buttonSize100);
  s2c8GoNext->setParent(cookPageSummer8);
  s2c8GoNext->setGeometry( 915,550,100,100);
  s2c8GoNext->setMouseTracking(true);
  s2c8GoNext->setFlat(true);
  s2c8GoNext->show();
  
  backToSeasonFromCookPageButton->setParent(cookPageSummer8);
  backToSeasonFromCookPageButton->setGeometry( 1035,550,100,100);
  backToSeasonFromCookPageButton->show();
  
} // CookPageLayoutSummer8

void UI::CookPageLayoutAutumn1() {
  
  pageAt = "AutumnPage1PickMeterial";
  time = new QTime ;
  time ->start() ;  
  materialOrder = 1 ;
  materialNum = 0 ;
  PictureLabelSet(s3c1OrderList1, cookPageAutumn1, "../images/Autumn/ginkgoLabelOn.png", 35,320,140,90) ;
  PictureLabelSet(s3c1OrderList2, cookPageAutumn1, "../images/Autumn/lilyBulbLabelOff.png", 35,430,140,90) ;
  PictureLabelSet(s3c1OrderList3, cookPageAutumn1, "../images/Autumn/redKindeyBeanLabelOff.png", 35,550,140,90) ;
  PictureLabelSet(s3c1OrderList4, cookPageAutumn1, "../images/Autumn/sugarLabelOff.png",200,320,140,90) ;
   
  IconButtonSet(s3c1material1,cookPageAutumn1,"../images/Autumn/ginkgo.png",250,50,150,150);
  IconButtonSet(s3c1material2,cookPageAutumn1,"../images/Autumn/lilyBulb.png",450,50,150,150);
  IconButtonSet(s3c1material3,cookPageAutumn1,"../images/Autumn/redKindeyBean.png",650,50,150,150);
  IconButtonSet(s3c1material4,cookPageAutumn1,"../images/Autumn/crystalSugar.png",850,50,150,150);
  IconButtonSet(s3c1material5,cookPageAutumn1,"../images/Autumn/fake.png",1050,50,150,150);
  
  backToSeasonFromCookPageButton->setGeometry( 1110,600,100,100);
  PageDefaultSet( cookPageAutumn1, "../images/background/bg5.png",s3c1finished ) ;
  StepPageLayout();
} // CookPageLayoutAutumn1()

void UI::CookPageLayoutAutumn2() {
  pageAt = "AutumnPage2CrashGingo";
  PageDefaultSet( cookPageAutumn2, "../images/background/bgS3C2P1.png", s3c2finished ) ;
  StepPageLayout();

} // CookPageLayoutAutumn2()

void UI::CookPageLayoutAutumn3() {
  
  pageAt = "AutumnPage3TickGingo";
  PageDefaultSet( cookPageAutumn3, "../images/background/bgS3C3P1.png", s3c3finished ) ;
  StepPageLayout();
} // CookPageLayoutAutumn3()

void UI::CookPageLayoutAutumn4() {
  pageAt = "AutumnPage4TearLily";
  PageDefaultSet( cookPageAutumn4, "../images/background/bgS3C4P1.png", s3c4finished ) ;
  StepPageLayout();
} // CookPageLayoutAutumn4()

void UI::CookPageLayoutAutumn5() {
  pageAt = "AutumnPage5WashRedBean";
  PageDefaultSet( cookPageAutumn5, "../images/background/bgS3C5P1.png", s3c5finished ) ;
  StepPageLayout();
} // CookPageLayoutAutumn5()

void UI::CookPageLayoutAutumn6() {
  
  pageAt = "AutumnPage6CookAll"; 
  
  IconButtonSet(s3c6material1,cookPageAutumn6,"../images/Autumn/ginkgoC5.png",75,130,130,160);
  IconButtonSet(s3c6material2,cookPageAutumn6,"../images/Autumn/redKindeyBeanC5.png",75,310,130,160);
  IconButtonSet(s3c6material3,cookPageAutumn6,"../images/Autumn/WaterC5.png",75,490,130,160);

  CoverWidgetSet(s3c6cover1,"../images/Autumn/ginkgoCover.png", cookPageAutumn6) ;
  CoverWidgetSet(s3c6cover2,"../images/Autumn/redKindeyBeanCover.png", cookPageAutumn6) ;
  CoverWidgetSet(s3c6cover3,"../images/Autumn/waterCover.png", cookPageAutumn6) ;

  PageDefaultSet( cookPageAutumn6, "../images/background/bgS3C6P1.png", s3c6finished ) ;
  StepPageLayout();
  
} // CookPageLayoutAutumn6()

void UI::CookPageLayoutAutumn7() {
  pageAt = "AutumnPage7CookAll";
  PageDefaultSet( cookPageAutumn7, "../images/background/bgS3C7P1.png", s3c7finished ) ;
  StepPageLayout();
} // CookPageLayoutAutumn7()

void UI::CookPageLayoutAutumn8() {
  
  pageAt = "AutumnPage8CookAll"; 
  
  IconButtonSet(s3c8material1,  cookPageAutumn8,"../images/Autumn/crystalSugarC5.png",220,200,130,160);
  IconButtonSet(s3c8material2,cookPageAutumn8,"../images/Autumn/lilyBulbC5.png",220,380,130,160);
  CoverWidgetSet(s3c8cover1,"../images/Autumn/CrystalSugarCover.png", cookPageAutumn8) ;
  CoverWidgetSet(s3c8cover2,"../images/Autumn/lilyBulbCover.png", cookPageAutumn8) ;
 
  PageDefaultSet( cookPageAutumn8, "../images/background/bgS3C8P1.png", s3c8finished ) ;
  StepPageLayout();
  
} // CookPageLayoutAutumn6()

void UI::CookPageLayoutAutumn9() {
  pageAt = "AutumnPage9CookAll";
  PageDefaultSet( cookPageAutumn9, "../images/background/bgS3C9P1.png", s3c9finished ) ;
  StepPageLayout();
} // CookPageLayoutAutumn9()

void UI::CookPageLayoutAutumn10() {
  pageAt = "AutumnPageFinish";
  HideAllPage();
  cookPageAutumn10->show();
  float timeGap = time -> elapsed()/1000.0;
  cookPageAutumn10->resize( sizeX, sizeY );
  palette.setBrush( cookPageAutumn10->backgroundRole(), QBrush(QPixmap("../images/background/bgS3C10P0.png") ) );
  cookPageAutumn10->setPalette( palette );
  cookPageAutumn10->setMask( QPixmap("../images/background/bgS3C7P0.png").mask() );
  cookPageAutumn10->setAutoFillBackground( true );
	cookPageAutumn10->setMouseTracking(true);
  
  if ( timeGap < 120 )
    s3c10Score->setText(codec->toUnicode( "100だ" ) );
  else if ( timeGap < 180 )
    s3c10Score->setText(codec->toUnicode( "90だ" ) );
  else
    s3c10Score->setText(codec->toUnicode( "80だ" ) );
  s3c10Score->setFont( QFont(codec->toUnicode("地眃ㄠ砰W4"), 60) );
  s3c10Score->setMouseTracking(true);
  s3c10Score->setParent(cookPageAutumn10);
  s3c10Score->setGeometry( 750,250,400,300);
  s3c10Score->show();

  QPixmap * pic = new QPixmap("../images/button/nextStage.png");
  QIcon * icon = new QIcon(*pic); 
  s3c10GoNext->setIcon(*icon);
  s3c10GoNext->setIconSize(buttonSize100);
  s3c10GoNext->setParent(cookPageAutumn10);
  s3c10GoNext->setGeometry( 915,550,100,100);
  s3c10GoNext->setMouseTracking(true);
  s3c10GoNext->setFlat(true);
  s3c10GoNext->show();
  
  backToSeasonFromCookPageButton->setParent(cookPageAutumn10);
  backToSeasonFromCookPageButton->setGeometry( 1035,550,100,100);
  backToSeasonFromCookPageButton->show();
} // CookPageLayoutAutumn7()

void UI::CookPageLayoutWinter1() {
  
  pageAt = "WinterPage1PickMeterial";
  time = new QTime ;
  time ->start() ;

  materialOrder = 1 ;
  materialNum = 0 ;
  
  PictureLabelSet(s4c1OrderList1, cookPageWinter1, "../images/Winter/NewYearCakeLabelOn.png", 48,330,175,110) ;
  PictureLabelSet(s4c1OrderList2, cookPageWinter1, "../images/Winter/LonganLabelOff.png", 48,450,175,110) ;
  PictureLabelSet(s4c1OrderList3, cookPageWinter1, "../images/Winter/RedSugarLabelOff.png", 48,570,175,110) ;
   
  IconButtonSet(s4c1material1,cookPageWinter1,"../images/Winter/NewYearCakeM1.png",300,50,150,150);
  IconButtonSet(s4c1material2,cookPageWinter1,"../images/Winter/LonganM2.png",800,50,150,150);
  IconButtonSet(s4c1material3,cookPageWinter1,"../images/Winter/RedSugarM3.png",1050,50,150,150);
  IconButtonSet(s4c1material4,cookPageWinter1,"../images/Winter/FakeM4.png",550,50,150,150);
  
  backToSeasonFromCookPageButton->setGeometry( 1110,600,100,100);
  PageDefaultSet( cookPageWinter1, "../images/background/bg5.png",s4c1finished ) ;
  StepPageLayout();
} // CookPageLayoutWinter1()

void UI::CookPageLayoutWinter2() {
  counterForAll2 = 1 ;
  pageAt = "WinterPage2LonganShell";
  PageDefaultSet( cookPageWinter2, "../images/background/bgS4C2P1.png",s4c2finished ) ;
  StepPageLayout();
} // CookPageLayoutWinter2()

void UI::CookPageLayoutWinter3() {

  pageAt = "WinterPage3WashLongan";
  PageDefaultSet( cookPageWinter3, "../images/background/bgS4C3P1.png",s4c3finished ) ;
  StepPageLayout();

} // CookPageLayoutWinter3()

void UI::CookPageLayoutWinter4() {
  counterForAll2 = 1 ;
  pageAt = "WinterPage4CutNewYearCake";
  PageDefaultSet( cookPageWinter4, "../images/background/bgS4C4P1.png",s4c4finished ) ;
  StepPageLayout();
} // CookPageLayoutWinter4()

void UI::CookPageLayoutWinter5() {
  
  pageAt = "WinterPage5PutAll";
  
  IconButtonSet(s4c5material1,cookPageWinter5,"../images/Winter/NewYearCakeC5.png",75,200,220,200);
  IconButtonSet(s4c5material2,cookPageWinter5,"../images/Winter/LonganC5.png",300,200,220,200);
  IconButtonSet(s4c5material3,cookPageWinter5,"../images/Winter/RedSugarC5.png",300,420,220,200);
  IconButtonSet(s4c5material4,cookPageWinter5,"../images/Winter/WaterC5.png",75,420,220,200);

  CoverWidgetSet(s4c5cover1,"../images/Winter/NewYearCakeCover.png", cookPageWinter5) ;
  CoverWidgetSet(s4c5cover2,"../images/Winter/LonganCover.png", cookPageWinter5) ;
  CoverWidgetSet(s4c5cover3,"../images/Winter/RedSugarCover.png", cookPageWinter5) ;
  CoverWidgetSet(s4c5cover4,"../images/Winter/waterCover.png", cookPageWinter5) ;

  PageDefaultSet( cookPageWinter5, "../images/background/bgS4C5P1.png", s4c5finished ) ;
  StepPageLayout();
} // CookPageLayoutWinter5()

void UI::CookPageLayoutWinter6() {
  counterForAll2 = 1 ;
  pageAt = "WinterPage6CookAll";
  PageDefaultSet( cookPageWinter6, "../images/background/bgS4C6P1.png",s4c6finished ) ;
  StepPageLayout();
} // CookPageLayoutWinter6()

void UI::CookPageLayoutWinter7() {
  
  HideAllPage();
  static bool first = true ;
  cookPageWinter7->show();
  pageAt = "WinterPage7End";
  
  float timeGap = time -> elapsed()/1000.0;
  cookPageWinter7->resize( sizeX, sizeY );
  palette.setBrush( cookPageWinter7->backgroundRole(), QBrush( QPixmap("../images/background/bgS4C7P0.png") ) );
  cookPageWinter7->setPalette( palette );
  cookPageWinter7->setMask( QPixmap("../images/background/bgS4C7P0.png").mask() );
  cookPageWinter7->setAutoFillBackground( true );
	cookPageWinter7->setMouseTracking(true);
  
  if ( timeGap < 120 )
    s4c7Score->setText(codec->toUnicode( "100だ" ) );
  else if ( timeGap < 180 )
    s4c7Score->setText(codec->toUnicode( "90だ" ) );
  else
    s4c7Score->setText(codec->toUnicode( "80だ" ) );
  s4c7Score->setFont( QFont(codec->toUnicode("地眃ㄠ砰W4"), 60) );
  s4c7Score->setMouseTracking(true);
  s4c7Score->setParent(cookPageWinter7);
  s4c7Score->setGeometry( 750,250,400,300);
  s4c7Score->show();

  
  backToSeasonFromCookPageButton->setParent(cookPageWinter7);
  backToSeasonFromCookPageButton->setGeometry( 1035,550,100,100);
  backToSeasonFromCookPageButton->show();
} // CookPageLayoutWinter7()

void UI::S1Material1() {
  cout << "IN" << endl ;
  if ( pageAt.compare("SpringPage1PickingMeterial") == 0 )
    s1c1material1->raise();
  else if ( pageAt.compare("SpringPage5AddToPot") == 0 )
    s1c5material1->raise();
  
	if ( !takingState ) {
	  takingState = true;
    materialNum = 1 ;
    this->setCursor(QCursor(QPixmap("../Images/cursor/hand2Cursor.png")));
  } // if
	else {
	  takingState = false;
    materialNum = 0 ;
    this->setCursor(QCursor(QPixmap("../Images/cursor/hand1Cursor.png")));
  } // else
} // S1Material1()

void UI::S1Material2() {
  if ( pageAt.compare("SpringPage1PickingMeterial") == 0 )
    s1c1material2->raise();
  else if ( pageAt.compare("SpringPage5AddToPot") == 0 )
    s1c5material2->raise();
  
	if ( !takingState ) {
	  takingState = true;
    materialNum = 2 ;
    this->setCursor(QCursor(QPixmap("../Images/cursor/hand2Cursor.png")));
  } // if
	else {
	  takingState = false;
    materialNum = 0 ;
    this->setCursor(QCursor(QPixmap("../Images/cursor/hand1Cursor.png")));
  } // else
} // S1Material2()

void UI::S1Material3() {
  if ( pageAt.compare("SpringPage1PickingMeterial") == 0 )
    s1c1material3->raise();
  else if ( pageAt.compare("SpringPage5AddToPot") == 0 )
    s1c5material3->raise();
  
	if ( !takingState ) {
	  takingState = true;
    materialNum = 3 ;
    this->setCursor(QCursor(QPixmap("../Images/cursor/hand2Cursor.png")));
  } // if
	else {
	  takingState = false;
    materialNum = 0 ;
    this->setCursor(QCursor(QPixmap("../Images/cursor/hand1Cursor.png")));
  } // else
} // S1Material3()

void UI::S1Material4() {
  if ( pageAt.compare("SpringPage1PickingMeterial") == 0 )
    s1c1material4->raise();
  else if ( pageAt.compare("SpringPage5AddToPot") == 0 )
    s1c5material4->raise();
  
	if ( !takingState ) {
	  takingState = true;
    materialNum = 4 ;
    this->setCursor(QCursor(QPixmap("../Images/cursor/hand2Cursor.png")));
  } // if
	else {
	  takingState = false;
    materialNum = 0 ;
    this->setCursor(QCursor(QPixmap("../Images/cursor/hand1Cursor.png")));
  } // else
} // S1Material4()

void UI::S1Material5() {
  if ( pageAt.compare("SpringPage1PickingMeterial") == 0 )
    s1c1material5->raise();
  else if ( pageAt.compare("SpringPage5AddToPot") == 0 )
    s1c5material5->raise();
  
	if ( !takingState ) {
	  takingState = true;
    materialNum = 5 ;
    this->setCursor(QCursor(QPixmap("../Images/cursor/hand2Cursor.png")));
  } // if
	else {
	  takingState = false;
    materialNum = 0 ;
    this->setCursor(QCursor(QPixmap("../Images/cursor/hand1Cursor.png")));
  } // else
} // S1Material5()

void UI::S2Material1() {
  if ( pageAt.compare("SummerPage1PickingMeterial") == 0 )
    s2c1material1->raise();
  else if ( pageAt.compare("SummerPage7PutAll") == 0 )
    s2c7material1->raise();

	if ( !takingState ) {
	  takingState = true;
    materialNum = 1 ;
    this->setCursor(QCursor(QPixmap("../Images/cursor/hand2Cursor.png")));
  } // if
	else {
	  takingState = false;
    materialNum = 0 ;
    this->setCursor(QCursor(QPixmap("../Images/cursor/hand1Cursor.png")));
  } // else 
} // S2Material1()

void UI::S2Material2() {
  if ( pageAt.compare("SummerPage1PickingMeterial") == 0 )
    s2c1material2->raise();
  else if ( pageAt.compare("SummerPage7PutAll") == 0 )
    s2c7material2->raise();
  
	if ( !takingState ) {
	  takingState = true;
    materialNum = 2 ;
    this->setCursor(QCursor(QPixmap("../Images/cursor/hand2Cursor.png")));
  } // if
	else {
	  takingState = false;
    materialNum = 0 ;
    this->setCursor(QCursor(QPixmap("../Images/cursor/hand1Cursor.png")));
  } // else
} // S2Material2()

void UI::S2Material3() {
  if ( pageAt.compare("SummerPage1PickingMeterial") == 0 )
    s2c1material3->raise();
  else if ( pageAt.compare("SummerPage7PutAll") == 0 )
    s2c7material3->raise();
  
	if ( !takingState ) {
	  takingState = true;
    materialNum = 3 ;
    this->setCursor(QCursor(QPixmap("../Images/cursor/hand2Cursor.png")));
  } // if
	else {
	  takingState = false;
    materialNum = 0 ;
    this->setCursor(QCursor(QPixmap("../Images/cursor/hand1Cursor.png")));
  } //else
} // S2Material3()

void UI::S2Material4() {
  if ( pageAt.compare("SummerPage1PickingMeterial") == 0 )
    s2c1material4->raise();
  else if ( pageAt.compare("SummerPage7PutAll") == 0 )
    s2c7material4->raise();
  
	if ( !takingState ) {
	  takingState = true;
    materialNum = 4 ;
    this->setCursor(QCursor(QPixmap("../Images/cursor/hand2Cursor.png")));
  } // if
	else {
	  takingState = false;
    materialNum = 0 ;
    this->setCursor(QCursor(QPixmap("../Images/cursor/hand1Cursor.png")));
  } //else

} // S2Material4()

void UI::S2Material5() {
    s2c1material5->raise();
  
	if ( !takingState ) {
	  takingState = true;
    materialNum = 5 ;
    this->setCursor(QCursor(QPixmap("../Images/cursor/hand2Cursor.png")));
  } // if
	else {
	  takingState = false;
    materialNum = 0 ;
    this->setCursor(QCursor(QPixmap("../Images/cursor/hand1Cursor.png")));
  } //else
} // S2Material5()

void UI::S3Material1() {
  if ( pageAt.compare("AutumnPage1PickMeterial") == 0 )
    s3c1material1->raise();
  else if ( pageAt.compare("AutumnPage6CookAll") == 0 )
    s3c6material1->raise();
  else if ( pageAt.compare("AutumnPage8CookAll") == 0 )
    s3c8material1->raise();
  
	if ( !takingState ) {
	  takingState = true;
    materialNum = 1 ;
    this->setCursor(QCursor(QPixmap("../Images/cursor/hand2Cursor.png")));
  } // if
	else {
	  takingState = false;
    materialNum = 0 ;
    this->setCursor(QCursor(QPixmap("../Images/cursor/hand1Cursor.png")));
  } // else
} // S3Material1()

void UI::S3Material2() {
  if ( pageAt.compare("AutumnPage1PickMeterial") == 0 )
    s3c1material2->raise();
  else if ( pageAt.compare("AutumnPage6CookAll") == 0 )
    s3c6material2->raise();
  else if ( pageAt.compare("AutumnPage8CookAll") == 0 )
    s3c8material2->raise();
  
	if ( !takingState ) {
	  takingState = true;
    materialNum = 2 ;
    this->setCursor(QCursor(QPixmap("../Images/cursor/hand2Cursor.png")));
  } // if
	else {
	  takingState = false;
    materialNum = 0 ;
    this->setCursor(QCursor(QPixmap("../Images/cursor/hand1Cursor.png")));
  } // else
} // S3Material2()

void UI::S3Material3() {
  if ( pageAt.compare("AutumnPage1PickMeterial") == 0 )
    s3c1material3->raise();
  else if ( pageAt.compare("AutumnPage6CookAll") == 0 )
    s3c6material3->raise();
  
	if ( !takingState ) {
	  takingState = true;
    materialNum = 3 ;
    this->setCursor(QCursor(QPixmap("../Images/cursor/hand2Cursor.png")));
  } // if
	else {
	  takingState = false;
    materialNum = 0 ;
    this->setCursor(QCursor(QPixmap("../Images/cursor/hand1Cursor.png")));
  } // else
} // S3Material3()

void UI::S3Material4() {
  if ( pageAt.compare("AutumnPage1PickMeterial") == 0 )
    s3c1material4->raise();
  
	if ( !takingState ) {
	  takingState = true;
    materialNum = 4 ;
    this->setCursor(QCursor(QPixmap("../Images/cursor/hand2Cursor.png")));
  } // if
	else {
	  takingState = false;
    materialNum = 0 ;
    this->setCursor(QCursor(QPixmap("../Images/cursor/hand1Cursor.png")));
  } // else
} // S3Material4()

void UI::S3Material5() {
    s3c1material5->raise();
  
	if ( !takingState ) {
	  takingState = true;
    materialNum = 5 ;
    this->setCursor(QCursor(QPixmap("../Images/cursor/hand2Cursor.png")));
  } // if
	else {
	  takingState = false;
    materialNum = 0 ;
    this->setCursor(QCursor(QPixmap("../Images/cursor/hand1Cursor.png")));
  } // else
} // S3Material5()

void UI::S4Material1() {
  
  if ( pageAt.compare("WinterPage1PickMeterial") == 0 )
    s4c1material1->raise();
  else if ( pageAt.compare("WinterPage5PutAll") == 0 )
    s4c5material1->raise();

	if ( !takingState ) {
	  takingState = true;
    materialNum = 1 ;
    this->setCursor(QCursor(QPixmap("../Images/cursor/hand2Cursor.png")));
  } // if
	else {
	  takingState = false;
    materialNum = 0 ;
    this->setCursor(QCursor(QPixmap("../Images/cursor/hand1Cursor.png")));
  } // else
} // S4Material1()

void UI::S4Material2() {
    
  
  if ( pageAt.compare("WinterPage1PickMeterial") == 0 )
    s4c1material2->raise();
  else if ( pageAt.compare("WinterPage5PutAll") == 0 )
    s4c5material2->raise();

	if ( !takingState ) {
	  takingState = true;
    materialNum = 2 ;
    this->setCursor(QCursor(QPixmap("../Images/cursor/hand2Cursor.png")));
  } // if
	else {
	  takingState = false;
    materialNum = 0 ;
    this->setCursor(QCursor(QPixmap("../Images/cursor/hand1Cursor.png")));
  } // else
} // S4Material2()

void UI::S4Material3() {
  if ( pageAt.compare("WinterPage1PickMeterial") == 0 )
    s4c1material3->raise();
  else if ( pageAt.compare("WinterPage5PutAll") == 0 )
    s4c5material3->raise();

	if ( !takingState ) {
	  takingState = true;
    materialNum = 3 ;
    this->setCursor(QCursor(QPixmap("../Images/cursor/hand2Cursor.png")));
  } // if
	else {
	  takingState = false;
    materialNum = 0 ;
    this->setCursor(QCursor(QPixmap("../Images/cursor/hand1Cursor.png")));
  } // else
} // S4Material3()

void UI::S4Material4() {
  if ( pageAt.compare("WinterPage1PickMeterial") == 0 )
    s4c1material4->raise();
  else if ( pageAt.compare("WinterPage5PutAll") == 0 )
    s4c5material4->raise();
  
	if ( !takingState ) {
	  takingState = true;
    materialNum = 4 ;
    this->setCursor(QCursor(QPixmap("../Images/cursor/hand2Cursor.png")));
  } // if
	else {
	  takingState = false;
    materialNum = 0 ;
    this->setCursor(QCursor(QPixmap("../Images/cursor/hand1Cursor.png")));
  } // else
} // S4Material4()

void UI::KinectThreadOpen() {
  if ( useKinect->isChecked() ) {
    kinectThread->stopped = false ;
    kinectThread->start();
  } // if
  else {
    kinectThread->stopped = true ;
  } // else
} // KinectThreadOpen()