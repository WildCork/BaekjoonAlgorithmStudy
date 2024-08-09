#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<set>

using namespace std;

int main() {
	string s1, s2;
	cin >> s1 >> s2;

	int len = 0;
	pair<int, int> p = {0,0};
	string answer = "";
	int check[1001][1001] = {};
	for (int i = 1; i <= s1.size(); i++) {
		for (int j = 1; j <= s2.size(); j++) {
			if (s1[i - 1] == s2[j - 1]) {
				check[i][j] = check[i - 1][j - 1] + 1;
			}
			else {
				check[i][j] = max(check[i][j - 1], check[i - 1][j]);
			}
			if (len < check[i][j]) {
				len = check[i][j];
				p = { i,j };
			}
		}
	}

	while (check[p.first][p.second] > 0)
	{
		if (check[p.first][p.second] == check[p.first - 1][p.second]) {
			p.first--;
		}
		else if (check[p.first][p.second] == check[p.first][p.second - 1]) {
			p.second--;
		}
		else if (check[p.first][p.second] == check[p.first - 1][p.second - 1]) {
			p.first--;
			p.second--;
		}
		else {
			answer = s1[p.first - 1] + answer;
			p.first--;
			p.second--;
		}
	}
	cout << len << endl << answer;
	return 0;
}

