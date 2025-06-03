/* AutoKeyPresser.h */
#pragma once

#include <QString>
#ifdef _WIN32
#  include <Windows.h>
#else
using HWND = void *;
#endif

class AutoKeyPresser
{
public:
    explicit AutoKeyPresser();
    ~AutoKeyPresser();

    // Pobiera uchwyt okna na podstawie pozycji kursora
    void WindowHandleFromPoint(HWND &handle, HWND &parentHandle);

    // Pobiera nazwę okna z uchwytu
    QString GetWindowTextFromHandle(const HWND hwnd) const;

    // Wysyła klawisz do podanego okna
    void SentKey(const HWND handle, const QString &key);

private:
};
