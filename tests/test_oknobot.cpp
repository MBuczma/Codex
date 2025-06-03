#include <QtTest/QtTest>
#include "../OknoBot.h"

class TestOknoBot : public QObject {
    Q_OBJECT
private slots:
    void test_getAllData();
};

void TestOknoBot::test_getAllData()
{
    int argc = 0;
    char *argv[] = {nullptr};
    QApplication app(argc, argv);

    OknoBot bot;
    QMetaObject::invokeMethod(&bot, "dodajRzad", Qt::DirectConnection);
    QMetaObject::invokeMethod(&bot, "dodajRzad", Qt::DirectConnection);

    QString expected = "Nowy GroupBox;;;0s;0ms;\nNowy GroupBox;;;0s;0ms;\n";
    QCOMPARE(bot.getAllDataFromGroupBox(), expected);
}

QTEST_MAIN(TestOknoBot)
#include "test_oknobot.moc"
