#include <algorithm>
#include <fstream>
#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

#include "Color3D.h"
#include "Vector3D.h"

int main() {
  const int width = 800;
  const int height = 400;
  const int channels = 3;
  uint8_t *pixels = new uint8_t[width * height * channels];
  const int maxColor = 255;
  const float fMaxColor = static_cast<float>(maxColor);
  int index = 0;
  for (int j = height - 1; j >= 0; --j) {
    for (int i = 0; i < width; ++i) {
      Color3D color(static_cast<float>(i) / static_cast<float>(width),
                    static_cast<float>(j) / static_cast<float>(height), 0.2f);
      int ir = int(255.99 * color.r());
      int ig = int(255.99 * color.g());
      int ib = int(255.99 * color.b());
      pixels[index++] = ir;
      pixels[index++] = ig;
      pixels[index++] = ib;
    }
  }
  stbi_write_png("image02.png", width, height, channels, pixels,
                 width * channels);
}
