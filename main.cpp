#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "toursagregator.h"
#include "agregatorgetter.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<ToursAgregator>("Tour", 1, 0, "Agregator");
    qmlRegisterType<AgregatorGetter>("Tour", 1, 0, "Getter");
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:///main.qml")));

    return app.exec();
}
