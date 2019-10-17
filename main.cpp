#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

typedef unsigned int ui;

int main() {
    unordered_map<char, ui> letterToInt = {{'I', 1}, {'V', 5}, {'X', 10},
                                                            {'L', 50}, {'C', 100}, {'D', 500},
                                                            {'M', 1000}};
    unordered_map<ui, char> intToLetter = {{1, 'I'}, {5, 'V'}, {10, 'X'},
                                                           {50, 'L'}, {100, 'C'}, {500, 'D'},
                                                           {1000, 'M'}};
    string line = "line";
    while (cin >> line) {
        if (isalpha(line[0])) {
            int output = 0;
            for (unsigned long i = 0; i < line.size(); ++i) {
                if (letterToInt[line[i + 1]] > letterToInt[line[i]]) {
                    output += letterToInt[line[i + 1]] - letterToInt[line[i]];
                    ++i;
                }
                else
                    output += letterToInt[line[i]];
            }
            cout << output << endl;
        } else {
            unsigned int base;
            switch (line.size()) {
                case 4: base = 1000; break;
                case 3: base = 100; break;
                case 2: base = 10; break;
                case 1: base = 1; break;
            }
            string output;
            for (char i : line) {
                ui iValue = int(i) - '0';
                if (iValue < 4) {
                    for (ui j = 0; j < iValue; ++j)
                        output += intToLetter[1 * base];
                } else if (iValue == 4) {
                    output += intToLetter[1 * base];
                    output += intToLetter[5 * base];
                } else if (iValue == 5) {
                    output += intToLetter[5 * base];
                } else if (iValue > 5 and iValue < 9) {
                    output += intToLetter[5 * base];
                    for (ui j = 0; j < iValue - 5; ++j) {
                        output += intToLetter[1 * base];
                    }
                } else if (iValue == 9) {
                    output += intToLetter[1 * base];
                    output += intToLetter[10 * base];
                }
                base /= 10;
            }
            cout << output << endl;
        }
    }
    return EXIT_SUCCESS;
}
