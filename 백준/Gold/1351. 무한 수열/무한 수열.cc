#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

typedef long long ll;

#define endl '\n'

ll n, p, q;

unordered_map<ll, ll> dp;

ll solve(ll idx) {
	if (dp.count(idx) > 0) {
		return dp[idx];
	}
	return dp[idx] = solve(idx / p) + solve(idx / q);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> p >> q;
	dp[0] = 1;
	cout << solve(n);
}