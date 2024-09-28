#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;

#define endl '\n'

int n, tc;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	vector<int> arr1(n),arr2;
	unordered_map<int, int> um1,um2;
	for (int i = 0; i < n; i++) {
		cin >> arr1[i];
		um1[arr1[i]]++;
	}
	arr2 = arr1;
	sort(arr2.begin(), arr2.end());
	for (int i = 0; i < n-1; i++) {
		if (arr2[i] != arr2[i+1]) {
			um2[arr2[i]] += (um1[arr2[i]] - 1);
			for (int j = 2; arr2[i] * j <= arr2.back(); j++) {
				auto l = lower_bound(arr2.begin(), arr2.end(), arr2[i]*j);
				auto u = upper_bound(arr2.begin(), arr2.end(), arr2[i]*j);
				if (u - l > 0) {
					um2[arr2[i] * j] += um1[arr2[i]];
				}
			}
		}
	}
	um2[arr2.back()] += (um1[arr2.back()] - 1);
	for (int i = 0; i < n; i++) {
		cout << um2[arr1[i]] << endl;
	}
}
