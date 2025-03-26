#include<stdio.h>
#include<stdbool.h>
#define MAX 100
int n, m;
int G[MAX][MAX], x[MAX], mincolors = MAX;
int solutions[MAX][MAX], solcount = 0;

bool isSafe(int k, int c) {
    for(int j = 1; j <= n; j++) {
        if(G[k][j] && x[j] == c)
            return false;
    }
    return true;
}

void NextValue(int k) {
    do {
        x[k] = (x[k] + 1) % (m + 1);
        if(x[k] == 0) return;
    } while(!isSafe(k, x[k]));
}

void mColoring(int k) {
    do {
        NextValue(k);
        if(x[k] == 0) return;
        if(k == n) {
            int colorset[MAX] = {0};
            int usedcolors = 0;
            for(int i = 1; i <= n; i++) {
                if(colorset[x[i]] == 0) {
                    colorset[x[i]] = 1;
                    usedcolors++;
                }
            }
            for(int i = 1; i <= n; i++) {
                printf("%d ", x[i]);
            }
            printf(" listed colors: %d\n", usedcolors);
            if(usedcolors < mincolors) {
                mincolors = usedcolors;
                solcount = 0;
            }
            if(usedcolors == mincolors) {
                for(int i = 1; i <= n; i++) {
                    solutions[solcount][i] = x[i];
                }
                solcount++;
            }
        } else {
            mColoring(k + 1);
        }
    } while(true);
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of colors: ");
    scanf("%d", &m);
    printf("Enter adjacency matrix:\n");
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            scanf("%d", &G[i][j]);
        }
    }
    for(int i = 1; i <= n; i++) {
        x[i] = 0;
    }
    printf("All coloring solutions:\n");
    mColoring(1);
    printf("Minimal coloring solutions (used %d colors):\n", mincolors);
    for(int i = 0; i < solcount; i++) {
        for(int j = 1; j <= n; j++) {
            printf("%d ", solutions[i][j]);
        }
        printf("\n");
    }
    return 0;
}
