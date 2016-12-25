# include <QApplication>
# include "UI.h"

int main( int argc, char *argv[] ) {
  QApplication app( argc, argv );
  
  UI *ui = new UI;
  ui->setMouseTracking(true);
  ui->resize( 1280, 720 );
  /*
  ui->seasonNum = 2 ;
  ui->CookPageLayoutSummer7();*/
  ui->MainPageLayout();
  ui->setCursor(QCursor(QPixmap("../Images/cursor/hand1Cursor.png")));
  QObject::connect( ui->startButton, SIGNAL( clicked() ), ui, SLOT( BrandPageLayout() ) );
  QObject::connect( ui->useKinect, SIGNAL( stateChanged(int) ), ui, SLOT( KinectThreadOpen() ) );
  // 主畫面Button接線
  
  QObject::connect( ui->backToSeasonFromCookPageButton, SIGNAL( clicked() ), ui, SLOT( SeasonPageLayout() ) );

  QObject::connect( ui->s1c1material1, SIGNAL( clicked() ), ui, SLOT( S1Material1() ) );
  QObject::connect( ui->s1c1material2, SIGNAL( clicked() ), ui, SLOT( S1Material2() ) );
  QObject::connect( ui->s1c1material3, SIGNAL( clicked() ), ui, SLOT( S1Material3() ) );
  QObject::connect( ui->s1c1material4, SIGNAL( clicked() ), ui, SLOT( S1Material4() ) );
  QObject::connect( ui->s1c1material5, SIGNAL( clicked() ), ui, SLOT( S1Material5() ) );

  QObject::connect( ui->s1c1finished, SIGNAL( clicked() ), ui, SLOT( CookPageLayoutSpring2() ) );
  QObject::connect( ui->s1c2finished, SIGNAL( clicked() ), ui, SLOT( CookPageLayoutSpring3() ) );
  QObject::connect( ui->s1c3finished, SIGNAL( clicked() ), ui, SLOT( CookPageLayoutSpring4() ) );
  QObject::connect( ui->s1c4finished, SIGNAL( clicked() ), ui, SLOT( CookPageLayoutSpring5() ) );
  QObject::connect( ui->s1c5finished, SIGNAL( clicked() ), ui, SLOT( CookPageLayoutSpring6() ) );
  QObject::connect( ui->s1c6finished, SIGNAL( clicked() ), ui, SLOT( CookPageLayoutSpring7() ) );
  QObject::connect( ui->s1c7finished, SIGNAL( clicked() ), ui, SLOT( CookPageLayoutSpring8() ) );
  
  QObject::connect( ui->s1c5material1, SIGNAL( clicked() ), ui, SLOT( S1Material1() ) );
  QObject::connect( ui->s1c5material2, SIGNAL( clicked() ), ui, SLOT( S1Material2() ) );
  QObject::connect( ui->s1c5material3, SIGNAL( clicked() ), ui, SLOT( S1Material3() ) );
  QObject::connect( ui->s1c5material4, SIGNAL( clicked() ), ui, SLOT( S1Material4() ) );
  QObject::connect( ui->s1c5material5, SIGNAL( clicked() ), ui, SLOT( S1Material5() ) );

  QObject::connect( ui->s2c1material1, SIGNAL( clicked() ), ui, SLOT( S2Material1() ) );
  QObject::connect( ui->s2c1material2, SIGNAL( clicked() ), ui, SLOT( S2Material2() ) );
  QObject::connect( ui->s2c1material3, SIGNAL( clicked() ), ui, SLOT( S2Material3() ) );
  QObject::connect( ui->s2c1material4, SIGNAL( clicked() ), ui, SLOT( S2Material4() ) );
  QObject::connect( ui->s2c1material5, SIGNAL( clicked() ), ui, SLOT( S2Material5() ) );
  
  QObject::connect( ui->s2c1finished, SIGNAL( clicked() ), ui, SLOT( CookPageLayoutSummer2() ) );
  QObject::connect( ui->s2c2finished, SIGNAL( clicked() ), ui, SLOT( CookPageLayoutSummer3() ) );
  QObject::connect( ui->s2c3finished, SIGNAL( clicked() ), ui, SLOT( CookPageLayoutSummer4() ) );
  QObject::connect( ui->s2c4finished, SIGNAL( clicked() ), ui, SLOT( CookPageLayoutSummer5() ) );
  QObject::connect( ui->s2c5finished, SIGNAL( clicked() ), ui, SLOT( CookPageLayoutSummer6() ) );
  QObject::connect( ui->s2c6finished, SIGNAL( clicked() ), ui, SLOT( CookPageLayoutSummer7() ) );
  QObject::connect( ui->s2c7finished, SIGNAL( clicked() ), ui, SLOT( CookPageLayoutSummer8() ) );
 
  QObject::connect( ui->s2c7material1, SIGNAL( clicked() ), ui, SLOT( S2Material1() ) );
  QObject::connect( ui->s2c7material2, SIGNAL( clicked() ), ui, SLOT( S2Material2() ) );
  QObject::connect( ui->s2c7material3, SIGNAL( clicked() ), ui, SLOT( S2Material3() ) );
  QObject::connect( ui->s2c7material4, SIGNAL( clicked() ), ui, SLOT( S2Material4() ) );
  
  QObject::connect( ui->s3c1material1, SIGNAL( clicked() ), ui, SLOT( S3Material1() ) );
  QObject::connect( ui->s3c1material2, SIGNAL( clicked() ), ui, SLOT( S3Material2() ) );
  QObject::connect( ui->s3c1material3, SIGNAL( clicked() ), ui, SLOT( S3Material3() ) );
  QObject::connect( ui->s3c1material4, SIGNAL( clicked() ), ui, SLOT( S3Material4() ) );
  QObject::connect( ui->s3c1material5, SIGNAL( clicked() ), ui, SLOT( S3Material5() ) );
  
  QObject::connect( ui->s3c1finished, SIGNAL( clicked() ), ui, SLOT( CookPageLayoutAutumn2() ) );
  QObject::connect( ui->s3c2finished, SIGNAL( clicked() ), ui, SLOT( CookPageLayoutAutumn3() ) );
  QObject::connect( ui->s3c3finished, SIGNAL( clicked() ), ui, SLOT( CookPageLayoutAutumn4() ) );
  QObject::connect( ui->s3c4finished, SIGNAL( clicked() ), ui, SLOT( CookPageLayoutAutumn5() ) );
  QObject::connect( ui->s3c5finished, SIGNAL( clicked() ), ui, SLOT( CookPageLayoutAutumn6() ) );
  QObject::connect( ui->s3c6finished, SIGNAL( clicked() ), ui, SLOT( CookPageLayoutAutumn7() ) );
  QObject::connect( ui->s3c7finished, SIGNAL( clicked() ), ui, SLOT( CookPageLayoutAutumn8() ) );
  QObject::connect( ui->s3c8finished, SIGNAL( clicked() ), ui, SLOT( CookPageLayoutAutumn9() ) );
  QObject::connect( ui->s3c9finished, SIGNAL( clicked() ), ui, SLOT( CookPageLayoutAutumn10() ) );
    
  QObject::connect( ui->s3c6material1, SIGNAL( clicked() ), ui, SLOT( S3Material1() ) );
  QObject::connect( ui->s3c6material2, SIGNAL( clicked() ), ui, SLOT( S3Material2() ) );
  QObject::connect( ui->s3c6material3, SIGNAL( clicked() ), ui, SLOT( S3Material3() ) );
  
  QObject::connect( ui->s3c8material1, SIGNAL( clicked() ), ui, SLOT( S3Material1() ) );
  QObject::connect( ui->s3c8material2, SIGNAL( clicked() ), ui, SLOT( S3Material2() ) );

  QObject::connect( ui->s4c1material1, SIGNAL( clicked() ), ui, SLOT( S4Material1() ) );
  QObject::connect( ui->s4c1material2, SIGNAL( clicked() ), ui, SLOT( S4Material2() ) );
  QObject::connect( ui->s4c1material3, SIGNAL( clicked() ), ui, SLOT( S4Material3() ) );
  QObject::connect( ui->s4c1material4, SIGNAL( clicked() ), ui, SLOT( S4Material4() ) );

  QObject::connect( ui->s4c1finished, SIGNAL( clicked() ), ui, SLOT( CookPageLayoutWinter2() ) );
  QObject::connect( ui->s4c2finished, SIGNAL( clicked() ), ui, SLOT( CookPageLayoutWinter3() ) );
  QObject::connect( ui->s4c3finished, SIGNAL( clicked() ), ui, SLOT( CookPageLayoutWinter4() ) );
  QObject::connect( ui->s4c4finished, SIGNAL( clicked() ), ui, SLOT( CookPageLayoutWinter5() ) );
  QObject::connect( ui->s4c5finished, SIGNAL( clicked() ), ui, SLOT( CookPageLayoutWinter6() ) );
  QObject::connect( ui->s4c6finished, SIGNAL( clicked() ), ui, SLOT( CookPageLayoutWinter7() ) );
  
  QObject::connect( ui->s4c5material1, SIGNAL( clicked() ), ui, SLOT( S4Material1() ) );
  QObject::connect( ui->s4c5material2, SIGNAL( clicked() ), ui, SLOT( S4Material2() ) );
  QObject::connect( ui->s4c5material3, SIGNAL( clicked() ), ui, SLOT( S4Material3() ) );
  QObject::connect( ui->s4c5material4, SIGNAL( clicked() ), ui, SLOT( S4Material4() ) );
  
  QObject::connect( ui->s1c8GoNext, SIGNAL( clicked() ), ui, SLOT( GoToNextCook() ) );
  QObject::connect( ui->s2c8GoNext, SIGNAL( clicked() ), ui, SLOT( GoToNextCook() ) );
  QObject::connect( ui->s3c10GoNext, SIGNAL( clicked() ), ui, SLOT( GoToNextCook() ) );
  ui->show();
  return app.exec();
} // main()