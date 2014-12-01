#include "Game.h"
#include <QApplication>
#include <QLineEdit>
#include <QTextEdit>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AdventureWindow W;
    W.show();

    return a.exec();
}
