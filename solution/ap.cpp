#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, k;
    std::cin >> n >> k;

    std::vector<int> x(n), y(n);
    for (int i = 0; i < n; ++ i) {
        std::cin >> x[i] >> y[i];
    }

    struct pos {
        int id1, id2;
    };

    std::vector<pos> g;
    for (int i = 0; i < n; ++ i) {
        for (int j = i + 1; j < n; ++ j) {
            g.push_back({i, j});
        }
    }

    auto get = [&](int pa, int pb) {
        return (x[pa] - x[pb]) * (x[pa] - x[pb]) + (y[pa] - y[pb]) * (y[pa] - y[pb]);
    };

    std::sort(g.begin(), g.end(),
        [&](pos a, pos b){
            return get(a.id1, a.id2) < get(b.id1, b.id2);
        });

    std::vector<int> fa(n);
    for (int i = 0; i < n; ++ i) {
        fa[i] = i;
    }

    auto find = [&](auto &self, int x) {
        if (x == fa[x]) {
            return x;
        } else {
            return fa[x] = self(self, fa[x]);
        }
    };

    int cnt = 0;
    for (auto cur : g) {
        int cx = cur.id1, cy = cur.id2;
        int fcx = find(find, cx), fcy = find(find, cy);
        if (fcx == fcy) {
            continue;
        } else {
            fa[fcx] = fcy;
            cnt ++;
            if (cnt == n - k) {
                break;
            }
        }
    }

    for (auto cur : g) {
        int cx = cur.id1, cy = cur.id2;
        int fcx = find(find, cx), fcy = find(find, cy);
        if (fcx != fcy) {
            std::cout << std::fixed << std::setprecision(2) << sqrt(get(cx, cy)) << '\n';
            break;
        }
    }
    
    return 0;
}
