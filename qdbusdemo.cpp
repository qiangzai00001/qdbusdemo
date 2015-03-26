#include "qdbusdemo.h"
#include <QtDBus/QDBusConnection>
#include <QtDBus/QDBusMessage>
#include <QDebug>

static const QLatin1String DEMO_DBUS_SERVICE("demo.qdbusService1");
static const QLatin1String DEMO_DBUS_PATH("/demo");
static const QLatin1String DEMO_DBUS_INTERFACE("demo.qdbusService.demoDoSomething");
static const QLatin1String DEMO_DBUS_INTERFACE_DOSOMETHING("doSomething");
static const QLatin1String DEMO_DBUS_INTERFACE_NOTIFY("notifyMsg");

DbusServer::DbusServer(QObject *parent):
    QObject(parent)
{
    //register a server on session bus
    QDBusConnection bus = QDBusConnection::sessionBus();
    if(!bus.registerService(DEMO_DBUS_SERVICE))
    {
        qDebug()<<"DbusServer::DbusServer() register service error!";
        exit(1);
    }
    //QDBusConnection::ExportAllContents can let all the functions can be called by client
    if(!bus.registerObject(DEMO_DBUS_PATH, this, QDBusConnection::ExportAllContents))
    {
        qDebug()<<"DbusServer::DbusServer() register object error!";
        exit(1);
    }
}

DbusServer::~DbusServer()
{

}

void DbusServer::doSomething()
{
    qDebug()<<"DbusServer::doSomething() has been called...";

    //after did something, then emit a signal
    emit notifyMsg();
}

DbusClient::DbusClient(QObject *parent):
    QObject(parent)
{
    qDebug()<<"DbusClient::DbusClient(QObject *parent) construct";
}

DbusClient::~DbusClient()
{

}

void DbusClient::sendMsg()
{
    QDBusMessage msg = QDBusMessage::createMethodCall(DEMO_DBUS_SERVICE,
                                                  DEMO_DBUS_PATH,
                                                  DEMO_DBUS_INTERFACE,
                                                  DEMO_DBUS_INTERFACE_DOSOMETHING);

//      int para = 10;
//      msg<<para;

    QDBusConnection::sessionBus().call(msg);
    qDebug()<<"void DbusClient::sendSignal()";

    QDBusConnection::sessionBus().call(msg);
//    QDBusMessage response = QDBusConnection::sessionBus().call(msg);
//    if(response.type() == QDBusMessage::ReplyMessage){
//        QStringList  data = response.arguments().takeFirst().toStringList();
//         qDebug()<<"void DbusClient::sendSignal() return:";
//         qDebug()<<data.at(0);
//    }
}

DbusMonitor::DbusMonitor(QObject *parent):
    QObject(parent)
{
    QDBusConnection::sessionBus().connect(DEMO_DBUS_SERVICE, DEMO_DBUS_PATH,
            DEMO_DBUS_INTERFACE, DEMO_DBUS_INTERFACE_NOTIFY ,this, SLOT(monitorMsg()));
}

DbusMonitor::~DbusMonitor()
{
}

void DbusMonitor::monitorMsg()
{
    qDebug()<<"DbusMonitor::monitorMsg(), means get a msg from server's' notifymsg...";
    emit changText();
}
