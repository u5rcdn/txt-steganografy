#include <iostream>
#include <fstream>
#include <bitset>

void encodeHiddenData(std::ofstream& file, const std::string& secret) {
    for (char ch : secret) {
        std::bitset<8> bits(ch);
        for (int i = 7; i >= 0; --i) {
            file << (bits[i] ? '\t' : ' ');
        }
    }
}

int main() {
    std::ofstream file("stegano.txt", std::ios::binary); 
    if (!file) {
        std::cerr << "Fayl ochilmadi!\n";
        return 1;
    }

    std::string visible = "u5rcdn\n"; 
    std::string hidden = "Bu yerga maxfiy malumot yoziladi ";

    file << visible; 
    encodeHiddenData(file, hidden); 
    file.close();

    std::cout << "Yashirin ma'lumot faylga yozildi.\n";
    return 0;
}
