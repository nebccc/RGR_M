#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <cctype>
#include <fstream>

using namespace std;

string init_polybius_square() {
    string choice, text;

    cout << "Хотите считать данные с файла? (Да/Нет): ";
    getline(cin, choice);

    transform(choice.begin(), choice.end(), choice.begin(),
        [](unsigned char c) {return tolower(c); });

    if(choice == "да" || choice == "yes" || choice == "д" || choice == "y") {
        string text_file_path;

        cout << "Введите путь до файла с текстом: ";
        getline(cin, text_file_path);

        ifstream text_file(text_file_path);

        while((!text_file.is_open())) {
            cerr << "Ошибка открытия файла. Пожалуйста, проверьте пути и повторите попытку." << endl;

            cout << "Введите путь до файла с текстом: ";
            getline(cin, text_file_path);

            ifstream text_file(text_file_path);
        }

        getline(text_file, text);
    }

    else{
        cout << "Введите текст: ";
        getline(cin, text);
    }

    return text;
}

void save_polybius_square(string text) {
    string choice;
    cout << "Хотите сохранить зашитфрованное сообщение в файл? (Да/Нет): ";

    cin >> choice;
    cin.ignore();

    transform(choice.begin(), choice.end(), choice.begin(),
        [](unsigned char c) {return tolower(c); });

    if(choice == "да" || choice == "yes" || choice == "д" || choice == "y") {
        string file_path;

        cout << "Введите путь куда сохранить текст: ";

        getline(cin, file_path);
        cin.ignore();

        ofstream file(file_path);
        if (file.is_open()) {
            file << text;
            
            file.close();
            cout << "Текст успешно записан в файл." << endl;
        } 
        
        else {
            cout << "Не удалось открыть файл." << endl;
        }
    }
}

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