#include <iostream>
#include <stdio.h>
//#include <math.h>
//https://ideone.com/VfrMk8

using namespace std;

int N, i, j, k, q, x1, yk, z1, x2, y2, z2, z, add, type, ntest, temp = 0, sum = 0;
int cube[201][201][201],
    A[201][201] = {}, //Y DAN Z NYA
    B[201][201] = {}, //X DAN Z NYA
    C[201][201] = {}; //X DAN Y NYA

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("output/output6.txt", "w", stdout); //harus 2 digit. kek input_01.txt input_02.txt
    freopen("input/input6.txt", "r", stdin);
    // scanf("%d", &N);
    cin >> N;

    //ambil input datanya
    for (i = 1; i <= N; i++) {
        for (j = 1; j <= N; j++) {
            for (k = 1; k <= N; k++) {
                // scanf("%d", &temp);
                cin >> temp;
                cube[i][j][k] = temp;
                sum += temp;
                A[j][k] += temp;
                B[i][j] += temp;
                C[i][k] += temp;
            }
        }
    }
    // scanf("%d", &ntest);
    cin >> ntest;
    for (q = 0; q < ntest; q++) {
        temp = 0;
        // scanf("%d", &type);
        cin >> type;
        if (type == 1) {
            // scanf("%d %d %d %d", &x1, &yk, &z1, &add);
            cin >> x1 >> yk >> z1 >> add;
            sum += (add - cube[x1][yk][z1]);
            A[yk][z1] += (add - cube[x1][yk][z1]);
            B[x1][yk] += (add - cube[x1][yk][z1]);
            C[x1][z1] += (add - cube[x1][yk][z1]);
            cube[x1][yk][z1] = add; //bener diganti
        } else if (type == 2) {
            // scanf("%d %d %d %d %d %d", &x1, &yk, &z1, &x2, &y2, &z2);
            cin >> x1 >> yk >> z1 >> x2 >> y2 >> z2;
            //tuker A B C
            A[yk][z1] += (cube[x2][y2][z2] - cube[x1][yk][z1]);
            A[y2][z2] += (cube[x1][yk][z1] - cube[x2][y2][z2]);
            B[x1][yk] += (cube[x2][y2][z2] - cube[x1][yk][z1]);
            B[x2][y2] += (cube[x1][yk][z1] - cube[x2][y2][z2]);
            C[x1][z1] += (cube[x2][y2][z2] - cube[x1][yk][z1]);
            C[x2][z2] += (cube[x1][yk][z1] - cube[x2][y2][z2]);
            z = cube[x1][yk][z1];
            cube[x1][yk][z1] = cube[x2][y2][z2];
            cube[x2][y2][z2] = z;
        } else if (type == 3) {
            temp = sum;
            // scanf("%d %d %d", &x1, &yk, &z1);
            cin >> x1 >> yk >> z1;
            temp = sum;
            temp -= (A[yk][z1] + B[x1][yk] + C[x1][z1]);
            temp += 2 * cube[x1][yk][z1];
            // printf("%d\n", temp);
            cout << temp << endl;
        }
    }
    return (0);
}
