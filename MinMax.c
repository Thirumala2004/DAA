#include <stdio.h>
void minmax(int a[], int l, int r, int *max, int *min) {
    int mid, max1, min1;
    if (l == r) { 
        *max = *min = a[l];
        return;
    }
    if (l == r - 1) {
        if (a[l] > a[r]) {
            *max = a[l];
            *min = a[r];
        } else {
            *max = a[r];
            *min = a[l];
        }
        return;
    }
    mid = (l + r) / 2;
    minmax(a, l, mid, max, min);
    minmax(a, mid + 1, r, &max1, &min1);
    if (*max < max1) *max = max1;
    if (*min > min1) *min = min1;
}
int main() {
    int n, a[10], min, max;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter array elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    minmax(a, 0, n - 1, &max, &min);
    printf("Maximum element in the array: %d\n", max);
    printf("Minimum element in the array: %d\n", min);
    return 0;
}
