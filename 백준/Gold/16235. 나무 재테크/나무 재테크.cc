#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m, k;
int forest[10][10];
int nutrients[10][10];
int trees[10][10][10000];
int treesCnt[10][10];
int answer = 0;

int dx[8] = {-1,-1,-1,0,0 , 1,1,1};
int dy[8] = {-1, 1, 0,1,-1,-1,1,0};

void Spring()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (treesCnt[i][j] > 0)
			{
				sort(trees[i][j], trees[i][j] + treesCnt[i][j]);
				int dead_trees_nutrients = 0;
				int aliveCnt = 0;
				for (int k = 0; k < treesCnt[i][j]; k++)
				{
					if (forest[i][j] >= trees[i][j][k])
					{
						forest[i][j] -= trees[i][j][k];
						trees[i][j][k]++;
						aliveCnt++;
					}
					else
					{
						dead_trees_nutrients += trees[i][j][k] / 2;
						trees[i][j][k] = 0;
					}
				}
				treesCnt[i][j] = aliveCnt;
				forest[i][j] += dead_trees_nutrients;
			}
		}
	}
}


void Autumn()
{

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (treesCnt[i][j] > 0) {
				for (int k = 0; k < treesCnt[i][j]; k++) {
					if (trees[i][j][k] % 5 == 0) {
						for (int p = 0; p < 8; p++) {
							int ni = i + dx[p];
							int nj = j + dy[p];
							if (ni >= 0 && ni < n && nj >= 0 && nj < n) {
								trees[ni][nj][treesCnt[ni][nj]++] = 1;
							}
						}
					}
				}
			}
		}
	}
}

void Winter()
{

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			forest[i][j] += nutrients[i][j];
		}
	}
}


int main()
{
	cin >> n >> m >> k;
	int a, b, c;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> nutrients[i][j];
			forest[i][j] = 5;
		}
	}

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		trees[a - 1][b - 1][treesCnt[a - 1][b - 1]++] = c;
	}
	for (int i = 0; i < k; i++)
	{
		Spring();
		Autumn();
		Winter();
	}

	answer = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			answer += treesCnt[i][j];
		}
	}
	
	cout << answer<<endl;
}

//
//5 2 7
//2 3 2 3 2
//2 3 2 3 2
//2 3 2 3 2
//2 3 2 3 2
//2 3 2 3 2
//2 1 3
//3 2 3
//
