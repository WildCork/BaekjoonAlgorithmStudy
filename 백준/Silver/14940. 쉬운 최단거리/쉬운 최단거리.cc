#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

#define MAXNUM 1000
#define endl '\n'

int n,m;
int arr[MAXNUM][MAXNUM];
int visited[MAXNUM][MAXNUM];
int di[4] = { 0,0,1,-1 };
int dj[4] = { 1,-1,0,0 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	int si, sj;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				si = i; sj = j;
			}
		}
	}

	queue<pair<int,int>> q;
	q.push({ si,sj});
	while (!q.empty())
	{
		auto f = q.front();
		int i = f.first;
		int j = f.second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			if (i + di[k] >= 0 && i + di[k] < n) {
				if (j + dj[k] >= 0 && j + dj[k] < m) {
					if (arr[i + di[k]][j + dj[k]] == 1 && !visited[i + di[k]][j + dj[k]]) {
						visited[i + di[k]][j + dj[k]] = visited[i][j] + 1;
						q.push({ i + di[k],j + dj[k] });
					}
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 1 && visited[i][j] == 0) {
				visited[i][j] = -1;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << visited[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}