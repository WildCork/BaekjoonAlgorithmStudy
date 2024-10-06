#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>

using namespace std;

typedef long long ll;

#define endl '\n'
#define MAXNUM 1000001

int n, m;

ll isNotPrime[MAXNUM];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	isNotPrime[0] = 0;
	isNotPrime[1] = 1;
	for (int i = 2; i <= MAXNUM; i++) {
		for (int j = 2; i*j <= MAXNUM; j++) {
			isNotPrime[i * j] = i;
		}
	}

	ll sum_[MAXNUM];
	sum_[1] = 1;
	ll acc[MAXNUM];
	acc[1] = 1;
	for (int i = 2; i < MAXNUM; i++) {
		if (isNotPrime[i]) {
			ll maxDiv = isNotPrime[i];
			ll nn = i / maxDiv;
			sum_[i] = sum_[maxDiv];
			if (maxDiv%nn == 0) {
				ll ii = i;
				ll div = 1;
				while (ii % nn == 0) {
					ii /= nn;
					div *= nn;
				}
				sum_[i] += (div)*sum_[ii];
			}
			else {
				sum_[i] += sum_[maxDiv] * nn;
			}
		}
		else {
			sum_[i] = i + 1;
		}
		acc[i] = acc[i - 1] + sum_[i];
	}

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> m;
		cout << acc[m] << endl;
	}
}

