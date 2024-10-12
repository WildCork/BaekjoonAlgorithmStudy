#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<unordered_map>

using namespace std;

typedef long long ll;

#define endl '\n'

int n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	vector<ll> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	int left = 0, right = arr.size() - 1;

	ll answer = 0;
	while (1) {
		if (left < n - 1 && arr[left] < 0 && arr[left + 1] <= 0) {
			answer += (arr[left] * arr[left + 1]);
		}
		else {
			break;
		}
		left += 2;
	}
	while (1) {
		if (right > 1 && arr[right] > 1 && arr[right - 1] > 1) {
			answer += (arr[right] * arr[right - 1]);
		}
		else {
			break;
		}
		right -= 2;
	}
	for (int i = left; i <= right; i++) {
		answer += arr[i];
	}
	cout << answer;
}

