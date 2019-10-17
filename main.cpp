#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<char, short unsigned int> letterToInt = {{'I', 1}, {'V', 5}, {'X', 10},
                                                            {'L', 50}, {'C', 100}, {'D', 500},
                                                            {'M', 1000}};
    unordered_map<short unsigned int, char> intToLetter = {{1, 'I'}, {5, 'V'}, {10, 'X'},
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
            unsigned int base = 1;
            switch (line.size()) {
                case 4: base = 1000; break;
                case 3: base = 100; break;
                case 2: base = 10; break;
                case 1: base = 1; break;
            }
            string output;
            for (unsigned long i = line.size() - 1; i >= 0; --i) {
                //cout << "ok" << endl;
                switch (stoi(to_string(line[i]))) {
                    case 1:
                    case 2:
                    case 3:
                        //cout << "ok2" << endl;
                        for (unsigned int j = 0; j < stoi(string(1, line[i])); ++j)
                            output += intToLetter[1 * base];
                        //cout << "ok3" << endl;
                        break;
                    case 4:
                        output += intToLetter[1 * base] + intToLetter[5 * base];
                        break;
                    case 5:
                        output += intToLetter[5 * base];
                        break;
                    case 6:
                    case 7:
                    case 8:
                        output += intToLetter[5 * base];
                        for (unsigned int j = 0; j < stoi(string(1, line[i])) - 5; ++j)
                            output += intToLetter[1 * base];
                        break;
                    case 9:
                        output += intToLetter[1 * base] + intToLetter[10 * base];
                        break;
                }
                if (stoi(to_string(line[i])) < 4) {
                    for (unsigned int j = 0; j < stoi(string(1, line[i])); ++j)
                        output += intToLetter[1 * base];
                }
                base /= 10;
            }
            cout << output << endl;
        }
    }
    //cout << stoi(string(1, '4'));
    return EXIT_SUCCESS;
}
