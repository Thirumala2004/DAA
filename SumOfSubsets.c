#include<stdio.h>
#define MAX 100
int w[MAX], x[MAX], n, m;
void SumOfSub(int s, int k, int r) {
    x[k] = 1;
    if(s + w[k] == m) {
        printf("{");
        for(int i = 0; i <= k; i++) {
            if(x[i])
                printf("%d ", w[i]);
        }
        printf("}\n");
    }
    else if(s + w[k] + w[k + 1] <= m && k + 1 < n) {
        SumOfSub(s + w[k], k + 1, r - w[k]);
    }
    if(s + r - w[k] >= m && s + w[k + 1] <= m && k + 1 < n) {
        x[k] = 0;
        SumOfSub(s, k + 1, r - w[k]);
    }
}
void main() {
    int r = 0;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements in non-decreasing order: ", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
        r += w[i];
    }
    printf("Enter target sum (m): ");
    scanf("%d", &m);
    printf("Subsets with sum %d are:\n", m);
    SumOfSub(0, 0, r);
}
