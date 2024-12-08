#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++ i) {
        std::cin >> a[i];
    }

    auto check = [&](int x) {
        int cnt = 0;
        for (int i = 0; i < n; ++ i) {
            cnt += (a[i] >= x);
        }
        return cnt >= x;
    };

    int l = 1, r = n;
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }

    std::cout << l << '\n';
    
    return 0;
}
