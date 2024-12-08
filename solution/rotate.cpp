#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    std::vector<std::vector<char> > a(n, std::vector<char> (n));
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < n; ++ j) {
            std::cin >> a[i][j];
        }
    }

    std::cout << a[1][0];
    for (int i = 1; i < n; ++ i) {
        std::cout << a[0][i - 1];
    }
    std::cout << '\n';
    for (int i = 1; i < n - 1; ++ i) {
        for (int j = 0; j < n; ++ j) {
            if (j == 0) {
                std::cout << a[i + 1][j];
            } else {
                if (j == n - 1) {
                    std::cout << a[i - 1][j];
                } else {
                    std::cout << a[i][j];
                }  
            }
        }
        std::cout << '\n';
    }
    for (int i = 0; i < n - 1; ++ i) {
        std::cout << a[n - 1][i + 1];
    }
    std::cout << a[n - 2][n - 1] << '\n';
    
    return 0;
}
