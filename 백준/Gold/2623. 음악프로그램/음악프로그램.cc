#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<unordered_set>

using namespace std;

int n, m, o, p;
vector<vector<int>> singers;
vector<bool> singersVisited;
vector<unordered_set<int>> singersTopogical;

int main() {
	cin >> n >> m;

	singers.resize(n);
	singersVisited.resize(n);
	singersTopogical.resize(n);

	for (int i = 0; i < m; i++) {
		cin >> o;
		singers[i].resize(o);
		for (int j = 0; j < o; j++) {
			cin >> singers[i][j];
			if (j != 0) {
				singersTopogical[singers[i][j] - 1].insert(singers[i][j - 1] - 1);
			}
		}
	}

	vector<int> answer;
	bool isCanSing = true;

	while (accumulate(singersVisited.begin(), singersVisited.end(), 0) < n) {
		int singer = -1;
		for (int i = 0; i < n; i++) {
			if (singersVisited[i] == false && singersTopogical[i].empty()) {
				singer = i;
				break;
			}
		}
		if (singer == -1) {
			isCanSing = false;
			break;
		}
		singersVisited[singer] = true;
		answer.push_back(singer + 1);
		for (int i = 0; i < n; i++) {
			if (singersTopogical[i].find(singer) != singersTopogical[i].end()) {
				singersTopogical[i].erase(singer);
			}
		}
	}

	if (isCanSing) {
		for (auto s : answer) {
			cout << s << endl;
		}
	}
	else {
		cout << 0;
	}

	return 0;
}