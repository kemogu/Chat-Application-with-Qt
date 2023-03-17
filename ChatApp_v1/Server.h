#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QDataStream>

class Server : public QTcpServer
{
    Q_OBJECT

public:
    Server(QObject *parent = nullptr);
    int getClientCount() const;
protected:
    void incomingConnection(qintptr socketDescriptor) override;

private slots:
    void readyRead();
    void disconnected();
private :
    QList<QTcpSocket*> clients;
signals:
    void onlineUsersChanged();
};

#endif // SERVER_H

