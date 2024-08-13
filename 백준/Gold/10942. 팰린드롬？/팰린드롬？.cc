#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

#define MAXNUM 10000000
#define endl '\n'

int n;
vector<int> numbers;
map<int, int> oddMid, evenMid;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;

	numbers.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> numbers[i];
	}

	int j = 0;
	for (int i = 0; i < n; i++) {
		j = 1;
		while (i - j >= 0 && i + j < n && numbers[i - j] == numbers[i + j]) { j++; }
		j--;
		oddMid[i] = 2 * j + 1;
		j = 1;
		while (i - j + 1 >= 0 && i + j < n && numbers[i - j + 1] == numbers[i + j]) { j++; }
		j--;
		evenMid[i] = 2 * j;
	}

	int m, a, b, c, d;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		a--; b--;
		c = (a + b) / 2;
		d = b - a + 1;
		if ((a + b) % 2 == 0) {
			cout << (oddMid[c] >= d) << endl;
		}
		else {
			cout << (evenMid[c] >= d) << endl;
		}
	}

	return 0;
}