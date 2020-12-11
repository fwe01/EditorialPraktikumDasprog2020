#include <iostream>
#include <math.h>

using namespace std;

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("output10.txt", "w", stdout); //harus 2 digit. kek input_01.txt input_02.txt

    int inputN;
    cin >> inputN;

    unsigned long long result = 1, offset = 1, offsetIncrement = 1;

    for (int i = 2; i <= inputN; i++) {
        result *= i;
        offset += offsetIncrement;
        offsetIncrement += pow(2, i - 1);
    }

    cout << result + offset << endl;

    return 0;
}
//2432902008177688556