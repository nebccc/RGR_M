#include <fstream>
#include <string>
#include <iostream>

using namespace std;

void write_text(const string& text) {
    string file_path;

    cout << "Введите путь куда сохранить текст: ";
    getline(cin, file_path);

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