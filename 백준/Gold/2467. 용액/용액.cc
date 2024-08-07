#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;

	vector<int> liquids(n);
	for (int i = 0; i < n; i++) {
		cin >> liquids[i];
	}

	int left = 0, right = n - 1;
	int differ = -1;
	int alkari, acid;
	sort(liquids.begin(), liquids.end());
	while (left < right) {
		while (left < right && liquids[left] + liquids[right] > 0) { right--; }
		if (left < right) {
			if (differ < 0 || differ > abs(liquids[left] + liquids[right])) {
				alkari = left, acid = right;
				differ = abs(liquids[left] + liquids[right]);
			}
		}
		right++;
		if (right >= n) { right = n - 1; }
		if (differ < 0 || differ > abs(liquids[left] + liquids[right])) {
			alkari = left, acid = right;
			differ = abs(liquids[left] + liquids[right]);
		}
		left++;
	}

	cout << liquids[alkari] << " " << liquids[acid];

}