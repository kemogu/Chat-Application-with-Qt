#include "server.h"

#include <QDebug>

Server::Server(QObject *parent)
    : QTcpServer(parent)
{
}

void Server::incomingConnection(qintptr socketDescriptor)
{

    QTcpSocket *socket = new QTcpSocket(this);
    if (!socket->setSocketDescriptor(socketDescriptor)) {
        // Soket oluşturulamadı.
        return;
    }

    // Soket bağlantısı tamamlandı.
    connect(socket, &QTcpSocket::readyRead, this, &Server::readyRead);
    connect(socket, &QTcpSocket::disconnected, this, &Server::disconnected);

    clients.append(socket);
    qDebug() << "Yeni bir istemci bağlandı. İstemci sayısı:" << clients.size();

    emit onlineUsersChanged();
}

void Server::readyRead()
{

    QTcpSocket *socket = static_cast<QTcpSocket*>(sender());
    QDataStream in(socket);
    QString message;
    in >> message;

    for (QTcpSocket *client : clients) {
        QDataStream out(client);
        out << message;
    }

    qDebug() << "Mesaj alındı:" << message;
}

void Server::disconnected()
{

    QTcpSocket *socket = static_cast<QTcpSocket*>(sender());
    clients.removeOne(socket);
    socket->deleteLater();

    qDebug() << "Bir istemci bağlantısı sonlandı. İstemci sayısı:" << clients.size();

    emit onlineUsersChanged();
}
int Server::getClientCount() const
{
    return clients.size();
}
