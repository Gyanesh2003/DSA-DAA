#include <stdio.h>
#include<stdlib.h>
void decToBinary(int n, FILE *destFile) {
    if (n == 0) {
        return;
    }

    decToBinary(n / 2, destFile);

    fprintf(destFile, "%d", n % 2);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s inp.dat out.dat\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    FILE *sourceFile = fopen(argv[2], "r");
    FILE *destFile = fopen(argv[3], "w");

    if (!sourceFile || !destFile) {
        printf("Error opening files.\n");
        return 1;
    }

    int decimalNum;
    while (fscanf(sourceFile, "%d", &decimalNum) != EOF) {
        fprintf(destFile, "The binary equivalent of %d is ", decimalNum);
        decToBinary(decimalNum, destFile);
        fprintf(destFile, "\n");
    }

    fclose(sourceFile);
    fclose(destFile);

    return 0;
}
