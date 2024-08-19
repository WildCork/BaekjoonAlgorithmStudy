#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define endl '\n'

int n, m;

struct Node {
	int idx = 0;
	int cost = 0;
	int depth = 0;
	int parentIndex = 0;
};
vector<vector<pair<int,int>>> edges;
vector<bool> visited;
vector<Node> nodes;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	int a, b, c;
	edges.resize(n + 1);
	visited.resize(n + 1);
	nodes.resize(n + 1);

	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b >> c;
		edges[a].push_back({ b,c });
		edges[b].push_back({ a,c });
	}

	queue<int> q;
	q.push(1);
	nodes[1].idx = 1;
	visited[1] = true;
	while (!q.empty()) {
		auto f = q.front();
		q.pop();
		for (int i = 0; i < edges[f].size(); i++) {
			int idx = edges[f][i].first;
			int cost = edges[f][i].second;
			if (visited[idx] == false) {
				visited[idx] = true;
				nodes[idx].depth = nodes[f].depth + 1;
				nodes[idx].cost = nodes[f].cost + cost;
				nodes[idx].parentIndex = f;
				nodes[idx].idx = idx;
				q.push(idx);
			}
		}
	}
	Node an, bn;
	int aCost, bCost;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		an = nodes[a];
		bn = nodes[b];
		aCost = an.cost;
		bCost = bn.cost;

		if (an.depth < bn.depth) {
			while (an.depth < bn.depth) {
				bn = nodes[bn.parentIndex];
			}
		}
		else if (an.depth > bn.depth) {
			while (an.depth > bn.depth) {
				an = nodes[an.parentIndex];
			}
		}

		while (an.idx != bn.idx) {
			an = nodes[an.parentIndex];
			bn = nodes[bn.parentIndex];
		}

		cout << aCost + bCost - 2 * an.cost << endl;
	}

}