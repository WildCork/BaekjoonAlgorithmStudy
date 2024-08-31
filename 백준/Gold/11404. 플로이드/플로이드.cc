#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>

using namespace std;

typedef long long ll;
#define MAXNUM 10000001

#define endl '\n'
int n, m;
int a, b, c;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	vector<vector<int>> edges(n+1, vector<int>(n+1));
	for (int i = 1; i <= n; i++) {
		fill(edges[i].begin(), edges[i].end(), MAXNUM);
		edges[i][i] = 0;
	}
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		edges[a][b] = min(edges[a][b], c);
	}

	for (int a = 0; a < 3; a++) {

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				for (int k = 1; k <= n; k++) {
					if (edges[i][k] > edges[i][j] + edges[j][k]) {
						edges[i][k] = edges[i][j] + edges[j][k];
					}
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (edges[i][j] == MAXNUM) {
				edges[i][j] = 0;
			}
			cout << edges[i][j] << " ";
		}
		cout << endl;
	}

}