#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, answer = 0;
vector<vector<int>> dice;
vector<vector<int>> procession;

vector<vector<int>> Rotate(vector<vector<int>> dice) {
	vector<vector<int>> dice_ = dice;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dice_[n - 1 - j][i] = dice[i][j];
		}
	}
	return dice_;
}

void Move(vector<vector<int>> dice_, int cnt) {
	for (int k = 0; k < 4; k++) {
		auto dice = dice_;
		for (int i = 0; i < n; i++) {
			vector<int> arr;
			for (int j = 0; j < n; j++) {
				if (dice[i][j]) {
					if (!arr.empty() && arr.back() < 0) {
						arr.back() = dice[i][j];
					}
					else if (arr.empty() || arr.back() != dice[i][j]) {
						arr.push_back(dice[i][j]);
					}
					else {
						arr.back() *= 2;
						arr.push_back(-1);
					}
				}
			}
			if (!arr.empty() && arr.back() < 0)arr.pop_back();
			for (int j = 0; j < n; j++) {
				if (arr.size() <= j) {
					dice[i][j] = 0;
				}
				else {
					dice[i][j] = arr[j];
				}
			}
		}
		for (int i = 0; i < n; i++) {
			answer = max(answer, *max_element(dice[i].begin(), dice[i].end()));
		}
		if (cnt < 4) Move(dice, cnt + 1);
		if (k < 3)dice_ = Rotate(dice_);
	}
}

int main() {
	cin >> n;
	dice.resize(n);
	for (int i = 0; i < n; i++) {
		dice[i].resize(n);
		for (int j = 0; j < n; j++) {
			cin >> dice[i][j];
		}
	}

	Move(dice, 0);
	cout << answer;
}


/*
4
2 2 4 8
2 2 4 8
4 4 8 16
8 8 16 32
*/