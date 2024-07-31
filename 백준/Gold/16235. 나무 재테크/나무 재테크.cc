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

int dx[8] = { -1,-1,-1,0,0 , 1,1,1 };
int dy[8] = { -1, 1, 0,1,-1,-1,1,0 };

void Spring()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (treesCnt[i][j] > 0)
			{
				sort(trees[i][j], trees[i][j] + treesCnt[i][j]);
				for (int k = 0; k < treesCnt[i][j]; k++)
				{
					if (forest[i][j] >= trees[i][j][k])
					{
						forest[i][j] -= trees[i][j][k];
						trees[i][j][k]++;
					}
					else
					{
						treesCnt[i][j] = k;
						break;
					}
				}
			}
		}
	}
}

void Summer()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = treesCnt[i][j]; trees[i][j][k] > 0; k++)
			{
				forest[i][j] += trees[i][j][k] / 2;
				trees[i][j][k] = 0;
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
							if (i + dx[p] >= 0 && i + dx[p] < n) {
								if (j + dy[p] >= 0 && j + dy[p] < n) {
									trees[i + dx[p]][j + dy[p]][treesCnt[i + dx[p]][j + dy[p]]++] = 1;
								}
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
		Summer();
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

	cout << answer << endl;
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