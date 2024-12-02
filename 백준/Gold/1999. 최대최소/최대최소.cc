#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

typedef long long ll;

#define endl '\n'

int n, b, k;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> b >> k;
	vector<vector<int>> v1(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> v1[i][j];
		}
	}

	vector<vector<int>> small(n - b  + 1, vector<int>(n-b+1));
	vector<vector<int>> big(n - b + 1, vector<int>(n-b+1));
	for (int i = 0; i < n - b + 1; i++) {
		for (int j = 0; j < n - b + 1; j++) {
			small[i][j] = v1[i][j];
			big[i][j] = v1[i][j];
			for (int l = 0; l < b; l++) {
				small[i][j] = min(small[i][j], *min_element(v1[i + l].begin() + j, v1[i + l].begin() + j + b));
				big[i][j] = max(big[i][j], *max_element(v1[i + l].begin() + j, v1[i + l].begin() + j + b));
			}
		}
	}

	int ii, jj;
	for (int i = 0; i < k; i++) {
		cin >> ii >> jj;
		cout << big[ii - 1][jj - 1] - small[ii - 1][jj - 1] << endl;
	}
}