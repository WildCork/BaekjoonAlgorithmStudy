#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<unordered_set>
#include<numeric>
#include<queue>

using namespace std;

typedef long long ll;

#define endl '\n'

int n, m;
int di[4] = { 0,0,1,-1 };
int dj[4] = { 1,-1,0,0 };

vector<vector<int>> arr1;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	arr1.resize(n, vector<int>(m));
	int cnt = 0, time = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr1[i][j];
			if (arr1[i][j]) {
				cnt++;
			}
		}
	}

	while (cnt) {
		time++;
		queue<pair<int, int>>q;
		q.push({ 0,0 });
		arr1[0][0] = 2;
		while (!q.empty()) {
			auto f = q.front();
			q.pop();
			for (int k = 0; k < 4; k++) {
				int ni = di[k] + f.first;
				int nj = dj[k] + f.second;
				if (ni >= 0 && ni < n && nj >= 0 && nj < m && arr1[ni][nj] == 0) {
					arr1[ni][nj] = 2;
					q.push({ ni,nj });
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr1[i][j] == 1) {
					for (int k = 0; k < 4; k++) {
						int ni = di[k] + i;
						int nj = dj[k] + j;
						if (ni >= 0 && ni < n && nj >= 0 && nj < m && arr1[ni][nj] == 2) {
							arr1[i][j] = 3;
							break;
						}
					}
				}
			}
		}
		int dummy = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr1[i][j] == 1) {
					dummy++;
				}
				else {
					arr1[i][j] = 0;
				}
			}
		}
		if (dummy == 0) {
			break;
		}
		else {
			cnt = dummy;
		}
	}

	cout << time << endl << cnt << endl;

	return 0;
}