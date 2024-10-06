#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>

using namespace std;

typedef long long ll;

#define endl '\n'

int n, m;

bool isNotPrime(int number) {
	int nn = sqrt(number);
	if (number == 1) {
		return true;
	}
	for (int i = 2; i <= nn; i++) {
		if (number % i == 0) {
			return true;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	vector<string> answer1, answer2;
	answer1 = { "" };
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < answer1.size(); i++) {
			for (int j = 0; j < 10; j++) {
				if (k == 0 && j == 0) {
					continue;
				}
				string dummy = answer1[i] + (char)('0' + j);
				int num = stoi(dummy);
				if (isNotPrime(num) == false) {
					answer2.push_back(dummy);
				}
			}
		}
		answer1 = answer2;
		answer2.clear();
	}
	for (int i = 0; i < answer1.size(); i++) {
		cout << answer1[i] << endl;
	}
}

