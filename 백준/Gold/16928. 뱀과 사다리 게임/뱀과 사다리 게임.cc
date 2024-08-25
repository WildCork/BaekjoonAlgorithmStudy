#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>

using namespace std;

#define endl '\n'
#define MAXNUM 10000

int n, m;
int answer = 0;
int teleport[101];
int visited[101];
int a, b;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n + m; i++) {
		cin >> a >> b;
		teleport[a] = b;
	}
	fill(visited, visited + 101, MAXNUM);
	queue<pair<int,int>> q;
	q.push({ 1,0 });
	while (!q.empty()) {
		auto f = q.front();
		q.pop();
		for (int i = 6; i > 0; i--) {
			int idx = f.first + i;
			if (idx > 100) {
				continue;
			}
			while (teleport[idx]) {
				idx = teleport[idx];
			}
			if (visited[idx] > f.second + 1) {
				visited[idx] = f.second + 1;
				q.push({ idx,f.second + 1 });
			}
		}
	}
	cout << visited[100];
}