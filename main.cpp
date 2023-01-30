#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "toursagregator.h"
#include "agregatorgetter.h"

//#include <QLocale>
//#include <QTranslator>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

//    ToursAgregator agregator(6);
    qmlRegisterType<ToursAgregator>("Tour", 1, 0, "Agregator");
    qmlRegisterType<AgregatorGetter>("Tour", 1, 0, "Getter");
    QQmlApplicationEngine engine;
//    engine.rootContext()->setContextProperty("agregator", &agregator);
    engine.load(QUrl(QStringLiteral("qrc:///main.qml")));

    return app.exec();
}
