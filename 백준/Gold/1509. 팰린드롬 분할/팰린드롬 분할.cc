#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>

using namespace std;

#define MAXNUM 2500
#define endl '\n'

int n;
bool arr[MAXNUM][MAXNUM];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string str = "";
	cin >> str;
	n = str.size();
	int j = 0;
	for (int i = 0; i < n; i++) {
		j = 1;
		while (i - j >= 0 && i + j < n && str[i - j] == str[i + j]) { j++; }
		j--;
		for (int k = 0; k <= j; k++) {
			arr[i - k][i + k] = 1;
		}
		if (i < str.size() - 1) {
			j = 1;
			while (i - j + 1 >= 0 && i + j < n && str[i - j + 1] == str[i + j]) { j++; }
			j--;
			if (j != 0) {
				for (int k = 1; k <= j; k++) {
					arr[i - k + 1][i + k] = 1;
				}
			}
		}
	}
	vector<int> arr2(n);
	arr2[0] = 1;
	for (int i = 0; i < n; i++) {
		vector<int> dummy;
		for (int j = 0; j <= i; j++) {
			if (arr[i - j][i]) {
				if (j == i) {
					dummy.push_back(1);
				}
				else {
					dummy.push_back(arr2[i - j - 1] + 1);
				}
			}
		}
		arr2[i] = *min_element(dummy.begin(), dummy.end());
		//cout << arr2[i] << " ";
	}
	cout << arr2.back() << endl;

	return 0;
}