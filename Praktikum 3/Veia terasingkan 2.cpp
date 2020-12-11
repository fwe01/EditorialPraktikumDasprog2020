#include <bits/stdc++.h>
#define W 10001
#define X 10002
#define V 10003
#define DOT 10004

using namespace std;

int veiaX, veiaY, width, length, wormX, wormY;
int maps[100][100];

void Place_steps(int x, int y, int step) {

    //check if the map[y][x] contain C or T or X
    if (maps[y][x] == X ||
        //maps[y][x] == X ||
        x >= width || y >= length || x < 0 || y < 0 || step >= maps[y][x]) {
        //go back to the calling function
        return;
    } else if (maps[y][x] == W || maps[y][x] == DOT || step < maps[y][x]) {
        maps[y][x] = step;
    }

    Place_steps(x + 1, y + 1, step + 1);
    Place_steps(x - 1, y + 1, step + 1);
    Place_steps(x + 1, y - 1, step + 1);
    Place_steps(x - 1, y - 1, step + 1);
    return;
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input/input1.txt", "r", stdin); //harus 2 digit. kek input_01.txt input_02.txt
    freopen("output/output1.txt", "w", stdout);

    cin >> length >> width;

    for (int i = 0; i < length; i++) {
        for (int j = 0; j < width; j++) {
            char temp;
            cin >> temp;
            if (temp == 'V') {
                veiaX = j;
                veiaY = i;
                maps[i][j] = V;
            } else if (temp == '.') {
                maps[i][j] = DOT;
            } else if (temp == 'X') {
                maps[i][j] = X;
            } else if (temp == 'W') {
                wormX = j;
                wormY = i;
                maps[i][j] = W;
            }
        }
    }

    Place_steps(veiaX, veiaY, 0);

    //debug
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < width; j++) {
            printf("%6d ", maps[i][j]);
        }
        printf("\n");
    }

    if (maps[wormY][wormX] == W) {
        cout << "Veia harus menunggu 100 tahun lagi" << endl;
    } else {
        cout << "Jarak yang harus ditempuh Veia adalah " << maps[wormY][wormX] << " parsecs\n";
    }

    return 0;
}

/*
4 4
. . . V
. . . X
. X X X
. . . W

4 4
. . . V
. . . .
. X . .
. . . W

4 4
. . . V
. . . .
. X . .
. . W . 
*/
