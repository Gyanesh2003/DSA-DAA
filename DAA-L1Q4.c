#include <stdio.h>

void ROTATE_RIGHT(int *p1, int p2)
 {  int i;
    int j;
    int temp;
    for(j = 0; j < p2; j++) 
	{
        temp = p1[p2 - 1];
        for(i = p2 - 1; i > 0; i--) 
		{
        p1[i] = p1[i - 1];
        }
        p1[0] = temp;
    }
}
int main() 
{
    int A[10] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int i;
    printf("Before ROTATE:\n");
    for (i = 0; i < 10; i++) 
	{
        printf("%d ", A[i]);
    }
    printf("\n");
    ROTATE_RIGHT(A, 5);
    printf("After ROTATE:\n");
    for (i = 0; i < 10; i++) 
	{
        printf("%d ", A[i]);
    }
    printf("\n");
    return 0;
}

