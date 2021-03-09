#ifndef RESULT_H
#define RESULT_H

#include <chrono>
#include <string>

#include "gameoptions.h"

using date_t = std::chrono::time_point<std::chrono::system_clock>;

class Result
{
public:
    Result(int time, date_t date, GameOptions opt);

    int elapsed_time;
    date_t date;
    GameOptions options;
};

#endif // RESULT_H
