#include "testlib.h"
#include<bits/stdc++.h>

#define int long long
using namespace std; 
const int maxn = 500000 + 7;

int T, cas;
int N, M, K;
int maxVal[maxn];
int p[maxn];
bool occ[maxn];

signed main(signed argc, char *argv[]) {
	registerTestlibCmd(argc, argv);
	T = inf.readInt(1, 10);
	while(T--) {
		++cas;
		N = inf.readInt(1, 500000);
		M = inf.readInt(1, 500000);
		K = inf.readInt(1, 500000);
		memset(maxVal, 0, sizeof(maxVal));
		memset(occ, false, sizeof(occ));
		for(int i = 1; i <= M; i++) {
			int a, t;
			a = inf.readInt(1, 2000000000);
			t = inf.readInt(1, N);
			maxVal[t] = max(maxVal[t], a);
		}
		for(int i = 1; i <= K; i++) p[i] = inf.readInt(1, 2000000000);
//		vector <int> std;
		int status = ans.readInt(-10, K);
		if(status == -1) {
			int player = ouf.readInt(-1, K);
			if(player != -1) {
				quitf(_wa, "In case %d, there are not a solution.", cas);
				return 0;
			}
		}
		else {
			for(int i = 2; i <= N; i++) status = ans.readInt(1, K);
			for(int i = 1; i <= N; i++) {
				int ot = ouf.readInt(1, K);
				if(occ[ot]) {
					quitf(_wa, "In case %d, classroom %d is given to multiple teachers", cas, ot);
					return 0;
				}
				occ[ot] = true;
				long long permission = 1ll * p[ot] * 2 / 3;
				if(permission < maxVal[i]) {
					quitf(_wa, "In case %d, classroom %d is not enough for teacher %d.", cas, ot, i);
				}
			}
		}
	}
	quitf(_ok, "Accepted");
	return 0;
}
