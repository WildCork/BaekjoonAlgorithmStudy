#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

#define endl '\n'

string str;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> str;
	vector<long long> zeroToNine(10);

	for (int i = 0; i < str.size(); i++) {
		long long powTen = 1;
		for (int j = i + 1; j < str.size(); j++) {
			powTen *= 10;
		}

		long long leftNum = 0;
		leftNum = stoi(str.substr(0, i + 1)) - 1;
		for (int j = 0; j < 10; j++) {
			if (j != 0 && leftNum % 10 >= j) {
				zeroToNine[j] += (leftNum / 10 + 1) * powTen;
			}
			else {
				zeroToNine[j] += (leftNum / 10) * powTen;
			}
		}

		if (i < str.size() - 1) {
			long long rightNum = stol(str.substr(i + 1)) + 1;
			zeroToNine[str[i] - '0'] += rightNum;
		}
	}

	zeroToNine[str.back() - '0']++;

	for (int i = 0; i < 10; i++) {
		cout << zeroToNine[i] << " ";
	}
}