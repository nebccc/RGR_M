#pragma once

#include <iostream>
#include <string>
#include <unordered_map>
#include <cctype>

using namespace std;

unordered_map<char, string> createPolybiusSquareLatin();
unordered_map<char, string> createPolybiusSquareRussian();
unordered_map<string, char> createReversePolybiusSquare(const unordered_map<char, string>& polybiusSquare);