/* main.cpp */
/*
 * Główny plik w którym jest tworzony obiekt QApplication o nazwie application.
 * W funkcji ustawStyl jest ustawiany wygląd GUI poprzez setStyle i setPalette.
 */

//Opisy dla użytkownika
//Komentarze dla siebie
//Ujednolicić nazwy funkcji i zmiennych

#include "GlowneOkno.h"
#include "Logger.h"

#include <QApplication>
#include <QDateTime>
#include <QPalette>
#include <QStyleFactory>
#include <memory> // std::unique_ptr

void ustawStyl(QApplication &application);

int main(int argc, char *argv[])
{
    QString plik_z_logami = "QtBot_log_" + QDateTime::currentDateTime().toString("yyyy-MM-dd")
                            + ".txt";
    initLogger(plik_z_logami);
    qInfo() << "Uruchomiono aplikacje";

    QApplication application(argc, argv);
    ustawStyl(application);

    std::unique_ptr<GlowneOkno> glowneOkno = std::make_unique<GlowneOkno>();
    glowneOkno->show();

    return application.exec();
}

void ustawStyl(QApplication &application)
{
    QApplication::setStyle(QStyleFactory::create("Fusion"));
    QPalette palette = application.palette();
    application.setStyleSheet("QPushButton:hover { background-color: #808080; }"
                              "QComboBox:hover { background-color: #808080; }");
    application.setPalette(palette);
}
