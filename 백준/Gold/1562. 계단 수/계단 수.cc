#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<unordered_map>

using namespace std;

#define MAXNUM 1000000000

int n;
vector<unordered_map<string, unordered_map<int,long long>>> arr1;

long long dfs(string visited, int idx, int num) {
	if (arr1[idx][visited][num] != 0)
	{
		return arr1[idx][visited][num];
	}
	else {
		if (idx == n - 1)
		{
			if (visited == "1111111111") {
				return arr1[idx][visited][num] = 1;
			}
			else {
				return 0;
			}
		}
		long long answer = 0;
		if (num > 0) {
			auto visited2 = visited;
			visited2[num - 1] = '1';
			answer += dfs(visited2, idx + 1, num - 1);
		}
		if (num < 9) {
			auto visited2 = visited;
			visited2[num + 1] = '1';
			answer += dfs(visited2, idx + 1, num + 1);
		}
		if (answer > 0) {
			cout << "";
		}
		return arr1[idx][visited][num] = answer % MAXNUM;
	}
}

int main() {
	cin >> n;

	string visited = "0000000000";
	arr1.resize(n + 1);
	long long answer = 0;
	for (int i = 1; i < 10; i++) {
		visited[i] = '1';
		answer += dfs(visited, 0, i);
		visited[i] = '0';
	}
	cout << answer % MAXNUM;
	return 0;
}