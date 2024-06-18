#include <iostream>
#include <string>
#include <unordered_map>
#include <cctype>

#include "../include/common_polybius_square.h"

using namespace std;

string encryptPolybiusSquare(const string& text, const unordered_map<char, string>& polybiusSquare) {
    string encryptedText;

    for (char ch : text) {
        if (isalpha(ch) || (ch >= 'А' && ch <= 'я')) {
            ch = toupper(ch);

            if (ch == 'J') {
                ch = 'I'; // Обрабатываем 'J' как 'I'
            }
            if (ch == 'Ё') {
                ch = 'Е'; // Обрабатываем 'Ё' как 'Е'
            }

            encryptedText += polybiusSquare.at(ch);
        }
    }

    return encryptedText;
}

void encrypt_polybius_square() {
    unordered_map<char, string> polybiusSquareLatin = createPolybiusSquareLatin();
    unordered_map<string, char> reversePolybiusSquareLatin = createReversePolybiusSquare(polybiusSquareLatin);

    unordered_map<char, string> polybiusSquareRussian = createPolybiusSquareRussian();
    unordered_map<string, char> reversePolybiusSquareRussian = createReversePolybiusSquare(polybiusSquareRussian);

    string text;
    cout << "Введите текст: ";
    getline(cin, text);

    bool isRussian = (text.find_first_of("АаБбВвГгДдЕеЁёЖжЗзИиЙйКкЛлМмНнОоПпРрСсТтУуФфХхЦцЧчШшЩщЪъЫыЬьЭэЮюЯя") != string::npos);

    string encryptedText = isRussian ? encryptPolybiusSquare(text, polybiusSquareRussian) : encryptPolybiusSquare(text, polybiusSquareLatin);

    cout << "Зашифрованный текст: " << encryptedText << endl;
}