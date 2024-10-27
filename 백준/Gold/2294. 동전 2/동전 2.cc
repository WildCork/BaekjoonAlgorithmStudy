#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

typedef long long ll;

#define endl '\n'

int n, k;
int arr[100] = {};
int visited[10001] = {};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	visited[0] = 1;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i <= k; i++) {
		for (int j = 0; j < n; j++) {
			int idx = i - arr[j];
			if (idx >= 0 && visited[idx] > 0) {
				if (visited[i] == 0 || visited[i] > visited[idx] + 1) {
					visited[i] = visited[idx] + 1;
				}
			}
		}
	}
	cout << visited[k] - 1;
}