#include "frontend.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Frontend f;
    f.start();
    return a.exec();
}
