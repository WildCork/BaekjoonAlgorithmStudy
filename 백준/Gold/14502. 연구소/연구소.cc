#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<unordered_map>

using namespace std;

typedef long long ll;

#define endl '\n'

int n, m;
int di[4] = {0,0,1,-1};
int dj[4] = {1,-1,0,0};
int answer = 0;
vector<vector<int>> arr(10, vector<int>(10));

void dfs(int cnt, int ii, int jj) {
	if (cnt == 0) {
		auto arr2 = arr;
		int dummy = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr2[i][j] == 2) {
					queue<pair<int, int>>q;
					q.push({ i,j });
					while (!q.empty()) {
						auto f = q.front();
						q.pop();
						for (int k = 0; k < 4; k++) {
							int ni = di[k] + f.first;
							int nj = dj[k] + f.second;
							if (ni >=0 && ni < n && nj >= 0 && nj < m) {
								if (arr2[ni][nj] == 0) {
									arr2[ni][nj] = 2;
									q.push({ni,nj});
								}
							}
						}
					}
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr2[i][j] == 0) {
					dummy++;
				}
			}
		}
		if (answer < dummy) {
			answer = dummy;
		}
		return;
	}
	for (int i = ii; i < n; i++) {
		for (int j = (i == ii ? jj:0); j < m; j++) {
			if (arr[i][j] == 0) {
				arr[i][j] = 1;
				dfs(cnt - 1, i, j);
				arr[i][j] = 0;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	dfs(3, 0, 0);
	cout << answer;
}

