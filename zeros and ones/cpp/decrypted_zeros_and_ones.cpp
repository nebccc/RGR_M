#include <iostream>
#include <vector>

#include "../include/common_zeros_and_ones.h"
#include "common/include/common.h"

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

void zero_and_ones_decrypt() {
    string inputText;

    cout << "Введите текст: ";
    getline(cin, inputText);

    vector<int> asciiValues = getIntAsciiValues(inputText);
    vector<vector<int>> binaryVectors = decimalToBinary(asciiValues);
    vector<vector<int>> encryptedSequences = decryptSequence(binaryVectors);
    vector<int> decryptedAsciiValues = binaryVectorsToDecimal(encryptedSequences);
    string text = getCharAsciiValues(decryptedAsciiValues);

    cout << "Расшифрованное сообщение: " << text << endl << endl;
    wride_text(text);
}