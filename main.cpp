#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "toursagregator.h"

//#include <QLocale>
//#include <QTranslator>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    ToursAgregator agregator;
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("agregator", &agregator);
    engine.load(QUrl(QStringLiteral("qrc:///main.qml")));

    return app.exec();
}
