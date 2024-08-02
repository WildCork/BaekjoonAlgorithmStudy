#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int visited[1001][1001][2] = {};
int miro[1001][1001] = {};
int dx[4] = { 0, 0, 1,-1 };
int dy[4] = { 1,-1, 0, 0 };

int main() {
	cin >> n >> m;
	int answer = -1;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			visited[i][j][0] = visited[i][j][1] = -1;
			miro[i][j] = s[j] - '0';
		}
	}
	queue<vector<int>>q;
	q.push({ 0,0,1,1 });
	visited[0][0][0] = visited[0][0][1] = 1;

	while (!q.empty()) {
		auto f = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int x = f[0] + dx[i];
			int y = f[1] + dy[i];
			if (x >= 0 && x < n && y >= 0 && y < m) {
				if (visited[x][y][f[3]] < 0 || visited[x][y][f[3]] > f[2] + 1) {
					visited[x][y][f[3]] = f[2] + 1;
					if (miro[x][y] == 1) {
						if (f[3] == 1) {
							q.push({ x,y,f[2] + 1, 0 });
						}
					}
					else {
						q.push({ x,y,f[2] + 1, f[3] });
					}
				}
			}
		}
	}

	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << visited[i][j][0] << " ";
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << visited[i][j][1] << " ";
		}
		cout << endl;
	}
	cout << endl;*/
	if (min(visited[n - 1][m - 1][0], visited[n - 1][m - 1][1]) < 0) {
		cout << max(visited[n - 1][m - 1][0], visited[n - 1][m - 1][1]);
	}
	else {
		cout << min(visited[n - 1][m - 1][0], visited[n - 1][m - 1][1]);
	}
}