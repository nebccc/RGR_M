#include <iostream>
#include <string>
#include <unordered_map>
#include <cctype>

#include "../include/common_polybius_square.h"

using namespace std;

string decryptPolybiusSquare(const string& encryptedText, const unordered_map<string, char>& reversePolybiusSquare) {
    string decryptedText;
    
    for (size_t i = 0; i < encryptedText.size(); i += 2) {
        string pair = encryptedText.substr(i, 2);
        decryptedText += reversePolybiusSquare.at(pair);
    }

    return decryptedText;
}

void decrypt_polybius_square() {
    // Создаем квадрат Полибия для латинского алфавита
    unordered_map<char, string> polybiusSquareLatin = createPolybiusSquareLatin();
    unordered_map<string, char> reversePolybiusSquareLatin = createReversePolybiusSquare(polybiusSquareLatin);

    // Создаем квадрат Полибия для русского алфавита
    unordered_map<char, string> polybiusSquareRussian = createPolybiusSquareRussian();
    unordered_map<string, char> reversePolybiusSquareRussian = createReversePolybiusSquare(polybiusSquareRussian);

    // Текст для шифрования
    string text;
    cout << "Введите текст: ";
    getline(cin, text);

    // Определяем, на каком языке текст
    bool isRussian = (text.find_first_of("АаБбВвГгДдЕеЁёЖжЗзИиЙйКкЛлМмНнОоПпРрСсТтУуФфХхЦцЧчШшЩщЪъЫыЬьЭэЮюЯя") != string::npos);

    string decryptedText = isRussian ? decryptPolybiusSquare(text, reversePolybiusSquareRussian) : decryptPolybiusSquare(text, reversePolybiusSquareLatin);
}