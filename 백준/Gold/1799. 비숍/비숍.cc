#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>

using namespace std;

int n;
int board[10][10];
vector<bool> cross1;
vector<bool> cross2;
int answer = 0;

void dfs(int cnt, int idxI, int idxJ) {
	if (answer < cnt) {
		answer = cnt;
	}
	for (int i = idxI;;) {
		for (int j = idxJ;;) {
			if (j >= n) {
				i++;
				j = (j % 2 == 0 ? 1 : 0);
			}
			if (i == n) {
				return;
			}
			if (board[i][j] == 1
				&& cross1[i + j] == false
				&& cross2[i - j + n - 1] == false) {

				board[i][j] = 2;
				cross1[i + j] = true;
				cross2[i - j + n - 1] = true;

				dfs(cnt + 1, i, j + 2);

				cross1[i + j] = false;
				cross2[i - j + n - 1] = false;
				board[i][j] = 1;
			}
			j += 2;
		}
	}

}

int main() {
	cin >> n;

	cross1.resize(2 * n - 1);
	cross2.resize(2 * n - 1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	dfs(0, 0, 0);
	int answer2 = answer;
	answer = 0;

	dfs(0, 0, 1);
	int answer1 = answer;
	cout << answer + answer2;
	return 0;
}