#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int> > a(n, std::vector<int> (m));
    int cnt = 1;
    for (int i = 0; i < m; ++ i) {
        int curx = 0, cury = i;
        while (curx < n && cury >= 0) {
            a[curx][cury] = cnt;
            curx ++;
            cury --;
            cnt ++;
        }
    }
    for (int i = 1; i < n; ++ i) {
        int curx = i, cury = m - 1;
        while (curx < n && cury >= 0) {
            a[curx][cury] = cnt;
            curx ++;
            cury --;
            cnt ++;
        }
    }

    std::cout << "Yes" << '\n';
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < m; ++ j) {
            std::cout << a[i][j] << ' ';
        }
        std::cout << '\n';
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    int T;
    std::cin >> T;

    while (T --) {
        solve();
    }

    return 0;
}
