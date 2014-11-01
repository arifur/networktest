#ifndef EVENTTEST_H
#define EVENTTEST_H

#include <QObject>
#include <QVariant>
#include <QDirIterator>
#include <QDebug>>

class EventTest : public QObject
{
    Q_OBJECT

private:
    int i = 0;

public:
    QObject* root;
    explicit EventTest(QObject *parent = 0);

signals:

public slots:
    void eventTest();
};

#endif // EVENTTEST_H
