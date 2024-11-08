#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>

using namespace std;

typedef long long ll;

#define endl '\n'
#define MAXNUM 10000

int n;
vector<int> arr1, arr2;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	vector<int> answer;

	for (int i = 1; i * i < n; i++) {
		if (n%i == 0) {
			int a = n / i;
			int b = i;
			if ((a+b)%2 == 0) {
				answer.push_back((a + b) / 2);
			}
		}
	}
	sort(answer.begin(), answer.end());
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << endl;
	}
	if (answer.empty()) {
		cout << -1;
	}
	return 0;
}