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
string answer = "";

void dfs(int cnt, string str) {
	if (cnt == n) {
		answer = str;
		return;
	}
	for (int k = 1; k <= 3; k++) {
		string dummy = (char)('0' + k) + str;
		bool isCheck = true;
		for (int l = 1; l * 2 <= dummy.size(); l++) {
			if (dummy.substr(0, l) == dummy.substr(l, l)) {
				isCheck = false;
				break;
			}
		}
		if (isCheck) {
			dfs(cnt + 1, dummy);
		}
		if (!answer.empty()) {
			return;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	dfs(0, "");
	reverse(answer.begin(), answer.end());
	cout << answer;
}

