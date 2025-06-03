#ifndef GLOBALKEYLISTENER_H
#define GLOBALKEYLISTENER_H

#include <QObject>
#ifdef _WIN32
#  include <Windows.h>
#else
using HHOOK = void *;
using WPARAM = unsigned long;
using LPARAM = long;
using LRESULT = long;
#endif

class GlobalKeyListener : public QObject
{
    Q_OBJECT

signals:
    void keyPressed(int vkCode);

public:
    explicit GlobalKeyListener(QObject *parent = nullptr);
    ~GlobalKeyListener();

    void start();

private:
    static LRESULT CALLBACK keyboardProc(int nCode, WPARAM wParam, LPARAM lParam);
    static HHOOK hook;
    static GlobalKeyListener *instance;

    static QString opisVK(int vkCode);
};

#endif // GLOBALKEYLISTENER_H
