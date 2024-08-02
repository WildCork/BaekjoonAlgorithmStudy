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

	vector<int> answer;
	queue<vector<int>>q;
	q.push({ s, 0, s });
	visited[s] = 1;
	while (!q.empty()) {
		auto f = q.front();
		q.pop();

		if (!answer.empty() && f[1] > answer[1]) {
			continue;
		}
		if (f[0] == e) {
			if (answer.empty() || answer[1] > f[1]) {
				answer = f;
			}
			continue;
		}
		for (int i = 1; i <= n; i++) {
			if (cost[f[0]][i] >= 0) {
				if (visited[i] < 0 || visited[i] > f[1] + cost[f[0]][i]) {
					visited[i] = f[1] + cost[f[0]][i];
					int pre = f[1];
					int pre2 = f[0];
					f[0] = i;
					f[1] = visited[i];
					f.push_back(i);
					q.push(f);
					f.pop_back();
					f[0] = pre2;
					f[1] = pre;
				}
			}
		}
	}
	cout << answer[1] << endl;
	cout << answer.size() - 2 << endl;
	for (int i = 2; i < answer.size(); i++)
	{
		cout << answer[i] << " ";
	}
}