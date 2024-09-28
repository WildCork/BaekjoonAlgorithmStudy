#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<unordered_map>

using namespace std;

typedef long long ll;

#define INF 200000000
#define endl '\n'

ll n, e, a, b, c, p, q;
ll edge[801][801];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> e;
	for (int i = 0; i <= 800; i++) {
		for (int j = 0; j <= 800; j++) {
			if (i == j) {
				edge[i][j] = 0;
			}
			else {
				edge[i][j]=INF;
			}
		}
	}
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		edge[a][b] = edge[b][a] = c;
	}
	cin >> p >> q;

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				edge[i][j] = min(edge[i][j], edge[i][k] + edge[k][j]);
			}
		}
	}

	ll answer = min(edge[1][p] + edge[n][q], edge[1][q] + edge[n][p]) + edge[p][q];
	if (answer >= INF) {
		cout << -1;
	}
	else {
		cout << answer;
	}
}

