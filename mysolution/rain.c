#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

int main() {
    int n;
    scanf("%d", &n);
    int rain[1100000];
    for (int i = 0; i < n; i++) {
        scanf("%d", &rain[i]);
    }

    qsort(rain, n, sizeof(int), compare);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (rain[i] >= i + 1) {
            ans = i + 1;
        } else {
            break;
        }
    }

    printf("%d", ans);
    return 0;
}