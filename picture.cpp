#include "picture.h"

#include <spdlog/spdlog.h>

Picture::Picture(const std::string &filename)
{
    _image = cimg_library::CImg<unsigned char>(filename.c_str());
}

std::map<int, std::string> Picture::save_fragmented(const std::string &save_dirname, int count)
{
    auto fragments = _fragment_image(count);
    std::map<int, std::string> ret;

    for (unsigned i = 0; i < fragments.size(); ++i) {
        auto path = save_dirname + '/' + std::to_string(i) + ".jpg";
        fragments[i].save_jpeg(path.c_str());
        ret[i] = path;

        spdlog::debug("Saved image fragment {} in path {}", i, path);
    }

    return ret;
}

std::vector<img_t> Picture::_fragment_image(int count)
{
    auto width = _image.width();
    auto height = _image.height();

    auto new_width = width / count;
    auto new_height = height / count;

    spdlog::debug("Fragmenting picture with dimensions ({},{})", width, height);

    std::vector<img_t> ret;
    for (int i = 0; i < count; ++i) {
        for (int j = 0; j < count; ++j) {
            auto x0 = j * new_width;
            auto x1 = x0 + new_width;

            auto y0 = i * new_height;
            auto y1 = y0 + new_height;

            ret.push_back(_image.get_crop(x0, y0, 0, 0, x1, y1, 0, 2));
        }
    }

    return ret;
}
