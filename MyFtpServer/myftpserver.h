#ifndef MYFTPSERVER_H
#define MYFTPSERVER_H

#include <QDialog>
#include "server.h"
namespace Ui {
class MyFtpServer;
}

class MyFtpServer : public QDialog
{
    Q_OBJECT

public:
    explicit MyFtpServer(QWidget *parent = 0);
    ~MyFtpServer();
private:
    Server *server;
private:
    Ui::MyFtpServer *ui;
};

#endif // MYFTPSERVER_H
