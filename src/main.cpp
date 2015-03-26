#include "qdbusdemoWorkspace.h"


Q_DECL_EXPORT int main(int argc, char *argv[])
{
    QScopedPointer<SYBEROS::CGuiApplication> app(SYBEROS::SyberosDeclarativeCache::qApplication(argc, argv));
    qdbusdemoWorkspace workspace(app.data());

    app->exec();
}

