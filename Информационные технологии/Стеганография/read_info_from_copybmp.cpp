#include <stdio.h>
#include <iostream>

void ReadText(char* buff, long fSize);

int main() {
    FILE* file;
    char filename[100];
    std::cout << "Input file for read: "; std::cin >> filename;
    file = fopen(filename, "rb");

    long fSize;
    fseek(file, 0, SEEK_END);
    fSize = ftell(file);
    rewind(file);

    char* buff = new char[fSize]();
    fread(buff, 1, fSize, file);
    ReadText(buff, fSize);

    fclose(file);
    free(buff);
}

void ReadText(char* buff, long fSize) {
    int start_of_byte = fSize - 1200;
    
    while (start_of_byte < fSize) {
        int first_byte = buff[start_of_byte] & 3;	
        int second_byte = buff[start_of_byte + 1] & 3;
        int third_byte = buff[start_of_byte + 2] & 3;	
        int fourth_byte = buff[start_of_byte + 3] & 3;
        std::cout <<(char) ((first_byte << 6) | (second_byte << 4) | (third_byte << 2) | fourth_byte);
        start_of_byte += 4;
    }
}
