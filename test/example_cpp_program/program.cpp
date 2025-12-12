#include <vector>
#include <string>
#include <cstdint>
#include <iostream>
#include <fstream>

template<typename T>
struct Image{
    std::vector<T> data;
    int width;
    int height;
};

Image<uint8_t> load_image(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file");
    }

    // Read the image dimensions
    int width, height;
    file.read(reinterpret_cast<char*>(&width), sizeof(width));
    file.read(reinterpret_cast<char*>(&height), sizeof(height));

    // Read the image data
    std::vector<uint8_t> data(width * height);
    file.read(reinterpret_cast<char*>(data.data()), width * height * sizeof(uint8_t));

    // Create and return the Image object
    return {data, width, height};
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <input_image_file>" << std::endl;
        return 1;
    }

    std::string input_filename = argv[1];
    Image<uint8_t> image = load_image(input_filename);

    std::cout << "Successfully loaded image from" << input_filename << ": " << image.width << "x" << image.height << std::endl;

    return 0;
}