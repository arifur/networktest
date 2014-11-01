#include <QApplication>
#include <QQmlApplicationEngine>
#include <QTimer>
#include <QObject>
#include <eventtest.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    auto root = engine.rootObjects()[0];

    auto eventTest = new EventTest();
    eventTest->root = root;

    QTimer *timer = new QTimer(root);
    QObject::connect(timer, SIGNAL(timeout()), eventTest, SLOT(eventTest()));
    timer->start(1000);

    return app.exec();
}

void updateText()
{

}
