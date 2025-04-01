#include <stdio.h>
#include <stdlib.h>
int optimalMerge(int files[], int n)
{
    int cost = 0;
    int mergeCount = 1; 
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (files[j] > files[j + 1]) {
                int temp = files[j];
                files[j] = files[j + 1];
                files[j + 1] = temp;
            }
        }
    }
    while (n > 1) {
        int mergedFileSize = files[0] + files[1];
        cost += mergedFileSize;
        printf("Merge move %d: new root weight = %d\n", mergeCount, mergedFileSize);
        mergeCount++;
        for (int i = 1; i < n - 1; i++) {
            files[i] = files[i + 1];
        }
        files[0] = mergedFileSize;
        n--; 
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (files[j] > files[j + 1]) {
                    int temp = files[j];
                    files[j] = files[j + 1];
                    files[j + 1] = temp;
                }
            }
        }
    }
    return cost;
}
int main()
{
    int no;
    printf("Enter the number of files: ");
    scanf("%d", &no);
    int files[no];
    printf("Enter the file sizes:\n");
    for (int i = 0; i < no; i++) {
        scanf("%d", &files[i]);
    }
    int minCost = optimalMerge(files, no);
    printf("\nTotal sum of all root weights during merge: %d\n", minCost);
    return 0;
}
