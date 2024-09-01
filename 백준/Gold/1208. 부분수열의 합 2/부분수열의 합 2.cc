#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

#define endl '\n'

typedef long long ll;

int n, s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> s;
	int m = n / 2, dummy;
	vector<int> la, ra;
	for (int i = 0; i < n; i++) {
		cin >> dummy;
		if (i < m) {
			la.push_back(dummy);
		}
		else {
			ra.push_back(dummy);
		}
	}

	vector<int> ls, rs;
	for (int i = 0; i < (1 << la.size()); i++) {
		int sum = 0;
		for (int j = 0; j < la.size(); j++) {
			if (i & 1 << j) {
				sum += la[j];
			}
		}
		ls.push_back(sum);
	}
	for (int i = 0; i < (1<<ra.size()); i++) {
		int sum = 0;
		for (int j = 0; j < ra.size(); j++) {
			if (i & 1 << j) {
				sum += ra[j];
			}
		}
		rs.push_back(sum);
	}
	ll answer = 0;
	sort(rs.begin(), rs.end());
	for (ll i = 0; i < ls.size(); i++) {
		auto f = s - ls[i];
		auto l = lower_bound(rs.begin(), rs.end(), f);
		auto u = upper_bound(rs.begin(), rs.end(), f);
		answer += (u - l);
	}
	if (s == 0) {
		answer--;
	}
	cout << answer;
}
