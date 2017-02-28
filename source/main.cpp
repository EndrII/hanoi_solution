#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include "source.h"
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    qmlRegisterType<source>("Source",1,0,"Source");
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
