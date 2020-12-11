#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("output06.txt", "w", stdout); //harus 2 digit. kek input_01.txt input_02.txt

    int ntest,
        panjang,
        lebar,
        tipe,
        x,
        y,
        z,
        buff;
    char type;

    // scanf("%d", &ntest);
    cin >> ntest;
    for (x = 1; x <= ntest; x++) {
        // scanf(" %c %d %d", &type, &panjang, &lebar);
        cin >> type >> panjang >> lebar;
        // printf("Testcase-%d\n", x);
        cout << "Testcase-" << x << endl;
        if (type == 'e') {
            tipe = 1;
            for (y = 1; y <= panjang; y++) {
                tipe = y % 2;
                if (tipe == 1) {
                    // printf(" ");
                    cout << " ";
                }
                for (z = 1; z <= lebar; z++) {
                    buff = z % 2;
                    if (buff == 0) {
                        // printf("#");
                        cout << "#";
                    } else {
                        // printf("*");
                        cout << "*";
                    }
                }
                if (x <= ntest || y < panjang) {
                    // printf("\n");
                    cout << endl;
                }
            }
        } else if (type == 'p') {
            for (y = 1; y <= panjang; y++) {
                tipe = y % 2;
                if (tipe != 1) {
                    // printf(" ");
                    cout << " ";
                }
                for (z = 1; z <= lebar; z++) {
                    buff = z % 2;
                    if (buff == 0) {
                        // printf("#");
                        cout << "#";
                    } else {
                        // printf("*");
                        cout << "*";
                    }
                }
                if (x <= ntest || y < panjang) {
                    // printf("\n");
                    cout << endl;
                }
            }
        }
    }
    return 0;
}
// 2 3 7 9 8 5