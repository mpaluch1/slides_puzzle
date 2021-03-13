#include "game.h"

#include <cxxopts.hpp>
#include <spdlog/spdlog.h>
#include <QApplication>

#include "config.h"

namespace {
constexpr auto def_conf_filename = "config.json";
}

int main(int argc, char *argv[])
{
    spdlog::set_level(spdlog::level::debug);
    cxxopts::Options options("Łamigłówka z lat dziecięcych", "Gra rozrywkowa");

    options.add_options()
      ("c, config", "Nazwa pliku konfiguracyjnego",
       cxxopts::value<std::string>()->default_value(def_conf_filename))
    ;

    auto result = options.parse(argc, argv);
    if (result.count("config") == 0) {
        spdlog::debug("Config file not provided, using default value {}", def_conf_filename);
    }

    QApplication a(argc, argv);

    auto config = result["config"].as<std::string>();
    Game game{Config{config}};
    game.start();
    return a.exec();
}
