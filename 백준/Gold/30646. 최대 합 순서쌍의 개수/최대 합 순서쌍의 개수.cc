#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;

typedef long long ll;

#define endl '\n'

int n, m;
ll arr[200000], acc[200001];
unordered_map<int, int> startIndex, endIndex;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		acc[i + 1] = acc[i] + arr[i];
		if (startIndex.count(arr[i]) == 0) {
			startIndex[arr[i]] = i;
		}
		endIndex[arr[i]] = i;
	}
	ll answer = 0, cnt = 0;
	for (auto it = startIndex.begin(); it != startIndex.end(); it++) {
		ll acc_ = acc[endIndex[it->first] + 1] - acc[startIndex[it->first]];
		if (answer < acc_) {
			answer = acc_;
			cnt = 1;
		}
		else if (answer == acc_) {
			cnt++;
		}
	}
	cout << answer << " " << cnt;
}

