#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ifstream inputFile;

    inputFile.open("input.txt");

    vector<int> arr;

    if (inputFile) {
        int num;
        while (inputFile >> num) {
            arr.push_back(num);
        }

        inputFile.close();
    } else {
        cout << "There was an error opening the input file." << endl;
    }

    for (int i = 0; i < arr.size(); i++) {
        bool funcBreak = false;

        for (int j = arr.size() - 1; j > 0; j--) {
            if (arr.at(i) + arr.at(j) == 2020) {
                cout << arr.at(i) * arr.at(j) << endl;
                funcBreak = true;
            }
        }

        if (funcBreak) break;
    }

    return 0;
}