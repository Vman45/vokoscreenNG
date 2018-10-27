#include "QvkHelp.h"
#include "ui_QvkHelp.h"

QvkHelp::QvkHelp(QWidget *parent) : QWidget(parent),
                                    ui(new Ui::QvkHelp)
{
    ui->setupUi(this);
}


void QvkHelp::initHelp(Ui_MainWindow *ui_mainwindow)
{
    gui = ui_mainwindow;

    setWindowTitle( "vokoscreen help" );
    resize( 800, 700 );
    QIcon icon;
    icon.addFile( QString::fromUtf8( ":/pictures/vokoscreen.png" ), QSize(), QIcon::Normal, QIcon::Off );
    setWindowIcon( icon );

    QStringList helpStringList;
#ifdef Q_OS_LINUX
    helpStringList << "http:/"
                   << "linuxecke.volkoh.de"
                   << "vokoscreen"
                   << "help"
                   << "linux"
                   << "3.0";
#endif
#ifdef Q_OS_WIN
    helpStringList << "http:/"
                   << "linuxecke.volkoh.de"
                   << "vokoscreen"
                   << "help"
                   << "windows"
                   << "3.0";
#endif
    vk_helpPath = helpStringList.join( "/" ).append( "/");
    QString language = "en";
    vk_helpPath = vk_helpPath + language + "/";

    webEngineProfile = new QWebEngineProfile();
    webEnginePage = new QWebEnginePage( webEngineProfile );
    webEngineView = new QWebEngineView();
    webEngineView->setPage( webEnginePage );
    ui->verticalLayout->addWidget( webEngineView );

    QAction *action = webEnginePage->action( QWebEnginePage::CopyImageUrlToClipboard );
    action->setVisible( false );
    action = webEnginePage->action( QWebEnginePage::DownloadImageToDisk );
    action->setVisible( false );
    action = webEnginePage->action( QWebEnginePage::CopyImageToClipboard );
    action->setVisible( false );
    action = webEnginePage->action( QWebEnginePage::DownloadLinkToDisk );
    action->setVisible( false );
    action = webEnginePage->action( QWebEnginePage::CopyLinkToClipboard );
    action->setVisible( false );
    action = webEnginePage->action( QWebEnginePage::OpenLinkInThisWindow );
    action->setVisible( false );

    connect( webEnginePage, SIGNAL( loadProgress( int ) ), this, SLOT( slot_progress( int ) ) );

    connect( gui->toolButtonHelpFullscreen, SIGNAL( clicked( bool ) ), this, SLOT( slot_screenFullscreen() ) );
    connect( gui->toolButtonHelpWindow, SIGNAL( clicked( bool ) ), this, SLOT( slot_screenWindow() ) );
    connect( gui->toolButtonHelpArea, SIGNAL( clicked( bool ) ), this, SLOT( slot_screenArea() ) );
    connect( gui->toolButtonHelpCountdown, SIGNAL( clicked( bool ) ), this, SLOT( slot_screenCountdown() ) );

    connect( gui->toolButtonAudioHelp, SIGNAL( clicked( bool ) ), this, SLOT( slot_audioHelp() ) );

    connect( gui->toolButtonHelpVideoPath, SIGNAL( clicked( bool ) ), this, SLOT( slot_miscHelpVideoPath() ) );
    connect( gui->toolButtonHelpStartTime, SIGNAL( clicked( bool ) ), this, SLOT( slot_miscHelpStartTime() ) );
    connect( gui->toolButtonHelpStopRecordingAfter, SIGNAL( clicked( bool ) ), this, SLOT( slot_miscHelpStopRecordingAfter() ) );
    connect( gui->toolButtonHelpScale, SIGNAL( clicked( bool ) ), this, SLOT( slot_miscHelpScal() ) );
    connect( gui->toolButtonHelpLimitOfFreeDiskSpace, SIGNAL( clicked( bool ) ), this, SLOT( slot_miscHelpLimitOfFreeDiskSpace() ) );

    connect( gui->toolButtonAvalaibleHelp, SIGNAL( clicked( bool ) ), this, SLOT( slot_availableHelp() ) );

}


QvkHelp::~QvkHelp()
{
    delete ui;
}


void QvkHelp::slot_close()
{
#ifdef Q_OS_LINUX
    close();
#endif
}


void QvkHelp::slot_progress( int value )
{
    qDebug() << value;
    ui->progressBar->setValue( value );
}



void QvkHelp::slot_screenFullscreen()
{
    QUrl url( vk_helpPath + "screencast/screenFullscreen.html", QUrl::TolerantMode );
#ifdef Q_OS_LINUX
    webEnginePage->setUrl( url );
    this->show();
#endif
#ifdef Q_OS_WIN
    QDesktopServices::openUrl( url );
#endif
}


