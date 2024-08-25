#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<string>
using namespace std;

#define endl '\n'
#define MAXNUM 10001

int n, tc;
char c;
int order;

map<int, int> m;

int answer = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> tc;
	for (int t = 0; t < tc; t++) {
		cin >> n;
		m.clear();
		for (int i = 0; i < n; i++) {
			cin >> c >> order;
			if (c == 'I') {
				m[order]++;
			}
			else if (!m.empty()) {
				if (order == 1) {
					m.rbegin()->second--;
					if (m.rbegin()->second == 0) {
						m.erase(m.rbegin()->first);
					}
				}
				else {
					m.begin()->second--;
					if (m.begin()->second == 0) {
						m.erase(m.begin()->first);
					}
				}
			}
		}
		if (m.empty()) {
			cout << "EMPTY" << endl;
		}
		else {
			cout << m.rbegin()->first << " " << m.begin()->first << endl;
		}
	}
}