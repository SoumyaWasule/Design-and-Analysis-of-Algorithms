#include <stdio.h>
#include <string.h>

#define MAX 100

int cost[MAX][MAX];
char dir[MAX][MAX];

void LRS(char a[], int n) {

    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i - 1] == a[j - 1] && i != j) {
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

void Print_LRS(int i, int j, char a[], int cost[MAX][MAX]) {
    if (i == 0 || j == 0) {
        return;
    }

    if (dir[i][j] == 'D') {
        Print_LRS(i - 1, j - 1, a, cost);
        printf("%c", a[i - 1]);
    } else if (dir[i][j] == 'U') {
        Print_LRS(i - 1, j, a, cost);
    } else {
        Print_LRS(i, j - 1, a, cost);
    }
}

int main() {
    char a[] = "AABCBDC";
    int n = strlen(a);

    LRS(a, n);
    
    printf("\nLRS: ");
    Print_LRS(n, n, a, cost);
    printf("\n");

    printf("Length of LRS: %d\n", cost[n][n]);

    return 0;
}
