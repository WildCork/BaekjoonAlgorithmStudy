#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

typedef long long ll;

#define endl '\n'

int tc, n, k;
ll all_cnt = 0;

ll factorial(ll n) {
	ll answer = 1;
	for (ll i = 2; i <= n; i++) {
		answer *= i;
	}
	return answer;
}

ll combination(int n, int k) {
	return factorial(n) / factorial(n - k) / factorial(k);
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> t >> n >> k;
		all_cnt = factorial(n);

		for (int i = 1; i <= k; i++) {
			if (i % 2 == 1) {
				all_cnt -= combination(k, i) * factorial(n - i);
			}
			else {
				all_cnt += combination(k, i) * factorial(n - i);
			}
		}
		cout << t << " " << all_cnt << endl;
	}
}