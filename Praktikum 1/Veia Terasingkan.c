#include <math.h>
#include <stdio.h>

int main(void) {
    int ntest,
        p,
        x,
        y,
        z,
        a;
    unsigned long long number;
    // FILE *fileOut;
    // fileOut = fopen("output_nomor10.txt", "w");
    scanf("%d", &ntest);
    for (x = 1; x <= ntest; x++) {
        scanf("%llu", &number);
        z = number;
        a = 0;
        p = 0;
        // fprintf(fileOut, "Testcase #%d : ", x);
        printf("Testcase #%d : ", x);
        // fprintf(fileOut, "0");
        printf("0");

        for (y = 32; y >= 0; y--) {
            z = z - pow(2, y);
            if (z < 0 && a == 0) {
                z = number;
            } else if (z >= 0) {
                a = 1;
                p = z;
                // fprintf(fileOut, "1");
                printf("1");
            } else if (z < 0 && a == 1) {
                z = p;
                // fprintf(fileOut, "0");
                printf("0");
            }
        }
        // fprintf(fileOut, "\n");
        printf("\n");
    }
    return 0;
}
// 4294967294
// 2147483647