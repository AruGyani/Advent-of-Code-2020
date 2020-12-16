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

        int min, max;
        string element;
        string password;

        int valid = 0;

        while (getline(input, line)) {
            int occurrences = 0;
            min = stoi(line.substr(0, line.find("-")));
            max = stoi(line.substr(line.find("-") + 1, line.find("-") + 1));
            string pos = line.substr(line.find("-") + 1, line.find("-") + 1);
            string delim = ":";
            element = line.substr(line.find(delim) - delim.size())[0];
            password = line.substr(line.find(delim) + delim.size() + 1);

            for (int i = 0; i < password.size(); i++) {
                if (password[i] == element[0]) {
                    occurrences++;
                }
            }

            if (occurrences >= min && occurrences <= max) valid++;
        }

        cout << valid << endl;

        input.close();
    } else {
        cout << "There was an error opening the input file."  << endl;
    }

    return 0;
}