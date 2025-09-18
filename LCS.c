#include <stdio.h>
#include <string.h>

#define MAX 100

int cost[MAX][MAX];
char dir[MAX][MAX];

int max(int a, int b) {
    return (a > b) ? a : b;
}

void LCS(char a[], char b[], int m, int n) {
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i - 1] == b[j - 1]) {
                cost[i][j] = cost[i - 1][j - 1] + 1;
                dir[i][j] = 'D';
            } else {
                if (cost[i - 1][j] >= cost[i][j - 1]) {
                    cost[i][j] = cost[i - 1][j];
                    dir[i][j] = 'U';
                } else {
                    cost[i][j] = cost[i][j - 1];
                    dir[i][j] = 'S';
                }
            }
        }
    }
}

void Print_LCS(int i, int j, char a[], int cost[MAX][MAX]) {
    if (i == 0 || j == 0) {
        return;
    }

    if (dir[i][j] == 'D') {
        Print_LCS(i - 1, j - 1, a, cost);
        printf("%c", a[i - 1]);
    } else if (dir[i][j] == 'U') {
        Print_LCS(i - 1, j, a, cost);
    } else {
        Print_LCS(i, j - 1, a, cost);
    }
}

int main() {
    char a[] = "AGCCCTAAGGGCTACCTAGCTT";
    char b[] = "GACAGCCTACAAGCGTTAGCTTG";

    int m = strlen(a);
    int n = strlen(b);

    LCS(a, b, m, n);

    printf("\nLCS: ");
    Print_LCS(m, n, a, cost);
    printf("\n");

    printf("Length of LCS: %d\n", cost[m][n]);

    return 0;
}
