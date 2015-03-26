#include "qdbusdemoWorkspace.h"
#include <QDebug>
#include <QQmlEngine>
#include <QQmlContext>
#include "qdbusdemo.h"

qdbusdemoWorkspace::qdbusdemoWorkspace(QObject* parent)
    : CWorkspace(parent)
{
    m_view = SyberosDeclarativeCache::qQuickView();
    QObject::connect(m_view->engine(), SIGNAL(quit()), qApp, SLOT(quit()));
    m_view->setSource(QUrl("qrc:/qml/main.qml"));
    m_view->showFullScreen();

    QQmlEngine *engine = m_view->engine();
    QQmlContext *context= engine->rootContext();

    context->setContextProperty("server", &server);
    context->setContextProperty("client", &client);
    context->setContextProperty("monitor", &monitor);
}

void qdbusdemoWorkspace::onLaunchComplete(Option option, const QStringList& params)
{
    Q_UNUSED(params);
    switch (option) {
    case CWorkspace::HOME:
        qDebug()<< "Start by Home";
        break;
    case CWorkspace::URL:
        break;
    case CWorkspace::EVENT:
        break;
    case CWorkspace::DOCUMENT:
        break;
    default:
        break;
    }
}


