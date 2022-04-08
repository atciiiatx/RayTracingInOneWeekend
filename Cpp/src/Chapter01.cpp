#include <algorithm>
#include <fstream>
#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

int main() {
  const int width = 800;
  const int height = 400;
  const int channels = 3;
  uint8_t *pixels = new uint8_t[width * height * channels];
  const int maxColor = 255;
  int index = 0;
  for (int j = height - 1; j >= 0; --j) {
    for (int i = 0; i < width; ++i) {
      const float r = static_cast<float>(i) / static_cast<float>(width);
      const float g = static_cast<float>(j) / static_cast<float>(height);
      const float b = 0.2f;
      int ir = int(255.99 * r);
      int ig = int(255.99 * g);
      int ib = int(255.99 * b);
      pixels[index++] = ir;
      pixels[index++] = ig;
      pixels[index++] = ib;
    }
  }
  stbi_write_png("image01.png", width, height, channels, pixels,
                 width * channels);
}
