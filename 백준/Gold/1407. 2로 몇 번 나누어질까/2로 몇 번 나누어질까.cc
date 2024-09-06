#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

typedef long long ll;

#define endl '\n'

ll a, b;

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	cin >> a >> b;

	ll two = 1, answer = 0, next_two = 2;
	a--;

	answer = b-a;
	while (next_two <= b) {
		answer += two * (b / next_two - a / next_two);
		two *= 2;
		next_two *= 2;
	}
	cout << answer;
}
