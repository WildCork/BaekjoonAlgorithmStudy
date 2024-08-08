#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>

using namespace std;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

set<int> dir;
vector<vector<int>> v(2);

int main() {
	int n;
	cin >> n;
	vector<int> dir(6), len(6);
	for (int i = 0; i < 6; i++)
	{
		cin >> dir[i] >> len[i];
		v[dir[i] <= 2? 0 : 1].push_back(len[i]);
	}
	int maxLenI = *max_element(v[0].begin(), v[0].end());
	int maxLenJ = *max_element(v[1].begin(), v[1].end());

	int minLenI, minLenJ;
	for (int i = 0; i < 6; i++) {
		if (dir[i] == dir[(i + 2) % 6] && dir[(i + 1) % 6] == dir[(i + 3) % 6]) {
			minLenI = len[(i + 2) % 6];
			minLenJ = len[(i + 1) % 6];
		}
	}
	cout << (maxLenI * maxLenJ - minLenI * minLenJ) * n;
}