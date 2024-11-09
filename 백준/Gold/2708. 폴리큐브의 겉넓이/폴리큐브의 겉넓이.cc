#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<unordered_set>
#include<numeric>

using namespace std;

typedef long long ll;

#define endl '\n'
#define MAXNUM 6

int tc, n, cnt;
int arr[MAXNUM][MAXNUM][MAXNUM];
int visit[MAXNUM][MAXNUM][MAXNUM];

void check(string str, int idx) {
	int num1 = str[0] - '0';
	int num2 = str[2] - '0';
	int num3 = str[4] - '0';
	arr[num1][num2][num3] = idx;
}

void dfs(int i, int j, int k) {
	if (visit[i][j][k] || !arr[i][j][k]) {
		return;
	}
	visit[i][j][k] = 1;
	cnt++;
	if (i > 0) {
		dfs(i - 1, j, k);
	}
	if (i < (MAXNUM - 1)) {
		dfs(i + 1, j, k);
	}
	if (j > 0) {
		dfs(i, j - 1, k);
	}
	if (j < (MAXNUM - 1)) {
		dfs(i, j + 1, k);
	}
	if (k > 0) {
		dfs(i, j, k - 1);
	}
	if (k < (MAXNUM - 1)) {
		dfs(i, j, k + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> tc;
	for (int t = 0; t < tc; t++) {
		cin >> n;
		for (int i = 0; i < MAXNUM; i++) {
			for (int j = 0; j < MAXNUM; j++) {
				for (int k = 0; k < MAXNUM; k++) {
					arr[i][j][k] = 0;
					visit[i][j][k] = 0;
				}
			}
		}
		string str;
		for (int i = 0; i < n; i++) {
			cin >> str;
			check(str, i + 1);
		}
		cnt = 0;
		dfs(0, 0, 0);

		if (n > cnt) {
			cout << "NO " << cnt + 1 << endl;
		}
		else {
			int answer = 0;
			for (int i = 0; i < MAXNUM; i++) {
				for (int j = 0; j < MAXNUM; j++) {
					for (int k = 0; k < MAXNUM; k++) {
						if (arr[i][j][k]) {
							int dummy = 6;
							if (i > 0 && arr[i - 1][j][k]) {
								dummy--;
							}
							if (i < (MAXNUM - 1) && arr[i + 1][j][k]) {
								dummy--;
							}
							if (j > 0 && arr[i][j - 1][k]) {
								dummy--;
							}
							if (j < (MAXNUM - 1) && arr[i][j + 1][k]) {
								dummy--;
							}
							if (k > 0 && arr[i][j][k - 1]) {
								dummy--;
							}
							if (k < (MAXNUM - 1) && arr[i][j][k + 1]) {
								dummy--;
							}
							answer += dummy;
						}
					}
				}
			}
			cout << answer << endl;
		}
	}

	return 0;
}