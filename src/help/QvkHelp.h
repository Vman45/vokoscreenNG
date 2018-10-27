#ifndef QVKHELP_H
#define QVKHELP_H

#include "ui_mainwindow.h"

#include <QWidget>

#ifdef Q_OS_LINUX
#include <QWebEngineView>
#include <QWebEnginePage>
#include <QWebEngineProfile>
#endif

namespace Ui {
class QvkHelp;
}

class QvkHelp : public QWidget
{
    Q_OBJECT

public:
    explicit QvkHelp(QWidget *parent = 0);
    ~QvkHelp();
    void initHelp( Ui_MainWindow *ui_mainwindow );

    QWebEngineProfile *webEngineProfile;
    QWebEnginePage *webEnginePage;
    QWebEngineView *webEngineView;

public slots:
    void slot_close();


private slots:
    void slot_screenFullscreen();
    void slot_screenWindow();
    void slot_screenArea();
    void slot_screenCountdown();

    void slot_audioHelp();

    void slot_miscHelpVideoPath();
    void slot_miscHelpStartTime();
    void slot_miscHelpStopRecordingAfter();
    void slot_miscHelpScal();
    void slot_miscHelpLimitOfFreeDiskSpace();

    void slot_availableHelp();

    void slot_progress(int value);

private:
    Ui::QvkHelp *ui;
    Ui_MainWindow *gui;
    QString vk_helpPath;
};

#endif // QVKHELP_H
