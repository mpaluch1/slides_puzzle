#ifndef GAMEOPTIONS_H
#define GAMEOPTIONS_H

#include <string>

class GameOptions
{
public:
    GameOptions();
    GameOptions(std::string name, int size);

    std::string player_name;
    int problem_size;
};

#endif // GAMEOPTIONS_H
