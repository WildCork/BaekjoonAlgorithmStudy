#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

typedef long long ll;

#define endl '\n'

int n, k;
int arr[50] = {};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int answer = 0;

	while (true) {
		bool isNotZero = true;
		for (int i = 0; i < n; i++) {
			if (arr[i]%2 == 1) {
				arr[i] -= 1;
				answer++;
			}
			if (arr[i] != 0) {
				isNotZero = false;
			}
		}

		if (isNotZero) {
			break;
		}
		else {
			for (int i = 0; i < n; i++) {
				arr[i] /= 2;
			}
			answer++;
		}
	}
	cout << answer;
}