#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <queue>

using namespace std;

int n, m;
int visited[1001][1001] = {};
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
			miro[i][j] = s[j] - '0';
		}
	}
	int cnt = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (miro[i][j] == 0 && visited[i][j] == 0)
			{
				queue<pair<int, int>>q;
				q.push({ i,j });
				visited[i][j] = cnt;
				while (!q.empty())
				{
					auto f = q.front();
					q.pop();
					for (int k = 0; k < 4; k++)
					{
						if (f.first + dx[k] >= 0 && f.first + dx[k] < n
							&& f.second + dy[k] >= 0 && f.second + dy[k] < m)
						{
							if (miro[f.first + dx[k]][f.second + dy[k]] == 0
								&& visited[f.first + dx[k]][f.second + dy[k]] == 0)
							{
								visited[f.first + dx[k]][f.second + dy[k]] = cnt;
								q.push({ f.first + dx[k],f.second + dy[k] });
							}
						}
					}
				}
				cnt++;
			}

		}
	}

	map<int, int> orderCntMap;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visited[i][j])
				orderCntMap[visited[i][j]]++;
		}
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (miro[i][j]) {
				set<int> s;
				for (int k = 0; k < 4; k++) {
					if (i + dx[k] >= 0 && i + dx[k] < n&&j + dy[k] >= 0 && j + dy[k] < m) {
						if (visited[i + dx[k]][j + dy[k]] > 0) {
							s.insert(visited[i + dx[k]][j + dy[k]]);
						}
					}
				}
				int answer = 1;
				for (auto it = s.begin(); it != s.end(); it++)
				{
					answer += orderCntMap[*it];
				}
				cout << answer % 10;
			}
			else {
				cout << "0";
			}
		}
		cout << endl;
	}

}