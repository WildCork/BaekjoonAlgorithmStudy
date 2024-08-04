#include <iostream>
#include <algorithm>

using namespace std;

#define MAXNUM 100000
long long arr[MAXNUM];
long long sum[MAXNUM];

int main() {
	long long n, m;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + arr[i - 1];
	}
	long long answer = -1;
	for (int i = 0; i <= n; i++) {
		int left = i, right = n;
		while (left <= right) {
			long long mid = (left + right) / 2;

			if (sum[mid] - sum[i] >= m) {
				if (answer < 0 || answer > mid - i) {
					answer = mid - i;
				}
				right = mid - 1;
			}
			else if (sum[mid] - sum[i] < m) {
				left = mid + 1;
			}
		}
	}
	if (answer < 0) { answer = 0; }
	cout << answer;
}