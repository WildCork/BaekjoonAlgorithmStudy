#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<unordered_set>

using namespace std;

#define MAXNUM 1000000
#define endl '\n'

int n, r, c;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> r >> c;

	int answer = 0;
	while (r != 0 || c != 0) {
		int two = 2;
		while (two <= r || two <= c) { two *= 2; }
		two /= 2;
		int powTwo = two * two;
		if (two <= r && two > c) {
			answer += powTwo * 2;
			r -= two;
		}
		else if (two > r && two <= c) {
			answer += powTwo;
			c -= two;
		}
		else {
			answer += powTwo * 3;
			r -= two;
			c -= two;
		}
	}
	cout << answer;
}