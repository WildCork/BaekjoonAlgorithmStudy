#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

#define endl '\n'
#define x first
#define y second

typedef long long ll;

string s;
string answer = "";
int w, n, dummy;
int product[5000];
unordered_map<int, pair<int, int>> sum;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> w >> n;
	for (int i = 0; i < n; i++) {
		cin >> product[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int cur = product[i] + product[j];
			if (sum.find(cur) == sum.end()) {
				sum[cur]= {i, j };
			}
		}
	}
	bool isYes = false;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int cur = product[i] + product[j];
			auto it = sum.find(w - cur);
			if (it == sum.end()) {
				continue;
			}
			if (it->y.x != i && it->y.y != i && it->y.x != j && it->y.y != j) {
				cout << "YES";
				return 0;
			}
		}
	}
	cout << "NO";
}
