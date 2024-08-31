#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

#define endl '\n'
int air1[51][51];
int air2[51][51];
int fanI1 = -1, fanI2 = -1;
int di[4] = { 0,0,1,-1 };
int dj[4] = { 1,-1,0,0 };
int r, c, t;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> r >> c >> t;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> air1[i][j];
			if (air1[i][j] < 0) {
				if (fanI1 < 0) {
					fanI1 = i;
					fanI2 = i + 1;
				}
				air1[i][j] = 0;
			}
		}
	}
	for (int T = 0; T < t; T++) {
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (air1[i][j]) {
					int sum = 0;
					int spread = air1[i][j] / 5;
					for (int k = 0; k < 4; k++) {
						int ni = i + di[k], nj = j + dj[k];
						if (ni >= 0 && ni < r && nj >= 0 && nj < c) {
							if (nj != 0 || (fanI1 != ni && fanI2 != ni)) {
								sum += spread;
								air2[ni][nj] += spread;
							}
						}
					}
					air1[i][j] -= sum;
				}
			}
		}
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (air1[i][j] >= 0) {
					air1[i][j] += air2[i][j];
				}
				air2[i][j] = 0;
			}
		}
		for (int i = fanI1; i > 0; i--) {
			air1[i][0] = air1[i - 1][0];
		}
		air1[fanI1][0] = 0;
		for (int j = 0; j < c - 1; j++) {
			air1[0][j] = air1[0][j + 1];
		}
		for (int i = 0; i < fanI1; i++) {
			air1[i][c-1] = air1[i + 1][c-1];
		}
		for (int j = c - 1; j > 0; j--) {
			air1[fanI1][j] = air1[fanI1][j - 1];
		}

		for (int i = fanI2; i < r - 1; i++) {
			air1[i][0] = air1[i + 1][0];
		}
		air1[fanI2][0] = 0;
		for (int j = 0; j < c - 1; j++) {
			air1[r - 1][j] = air1[r - 1][j + 1];
		}
		for (int i = r - 1; i > fanI2; i--) {
			air1[i][c - 1] = air1[i - 1][c - 1];
		}
		for (int j = c - 1; j > 0; j--) {
			air1[fanI2][j] = air1[fanI2][j - 1];
		}


		air1[fanI1][0] = 0;
		air1[fanI2][0] = 0;

	}
	int answer = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			answer += air1[i][j];
		}
	}
	cout << answer;
}


/*
7 8 100
0 0 0 0 0 0 0 9
0 0 0 0 3 0 0 8
-1 0 5 0 0 0 22 0
-1 8 0 0 0 0 0 0
0 0 0 0 0 10 43 0
0 0 5 0 15 0 0 0
0 0 40 0 0 0 20 0
*/