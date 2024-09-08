#include <stdio.h>
#include <iostream>
#include <string>

void WriteText(char* buff, long fSize);

int main() {
    FILE* file;

    file = fopen("changed_image.bmp", "rb");

    long fSize;
    fseek(file, 0, SEEK_END);
    fSize = ftell(file);
    rewind(file);

    char* buff = new char[fSize]();
    fread(buff, 1, fSize, file);
    fclose(file);
    
    file = fopen("masked_image.bmp", "wb");

    WriteText(buff, fSize);

    fwrite(buff, fSize, 1, file);

    fclose(file);
    free(buff);
}

void WriteText(char* buff, long fSize) {
    char mask[100] = "";
    std::cout << "Input your mask: "; std::cin >> mask; // 10011010 надо ввести когда код до сюда дойдет
    int bits[8];
    for (int i = 0; i < 8; i++) {
        bits[(i+2)%8] = (mask[i] - 48);
    }
    std::string text = "It is better to laugh at your folly than to cry from your intelligence.";
    int start_of_byte = fSize - 1200;
    std::string::iterator it = text.begin();
    int curr_bits_char = 1;
    for (int i = start_of_byte; i < 1338; i++) {
        int curr_char = *it;
        if (bits[i%8] == 1) {
            buff[i] = (buff[i] & 0xfc) | ((int) ((curr_char & (3 << (8 - (curr_bits_char*2)))) >> (8 - (curr_bits_char*2))));
            curr_bits_char++;
        }
        if (curr_char == '.' && curr_bits_char == 5) {
            break;
        }
        if (curr_bits_char == 5) {
            curr_bits_char = 1;
            it++;
        }
    }
}