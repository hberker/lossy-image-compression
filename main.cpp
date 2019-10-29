#include "png++/png.hpp"
using namespace png;

int main()
{
    image<rgb_pixel > image(128, 128);
    for (size_t y = 0; y < image.get_height(); ++y)
    {
    for (size_t x = 0; x < image.get_width(); ++x)
    {
        image[y][x] = rgb_pixel(x, y, x + y);
    }
    }
    image.write("rgb.png");
}