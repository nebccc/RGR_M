#include <iostream>
#include <fstream>
#include <vector>

#include "../include/common_zeros_and_ones.h"

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
    string inputText = init_zeros_and_ones();

    vector<int> asciiValues = getIntAsciiValues(inputText);
    vector<vector<int>> binaryVectors = decimalToBinary(asciiValues);
    vector<vector<int>> encryptedSequences = decryptSequence(binaryVectors);
    vector<int> decryptedAsciiValues = binaryVectorsToDecimal(encryptedSequences);
    string text = getCharAsciiValues(decryptedAsciiValues);

    cout << "Расшифрованное сообщение: " << text << endl << endl;

    write_text(text);

    string exit;

    cout << endl << endl;
    cout << "Выход (q): ";

    cin >> exit;
    
    printf("\033[2J");
    printf("\033[0;0f");
}