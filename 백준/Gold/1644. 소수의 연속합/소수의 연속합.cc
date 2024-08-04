#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

#define MAXNUM 4000001
long long arr[MAXNUM];
vector<long long> primes;

int main() {
	int n;
	cin >> n;
	int m = sqrt(n);

	for (int i = 2; i <= m; i++) {
		for (int j = 2; i * j <= n; j++) {
			arr[i * j] = 1;
		}
	}

	primes.push_back(0);
	for (int i = 2; i <= n; i++) {
		if (arr[i] == 0) {
			primes.push_back(i + primes.back());
		}
	}
	int answer = 0;
	for (int i = 0; i < primes.size(); i++) {
		int left = i, right = primes.size() - 1;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (primes[mid] - primes[i] == n) {
				answer++;
				break;
			}
			else if (primes[mid] - primes[i] > n) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
	}
	cout << answer;
}