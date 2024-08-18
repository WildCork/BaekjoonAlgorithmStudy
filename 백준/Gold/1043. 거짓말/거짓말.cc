#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_set>

using namespace std;

#define endl '\n'

int n, m, knowTrueCnt = 0, idx,cnt;
unordered_set<int> knowTrue;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	cin >> knowTrueCnt;
	for (int i = 0; i < knowTrueCnt; i++) {
		cin >> idx;
		knowTrue.insert(idx);
	}
	vector<vector<int>> parties(m);
	vector<int> visited(m);
	for (int i = 0; i < m; i++) {
		cin >> cnt;
		parties[i].resize(cnt);
		for (int j = 0; j < cnt; j++) {
			cin >> parties[i][j];
			if (knowTrue.find(parties[i][j]) != knowTrue.end()) {
				visited[i] = 1;
			}
		}
	}

	while (1) {
		bool isEnd = true;
		for (int i = 0; i < m; i++) {
			if (visited[i] == 1) {
				for (int j = 0; j < parties[i].size(); j++) {
					knowTrue.insert(parties[i][j]);
				}
				visited[i] = 2;
				isEnd = false;
			}
			else if(visited[i] == 0) {
				for (int j = 0; j < parties[i].size(); j++) {
					if (knowTrue.find(parties[i][j]) != knowTrue.end()) {
						visited[i] = 1;
						isEnd = false;
						break;
					}
				}
			}
		}
		if (isEnd) {
			break;
		}
	}

	cout << count(visited.begin(), visited.end(),0);

}