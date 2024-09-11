#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>

#define endl '\n'

using namespace std;

typedef long long ll;
int n,m;
int arr1[101];
int arr2[101];
vector<int> arr[101][101];

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr1[i];
	}
	cin >> m;
	for (int i = 1; i <= m; i++) {
		cin >> arr2[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (arr1[i] == arr2[j]) {
				auto v = arr[i - 1][j - 1];
				vector<int> vv;
				for (int k = 0; k <= v.size(); k++) {
					if (k == v.size() || v[k] < arr1[i]) {
						vv.push_back(arr1[i]);
						break;
					}
					vv.push_back(v[k]);
				}
				arr[i][j] = vv;
			}
			else {
				if (arr[i-1][j] < arr[i][j-1]) {
					arr[i][j] = arr[i][j - 1];
				}
				else {
					arr[i][j] = arr[i - 1][j];
				}
			}
		}
	}

	cout << arr[n][m].size() << endl;
	for (auto e : arr[n][m]) {
		cout << e << " ";
	}
}
