#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    std::map<std::stack<std::string>, bool> mp;

    auto solve = [&](std::string s, int pd) {
        s += '/';
        std::stack<std::string> st;
        for (int i = 0; i < (int) s.size() - 1; ++ i) {
            std::string cur;
            for (int j = i + 1; j < (int) s.size(); ++ j) {
                if (s[j] == '/') {
                    i = j - 1;
                    break;
                }
                cur += s[j];
            }
            if (cur == ".") {
                continue;
            }
            if (cur == "..") {
                st.pop();
                continue;
            }
            st.push(cur);
        }
        if (pd == 1) {
            if (mp.find(st) == mp.end()) {
                std::cout << "No" << '\n';
            } else {
                std::cout << "Yes" << '\n';
            }
        }
        mp[st] = 1;
    };

    for (int i = 0; i < n; ++ i) {
        std::string s;
        std::cin >> s;
        solve(s, 0);
    }

    int q;
    std::cin >> q;

    for (int i = 0; i < q; ++ i) {
        std::string s;
        std::cin >> s;
        solve(s, 1);
    }
    
    return 0;
}
