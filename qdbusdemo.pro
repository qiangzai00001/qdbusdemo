QML_IMPORT_PATH = /home/ycg/SyberOS-SDK/SDKQt/qt530/usr/lib/qt5/qml

RESOURCES += res.qrc

CONFIG += link_pkgconfig

PKGCONFIG += syberos-application syberos-application-cache

# This is needed for using syberos-application module
INCLUDEPATH += $$[QT_INSTALL_HEADERS]/../syberos_application

QT += gui qml quick  dbus

TARGET = qdbusdemo

#Please Do not modify these macros, otherwise your app will not installed correctly and will not run at all.
APP_DIR = /altdata/apps
APP_DATA = /altdata/data
INS_DIR = $$APP_DIR/com.mycompany.qdbusdemo
DATA_DIR = $$APP_DATA/com.mycompany.qdbusdemo

DEFINES += SOP_ID=\\\"com.mycompany.qdbusdemo\\\"
DEFINES += APP_DIR_ENVVAR=\\\"APPDIR_REGULAR\\\"
# Currently home screen sets the environment variable, so when run from
# elsewhere, use this work-around instead.
DEFINES += APP_DIR=\\\"$$APP_DIR\\\"

# The .cpp file which was generated for your project.
SOURCES += src/main.cpp \
           src/qdbusdemoWorkspace.cpp \
    qdbusdemo.cpp

HEADERS += src/qdbusdemoWorkspace.h \
    qdbusdemo.h


# Installation path
target.path = $$INS_DIR/bin

res.files = res
res.path = $$INS_DIR/

meta.files = META-INF
meta.path = $$INS_DIR/

syber.files = sopconfig.xml
syber.path = $$INS_DIR/

INSTALLS += target res meta syber

QML_FILES = qml/*.qml

OTHER_FILES += $$QML_FILES *.qm
               


