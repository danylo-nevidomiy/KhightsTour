#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "horse.h"
#include "toursagregator.h"

//#include <QLocale>
//#include <QTranslator>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    ToursAgregator agregator;
    Horse horse;
//    horse.find();
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("agregator", &agregator);
    engine.load(QUrl(QStringLiteral("qrc:///main.qml")));

    return app.exec();
}
