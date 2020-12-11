#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input/input11.txt", "r", stdin); //harus 2 digit. kek input_01.txt input_02.txt
    freopen("output/output11.txt", "w", stdout);

    int nTest;
    cin >> nTest;

    for (int i = 0; i < nTest; i++) {
        string firstRNA, secondRNA;
        cin >> firstRNA >> secondRNA;
        //convert salah satu biar jadi pasangannya
        for (int j = 0; j < firstRNA.length(); j++) {
            switch (firstRNA.at(j)) {
            case 'A':
                firstRNA.replace(j, 1, "T");
                break;
            case 'T':
                firstRNA.replace(j, 1, "A");
                break;
            case 'C':
                firstRNA.replace(j, 1, "G");
                break;
            case 'G':
                firstRNA.replace(j, 1, "C");
                break;
            }
        }
        if (secondRNA.find(firstRNA) != -1) {
            cout << "Bisa" << endl;
        } else {
            cout << "Tidak Bisa" << endl;
        }
    }
    return 0;
}
