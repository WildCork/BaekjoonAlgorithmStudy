#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

#define MAXNUM 1000000
#define endl '\n'

int n;
int arr[MAXNUM];
int dp[MAXNUM];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;

	int dp_len = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		auto here = lower_bound(dp, dp + dp_len, arr[i]);
		*here = arr[i];
		if (here == dp+dp_len)		{
			dp_len++;
		}
	}

	cout << dp_len;


	return 0;
}