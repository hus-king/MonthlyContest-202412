#include "testlib.h"
#include <bits/stdc++.h>

int main(int argc, char** argv) {
    registerTestlibCmd(argc, argv);

    int T = inf.readInt();

    while (T --) {
        int n = inf.readInt(), m = inf.readInt();

        std::string s = ouf.readToken();
        if (s[0] != 'Y' || s[1] != 'e' || s[2] != 's') {
            quitf(_wa,"Wrong Answer!");
        }

        std::vector<std::vector<int> > g(n, std::vector<int> (m));
        std::vector<int> arr;
        for (int i = 0; i < n; ++ i) {
            for (int j = 0; j < m; ++ j) {
                g[i][j] = ouf.readInt(1, n * m);
                arr.push_back(g[i][j]);
            }
        }

        std::sort(arr.begin(), arr.end());

        for (int i = 0; i < (int) arr.size(); ++ i) {
            if (arr[i] != i + 1) {
                quitf(_wa,"Wrong Answer!");
            } 
        }

        std::vector<int> mp(2 * n * m);
        for (int i = 0; i < n; ++ i) {
            for (int j = 0; j < m; ++ j) {
                if (i > 0) {
                    int num = g[i][j] + g[i - 1][j];
                    if (mp[num]) {
                        quitf(_wa,"Wrong Answer!");
                    }
                    mp[num] = 1;
                }
                if (j > 0) {
                    int num = g[i][j] + g[i][j - 1];
                    if (mp[num]) {
                        quitf(_wa,"Wrong Answer!");
                    }
                    mp[num] = 1;
                }
            }
        }
    }

    quitf(_ok,"Correct!");

    return 0;
}