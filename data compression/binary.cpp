#include <iostream>
#include <fstream>
#include <bitset>

int main() {
    std::ifstream videoFile("Brown rang (slowed + reverb).mp4", std::ios::binary);
    std::ofstream outputFile("output_bits.txt");

    if (!videoFile.is_open() || !outputFile.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    char byte;
    while (videoFile.read(&byte, 1)) {
        // Convert each byte to an 8-bit binary representation
        std::bitset<8> bits(byte);
        outputFile << bits;
    }

    videoFile.close();
    outputFile.close();

    std::cout << "Video file converted to bits and saved in output_bits.txt" << std::endl;
    return 0;
}
