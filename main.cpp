#include "game.h"

#include <spdlog/spdlog.h>
#include <QApplication>

int main(int argc, char *argv[])
{
    spdlog::set_level(spdlog::level::debug);

    QApplication a(argc, argv);
    Game game;
    game.start();
    return a.exec();
}
