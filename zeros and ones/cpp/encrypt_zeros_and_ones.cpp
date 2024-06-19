#include <iostream>
#include <fstream>
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
    string inputText = init_zeros_and_ones();

    vector<int> asciiValues = getIntAsciiValues(inputText);
    vector<vector<int>> binaryVectors = decimalToBinary(asciiValues);
    vector<vector<int>> encryptedSequences = encryptSequence(binaryVectors);
    vector<int> decryptedAsciiValues = binaryVectorsToDecimal(encryptedSequences);
    string text = getCharAsciiValues(decryptedAsciiValues);

    for(auto row : encryptedSequences) {
        for(int num : row) {
            cout << num;
        }
        cout << endl;
    }

    cout << "Зашифрованное сообщение: " << text << endl << endl;

    write_text(text);

    string exit;

    cout << endl << endl;
    cout << "Выход (q): ";

    cin >> exit;
    
    printf("\033[2J");
    printf("\033[0;0f");
}