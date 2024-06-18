#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> getIntAsciiValues(const string& text) {
    vector<int> asciiValues;

    for (char character : text) {
        int asciiCode = static_cast<int>(character);
        asciiValues.push_back(asciiCode);
    }

    return asciiValues;
}

string getChar(const vector<int>& asciiValues) {
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

vector<vector<int>> encryptSequence(const vector<vector<int>>& sequences) {
    vector<vector<int>> encryptedSequences;

    for (const auto& sequence : sequences) {

        vector<int> encryptedSequence;
        encryptedSequence.push_back(sequence[0]);

        for (size_t i = 1; i < sequence.size(); ++i) {
            if (sequence[i] == sequence[i - 1]) {
                encryptedSequence.push_back(1);
            } else {
                encryptedSequence.push_back(0);
            }
        }

        encryptedSequences.push_back(encryptedSequence);
    }

    return encryptedSequences;
}

vector<vector<int>> decryptSequence(const vector<vector<int>>& encryptedSequences) {
    vector<vector<int>> decryptedSequences;

    for (const auto& encryptedSequence : encryptedSequences) {
        vector<int> decryptedSequence;
        decryptedSequence.push_back(encryptedSequence[0]);

        for (size_t i = 1; i < encryptedSequence.size(); ++i) {
            if (encryptedSequence[i] == 1) {
                decryptedSequence.push_back(decryptedSequence.back());
            } 
            
            else {
                decryptedSequence.push_back(1 - decryptedSequence.back());
            }
        }

        decryptedSequences.push_back(decryptedSequence);
    }

    return decryptedSequences;
}

int main() {
    string inputText;

    cout << "Введите текст: ";
    getline(cin, inputText);

    vector<int> asciiValues = getIntAsciiValues(inputText);

    // Шаг 2: Переводим ASCII коды в двоичные представления
    vector<vector<int>> binaryVectors = decimalToBinary(asciiValues);

    // Шаг 3: Шифруем последовательности двоичных чисел
    vector<vector<int>> encryptedSequences = encryptSequence(binaryVectors);

    // Шаг 4: Дешифруем зашифрованные последовательности
    vector<vector<int>> decryptedBinaryVectors = decryptSequence(encryptedSequences);

    // Шаг 5: Переводим дешифрованные двоичные представления обратно в ASCII коды
    vector<int> decryptedAsciiValues = binaryVectorsToDecimal(decryptedBinaryVectors);

    // Шаг 6: Получаем строку из дешифрованных ASCII кодов
    string decryptedText = getChar(decryptedAsciiValues);

    // Выводим результаты
    cout << "Исходные ASCII коды: ";
    for (int num : asciiValues) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Зашифрованные последовательности: " << endl;
    for (const auto& sequence : encryptedSequences) {
        for (int num : sequence) {
            cout << num << " ";
        }
        cout << endl;
    }

    cout << "Дешифрованные ASCII коды: ";
    for (int num : decryptedAsciiValues) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Дешифрованный текст: " << decryptedText << endl;

    return 0;
}