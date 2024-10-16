#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define endl '\n'

int n,s;
string str;
int arr[50];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cin >> s;

	for (int i = 0; i < n && s; i++) {
		vector<pair<int, int>> backVec;
		for (int j = i; j < n; j++) {
			backVec.push_back({ arr[j], j });
		}
		sort(backVec.begin(), backVec.end());
		int idx = i;
		for (int j = 0; j < backVec.size(); j++) {
			if ((backVec[j].second - i) <= s && backVec[j].first > arr[idx]) {
				idx = backVec[j].second;
			}
		}
		int tmp = arr[idx];
		for (int j = idx; j > i; j--) {
			arr[j] = arr[j - 1];
		}
		arr[i] = tmp;
		s -= (idx - i);
	}

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
}