#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

#define endl '\n'


long long n;
long long cnt = 0;
vector<long long> v(0);
vector<long long> divideNums;

vector<long long> dividers(long long n) {
	long long d = 2;
	vector<long long> answer;
	long long sqrtNum = (long long)sqrt(n);
	while (d <= sqrtNum) {
		if (n%d == 0) {
			answer.push_back(d);
			while (n%d == 0) { n /= d; }
			d = 1;
			sqrtNum = (long long)sqrt(n);
		}
		d++;
	}
	if (n != 1) {
		answer.push_back(n);
	}
	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	divideNums = dividers(n);

	long long answer = n;
	for (int i = 0; i < divideNums.size(); i++) {
		answer /= divideNums[i];
		answer *= (divideNums[i] - 1);
	}
	cout << answer;
}