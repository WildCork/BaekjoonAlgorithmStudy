#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int house[1001][3];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> house[i][0] >> house[i][1] >> house[i][2];
	}

	for (int i = 1; i < n; i++)
	{
		house[i][0] += min(house[i-1][1], house[i-1][2]);
		house[i][1] += min(house[i-1][0], house[i-1][2]);
		house[i][2] += min(house[i-1][0], house[i-1][1]);
	}
	cout << *min_element(house[n - 1], house[n - 1] + 3);
}