void QvkHelp::slot_screenWindow()
{
    QUrl url( vk_helpPath + "screencast/screenWindow.html", QUrl::TolerantMode );
#ifdef Q_OS_LINUX
    webEnginePage->setUrl( url );
    this->show();
#endif
#ifdef Q_OS_WIN
    QDesktopServices::openUrl( url );
#endif
}


void QvkHelp::slot_screenArea()
{
    QUrl url( vk_helpPath + "screencast/screenArea.html", QUrl::TolerantMode );
#ifdef Q_OS_LINUX
    webEnginePage->setUrl( url );
    this->show();
#endif
#ifdef Q_OS_WIN
    QDesktopServices::openUrl( url );
#endif
}


void QvkHelp::slot_screenCountdown()
{
    QUrl url( vk_helpPath + "screencast/screenCountdown.html", QUrl::TolerantMode );
#ifdef Q_OS_LINUX
    webEnginePage->setUrl( url );
    this->show();
#endif
#ifdef Q_OS_WIN
    QDesktopServices::openUrl( url );
#endif
}


void QvkHelp::slot_audioHelp()
{
    QUrl url( vk_helpPath + "screencast/audio.html", QUrl::TolerantMode );
#ifdef Q_OS_LINUX
    webEnginePage->setUrl( url );
    this->show();
#endif
#ifdef Q_OS_WIN
    QDesktopServices::openUrl( url );
#endif
}

void QvkHelp::slot_miscHelpVideoPath()
{
#ifdef Q_OS_LINUX
    webEnginePage->load( QUrl("http://linuxecke.volkoh.de/vokoscreen/help/linux/3.0/screencast/misc.html#miscHelpVideoPath") );
    this->show();
#endif
#ifdef Q_OS_WIN
    QDesktopServices::openUrl( QUrl( "http://linuxecke.volkoh.de/vokoscreen/help/windows/3.0/screencast/misc.html#miscHelpVideoPath", QUrl::TolerantMode ) );
#endif
}

void QvkHelp::slot_miscHelpStartTime()
{
#ifdef Q_OS_LINUX
    webEnginePage->load( QUrl( "http://linuxecke.volkoh.de/vokoscreen/help/linux/3.0/screencast/misc.html#miscHelpStartTime" ) );
    this->show();
#endif
#ifdef Q_OS_WIN
    QDesktopServices::openUrl( QUrl( "http://linuxecke.volkoh.de/vokoscreen/help/windows/3.0/screencast/misc.html#miscHelpStartTime", QUrl::TolerantMode ) );
#endif
}

void QvkHelp::slot_miscHelpStopRecordingAfter()
{
#ifdef Q_OS_LINUX
    webEnginePage->load( QUrl( "http://linuxecke.volkoh.de/vokoscreen/help/linux/3.0/screencast/misc.html#miscHelpStopRecordingAfter" ) );
    this->show();
#endif
#ifdef Q_OS_WIN
    QDesktopServices::openUrl( QUrl( "http://linuxecke.volkoh.de/vokoscreen/help/windows/3.0/screencast/misc.html#miscHelpStopRecordingAfter", QUrl::TolerantMode ) );
#endif
}

void QvkHelp::slot_miscHelpScal()
{
#ifdef Q_OS_LINUX
    webEnginePage->load( QUrl( "http://linuxecke.volkoh.de/vokoscreen/help/linux/3.0/screencast/misc.html#miscHelpScal" ) );
    this->show();
#endif
#ifdef Q_OS_WIN
    QDesktopServices::openUrl( QUrl( "http://linuxecke.volkoh.de/vokoscreen/help/windows/3.0/screencast/misc.html#miscHelpScal", QUrl::TolerantMode ) );
#endif
}

void QvkHelp::slot_miscHelpLimitOfFreeDiskSpace()
{
#ifdef Q_OS_LINUX
    webEnginePage->load( QUrl( "http://linuxecke.volkoh.de/vokoscreen/help/linux/3.0/screencast/misc.html#miscHelpLimitOfFreeDiskSpace" ) );
    this->show();
#endif
#ifdef Q_OS_WIN
    QDesktopServices::openUrl( QUrl( "http://linuxecke.volkoh.de/vokoscreen/help/windows/3.0/screencast/misc.html#miscHelpLimitOfFreeDiskSpace", QUrl::TolerantMode ) );
#endif
}

void QvkHelp::slot_availableHelp()
{
    QUrl url( vk_helpPath + "screencast/available.html", QUrl::TolerantMode );
#ifdef Q_OS_LINUX
    webEnginePage->setUrl( url );
    this->show();
#endif
#ifdef Q_OS_WIN
    QDesktopServices::openUrl( url );
#endif
}
