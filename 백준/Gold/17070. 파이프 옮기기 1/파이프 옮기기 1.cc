#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

//0 hor 1 cross 2 verti

int main() {
	int n;
	cin >> n;
	vector<vector<vector<int>>> visited(n);
	vector<vector<int>> table(n);

	for (int i = 0; i < n; i++)	{
		table[i].resize(n);
		visited[i].resize(n);
		for (int j = 0; j < n; j++)		{
			cin >> table[i][j];
			visited[i][j].resize(3);
		}
	}

	visited[0][1][0] = 1;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (table[i][j] == 0 && !(i ==0 && j == 1))
			{
				for (int k = 0; k < 3; k++)
				{
					switch (k)
					{
					case 0:
						if (j > 0)
						{
							visited[i][j][0] = visited[i][j - 1][0] + visited[i][j - 1][1];
						}
						break;
					case 1:
						if (i > 0 && j > 0 && table[i-1][j] == 0 && table[i][j-1] == 0)
						{
							visited[i][j][1] = visited[i - 1][j - 1][0] + visited[i - 1][j - 1][1] + visited[i - 1][j - 1][2];
						}
						break;
					case 2:
						if (i > 0)
						{
							visited[i][j][2] = visited[i - 1][j][2] + visited[i - 1][j][1];
						}
						break;
					default:
						break;
					}
				}
			}

			//cout << visited[i][j][0] + visited[i][j][1] + visited[i][j][2] << " ";
		}
		//cout << endl;
	}

	cout << visited[n - 1][n - 1][0] + visited[n - 1][n - 1][1] + visited[n - 1][n - 1][2];

	return 0;
}