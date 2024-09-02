#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>

using namespace std;

#define endl '\n'
#define MAXNUM 100001

int n;
int a, b, c;

vector<pair<int,int>> caveCost[MAXNUM];
int answer[MAXNUM];
int energy[MAXNUM];
int costSum[MAXNUM];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> energy[i];
	}
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b >> c;
		caveCost[a].push_back({ b,c });
		caveCost[b].push_back({ a,c });
	}

	queue<vector<int>> q;
	q.push({1});
	
	while (!q.empty()) {
		auto f = q.front();
		q.pop();
		b = f.back();

		int left = 0, mid, right = f.size() - 1;
		int checkEnergy = costSum[b] - energy[b];
		if (checkEnergy <= 0) {
			answer[b] = 1;
		}
		else {
			while (left < right - 1) {
				mid = (left + right) / 2;
				if (costSum[f[mid]] > checkEnergy) {
					right = mid;
				}
				else {
					left = mid;
				}
			}
			if (costSum[f[left]] == checkEnergy) {
				answer[b] = f[left];
			}
			else {
				answer[b] = f[right];
			}
		}

		for (int i = 0; i < caveCost[b].size(); i++) {
			int idx = caveCost[b][i].first;
			int cost = caveCost[b][i].second;

			if (idx != 1) {
				if (costSum[idx] == 0 || costSum[idx] > costSum[b] + cost) {
					costSum[idx] = costSum[b] + cost;
					f.push_back(idx);
					q.push(f);
					f.pop_back();
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << answer[i] << endl;
	}
	return 0;
}

/*
10
123 1
2737 1
757148 1
78466 2
32888 2
777770 5
436659 2
431159 7
112233 3
456789 10
*/