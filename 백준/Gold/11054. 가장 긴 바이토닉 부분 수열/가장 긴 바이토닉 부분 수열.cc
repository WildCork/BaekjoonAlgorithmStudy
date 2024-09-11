#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>

#define endl '\n'

using namespace std;

typedef long long ll;
int n;
int arr[1001];
int dp1[1001];
int dp2[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int i = 0;
	int answer = 0;
	for (int i = 0; i < n; i++) {
		dp1[arr[i]] = *max_element(dp1, dp1 + arr[i]) + 1;
		dp2[arr[i]] = *max_element(dp2 + arr[i] + 1, dp2 + 1001) + 1;
		dp2[arr[i]] = max(dp2[arr[i]], dp1[arr[i]]);
	}
	cout << *max_element(dp2, dp2 + 1001);
}
