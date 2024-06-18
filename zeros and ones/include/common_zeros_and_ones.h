#pragma once

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string init_zeros_and_ones();
void write_text(const string& text);
vector<int> getIntAsciiValues(const string& text);
string getCharAsciiValues(const vector<int>& asciiValues);
vector<vector<int>> decimalToBinary(const vector<int>& nums);
int binaryToDecimal(const vector<int>& binary);
vector<int> binaryVectorsToDecimal(const vector<vector<int>>& binaryVectors);