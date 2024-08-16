#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>

using namespace std;

#define endl '\n'

int n, m;
vector<vector<int>> problems;
vector<int> inDegrees;
vector<int> visited;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	problems.resize(n+1);
	inDegrees.resize(n+1);
	visited.resize(n+1);
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		problems[a].push_back(b);
		inDegrees[b]++;
	}

	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (inDegrees[i] == 0){
			q.push(i);
			break;
		}
	}

	while (!q.empty())
	{
		auto f = q.front();
		q.pop();
		visited[f] = true;
		cout << f << " ";
		for (int i = 0; i < problems[f].size(); i++) {
			inDegrees[problems[f][i]]--;
		}
		for (int i = 1; i <= n; i++) {
			if (visited[i] == false && inDegrees[i] == 0) {
				q.push(i);
				break;
			}
		}
	}
	
}