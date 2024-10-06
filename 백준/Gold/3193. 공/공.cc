#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

typedef long long ll;

#define endl '\n'
#define MAXNUM 1000001

int n, m;
int pi, pj;

vector<vector<char>> Turn(vector<vector<char>> v, bool isClock) {
	vector<vector<char>> answer(n, vector<char>(n));
	if (isClock) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				answer[j][n - i - 1] = v[i][j];
				if (v[i][j] == 'L') {
					pi = j; pj = n - i - 1;
				}
			}
		}
	}
	else {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				answer[n - j - 1][i] = v[i][j];
				if (v[i][j] == 'L') {
					pi = n - j - 1; pj = i;
				}
			}
		}
	}
	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string str;
	cin >> n >> m;
	vector<vector<char>> answer(n, vector<char>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> answer[i][j];
			if (answer[i][j] == 'L') {
				pi = i; pj = j;
			}
		}
	}
	char c;
	int dir = 0;
	for (int i = 0; i < m; i++) {
		cin >> c;
		if (c == 'L') {
			dir = (dir + 3) % 4;
		}
		else {
			dir = (dir + 1) % 4;
		}
		answer[pi][pj] = '.';
		switch (dir) {
		default:
		case 0:
			for (int ii = pi; ii < n; ii++) {
				if (answer[ii][pj] != '.') {
					pi = ii - 1;
					break;
				}
				if (ii == n - 1) {
					pi = n - 1;
				}
			}
			break;
		case 1:
			for (int ii = pj; ii < n; ii++) {
				if (answer[pi][ii] != '.') {
					pj = ii - 1;
					break;
				}
				if (ii == n - 1) {
					pj = n - 1;
				}
			}
			break;
		case 2:
			for (int ii = pi; ii >= 0; ii--) {
				if (answer[ii][pj] != '.') {
					pi = ii + 1;
					break;
				}
				if (ii == 0) {
					pi = 0;
				}
			}
			break;
		case 3:
			for (int ii = pj; ii >= 0; ii--) {
				if (answer[pi][ii] != '.') {
					pj = ii + 1;
					break;
				}
				if (ii == 0) {
					pj = 0;
				}
			}
			break;
		}
		answer[pi][pj] = 'L';
	}

	for (int i = 0; i < dir; i++) {
		answer = Turn(answer, 1);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << answer[i][j];
		}
		cout << endl;
	}
}

