#ifndef MYSOCKET
#define MYSOCKET

#include <QTcpSocket>

class MySocket : public QTcpSocket
{
    Q_OBJECT

public:
    MySocket(QObject *parent = 0);
    ~MySocket();
public slots:
    void readClient();



};
#endif // MYSOCKET

