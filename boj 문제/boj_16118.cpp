#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

struct P {int v,w,speed;};
bool operator <(P a, P b) {
	return a.w > b.w;
}

priority_queue<P> pq;
vector<P> graph[4000 + 5];
int dist[4000 + 5][3];
const int INF = 1e9;
int dist2[4000 + 5];
int N, M, cnt;

void d(int start) {
	fill(&dist[0][0], &dist[4004][2], INF);
	dist[1][1] = 0;
	dist[1][2] = INF;
	pq.push({ 1,0,1 });

	while (pq.size()) {
		P cur = pq.top();
		int curv = cur.v, curw = cur.w, curs = cur.speed;
		pq.pop();

		if (dist[curv][curs] < curw)
			continue;
			
		for (P i : graph[curv]) {
			int nextv = i.v, nextw = i.w;
			int nexts = 3 - curs;
			if(curs == 1) nextw/=2;
			else nextw*=2;
			
			if (dist[curv][curs] + nextw < dist[nextv][nexts]) {
				dist[nextv][nexts] = dist[curv][curs] + nextw;
				pq.push({ nextv, dist[nextv][nexts], nexts });
			}
		}
	}
}

void d2(int start) {
	priority_queue<P> pq2;
	for (int i = 1; i <= N; i++)
		dist2[i] = INF;
	dist2[start] = 0;
	pq2.push({ start, 0, 0 });

	while (pq2.size()) {
		P cur = pq2.top();
		pq2.pop();
		int curv = cur.v, curw = cur.w;

		if (dist2[curv] < curw)
			continue;
		for (P i : graph[curv]) {
			if (dist2[curv] + i.w < dist2[i.v]) {
				dist2[i.v] = dist2[curv] + i.w;
				pq2.push({ i.v, dist2[i.v], 0 });
			}
		}
	}
}

int main() {
	cin.sync_with_stdio(false);cin.tie(nullptr);
	cin>>N>>M;
	while (M--) {
		int a, b, d;
		cin>>a>>b>>d;
		graph[a].push_back({ b,2 * d,4 });
		graph[b].push_back({ a,2 * d,4 });
	}
	d(1);
	d2(1);
	for (int i = 1; i <= N; i++)
		if (dist2[i] < dist[i][1] && dist2[i] < dist[i][2])
			cnt++;

	cout<<cnt<<endl;

	return 0;
}