#ifndef FTPCMDANALYSIS
#define FTPCMDANALYSIS
/*
 * 此类的作用在于收到客户端连接后，对客户端的命令进行解析，并根据命令进行回复
 */

#include<QSslSocket>
#include<QFile>

 class FtpCmdAnalysis : public QObject
 {

     Q_OBJECT
 public:
     FtpCmdAnalysis(QObject * parent,QSslSocket * socket,const QString &username = QString(),const QString &password = QString(),const QString &path = QString());
     ~FtpCmdAnalysis();
 private:

     QSslSocket * socket;

     QString username;

     QString password;

     QString path;

     QFile cmdfile;

 public:
     void replyMsg(const QString &msg);
     void processCmd(const QString &command,QString *procommand,QString *afcommand);

 public slots:
     void analysisCmd();
     void disconnect();


 };
#endif // FTPCMDANALYSIS

