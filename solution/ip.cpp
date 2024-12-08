#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::string s;
    std::cin >> s;
    s = s + '.';

    int num = 0;
    for (int i = 0; i < (int) s.size(); ++ i) {
        if (s[i] == '.') {
            std::vector<int> g;
            while (num) {
                g.push_back(num % 2);
                num /= 2;
            }
            while (g.size() < 8) {
                g.push_back(0);
            }
            std::reverse(g.begin(), g.end());
            for (auto j : g) {
                std::cout << j;
            }
        } else {
            num = num * 10 + s[i] - '0';
        }
    }
    std::cout << '\n';
    
    return 0;
}
