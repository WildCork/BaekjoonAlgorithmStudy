#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

typedef long long ll;

#define MAXNUM 300001
#define endl '\n'

int n,m;
int oven[MAXNUM], pizza[MAXNUM];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n>>m;
	vector<int> minOven;
	for (int i = 0; i < n; i++) {
		cin >> oven[i];
		if (minOven.empty()) {
			minOven.push_back(oven[i]);
		}
		else {
			minOven.push_back(min(minOven.back(), oven[i]));
		}
	}
	reverse(minOven.begin(), minOven.end());
	int deep = 0;
	for (int i = 0; i < m; i++) {
		cin >> pizza[i];
		auto l = lower_bound(minOven.begin() + deep, minOven.end(), pizza[i]);
		if (l == minOven.end()) {
			deep = -1;
			break;
		}
		else {
			deep = distance(minOven.begin(), l) + 1;
		}
	}
	if (deep < 0) {
		cout << 0;
	}
	else {
		cout << n - deep + 1;
	}
}

