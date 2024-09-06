#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;

typedef long long ll;
#define endl '\n'

int n;
ll arr[4000][4];
vector<ll> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			v.push_back(arr[i][2] + arr[j][3]);
		}
	}
	sort(v.begin(), v.end());
	ll answer = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ll half = -arr[i][0] - arr[j][1];
			auto l = lower_bound(v.begin(), v.end(), half);
			auto u = upper_bound(v.begin(), v.end(), half);
			answer += (u - l);
		}
	}
	cout << answer;
	return 0;
}


//