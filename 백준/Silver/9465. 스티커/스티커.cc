#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

#define endl '\n'

int t, n;
vector<vector<int>> table(2);

int main() {
	cin >> t;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for (int tc = 1; tc <= t; tc++) {
		cin >> n;
		for (int i = 0; i < 2; i++) {
			table[i].resize(n);
			for (int j = 0; j < n; j++) {
				cin >> table[i][j];
			}
		}

		vector<vector<int>> dp(2, vector<int>(n));
		dp[0][0] = table[0][0];
		dp[1][0] = table[1][0];

		for (int i = 1; i < n; i++) {
			for (int j = 0; j < 2; j++) {
				if (i == 1) {
					dp[j][i] = table[j][i] + dp[!j][i - 1];
				}
				else {
					dp[j][i] = table[j][i] + max(dp[!j][i - 1], dp[!j][i - 2]);
				}
			}
		}
		cout << max(dp[0].back(), dp[1].back()) << endl;
	}
}