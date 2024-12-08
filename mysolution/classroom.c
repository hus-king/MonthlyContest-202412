#include <stdio.h>
#include <stdbool.h>

#define MAX 10000

void classroom(int m, int n, int p);
bool find(int a[MAX], int m, int n, int p, int key);
bool check(int a[MAX], int m, int n);
int keypoint[11] = {0};

int main() {
    int t;
    scanf("%d", &t);
    for (int p = 0; p < t; p++) {
        int m, n;
        scanf("%d%d", &m, &n);
        classroom(m, n, p);
    }
}

void classroom(int m, int n, int p) {
    int a[MAX] = {0};
    if (!find(a, m, n, p, 0)) {
        printf("No\n");
    }
}

bool find(int a[MAX], int m, int n, int p, int key) {
    if (keypoint[p] == 1) return true;
    if (key == m * n) {
        if (check(a, m, n)) {
            printf("Yes\n");
            for (int j = 0; j < m; j++) {
                for (int k = 0; k < n; k++) {
                    if (k == n - 1)
                        printf("%d", a[j * n + k]);
                    else
                        printf("%d ", a[j * n + k]);
                }
                printf("\n");
            }
            keypoint[p] = 1;
            return true;
        }
        return false;
    }
    for (int i = 1; i <= m * n; i++) {
        bool flag = false;
        for (int j = 0; j < key; j++) {
            if (a[j] == i) {
                flag = true;
                break;
            }
        }
        if (!flag) {
            a[key] = i;
            if (find(a, m, n, p, key + 1)) {
                return true;
            }
            a[key] = 0;
        }
    }
    return false;
}

bool check(int a[MAX], int m, int n) {
    bool checknum[20000] = {0};
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (checknum[a[i * n + j] + a[i * n + j + 1]]) {
                return false;
            } else {
                checknum[a[i * n + j] + a[i * n + j + 1]] = true;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m - 1; j++) {
            if (checknum[a[j * n + i] + a[(j + 1) * n + i]]) {
                return false;
            } else {
                checknum[a[j * n + i] + a[(j + 1) * n + i]] = true;
            }
        }
    }
    return true;
}