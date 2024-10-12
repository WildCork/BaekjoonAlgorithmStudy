#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<unordered_map>

using namespace std;

typedef long long ll;

#define endl '\n'

int n, m;
int answer = -1;
ll arr[200000], acc[200001];
unordered_map<int, int> startIndex, endIndex;

bool isSquare(string str) {
	int num = stoi(str);
	int div = sqrt(num);
	return div * div == num && num > answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	vector<string> strV(n);
	for (int i = 0; i < n; i++) {
		cin >> strV[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			string str2 = to_string(strV[i][j] - '0');
			if (isSquare(str2)) {
				answer = strV[i][j] - '0';
			}
			for (int di = 0; di < n; di++) {
				for (int dj = -m; dj < m; dj++) {
					string str = "";
					if (di != 0 || dj != 0) {
						for (int k = 0; i + di * k < n 
							&& j + dj * k < m 
							&& j + dj * k >= 0; k++) {
							str += strV[i + di * k][j + dj * k];
							if (isSquare(str)) {
								answer=stoi(str);
							}
							reverse(str.begin(), str.end());
							if (isSquare(str)) {
								answer = stoi(str);
							}
							reverse(str.begin(), str.end());
						}
					}
				}
			}
		}
	}
	cout << answer;
}

