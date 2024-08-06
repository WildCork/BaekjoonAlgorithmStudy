#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;

#define endl '\n'

int n, m;
int dx[4] = { 1,0,0,-1 };
int dy[4] = { 0,1,-1,0 };
vector<vector<int>> cheeze;

void PushAir(int a, int b, vector<vector<int>> &cheeze2) {
	queue<pair<int, int>> q;
	q.push({ a,b });
	cheeze2[a][b] = -1;

	while (!q.empty()) {
		auto f = q.front();
		q.pop();
		int i = f.first;
		int j = f.second;
		for (int k = 0; k < 4; k++) {
			if (i + dx[k] >= 0 && i + dx[k] < n) {
				if (j + dy[k] >= 0 && j + dy[k] < m) {
					if (cheeze2[i + dx[k]][j + dy[k]] == 0) {
						cheeze2[i + dx[k]][j + dy[k]] = -1;
						q.push({ i + dx[k],j + dy[k] });
					}
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	cheeze.resize(n);
	for (int i = 0; i < n; i++) {
		cheeze[i].resize(m);
		for (int j = 0; j < m; j++) {
			cin >> cheeze[i][j];
		}
	}

	int answer = 0;
	PushAir(0, 0, cheeze);
	while (true) {
		bool isEnd = true;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (cheeze[i][j] == 1) {
					isEnd = false;
					break;
				}
			}
			if (!isEnd)break;
		}
		if (isEnd)break;

		auto cheeze2 = cheeze;


		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (cheeze[i][j] == 1) {
					int cnt = 0;
					for (int k = 0; k < 4; k++) {
						if (i + dx[k] >= 0 && i + dx[k] < n) {
							if (j + dy[k] >= 0 && j + dy[k] < m) {
								if (cheeze[i + dx[k]][j + dy[k]] < 0) {
									cnt++;
								}
							}
						}
					}
					if (cnt > 1) {
						PushAir(i, j, cheeze2);
					}
				}
			}
		}
		cheeze = cheeze2;

		/*cout << endl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << cheeze[i][j] << " ";
			}
			cout << endl;
		}*/
		answer++;
	}
	cout << answer;
}

/*
8 9
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 1 1 0 0 0 1 1 0
0 1 0 1 1 1 0 1 0
0 1 0 0 1 0 0 1 0
0 1 0 1 1 1 0 1 0
0 1 1 0 0 0 1 1 0
0 0 0 0 0 0 0 0 0
*/