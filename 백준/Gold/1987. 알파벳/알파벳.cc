#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<unordered_set>

using namespace std;

typedef long long ll;
#define endl '\n'

int r, c, answer = 0;
char alpha;
int board[20][20];
unordered_set<ll> visited[20][20];
int di[4] = { 1,-1,0,0 };
int dj[4] = { 0,0,1,-1 };

void dfs(int i, int j, ll visit, int dis) {
	if (answer < dis) {
		answer = dis;
	}

	for (int k = 0; k < 4; k++) {
		int ni = i + di[k];
		int nj = j + dj[k];
		if (ni >= 0 && ni < r && nj >= 0 && nj < c && (visit & 1 << board[ni][nj]) == false) {
			ll nextVist = visit | 1 << board[ni][nj];
			visited[ni][nj].insert(nextVist);
			dfs(ni, nj, nextVist, dis + 1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> alpha;
			board[i][j] = alpha - 'A';
		}
	}

	dfs(0, 0, 1 << board[0][0], 1);
	cout << answer;
	return 0;
}

