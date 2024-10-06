#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

typedef long long ll;

#define endl '\n'
#define MAXNUM 1000001

int n;
unordered_map<string, int> um;

string shuffle(string str) {
	string answer = "";
	string remain = "";
	for (int i = 0; i < str.size(); i++) {
		if (i % 2 == 0) {
			answer += str[i];
		}
		else {
			remain = str[i] + remain;
		}
	}
	return answer + remain;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string str;
	cin >> n;
	cin >> str;
	for (int i = 0; i < n; i++) {
		if (um.count(str) > 0) {
			int nn = i - um[str];
			while (i + nn < n) {
				i += nn;
			}
		}
		um[str] = i;
		str = shuffle(str);
	}
	cout << str;
}

