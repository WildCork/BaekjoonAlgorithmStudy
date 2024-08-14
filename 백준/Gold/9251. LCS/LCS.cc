#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>

using namespace std;

#define MAXNUM 1000
#define endl '\n'

int n;
int arr[MAXNUM][MAXNUM];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string a, b;
	cin >> a >> b;

	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < b.size(); j++) {
			if (a[i] == b[j]) {
				arr[i][j] = 1;
			}
			if (i > 0 && j > 0 && arr[i - 1][j - 1] > 0) {
				arr[i][j] += arr[i - 1][j - 1];
			}
			if (j > 0 && arr[i][j - 1] > 0) {
				arr[i][j] = max(arr[i][j - 1], arr[i][j]);
			}
			if (i > 0 && arr[i - 1][j] > 0) {
				arr[i][j] = max(arr[i - 1][j], arr[i][j]);
			}
		}
	}
	cout << arr[a.size() - 1][b.size() - 1];

	return 0;
}