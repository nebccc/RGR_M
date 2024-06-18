#include <iostream>
#include <string>
#include <unordered_map>
#include <cctype>

using namespace std;

// Функция для создания квадрата Полибия для латинского алфавита
unordered_map<char, string> createPolybiusSquareLatin() {
    unordered_map<char, string> polybiusSquare;
    char letter = 'A';
    for (int row = 1; row <= 5; ++row) {
        for (int col = 1; col <= 5; ++col) {
            if (letter == 'J') {
                ++letter; // Пропускаем букву 'J'
            }
            polybiusSquare[letter] = to_string(row) + to_string(col);
            ++letter;
        }
    }
    return polybiusSquare;
}

// Функция для создания квадрата Полибия для русского алфавита
unordered_map<char, string> createPolybiusSquareRussian() {
    unordered_map<char, string> polybiusSquare;
    char letter = 'А';
    for (int row = 1; row <= 6; ++row) {
        for (int col = 1; col <= 6; ++col) {
            if (letter == 'Ё') {
                ++letter; // Пропускаем букву 'Ё'
            }
            polybiusSquare[letter] = to_string(row) + to_string(col);
            ++letter;
        }
    }
    return polybiusSquare;
}

// Функция для создания обратного квадрата Полибия
unordered_map<string, char> createReversePolybiusSquare(const unordered_map<char, string>& polybiusSquare) {
    unordered_map<string, char> reversePolybiusSquare;
    for (const auto& pair : polybiusSquare) {
        reversePolybiusSquare[pair.second] = pair.first;
    }
    return reversePolybiusSquare;
}

// Функция для шифрования текста с использованием квадрата Полибия
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

// Функция для дешифрования текста с использованием квадрата Полибия
string decryptPolybiusSquare(const string& encryptedText, const unordered_map<string, char>& reversePolybiusSquare) {
    string decryptedText;
    
    for (size_t i = 0; i < encryptedText.size(); i += 2) {
        string pair = encryptedText.substr(i, 2);
        decryptedText += reversePolybiusSquare.at(pair);
    }

    return decryptedText;
}

int main() {
    // Создаем квадрат Полибия для латинского алфавита
    unordered_map<char, string> polybiusSquareLatin = createPolybiusSquareLatin();
    unordered_map<string, char> reversePolybiusSquareLatin = createReversePolybiusSquare(polybiusSquareLatin);

    // Создаем квадрат Полибия для русского алфавита
    unordered_map<char, string> polybiusSquareRussian = createPolybiusSquareRussian();
    unordered_map<string, char> reversePolybiusSquareRussian = createReversePolybiusSquare(polybiusSquareRussian);

    // Текст для шифрования
    string text;
    cout << "Введите текст для шифрования (латинский или русский): ";
    getline(cin, text);

    // Определяем, на каком языке текст
    bool isRussian = (text.find_first_of("АаБбВвГгДдЕеЁёЖжЗзИиЙйКкЛлМмНнОоПпРрСсТтУуФфХхЦцЧчШшЩщЪъЫыЬьЭэЮюЯя") != string::npos);

    // Шифруем текст
    string encryptedText = isRussian ? encryptPolybiusSquare(text, polybiusSquareRussian) : encryptPolybiusSquare(text, polybiusSquareLatin);

    // Выводим зашифрованный текст
    cout << "Зашифрованный текст: " << encryptedText << endl;

    // Дешифруем текст
    string decryptedText = isRussian ? decryptPolybiusSquare(encryptedText, reversePolybiusSquareRussian) : decryptPolybiusSquare(encryptedText, reversePolybiusSquareLatin);

    // Выводим дешифрованный текст
    cout << "Дешифрованный текст: " << decryptedText << endl;

    return 0;
}