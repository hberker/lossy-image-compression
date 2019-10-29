#include "png++/png.hpp"
#include<vector>
using namespace png;
using namespace std;

int reduce_image(image<rgb_pixel> &img)
{
    vector<rgb_pixel> pixels = {};
    int index=0;
    for (size_t r = 0; r < img.get_width(); ++r)
    {
        for (size_t c = 0; c < img.get_height(); ++c)
        {
            if (c % 2==0)
            {
                pixels.insert(pixels.end(),img[c][r]);
            }
        }
    }
    for (size_t r = 0; r < img.get_width(); ++r)
    {
        for (size_t c = 0; c < img.get_height(); ++c)
        {
            if (c % 2 !=0 )
            {
                pixels.insert(pixels.end(),img[c][r]);
            }
        }
    }
    for (size_t r = 0; r < img.get_width(); ++r)
    {
        for (size_t c = 0; c <img.get_height(); ++c)
        {
            img[c][r] = pixels.at(index);
            index++;
        }
    }
    return 0;
}
int main(int argc, char *argv[])
{
    unsigned int compression_number = atoi(argv[1]);
    image<rgb_pixel> image("mouse.png");
    for(int i = 0; i < compression_number; i++)
    {
        reduce_image(image);
    }
    image.write("output.png");
    return 0;
}