#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>

using namespace std;

#define endl '\n'
#define MAXNUM 10000

int n;
char c;
bool visited[100][100];
vector<string> sv;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void dfs1(int i, int j) {
	visited[i][j] = true;
	for (int k = 0; k < 4; k++) {
		int ni = i + dx[k];
		int nj = j + dy[k];
		if (ni >= 0 && ni < n) {
			if (nj >= 0 && nj < n) {
				if (sv[ni][nj] == c && visited[ni][nj] == false) {
					dfs1(ni, nj);
				}
			}
		}
	}
}
void dfs2(int i, int j) {
	visited[i][j] = true;
	for (int k = 0; k < 4; k++) {
		int ni = i + dx[k];
		int nj = j + dy[k];
		if (ni >= 0 && ni < n) {
			if (nj >= 0 && nj < n) {
				if (visited[ni][nj] == false) {
					if (c == 'R' || c == 'G') {
						if (sv[ni][nj] == 'R' || sv[ni][nj] == 'G') {
							dfs2(ni, nj);
						}
					}
					else if (sv[ni][nj] == c) {
						dfs2(ni, nj);
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
	cin >> n;
	sv.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> sv[i];
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] == false) {
				c = sv[i][j];
				dfs1(i,j);
				cnt++;
			}
		}
	}
	cout << cnt<< " ";
	cnt = 0;
	for (int i = 0; i < n; i++) {
		fill(visited[i], visited[i] + n, 0);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] == false) {
				c = sv[i][j];
				dfs2(i, j);
				cnt++;
			}
		}
	}
	cout << cnt;
}