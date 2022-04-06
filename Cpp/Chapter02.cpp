
#include <algorithm>
#include <fstream>
#include <iostream>

#include "Color3D.h"
#include "Vector3D.h"

int main() {
  const int nx = 200;
  const int ny = 100;
  const int maxColor = 255;
  const float fMaxColor = static_cast<float>(maxColor);
  std::ofstream myFile("image.ppm");
  myFile << "P3" << std::endl;
  myFile << nx << " " << ny << std::endl;
  myFile << maxColor << std::endl;
  for (int j = ny - 1; j >= 0; --j) {
    for (int i = 0; i < nx; ++i) {
      Color3D color(static_cast<float>(i) / static_cast<float>(nx),
                                 static_cast<float>(j) / static_cast<float>(ny),
                                 0.2f);
      const int ir = std::min(static_cast<int>(color.r() * maxColor), maxColor);
      const int ig = std::min(static_cast<int>(color.g() * maxColor), maxColor);
      const int ib = std::min(static_cast<int>(color.b() * maxColor), maxColor);
      myFile << ir << " " << ig << " " << ib << std::endl;
    }
  }
  myFile.close();
  return 0;
}
