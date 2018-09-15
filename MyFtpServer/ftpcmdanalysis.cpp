#include"ftpcmdanalysis.h"
#include <QTextStream>
FtpCmdAnalysis::FtpCmdAnalysis(QObject *parent, QSslSocket *socket, const QString &username, const QString &password, const QString &path)
    :QObject(parent)
{

    this->socket = socket;
    this->username = username;
    this->password = password;
    this->path = path;

    socket->setParent(this);
    connect(socket,SIGNAL(readyRead()),this,SLOT(analysisCmd()));
    connect(socket,SIGNAL(disconnected()),this,SLOT(disconnect()));
    replyMsg("220 weicome");

    //cmdfile =  QFile("G:\\Project\\config\\cmd.txt"); //用于存储接收到的客户端的命令，便于理解FTP协议的命令

    FILE * file;

    file = fopen("G:\\Project\\config\\cmd.txt","w");

    if(!cmdfile.open(file,QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug()<<"open file fail";
        return;

    }


}

FtpCmdAnalysis::~FtpCmdAnalysis()
{

}

void FtpCmdAnalysis::replyMsg(const QString &msg)
{

    socket->write((msg+("\r\n")).toUtf8());
}

void FtpCmdAnalysis::analysisCmd()
{
    QString cmd = QString::fromUtf8(socket->readLine().trimmed());


    QTextStream writecmd(&cmdfile);

    writecmd << cmd <<"\n";



    QString procommand;

    QString afcommand;

    processCmd(cmd,&procommand,&afcommand);


    if(procommand == "USER")
    {
        replyMsg("331 username is current");
    }
    replyMsg("220 weicome");

}

void FtpCmdAnalysis::processCmd(const QString &command,QString * procommand,QString * afcommand) //解析命令函数
{
    int pos = command.indexOf(" ");

    if(pos != -1)
    {
        *procommand = command.left(pos).trimmed().toUpper();

        *afcommand = command.mid(pos+1).trimmed().toUpper();

    }
    else
    {
        *procommand = command.trimmed().toUpper();
    }
}

void FtpCmdAnalysis::disconnect()
{
    cmdfile.close();

}






