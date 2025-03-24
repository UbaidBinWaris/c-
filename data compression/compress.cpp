#include <iostream>
#include <fstream>
#include <string>
#include <bitset>
#include <sstream>

// Function to compress binary data using Run-Length Encoding with prefix for 0s
std::string compressBinary(const std::string& binary) {
    std::string compressed = "";
    int count = 0;

    for (size_t i = 0; i < binary.length(); ++i) {
        if (binary[i] == '1') {
            if (count > 0) {
                // Append the prefix for 0's if needed
                compressed += "0" + std::to_string(count);
                count = 0;
            }
            compressed += "1";  // Directly append 1
        } else {  // Handling 0's
            count++;
        }
    }

    // If the last part was zeros
    if (count > 0) {
        compressed += "0" + std::to_string(count);
    }

    return compressed;
}

// Function to decompress binary data using RLE
std::string decompressBinary(const std::string& compressed) {
    std::string decompressed = "";
    size_t i = 0;

    while (i < compressed.length()) {
        if (compressed[i] == '1') {
            decompressed += "1";  // Directly append 1
            i++;  // Move to the next character
        } else {
            // We encountered a '0' prefix, which means a count of zeros
            size_t j = i + 1;
            std::string countStr = "";
            while (j < compressed.length() && isdigit(compressed[j])) {
                countStr += compressed[j];
                j++;
            }
            int count = std::stoi(countStr);  // Convert the count to an integer
            decompressed.append(count, '0');  // Append the appropriate number of zeros
            i = j;  // Move past the count
        }
    }

    return decompressed;
}

// Function to read binary data from a file
std::string readBinaryFromFile(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return "";
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    file.close();

    // Convert binary file content to a string of '0' and '1'
    std::string binaryData = "";
    char byte;
    while (buffer.get(byte)) {
        std::bitset<8> bits(byte);
        binaryData += bits.to_string();  // Convert each byte to 8-bit binary representation
    }
    
    return binaryData;
}

// Function to write compressed data to a file
void writeToFile(const std::string& filename, const std::string& data) {
    std::ofstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    file.write(data.c_str(), data.size());
    file.close();
}

int main() {
    // Load binary data from a file (the file should contain binary data, e.g., a video or large file)
    std::string binaryData = readBinaryFromFile("output_bits.txt");
    if (binaryData.empty()) {
        return 1; // Exit if file reading failed
    }

    // Compress the binary data using RLE with the prefix for 0
    std::string compressed = compressBinary(binaryData);

    // Write the compressed data to a file
    writeToFile("compressed_output.dat", compressed);

    // Optionally, if you need to decompress the data later:
    // std::string decompressed = decompressBinary(compressed);
    // writeToFile("decompressed_output.dat", decompressed);

    return 0;
}
