#include <stdio.h>
#include <string.h>

int lcs(char *X, char *Y, int m, int n, char *LCS)
{
    int L[m + 1][n + 1];
    int i;
    int j;
    for (i = 0; i <= m; i++) {
        for (j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                L[i][j] = 0;
            } else if (X[i - 1] == Y[j - 1]) {
                L[i][j] = L[i - 1][j - 1] + 1;
            } else {
                L[i][j] = (L[i - 1][j] > L[i][j - 1]) ? L[i - 1][j] : L[i][j - 1];
            }
        }
    }
    int index = L[m][n];
    LCS[index] = '\0';
    i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            LCS[--index] = X[i - 1];
            i--;
            j--;
        } else if (L[i - 1][j] > L[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    return L[m][n];
}

int main()
{
    char X[100], Y[100];
    char LCS[100];
    
    printf("Enter the first string into an array: ");
    scanf("%s", X);
    
    printf("Enter the second string into an array: ");
    scanf("%s", Y);
    
    int m = strlen(X);
    int n = strlen(Y);

    int length = lcs(X, Y, m, n, LCS);

    printf("\nLCS: %s\n", LCS);
    printf("LCS Length: %d\n", length);

    return 0;
}
