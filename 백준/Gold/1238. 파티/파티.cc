#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>

using namespace std;

#define endl '\n'
#define MAXNUM 1000

int n, m, x;
int a, b, c;
int visited1[MAXNUM + 1] = { 0 };
int visited2[MAXNUM + 1] = { 0 };
vector<vector<pair<int, int>>> edge1(MAXNUM + 1);
vector<vector<pair<int, int>>> edge2(MAXNUM + 1);

int main() {
	ios_base::sync_with_stdio(false);
	cin. tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> x;
	fill(visited1, visited1 + n + 1, 10000000);
	fill(visited2, visited2 + n + 1, 10000000);
	visited1[x] = 0;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		edge1[a].push_back({ b,c });
		edge2[b].push_back({ a,c });
	}
	queue<int> q;
	q.push(x);
	while (!q.empty()) {
		auto f = q.front();
		q.pop();
		for (int i = 0; i < edge1[f].size(); i++) {
			auto idx = edge1[f][i].first;
			auto cost = edge1[f][i].second;

			if (visited1[idx] > visited1[f] + cost) {
				visited1[idx] = visited1[f] + cost;
				q.push(idx);
			}
		}
	}
	visited2[x] = 0;
	q.push(x);
	while (!q.empty()) {
		auto f = q.front();
		q.pop();
		for (int i = 0; i < edge2[f].size(); i++) {
			auto idx = edge2[f][i].first;
			auto cost = edge2[f][i].second;

			if (visited2[idx] > visited2[f] + cost) {
				visited2[idx] = visited2[f] + cost;
				q.push(idx);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		visited1[i] += visited2[i];
	}
	cout << *max_element(visited1 + 1, visited1 + n + 1);
}