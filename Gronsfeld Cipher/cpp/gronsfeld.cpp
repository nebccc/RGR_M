#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <tuple>
#include <fstream>
#include <cctype>

using namespace std;


pair<vector<int>, string> init_gronsfeld() {
    string choice, key, text;
    vector<int> key_nums;

    cout << "Хотите считать данные с файла? (Да/Нет): ";
    getline(cin, choice);

    transform(choice.begin(), choice.end(), choice.begin(),
        [](unsigned char c) {return tolower(c); });

    if(choice == "да" || choice == "yes" || choice == "д" || choice == "y") {
        string key_file_path, text_file_path;

        cout << "Введите путь до ключа: ";
        getline(cin, key_file_path);

        ifstream key_file(key_file_path);

        while((!key_file.is_open())) {
            cerr << "Ошибка открытия файла. Пожалуйста, проверьте пути и повторите попытку." << endl;

            cout << "Введите путь до ключа: ";
            getline(cin, key_file_path);

            ifstream key_file(key_file_path);
        }

        getline(key_file, key);

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

        istringstream stream(key);

        char ch;
        while(stream >> ch) {
            int num = ch - '0';
            key_nums.push_back(num);
        }
    }

    else{
        cout << "Введите ключ: ";
        getline(cin, key);

        istringstream stream(key);

        char ch;
        while(stream >> ch) {
            int num = ch - '0';
            key_nums.push_back(num);
        }

        cout << "Введите текст: ";
        getline(cin, text);
    }

    return {key_nums, text};
}

void wride_text(string text) {
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

void caesarCipher() {
    string message;
    vector<int> shifts;

    tie(shifts, message) = init_gronsfeld();

    string result = "";

    int shift_size = shifts.size();

    for (size_t i = 0; i < message.size(); ++i) {
        char c = message[i];
        int shift = shifts[i % shift_size];

        result += char((c + shift) % 256); // Используем модуль 256 для всех символов ASCII
    }

    cout << "Зашифрованное сообщение: " << result << endl;

    wride_text(result);

    string exit;
    cin >> exit;
}

void caesarDecipher() {
    string message;
    vector<int> shifts;

    tie(shifts, message) = init_gronsfeld();

    string result = "";
    int shift_size = shifts.size();

    for (size_t i = 0; i < message.size(); ++i) {
        char c = message[i];
        int shift = shifts[i % shift_size];

        result += char((c - shift + 256) % 256);
    }

    cout << "Расшифрованный текст: " << result << endl;

    wride_text(result);

    string exit;
    cin >> exit;
}