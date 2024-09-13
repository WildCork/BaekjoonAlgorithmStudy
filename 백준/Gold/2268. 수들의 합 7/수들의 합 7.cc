#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;
#define endl '\n'

ll a, b, c, n, m;
ll penwick[1000001];
ll arr[1000001];

ll find(ll i) {
	ll answer = 0;
	while (i > 0) {
		answer+=penwick[i];
		i -= (i&-i);
	}
	return answer;
}

void update(ll i, ll val) {
	while (i <= n) {
		penwick[i] += val;
		i += (i&-i);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		if (a == 0) {
			int left = min(c, b);
			int right = max(c, b);
			cout << abs(find(right) - find(left - 1)) << endl;
		}
		else {
			ll differ = c - arr[b];
			update(b, differ);
			arr[b] = c;
		}
	}
}