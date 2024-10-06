#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>

using namespace std;

typedef long long ll;

#define endl '\n'

int n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	vector<string> arr1, arr2;
	arr1 = { "" };
	while (1) {
		for (int i = 0; i < arr1.size(); i++) {
			for (int j = 0; j < 10; j++) {
				if (arr1[i].size() > 0 && arr1[i].back() <= '0' + j) {
					break;
				}
				string dummy = arr1[i] + (char)('0' + j);
				arr2.push_back(dummy);
			}
		}
		if (arr2.empty()) {
			cout << -1;
			break;
		}
		if (arr2.size() < n) {
			n -= arr2.size();
			arr1 = arr2;
			arr2.clear();
		}
		else {
			cout << arr2[n - 1];
			break;
		}
	}
}

