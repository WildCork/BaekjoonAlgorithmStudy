#include<iostream>
#include<algorithm>
#include<vector>
#include<list>

using namespace std;

int board[5][5] = { 0 };
vector<vector<int>> nextBoard(5);

int Cost(int i, int order) {
	if (i == 0)	{
		return 2;
	}
	order--;
	i--;
	if ((i + 3) % 4 == order || (i + 1) % 4 == order) {
		return 3;
	}
	else if ((i + 2) % 4 == order) {
		return 4;
	}
	else {
		return 1;
	}
}

void Pump(int order) {
	for (int i = 0; i < 5; i++) {
		fill(nextBoard[i].begin(), nextBoard[i].end(), -1);
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (board[i][j] >= 0) {
				if (i != order) {
					if (nextBoard[i][order] < 0 || nextBoard[i][order] > board[i][j] + Cost(j, order)) {
						nextBoard[i][order] = board[i][j] + Cost(j, order);
					}
				}
				if (j != order) {
					if (nextBoard[order][j] < 0 || nextBoard[order][j] > board[i][j] + Cost(i, order)) {
						nextBoard[order][j] = board[i][j] + Cost(i, order);
					}
				}
			}
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			board[i][j] = nextBoard[i][j];
			//cout << board[i][j] << " ";
		}
		//cout << endl;
	}
	//cout << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int idx = 0, order = 0;

	for (int i = 0; i < 5; i++) {
		nextBoard[i].resize(5);
		fill(board[i], board[i] + 5, -1);
	}

	board[0][0] = 0;

	while (true) {
		cin >> order;
		if (order == 0) {
			break;
		}
		Pump(order);
		idx++;
	}

	int answer = -1;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (board[i][j] >= 0) {
				if (answer < 0 || answer > board[i][j]) {
					answer = board[i][j];
				}
			}
		}
	}

	cout << answer;
}