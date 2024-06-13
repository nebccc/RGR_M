#pragma once

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> getIntAsciiValues(const string& text);
string getCharAsciiValues(const vector<int>& asciiValues);
vector<vector<int>> decimalToBinary(const vector<int>& nums);
int binaryToDecimal(const vector<int>& binary);
vector<int> binaryVectorsToDecimal(const vector<vector<int>>& binaryVectors);