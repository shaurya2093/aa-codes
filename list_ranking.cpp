#include <iostream>

using namespace std;

void listRanking(int inputList[], int ranks[], int n) {
    
    for (int i = 0; i < n; ++i) {
        ranks[i] = 0;     }

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (inputList[j] < inputList[i]) {
                ranks[i]++;
            } else {
                ranks[j]++;
            }
        }
    }
}

int main() {
    int inputList[] = {5, 2, 7, 3, 1, 6, 4};
    int n = sizeof(inputList) / sizeof(inputList[0]);

    int ranks[n];

    listRanking(inputList, ranks, n);

    cout << "Input List: ";
    for (int i = 0; i < n; ++i) {
        cout << inputList[i] << " ";
    }
    cout << endl;

    cout << "Ranks: ";
    for (int i = 0; i < n; ++i) {
        cout << ranks[i] << " ";
    }
    cout << endl;

    return 0;
}