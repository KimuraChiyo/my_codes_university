#include <stdio.h>
#include <iostream>

void ChangeColor(char* buff, long fSize);
void WriteText(char* buff, long fSize);

int main() {
    // переменная для файла
    FILE* file;
    // открываем  
    file = fopen("image.bmp", "rb");
    // длина файла
    long fSize;
    fseek(file, 0, SEEK_END);
    fSize = ftell(file);
    rewind(file);
    // инфа с файла
    char* buff = new char[fSize]();
    fread(buff, 1, fSize, file);
    fclose(file);
    // открываем новое изображение с нужным именем для записи
    file = fopen("changed_image.bmp", "wb");
    // меняем цуэт
    ChangeColor(buff, fSize);
    // записываем тэкст
    WriteText(buff, fSize);
    // записываем измененный бафф в файл
    fwrite(buff, fSize, 1, file);
    //закрываем файл
    fclose(file);
    // освобождаем бафф
    free(buff);
}

void ChangeColor(char* buff, long fSize) {
    std::cout << std::endl << std::endl << std::endl;
    for (int i = fSize - 1200; i < fSize;) {
        // B
        buff[i] = 71 & 0xfc;
        // G
        buff[i+1] = 99 & 0xfc;
        // R
        buff[i+2] = 255 & 0xfc;
        i += 3;
    }
}
void WriteText(char* buff, long fSize) {
    // текст
    std::string text = "PM-2-22-5";
    // начальный байт
    int start_of_byte = fSize - 1200;
    // штука, позволяющая перемещаться по строке
    std::string::iterator it = text.begin();
    // цикл по всем буквам в строке
    for (std::string::iterator it = text.begin(); it != text.end(); ++it) {
        char symbol = *it;// текущий символ
        int first_byte_of_symbol = (int) ((symbol & (3 << 6)) >> 6);
        int second_byte_of_symbol = (int) ((symbol & (3 << 4)) >> 4);
        int third_byte_of_symbol = (int) ((symbol & (3 << 2)) >> 2);
        int fourth_byte_of_symbol = (int) (symbol & 3);
        buff[start_of_byte] = (buff[start_of_byte] & 0xfc) | first_byte_of_symbol;
        buff[start_of_byte+1] = (buff[start_of_byte+1] & 0xfc) | second_byte_of_symbol;
        buff[start_of_byte+2] = (buff[start_of_byte+2] & 0xfc) | third_byte_of_symbol;
        buff[start_of_byte+3] = (buff[start_of_byte+3] & 0xfc) | fourth_byte_of_symbol;
        start_of_byte += 4;
    }
}