#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<unordered_set>

using namespace std;

#define MAXNUM 1000000
#define endl '\n'

int n, m;
int dp[MAXNUM + 1];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;

	queue<pair<int,int>> q;
	q.push({ m , 1});
	while (!q.empty()) {
		auto f = q.front();
		int p = f.first;
		int cost = f.second;
		q.pop();

		if (dp[n] > 0 && dp[n] < cost) {
			continue;
		}

		if (dp[p] == 0 || dp[p] > cost) {
			dp[p] = cost;
		}
		else {
			continue;
		}

		if (p % 2 == 0 && p > n) {
			q.push({ p / 2,cost + 1 });
		}
		if (p > 0) {
			q.push({ p - 1,cost + 1 });
		}
		if (p < MAXNUM) {
			q.push({ p + 1,cost + 1 });
		}
	}
	cout << dp[n] - 1;
}