#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;

int n, m;
int arr[10][10], brr[10][10];
int di[] = { 0,0,1,-1 }, dj[] = { 1,-1,0,0 };

bool check(int i, int j) { return 1 <= i && i <= n && 1 <= j && j <= m; }

int bfs() {
	queue<pi> q;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			brr[i][j] = arr[i][j];
			if (brr[i][j] == 2) q.push({ i,j });
		}
	while (q.size()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ni = x + di[i], nj = y + dj[i];
			if (check(ni, nj)) {
				if (!brr[ni][nj]) {
					brr[ni][nj] = 2;
					q.push({ ni, nj });
				}
			}
		}
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++)for (int j = 1; j <= m; j++)if (brr[i][j] == 0) cnt++;
	return cnt;
}

int choice() {
	int ans = 0;
	for (int ax = 1; ax <= n; ax++)
		for (int ay = 1; ay <= m; ay++)
			for (int bx = 1; bx <= n; bx++)
				for (int by = 1; by <= m; by++)
					for (int cx = 1; cx <= n; cx++)
						for (int cy = 1; cy <= m; cy++) {
							if ((ax == bx && ay == by) || (ax == cx && ay == cy) || (bx == cx && by == cy)) continue;
							if (arr[ax][ay] || arr[bx][by] || arr[cx][cy]) continue;
							arr[ax][ay] = arr[bx][by] = arr[cx][cy] = 1;
							ans = max(ans, bfs());
							arr[ax][ay] = arr[bx][by] = arr[cx][cy] = 0;
						}
	return ans;
}

vector<pi> v;
bool visited[11][11];
int ans;

void dfs(vector<pi>& v) {
	if (v.size() == 3) {
		for (int i = 0; i < 3; i++) {
			pi now = v[i];
			arr[now.first][now.second] = 1;
		}
		ans = max(ans, bfs());
		for (int i = 0; i < 3; i++) {
			pi now = v[i];
			arr[now.first][now.second] = 0;
		}
		return; 
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (visited[i][j] == false && !arr[i][j]) {
				v.push_back({ i,j });
				visited[i][j] = true;
				dfs(v);
				visited[i][j] = false;
				v.pop_back();
			}
		}
	}
}

void input() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)for (int j = 1; j <= m; j++) cin >> arr[i][j];
}

int solve() {
	input();
	dfs(v);
	return ans;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cout << solve() << '\n';

	return 0;
}