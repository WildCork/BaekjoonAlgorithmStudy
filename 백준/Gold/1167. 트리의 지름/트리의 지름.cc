#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;
#define endl '\n'

int v, node1, node2, cost;
struct Node {
	vector<vector<int>> linked;
	vector<vector<int>> child;
};

vector<Node> edges(100001);
vector<bool> visited(100001);

bool cmp(vector<int> a, vector<int> b) {
	return a.back() > b.back();
}

int findTotalCost(int idx) {
	int cost = 0;
	Node& node = edges[idx];
	visited[idx] = true;
	for (int i = 0; i < node.linked.size(); i++) {
		int nextNode = node.linked[i][0];
		if (!visited[nextNode]) {
			node.child.push_back({ nextNode, node.linked[i][1] + findTotalCost(nextNode)});
		}
	}
	if (node.child.empty()) {
		return 0;
	}
	sort(node.child.begin(), node.child.end(),cmp);
	return node.child.front()[1];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> v;
	int rootNode = -1;
	for (int i = 1; i <= v; i++) {
		cin >> node1;
		while (1) {
			cin >> node2;
			if (node2 < 0) {
				break;
			}
			cin >> cost;
			edges[node1].linked.push_back({ node2,cost });
		}
		if (rootNode < 0 && edges[node1].linked.size() == 1) {
			rootNode = node1;
		}
	}

	int answer = findTotalCost(rootNode);
	node1 = rootNode;
	while (1) {
		if (edges[node1].child.size() == 0) {
			break;
		}
		if (edges[node1].child.size() > 1) {
			answer = max(answer, edges[node1].child[0][1] + edges[node1].child[1][1]);
		}
		node1 = edges[node1].child[0][0];
	}
	cout << answer;
}