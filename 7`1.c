#include <stdio.h>
#include <limits.h>

void matrix_chain_multiplication(int dims[], int n, int M[][n+1], int S[][n])
{
	int chain_length; 
	int i;
	int k;
    for ( chain_length = 2; chain_length <= n; chain_length++) {
        for (i = 0; i < n - chain_length + 1; i++) {
            int j = i + chain_length - 1;
            M[i][j] = INT_MAX;
            
            for (k = i; k < j; k++) {
                int cost = M[i][k] + M[k+1][j] + dims[i] * dims[k+1] * dims[j+1];
                if (cost < M[i][j]) {
                    M[i][j] = cost;
                    S[i][j-1] = k;
                }
            }
        }
    }
}

void print_tables(int M[][4], int S[][3], int n)
{
	int i;
	int j;
    printf("M Table:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j <= n; j++) {
            printf(" %5d ", M[i][j]);
        }
        printf("\n");
    }
    
    printf("\nS Table:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf(" %5d ", S[i][j]);
        }
        printf("\n");
    }
}

void optimal_parenthesization(int S[][3], int i, int j, char matrix_names[], char result[])
{
    if (i == j) {
        sprintf(result, "%c", matrix_names[i]);
    } else {
        int split_point = S[i][j - 1];
        char left[100], right[100];
        optimal_parenthesization(S, i, split_point, matrix_names, left);
        optimal_parenthesization(S, split_point + 1, j, matrix_names, right);
        sprintf(result, "(%s %s)", left, right);
    }
}

int main()
{
    int n;
    printf("Enter number of matrices: ");
    scanf("%d", &n);
    int dims[2 * n];
    char matrix_names[n];
    int i;
    for (i = 0; i < n; i++) {
        printf("Enter DIMENSION of A%d: ", i + 1);
        scanf("%d %d", &dims[2 * i], &dims[2 * i + 1]);
        matrix_names[i] = 'A' + i;
    }
    
    int M[n][n+1];
    int S[n][n];
    matrix_chain_multiplication(dims, n, M, S);
    
    printf("\nM Table:\n");
    print_tables(M, S, n);
    
    char optimal_ordering[100];
    optimal_parenthesization(S, 0, n - 1, matrix_names, optimal_ordering);
    printf("\nOptimal parenthesization: %s\n", optimal_ordering);
    printf("The optimal ordering of the given matrices requires %d scalar multiplications.\n", M[0][n - 1]);
    
    return 0;
}
