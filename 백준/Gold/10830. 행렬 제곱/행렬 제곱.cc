#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;
#define endl '\n'

ll n, b, dummy;

ll arr[51][5][5];
ll calcul[5][5];
vector<vector<ll>> answer;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> b;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[0][i][j];
		}
	}

	for (int idx = 1; idx <= 50; idx++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dummy = 0;
				for (int k = 0; k < n; k++) {
					dummy += arr[idx - 1][i][k] * arr[idx - 1][k][j];
				}
				arr[idx][i][j] = dummy % 1000;
			}
		}
	}

	answer.resize(n);
	for (int i = 0; i < n; i++) {
		answer[i].resize(n);
		answer[i][i] = 1;
	}

	for (ll idx = 0; idx <= 50; idx++) {
		if ((b & (1LL << idx)) > 0) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					dummy = 0;
					for (int k = 0; k < n; k++) {
						dummy += answer[i][k] * arr[idx][k][j];
					}
					calcul[i][j] = dummy % 1000;
				}
			}
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					answer[i][j] = calcul[i][j];
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << answer[i][j] << " ";
		}
		cout << endl;
	}
}