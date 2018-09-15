#include "myftpserver.h"
#include "ui_myftpserver.h"
#include <QHostAddress>

MyFtpServer::MyFtpServer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyFtpServer)
{
    ui->setupUi(this);

    server = new Server(this);
    QHostAddress address = QHostAddress::LocalHost;

    qint16 port = 21;

    bool ok = server->listen(address,port);
}

MyFtpServer::~MyFtpServer()
{
    delete ui;
}
