#include <bits/stdc++.h>
#define MOD 100000007
using namespace std;

unsigned long long factorials[1005];

void buildFactorial() {
    for (int i = 0; i <= 1000; i++) {
        if (i == 0 || i == 1) {
            factorials[i] = 1;
        } else {
            factorials[i] = ((factorials[i - 1] % MOD) * (i % MOD)) % MOD;
        }
    }
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("input/input12.txt", "r", stdin); //harus 2 digit. kek input_01.txt input_02.txt
    // freopen("output/output12.txt", "w", stdout);

    buildFactorial();

    unsigned long long nTest;
    cin >> nTest;

    for (unsigned long long i = 0; i < nTest; i++) {
        int temp;
        cin >> temp;
        cout << factorials[temp] << endl;
    }
    return 0;
}
