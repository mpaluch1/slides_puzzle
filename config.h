#ifndef CONFIG_H
#define CONFIG_H

#include <vector>
#include <string>

struct Config
{
    Config(const std::string &filename);

    std::vector<int> problem_sizes;
    int results_view_count;
    std::vector<std::string> results_view_headers;
    std::string results_filename;
    int default_shuffle_moves_count;
    std::string default_image;
};

#endif // CONFIG_H
