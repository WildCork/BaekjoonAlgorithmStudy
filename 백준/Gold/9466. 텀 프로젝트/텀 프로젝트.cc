#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>

#define endl '\n'

using namespace std;

typedef long long ll;

int n, tc;
int arr[100001];
int visited[100001];

//1 cur 2 no team 3 already team

int dfs(int i) {
	if (arr[i] == i) {
		visited[i] = 3;
		return 2;
	}
	if (visited[i] == 0) {
		visited[i] = 1;
		int dummy = dfs(arr[i]);
		if (dummy == 3) {
			if (visited[i] == 1) {
				return visited[i] = 3;
			}
			else {
				return 2;
			}
		}
		else {
			return visited[i] = dummy;
		}
	}
	if (visited[i] == 1) {
		return visited[i] = 3;
	}
	return 2;
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	cin >> tc;
	for (int t = 0; t < tc; t++) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
			visited[i] = 0;
		}
		for (int i = 1; i <= n; i++) {
			if (!visited[i]) {
				dfs(i);
			}
		}
		cout << count(visited, visited + n + 1, 2) << endl;
	}
}
