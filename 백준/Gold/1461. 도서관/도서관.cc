#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>

using namespace std;

typedef long long ll;

#define endl '\n'
#define MAXNUM 10000

int n, m, dummy;
vector<int> arr1, arr2;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> dummy;
		if (dummy > 0) {
			arr1.push_back(dummy);
		}
		else {
			arr2.push_back(-dummy);
		}
	}

	sort(arr1.begin(), arr1.end());
	sort(arr2.begin(), arr2.end());

	int answer1 = 0, answer2 = 0;

	int arr1Len = arr1.size();
	int arr2Len = arr2.size();

	if(!arr1.empty())
	for (int i = arr1Len % m - 1; i < arr1Len;) {
		if (i == arr1Len - 1) {
			answer1 += 2 * arr1.back();
			answer2 += arr1.back();
		}
		else if (i >= 0) {
			answer1 += 2 * arr1[i];
			answer2 += 2 * arr1[i];
		}
		i += m;
	}
	if (!arr2.empty())
	for (int i = arr2Len % m - 1; i < arr2Len;) {
		if (i == arr2Len - 1) {
			answer1 += arr2.back();
			answer2 += 2 * arr2.back();
		}
		else if (i >= 0) {
			answer1 += 2 * arr2[i];
			answer2 += 2 * arr2[i];
		}
		i += m;
	}

	cout << min(answer1, answer2);

	return 0;
}