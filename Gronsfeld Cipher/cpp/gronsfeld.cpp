#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <tuple>
#include <fstream>
#include <cctype>

using namespace std;


pair<vector<int>, string> init_gronsfeld() {
    string input_key;
    vector<int> init_key;

    cout << "Введите ключ: ";
    getline(cin, input_key);

    bool valid_key = true;

    // Проверяем, что в ключе содержатся только цифры
    for (char ch : input_key) {
        if (!isdigit(ch)) {
            valid_key = false;
            break;
        }
    }

    if (!valid_key) {
        cout << "Ошибка: Ключ должен состоять только из цифр. Пожалуйста, введите ключ заново." << endl;
        return init_gronsfeld(); // Рекурсивно вызываем функцию для повторного ввода
    }

    istringstream stream(input_key);

    char ch;
    while (stream >> ch) {
        if (isdigit(ch)) {
            int num = ch - '0';
            init_key.push_back(num);
        }
    }

    string text;

    cout << "Введите текст: ";
    getline(cin, text);

    return {init_key, text};
}

void wride_text(string text) {
    ofstream outputFile("ciphertext.txt");
    if (outputFile.is_open()) {
        for (unsigned char ch : text) {
            outputFile << ch;
        }

        outputFile.close();

        cout << "Текст успешно записан в файл ciphertext.txt" << endl;
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