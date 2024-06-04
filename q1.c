#include <stdio.h>

int gcd(int num1, int num2) {
    if (num2 == 0) {
        return num1;
    } else {
        return gcd(num2, num1 % num2);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s ins.dat outp.dat\n", argv[0]);
        return 1;
    }

    FILE *sourceFile = fopen(argv[1], "r");
    FILE *destFile = fopen(argv[2], "w");

    if (!sourceFile || !destFile) {
        printf("Error opening files.\n");
        return 1;
    }

    int num1, num2;
    while (fscanf(sourceFile, "%d %d", &num1, &num2) != EOF) {
        int result = gcd(num1, num2);
        fprintf(destFile, "The GCD of %d and %d is %d\n", num1, num2, result);
    }

    fclose(sourceFile);
    fclose(destFile);

    return 0;
}

