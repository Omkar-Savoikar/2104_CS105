/*
    AUTHOR: MCA.2104
    PROGRAM: COIN CHANGE
    DATE CREATED: 04 JAN 2022
    DATE MODIFIED: 04 JAN 2022
*/
//APPLICATION DEVELOPER
#include<stdio.h>
#include<conio.h>

void main() {
    int n, A, den[10], C[10][50];
    int i, j, temp, min;
    printf("\nEnter the number of denominations: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        printf("\nEnter denomination %d: ", i+1);
        scanf("%d", &den[i]);
    }
    printf("\nEnter the amount: ");
    scanf("%d", &A);
    for (i = 0; i <= A; i++)
        C[n-1][i] = i;
    for (i = n-2; i >= 0; i--)
        for (j = 0; j <= A; j++) {
            if (den[i] > j)
                C[i][j] = C[i+1][j];
            else
                C[i][j] = (C[i+1][j] < (1 + C[i][j - den[i]]) ) ? C[i+1][j] : (1 + C[i][j - den[i]]);
        }
    printf("\nDenominations:");
    for (i = 0; i < n; i++) {
        printf("\n%d = %d", den[i], C[i][A]);
    }
}