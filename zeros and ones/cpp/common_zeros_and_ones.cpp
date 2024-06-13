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