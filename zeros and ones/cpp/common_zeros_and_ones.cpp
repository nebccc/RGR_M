#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string init_zeros_and_ones() {
    string choice, text;

    while(true) {
        cout << "Хотите прочитать данные из файла? (Да/Нет) : ";
        getline(cin, choice);

        transform(choice.begin(), choice.end(), choice.begin(),
            [](unsigned char c) {return tolower(c); });

        if(choice == "да" || choice == "yes" || choice == "д" || choice == "y") {
            string text_file_path;

            cout << "Введите путь к файлу с текстом: ";
            getline(cin, text_file_path);

            ifstream text_file(text_file_path);

            while ((!text_file.is_open()))
            {
                cerr << "Ошибка открытия файла. Пожалуйста, проверьте пути и повторите попытку." << endl;

                cout << "Путь к файлу с текстом: ";
                getline(cin, text_file_path);
                
                ifstream text_file(text_file_path);
            }

            getline(text_file, text);

            text_file.close();

            break;
        }

        else{
            cout << "Введите текст: ";
            getline(cin, text);

            break;
        }
    }

    return text;
}

void write_text(const string& text) {
    string choice;

    cout << "Хотите записать результат в файл? (Да/Нет) : ";
    getline(cin, choice);

    transform(choice.begin(), choice.end(), choice.begin(),
        [](unsigned char c) {return tolower(c); });

    if(choice == "да" || choice == "yes" || choice == "д" || choice == "y") {
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
}

vector<int> getIntAsciiValues(const string& text) {
    vector<int> asciiValues;

    for (char character : text) {
        int asciiCode = static_cast<int>(character);
        asciiValues.push_back(asciiCode);
    }

    return asciiValues;
}

string getCharAsciiValues(const vector<int>& asciiValues) {
    string decodedText;

    for (int ascii : asciiValues) {
        decodedText += static_cast<char>(ascii);
    }

    return decodedText;
}

vector<vector<int>> decimalToBinary(const vector<int>& nums) {
    vector<vector<int>> binarys;

    for (int num : nums) {
        vector<int> binary;

        if (num == 0) {
            binary.push_back(0);
        } else {
            while (num > 0) {
                binary.push_back(num % 2);
                num /= 2;
            }
            reverse(binary.begin(), binary.end());
        }

        binarys.push_back(binary);
    }

    return binarys;
}

int binaryToDecimal(const vector<int>& binary) {
    int decimal = 0;
    int power = 1;

    for (int i = binary.size() - 1; i >= 0; --i) {
        decimal += binary[i] * power;
        power *= 2;
    }

    return decimal;
}

vector<int> binaryVectorsToDecimal(const vector<vector<int>>& binaryVectors) {
    vector<int> decimalNumbers;

    for (const auto& vec : binaryVectors) {
        int decimal = binaryToDecimal(vec);
        decimalNumbers.push_back(decimal);
    }

    return decimalNumbers;
}