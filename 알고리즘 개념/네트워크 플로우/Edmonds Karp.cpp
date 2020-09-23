# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
#pragma comment(linker, "/STACK:336777216")
#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
const int di[] = { -1, 0, 0, 1 }, dj[] = { 0, -1, 1, 0 };

const int INF = 1e9;
const int MAX = 100;

int n = 6;
int c[MAX][MAX], f[MAX][MAX], d[MAX]; // capacity(u, v), flow(u,v), visited와 경로 저장 역할
vector<int> v[MAX];

int maxFlow(int start, int end) {
	int result = 0;
	while (1) {
		fill(d, d + MAX, -1); // 모든 정점을 방문하지 않음
		queue<int> q;
		q.push(start);
		while (q.size()) {
			int cur = q.front(); q.pop();
			for (auto next : v[cur]) {
				// 방문하지 않는 노드 중 용량이 남은 경우만 탐색
				if (c[cur][next] - f[cur][next] > 0 && d[next] == -1) {
					q.push(next);
					d[next] = cur; //next 노드를 cur 다음으로 방문함, 경로 저장
					if (next == end) break;
				}
			}
		}
		// 모든 경우를 다 탐색한 경우에는 end를 더 이상 도달하지 못함
		// 따라서 end가 방문되지 않는 경우에 모든 경로 탐색이 끝남
		if (d[end] == -1) break;
		int flow = INF;

		// 경로의 모든 간선 중 남은 유량의 최솟값만큼 유량을 흘려보낼 수 있다
		for (int i = end; i != start; i = d[i]) {
			flow = min(flow, c[d[i]][i] - f[d[i]][i]);
		}

		// d[i](=i의 이전 노드)에서 i까지 흐르는 플로우를 갱신
		for (int i = end; i != start; i = d[i]) {
			f[d[i]][i] += flow;
			f[i][d[i]] -= flow;
		}
		result += flow;
	}
	return result;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	v[1].pb(2);
	v[2].pb(1);
	c[1][2] = 12;

	v[1].pb(4);
	v[4].pb(1);
	c[1][4] = 11;

	v[2].pb(3);
	v[3].pb(2);
	c[2][3] = 6;

	v[2].pb(4);
	v[4].pb(2);
	c[2][4] = 3;
	
	v[2].pb(5);
	v[5].pb(2);
	c[2][5] = 5;

	v[2].pb(6);
	v[6].pb(2);
	c[2][6] = 9;

	v[3].pb(6);
	v[6].pb(3);
	c[3][6] = 8;

	v[4].pb(5);
	v[5].pb(4);
	c[4][5] = 9;

	v[5].pb(3);
	v[3].pb(5);
	c[5][3] = 3;

	v[5].pb(6);
	v[6].pb(5);
	c[5][6] = 4;

	cout << maxFlow(1, 6) << endl;

	return 0;
}

