#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const int di[] = { -1, 0, 0, 1 }, dj[] = { 0, -1, 1, 0 };

struct p { int i, j, k; };

int n, m, k;
int arr[1111][1111];
int dist[1111][1111][11];

bool safe(int i, int j) { return i >= 1 && i <= n && j <= m && j >= 1; }

int bfs() {
	int mn = 1e9;
	dist[1][1][0] = 1;
	queue<p> q;
	q.push({ 1,1,0 });
	while (q.size()) {
		int nowi = q.front().i;
		int nowj = q.front().j;
		int nowk = q.front().k;  
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ni = nowi + di[i], nj = nowj + dj[i], nk = nowk + arr[ni][nj];
			if (safe(ni, nj) == false)continue;
			if (dist[ni][nj][nk] == 0) {
				if (nk <= k) {
					dist[ni][nj][nk] = dist[nowi][nowj][nowk] + 1;
					q.push({ ni,nj,nk });
				}
			}
		}
	}
	for (int i = 0; i <= 10; i++)if (dist[n][m][i] != 0)mn = min(mn, dist[n][m][i]);
	return mn;
}

int main() {
	//cin.sync_with_stdio(0); cin.tie(0);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++)for (int j = 1; j <= m; j++)scanf("%1d", &arr[i][j]);
	int ans = bfs();
	if (ans == 1e9) printf("-1\n");
	else printf("%d\n", ans);

	return 0;
}