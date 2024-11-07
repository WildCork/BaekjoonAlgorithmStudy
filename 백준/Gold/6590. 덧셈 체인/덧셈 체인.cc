#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>

using namespace std;

typedef long long ll;

#define endl '\n'

int n, k;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	vector<vector<int>> arr[101];

	arr[1].push_back({ 1 });
	for (int i = 1; i <= 100; i++) {
		for (int j = 0; j < arr[i].size(); j++) {
			for (int k = arr[i][j].size() - 1; k >= 0; k--) {
				auto v = arr[i][j];
				if (v.back() + arr[i][j][k] <= 100) {
					v.push_back(v.back() + arr[i][j][k]);
					if (arr[v.back()].size() == 0 || arr[v.back()][0].size() > v.size()) {
						arr[v.back()].clear();
						arr[v.back()].push_back(v);
					}
					else if (arr[v.back()][0].size() == v.size()) {
						arr[v.back()].push_back(v);
					}
				}
			}
		}
	}
	while(1) {
		cin >> n;
		if (n == 0) {
			break;
		}
		for (int i = 0; i < arr[n][0].size(); i++) {
			cout << arr[n][0][i] << " ";
		}
		cout << endl;
	}
}