#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

typedef long long ll;

#define endl '\n'

int n, x, y;
ll arr[1500][2];
ll dis[1500][1500];

void Distance(int a, int b) {
	dis[a][b] = dis[b][a]
		= (arr[a][0] - arr[b][0]) * (arr[a][0] - arr[b][0])
		+ (arr[a][1] - arr[b][1]) * (arr[a][1] - arr[b][1]);
}

bool isAnswer(int a, int b, int c) {
	return
		(dis[a][b] + dis[b][c] == dis[c][a]) ||
		(dis[a][c] + dis[b][c] == dis[b][a]) ||
		(dis[a][b] + dis[a][c] == dis[c][b]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i][0] >> arr[i][1];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			Distance(i, j);
		}
	}
	int answer = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			for (int k = j+1; k < n; k++) {
				answer += isAnswer(i, j, k);
			}
		}
	}
	cout << answer;
}

