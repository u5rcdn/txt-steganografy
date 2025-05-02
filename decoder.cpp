#include <iostream>
#include <fstream>
#include <bitset>

std::string decodeHiddenData(const std::string& data) {
    std::string secret = "";
    for (size_t i = 0; i + 7 < data.size(); i += 8) {
        std::bitset<8> bits;
        for (int j = 0; j < 8; ++j) {
            char c = data[i + j];
            bits[7 - j] = (c == '\t') ? 1 : 0;
        }
        secret += static_cast<char>(bits.to_ulong());
    }
    return secret;
}

int main() {
    std::ifstream file("stegano.txt", std::ios::binary);
    if (!file) {
        std::cerr << "Fayl ochilmadi!\n";
        return 1;
    }

    std::string visible;
    std::getline(file, visible); 

    std::string hiddenData((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

    std::string result = decodeHiddenData(hiddenData);
    std::cout << "Topilgan maxfiy ma'lumot: " << result << "\n";
    return 0;
}
