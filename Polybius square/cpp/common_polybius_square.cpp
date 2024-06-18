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