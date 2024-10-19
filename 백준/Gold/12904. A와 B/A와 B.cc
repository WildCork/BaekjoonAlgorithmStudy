#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

typedef long long ll;

#define endl '\n'

int n,m,a,b;

string str1, str2;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> str1 >> str2;
	bool answer = false;
	while (str2 != "") {
		if (str1 == str2) {
			answer = true;
			break;
		}
		if (str2.back() == 'A') {
			str2.pop_back();
		}
		else {
			str2.pop_back();
			reverse(str2.begin(), str2.end());
		}
	}
	cout << answer;
}

