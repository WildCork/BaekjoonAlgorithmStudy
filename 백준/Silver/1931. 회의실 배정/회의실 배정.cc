#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

#define MAXNUM 100000
#define endl '\n'

int dp[MAXNUM] = { 0 };

int n;
bool visited[21] = { 0 };

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second != b.second) {
		return a.second < b.second;
	}
	return a.first < b.first;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n; 
	int a, b;
	vector<pair<int, int>> semina(n);
	for (int i = 0; i < n; i++)	{
		cin >> semina[i].first >> semina[i].second;
	}
	sort(semina.begin(), semina.end(),cmp);
	int cnt = 1;
	int time = semina[0].second;
	for (int i = 1; i < n; i++){
		if (time <= semina[i].first) {
			time = semina[i].second;
			cnt++;
		}
	}
	cout << cnt;
}