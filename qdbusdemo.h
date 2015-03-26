#ifndef QDBUSDEMO_H
#define QDBUSDEMO_H

#include <QObject>

class DbusServer :public QObject {
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "demo.qdbusService.demoDoSomething")
public:
    DbusServer(QObject*parent = 0);
    ~DbusServer();
signals:
    void notifyMsg();
public slots:
    void doSomething();
};

class DbusClient :public QObject {
    Q_OBJECT
public:
    DbusClient(QObject*parent = 0);
    ~DbusClient();
    Q_INVOKABLE void sendMsg();
};

class DbusMonitor: public QObject {
    Q_OBJECT
public:
    DbusMonitor(QObject*parent = 0);
    ~DbusMonitor();
signals:
    void changText();
public slots:
    void monitorMsg();
};

#endif // QDBUSDEMO_H
