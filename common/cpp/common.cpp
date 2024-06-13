#include <fstream>
#include <string>
#include <iostream>

using namespace std;

void wride_text(string text) {
    ofstream outputFile("ciphertext.txt");
    if (outputFile.is_open()) {
        for (unsigned char ch : text) {
            outputFile << ch;
        }

        outputFile.close();

        cout << "Зашифрованный текст успешно записан в файл ciphertext.txt" << endl;
    }
}