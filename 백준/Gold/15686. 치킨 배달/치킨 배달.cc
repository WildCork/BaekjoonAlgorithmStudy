#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_set>

using namespace std;

int n, m;
int visited[25001];
vector<int> house, chicken;
int table[50][50];
int Distance[2501][2501];
int answer = -1;

void Combination(int idx, int cnt)
{
	int allDis = 0;
	if (cnt > 0)
	{
		for (int i = 0; i < house.size(); i++)
		{
			int dis = -1;
			for (int j = 0; j < cnt; j++)
			{
				if (dis < 0 || dis > Distance[house[i]][visited[j]])
				{
					dis = Distance[house[i]][visited[j]];
				}
			}
			allDis += dis;
		}
		if (answer <0 || answer > allDis)
		{
			answer = allDis;
		}
	}
	if (cnt < m)
	{
		for (int i = idx; i < chicken.size(); i++)
		{
			visited[cnt] = chicken[i];
			Combination(i + 1, cnt + 1);
		}
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> table[i][j];
			if (table[i][j] == 1)
			{
				house.push_back(i * 50 + j);
			}
			else if (table[i][j] == 2)
			{
				chicken.push_back(i * 50 + j);
			}
		}
	}
	for (int i = 0; i < house.size(); i++)
	{
		for (int j = 0; j < chicken.size(); j++)
		{
			Distance[house[i]][chicken[j]] = abs(house[i] / 50 - chicken[j] / 50) + abs(house[i] % 50 - chicken[j] % 50);
		}
	}
	Combination(0, 0);
	cout << answer;
}
