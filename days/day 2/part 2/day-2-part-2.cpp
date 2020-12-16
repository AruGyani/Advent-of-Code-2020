#include <fstream>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main() {
    ifstream input;

    input.open("input.txt");

    if (input) {
        string line;

        int index1, index2;
        string element;
        string password;

        int valid = 0;

        while (getline(input, line)) {
            index1 = stoi(line.substr(0, line.find("-")));
            index2 = stoi(line.substr(line.find("-") + 1, line.find("-") + 1));

            index1 -= 1;
            index2 -= 1;

            string pos = line.substr(line.find("-") + 1, line.find("-") + 1);
            string delim = ":";
            element = line.substr(line.find(delim) - delim.size())[0];
            password = line.substr(line.find(delim) + delim.size() + 1);

            if (password[index1] == element[0] && !(password[index2] == element[0])) {
                valid++;
            } else if (password[index2] == element[0] && !(password[index1] == element[0])) {
                valid++;
            }
        }

        cout << valid << endl;

        input.close();
    } else {
        cout << "There was an error opening the input file."  << endl;
    }

    return 0;
}