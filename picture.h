#ifndef PICTURE_H
#define PICTURE_H

#include <string>

#include <CImg.h>

using img_t = cimg_library::CImg<unsigned char>;

class Picture
{
public:
    Picture(const std::string &filename);
    void save_fragmented(const std::string &save_dirname, int count);

private:
    img_t _image;

    std::vector<img_t> _fragment_image(int count);
};

#endif // PICTURE_H
