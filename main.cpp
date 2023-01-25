#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "horse.h"

//#include <QLocale>
//#include <QTranslator>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    Horse horse;
//    horse.find();
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("horse", &horse);
    engine.load(QUrl(QStringLiteral("qrc:///main.qml")));

    return app.exec();
}
