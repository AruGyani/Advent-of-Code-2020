#include <vector>
#include <fstream>
#include <iostream>

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
        for (int j = i + 1; j < arr.size(); j++) {
            for (int k = j + 1; k < arr.size(); k++) {
                if ((arr[i] + arr[j] + arr[k]) == 2020) cout << arr[i] * arr[j] * arr[k] << endl;
            }
        }
    }

    return 0;
}