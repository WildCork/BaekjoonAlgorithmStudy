#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int visited[1001] = {};
int cost[1001][1001];

int main() {
	cin >> n >> m;
	fill(visited, visited + 1001, -1);
	for (int i = 0; i <= n; i++) {
		fill(cost[i], cost[i] + 1001, -1);
	}
	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		if (cost[a][b] < 0 || cost[a][b] > c) {
			cost[a][b] = c;
		}
	}
	int s, e;
	cin >> s >> e;

	int answer = -1;
	queue<pair<int, int>>q;
	q.push({ s,0 });
	visited[s] = 1;
	while (!q.empty()) {
		auto f = q.front();
		q.pop();

		if (answer >= 0 && f.second > answer) {
			continue;
		}
		if (f.first == e) {
			if (answer < 0 || answer > f.second) {
				answer = f.second;
			}
			continue;
		}
		for (int i = 1; i <= n; i++) {
			if (cost[f.first][i] >= 0) {
				if (visited[i] < 0 || visited[i] > f.second + cost[f.first][i]) {
					visited[i] = f.second + cost[f.first][i];
					q.push({ i, f.second + cost[f.first][i] });
				}
			}
		}
	}

	cout << answer;
}