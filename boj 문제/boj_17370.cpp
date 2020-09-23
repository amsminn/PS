#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;

int n, ans;
int visited[111][111];

void dfs(pi now = { 33,33 }, pi pre = { 34,33 }, int cnt = 0) {
	int i = now.first, j = now.second;
	if (cnt == n) {
		//cout << "dsas " << i << ' ' << j << ' ' << visited[i][j] << '\n';
		if (visited[i][j] == 2) ans++;
		return;
	}
	if (visited[i][j] == 2) return;
	int level = 1;
	if (now.first % 2 == 1)
		level *= -1;
	// (i+level, j-1), (i+level, j+1), (i-level,j)
	pi go = { i + level, j - 1 };
	if (go != pre) {
		visited[go.first][go.second]++;
		dfs(go, now, cnt + 1);
		visited[go.first][go.second]--;
	}
	go = { i + level, j + 1 };
	if (go != pre) {
		visited[go.first][go.second]++;
		dfs(go, now, cnt + 1);
		visited[go.first][go.second]--;
	}
	go = { i - level, j };
	if (go != pre) {
		visited[go.first][go.second]++;
		dfs(go, now, cnt + 1);
		visited[go.first][go.second]--;
	}
}

int main() {
	cin.sync_with_stdio(NULL); cin.tie(nullptr);
	cin >> n;
	visited[34][33] = 1;
	visited[33][33] = 1;
	dfs();
	cout << ans << '\n';

	return 0;
}