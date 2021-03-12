#include "result.h"

#include <algorithm>

Result::Result(int time, date_t date, GameOptions opt)
    : elapsed_time{time}
    , date{date}
    , options{opt}
{

}

std::string Result::date_to_string() const
{
    std::time_t tmp = std::chrono::system_clock::to_time_t(date);
    auto date_str = std::string(std::ctime(&tmp));

    // remove trailing newline
    date_str.erase(
        std::remove(date_str.begin(), date_str.end(), '\n'),
        date_str.end()
    );

    return date_str;
}
