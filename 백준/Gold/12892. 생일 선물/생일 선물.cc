#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<vector>
#include<string>

using namespace std;

#define endl '\n'
typedef long long ll;

int n, d;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> d;
	vector<pair<ll, ll>> input(n);
	for (int i = 0; i < n; i++) {
		cin >> input[i].first >> input[i].second;
	}

	sort(input.begin(), input.end());
	vector<ll> p(n), v(n), accv(n + 1);
	for (int i = 0; i < n; i++) {
		p[i] = input[i].first;
		v[i] = input[i].second;
	}

	for (int i = 0; i < n; i++) {
		accv[i + 1] = accv[i] + v[i];
	}

	ll answer = 0;
	for (int i = 0; i < n; i++) {
		auto l = lower_bound(p.begin() + i, p.end(), p[i] + d) - p.begin();
		answer = max(answer, accv[l] - accv[i]);
	}
	cout << answer;
}