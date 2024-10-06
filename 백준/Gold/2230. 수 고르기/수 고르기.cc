#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

typedef long long ll;

#define endl '\n'
#define MAXNUM 1000001

int n, m;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string str;
	cin >> n >> m;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int answer = 2000000000;
	sort(arr.begin(), arr.end());
	for (int i = 0; i < n; i++) {
		auto l = lower_bound(arr.begin() + i, arr.end(), arr[i] + m) - arr.begin();
		if (l >= n) {
			continue;
		}
		int differ = arr[l] - arr[i];
		answer = min(answer, differ);
	}
	cout << answer;
}

