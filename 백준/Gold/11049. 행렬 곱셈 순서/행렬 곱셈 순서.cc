#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<numeric>

using namespace std;

#define endl '\n'

typedef long long ll;

int n;
int arr[500][2];
int dp[500][500];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i][0] >> arr[i][1];
	}

	for (int i = 0; i < n; i++) {
		for (int j = i; j >= 0; j--) {
			for (int k = i-1; k >= j; k--) {
				int sum = dp[j][k] + dp[k + 1][i] + arr[j][0] * arr[k][1] * arr[i][1];
				if (dp[j][i]) {
					dp[j][i] = min(dp[j][i], sum);
				}
				else {
					dp[j][i] = sum;
				}
			}
		}
		/*for (int a = 0; a <= i; a++) {
			for (int b = 0; b <= i; b++) {
				cout << dp[a][b] << " ";
			}
			cout << endl;
		}
		cout << endl;*/
	}
	cout << dp[0][n - 1];
}