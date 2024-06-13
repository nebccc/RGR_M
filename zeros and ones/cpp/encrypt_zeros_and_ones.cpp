#include <iostream>
#include <vector>

#include "../include/common_zeros_and_ones.h"

vector<vector<int>> encryptSequence(const vector<vector<int>>& sequences) {
    vector<vector<int>> encryptedSequences;

    for (const auto& sequence : sequences) {
        vector<int> encryptedSequence;

        encryptedSequence.push_back(sequence[0]);

        for (size_t i = 1; i < sequence.size(); ++i) {
            if (sequence[i] == sequence[i - 1]) {
                encryptedSequence.push_back(1);
            } 
            
            else {
                encryptedSequence.push_back(0);
            }
        }

        encryptedSequences.push_back(encryptedSequence);
    }

    return encryptedSequences;
}

void zero_and_ones_encrypt() {
    string inputText;

    cout << "Введите текст: ";
    getline(cin, inputText);

    vector<int> asciiValues = getIntAsciiValues(inputText);
    vector<vector<int>> binaryVectors = decimalToBinary(asciiValues);
    vector<vector<int>> encryptedSequences = encryptSequence(binaryVectors);
    vector<int> decryptedAsciiValues = binaryVectorsToDecimal(encryptedSequences);
    string text = getCharAsciiValues(decryptedAsciiValues);

    cout << "Зашифрованное сообщение: " << text << endl << endl;
}