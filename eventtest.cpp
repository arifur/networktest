#include "eventtest.h"

EventTest::EventTest(QObject *parent) :
    QObject(parent)
{
}

void EventTest::eventTest()
{
    auto textTarget = root->findChild<QObject*>("text");
    QString text = QString();

    auto fileCount = 2;
    QString files [] = {
        "rx_bytes",
        "tx_bytes",
    };

    QDirIterator it("/sys/class/net");
    while (it.hasNext()) {
        auto partialPath = it.next();

        const auto intend = "    ";
        auto fullPath = partialPath + "/statistics";
        qDebug() << fullPath;
        if (!QDir(fullPath).exists())
        {
            continue;
        }

        auto ifName = partialPath.right(partialPath.length() - 1 - partialPath.lastIndexOf(QChar('/')));
        text.append(ifName);
        text.append("\n");

        for (int i = 0; i < fileCount; i++)
        {
            text.append(intend);
            text.append(files[i]);
            text.append(intend);

            QFile file(fullPath + "/" + files[i]);
            if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
                continue;

            QTextStream in(&file);
            while (!in.atEnd()) {
                QString line = in.readLine();
                text.append(line);
                break;
            }
            file.close();

            text.append("\n");
        }

        textTarget->setProperty("text", text);
    }
}
