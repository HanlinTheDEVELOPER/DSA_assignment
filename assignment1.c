#include <stdio.h>

int main() {
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    int size = 10;
    int column = 2;

    for (a = 0; a < size; a++) {
        for (d = 0; d < column; d++) {
            for (b = 0; b < size - a; b++) {
                printf(" ");
            }
            for (c = 0; c <= a * 2; c++) {
                printf("*");
            }
            for (b = 0; b < size - a; b++) {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
