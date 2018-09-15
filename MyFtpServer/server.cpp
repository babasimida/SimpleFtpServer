#include "server.h"
#include <QTcpSocket>
#include <QSslSocket>
#include <QByteArray>
#include <QDataStream>
#include"ftpcmdanalysis.h"

Server::Server(QObject *parent)
    :QTcpServer(parent)
{

    username = "admin";
    password = "1234";
    path =     "D:\\";
}

Server::~Server()
{

}

void Server::incomingConnection(int socketId)
{
    QSslSocket * clientSocket = new QSslSocket(this);
    clientSocket->setSocketDescriptor(socketId);
/*
    QByteArray block;

    QDataStream out(&block,QIODevice::WriteOnly);

    out.setVersion(QDataStream::Qt_4_3);


    QString replyCode = QString("331") + "\r\n";

    out << replyCode.toUtf8();

    //block = replyCode.toUtf8();

    clientSocket->write(&replyCode);
    */
    new FtpCmdAnalysis(this,clientSocket,username,password,path);


}
