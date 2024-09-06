#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>

using namespace std;

#define endl '\n'

int n, a, b, c;
int answer = 0;
struct Node {
	int cost;
	vector<pair<int,int>>childs;
};
Node nodes[10001];

bool cmp(pair<int, int>a, pair<int, int>b) {
	return a.second < b.second;
}

int findCost(int idx) {
	Node& node = nodes[idx];
	for (int i = 0; i < node.childs.size(); i++) {
		node.childs[i].second = findCost(node.childs[i].first);
	}
	sort(node.childs.begin(), node.childs.end(), cmp);
	if (node.childs.size() > 0) {
		return node.childs.back().second + node.cost;
	}
	return node.cost;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b >> c;
		nodes[a].childs.push_back({ b,0 });
		nodes[b].cost = c;
	}
	answer = findCost(1);
	int idx = 1;
	while (true) {
		if (nodes[idx].childs.size() > 1) {
			auto cs = nodes[idx].childs;
			n = cs.size();
			answer = max(answer, cs[n - 1].second + cs[n - 2].second);
		}
		if (nodes[idx].childs.size() > 0) {
			idx = nodes[idx].childs.back().first;
		}
		else {
			break;
		}
	}
	cout << answer;
}