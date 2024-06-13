#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <tuple>
#include <fstream>

using namespace std;

pair<vector<int>, string> init() {
    string input_key;
    vector<int> init_key;

    cout << "Введите ключ: ";
    getline(cin, input_key);

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

    tie(shifts, message) = init();

    string result = "";

    int shift_size = shifts.size();

    for (size_t i = 0; i < message.size(); ++i) {
        char c = message[i];
        int shift = shifts[i % shift_size];

        result += char((c + shift) % 256); // Используем модуль 256 для всех символов ASCII
    }

    wride_text(result);
}

void caesarDecipher() {
    string message;
    vector<int> shifts;

    tie(shifts, message) = init();

    string result = "";
    int shift_size = shifts.size();

    for (size_t i = 0; i < message.size(); ++i) {
        char c = message[i];
        int shift = shifts[i % shift_size];

        result += char((c - shift + 256) % 256);
    }

    wride_text(result);
}