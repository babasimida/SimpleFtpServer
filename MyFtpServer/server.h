#ifndef SERVER
#define SERVER

#include <QTcpServer>

class Server : public QTcpServer
{
    Q_OBJECT

public:
    Server(QObject * parent = 0);
    ~Server();

private:
    void incomingConnection(int socketId);

private:

    QString username;
    QString password;
    QString path;

};
#endif // SERVER

