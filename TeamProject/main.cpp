#include "mainsystem.h"
#include <QApplication>
#include <QPixmap>
#include <QSplashScreen>
#include <QtTest>
#include <QFont>
#include <QPalette>
//#include "users.h"
int main(int argc, char *argv[])
{
    //下面一段代码是程序启动画面
    QApplication a(argc, argv);
    QPixmap pixmap("logo.png");
    QSplashScreen splash(pixmap);
    splash.show();
    Qt::Alignment topRight = Qt::AlignCenter | Qt::AlignTop;
    QFont ft;
    ft.setPointSize(14);
    splash.setFont(ft);
    splash.showMessage(QObject::tr("Setting up the software..."),
                            topRight,
                            Qt::green);
    splash.resize(2*splash.size());

    QTest::qSleep(3000);
    a.processEvents();
    a.connect(&a,SIGNAL(lastWindowClosed()),&a,SLOT(quit()));


    MainSystem w;
    w.show();
    splash.finish(&w); 
    return a.exec();
}
