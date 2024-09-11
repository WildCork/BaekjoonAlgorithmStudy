#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_set>
#include<queue>

using namespace std;

typedef long long ll;

#define endl '\n'
int n;
ll arr[5000];
vector<vector<ll>> arr2;

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	ll answer = abs(arr[0] + arr[1] + arr[2]);
	vector<ll> v = { arr[0] , arr[1] , arr[2] };
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			int check = -(arr[i] + arr[j]);
			auto l = lower_bound(arr, arr + n, check) - arr;
			for (int k = l; k < n; k++) {
				if (k != i && k != j) {
					if (answer > abs(arr[i] + arr[j] + arr[k])) {
						answer = abs(arr[i] + arr[j] + arr[k]);
						v = { arr[i] , arr[j] , arr[k] };
					}
					break;
				}
			}
			for (int k = l - 1; k >= 0; k--) {
				if (k != i && k != j) {
					if (answer > abs(arr[i] + arr[j] + arr[k])) {
						answer = abs(arr[i] + arr[j] + arr[k]);
						v = { arr[i] , arr[j] , arr[k] };
					}
					break;
				}
			}
		}
	}

	for (int i = 0; i < 3; i++) {
		cout << v[i] << " ";
	}
}
