#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

#define endl '\n'

int n, m, k, s, x, y;
int arr[200][200];
int di[4] = { 0,0,1,-1 };
int dj[4] = { 1,-1,0,0 };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	cin >> s >> x >> y;
	x--; y--;
	while (s && !arr[x][y]) {
		vector<vector<int>> arr2(n, vector<int>(n));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][j] == 0) {
					int dummy = 0;
					for (int k = 0; k < 4; k++) {
						int ni = i + di[k];
						int nj = j + dj[k];
						if (ni >= 0 && ni < n && nj >= 0 && nj < n) {
							if (arr[ni][nj] > 0) {
								if (dummy == 0 || dummy > arr[ni][nj]) {
									dummy = arr[ni][nj];
								}
							}
						}
					}
					arr2[i][j] = dummy;
				}
			}
		}
		s--;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				arr[i][j] += arr2[i][j];
			}
		}
	}
	cout << arr[x][y];
}