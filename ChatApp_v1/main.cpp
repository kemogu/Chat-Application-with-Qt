#include "mainwindow.h"
#include "server.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Server server;
    if (!server.listen(QHostAddress::Any, 8080)) {
        qCritical() << "Sunucu başlatılamadı.";
        return -1;
    }

    qDebug() << "Sunucu başlatıldı. Port:" << server.serverPort();

    MainWindow w;
    w.show();

    return a.exec();
}
