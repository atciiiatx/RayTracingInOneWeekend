#include <algorithm>
#include <fstream>
#include <iostream>

int main() { 
	const int nx = 200;
	const int ny = 100;
    const int maxColor = 255;
    std::ofstream myFile("image.ppm");
    myFile << "P3" << std::endl;
    myFile << nx << " " << ny << std::endl;
    myFile << maxColor << std::endl;
    for (int j = ny - 1; j >= 0; --j) {
        for (int i = 0; i < nx; ++i) {
            const float r = static_cast<float>(i) / static_cast<float>(nx);
            const float g = static_cast<float>(j) / static_cast<float>(ny);
            const float b = 0.2f;
            const int ir = std::min(static_cast<int>(r * maxColor), maxColor);
            const int ig = std::min(static_cast<int>(g * maxColor), maxColor);
            const int ib = std::min(static_cast<int>(b * maxColor), maxColor);
            myFile << ir << " " << ig << " " << ib << std::endl;
        }
    }
    myFile.close();
	return 0; 
}
