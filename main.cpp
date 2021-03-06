#include "maintray.h"
#include <QApplication>
#include <QTranslator>
#include <QFont>

int main(int argc, char *argv[])
{
    QTranslator t;
    t.load(QString(":/translations/qt_zh_CN.qm"));
    QApplication a(argc, argv);
    a.installTranslator(&t);
    a.setQuitOnLastWindowClosed(false);
    a.setApplicationName(QObject::tr("NEU-Monitor"));
    a.setWindowIcon(QIcon(QObject::tr(":/icon/favicon.ico")));
    a.setFont(QFont("Microsoft YaHei", 9));
    MainTray *tray = new MainTray();
    QObject::connect(tray, &MainTray::exit, &a, &QApplication::quit);
    tray->show();
    return a.exec();
}
