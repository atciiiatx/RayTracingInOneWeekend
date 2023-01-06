#include <stdint.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

#include "Color3f.h"
#include "Color3i.h"

int main() {
  const int width = 800;
  const int height = 400;
  const int channels = 3;
  auto pixels = new uint8_t[width * height * channels];
  int index = 0;
  for (int j = height - 1; j >= 0; --j) {
    for (int i = 0; i < width; ++i) {
      Color3f color(static_cast<float>(i) / static_cast<float>(width),
                    static_cast<float>(j) / static_cast<float>(height), 0.2f);
      Color3i rgb(color);
      pixels[index++] = rgb.r();
      pixels[index++] = rgb.g();
      pixels[index++] = rgb.b();
    }
  }
  stbi_write_png("image02.png", width, height, channels, pixels,
                 width * channels);
}
