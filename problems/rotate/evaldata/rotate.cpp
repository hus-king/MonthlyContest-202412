#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100 + 7; 

int N, a[MAXN][MAXN];

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			scanf("%1d", &a[i][j]);
		}
	}
	int st = a[1][1];
	for(int i = 1; i < N; i++) a[i][1] = a[i + 1][1];
	for(int i = 1; i < N; i++) a[N][i] = a[N][i + 1];
	for(int i = N; i > 1; i--) a[i][N] = a[i - 1][N];
	for(int i = N; i > 2; i--) a[1][i] = a[1][i - 1];
	a[1][2] = st;
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			printf("%d", a[i][j]);
		}
		puts("");
	}
	return 0;
}