#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<unordered_map>

using namespace std;

#define endl '\n'

int n, a, b;

vector<string> vs;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int idx=0;
	string str1, str2, str3;
	vs.resize(1000001);
	cin >> str1 >> str2;
	for (int i = 0; i < str1.size(); i++) {
		if (str1[i] == str2[vs[idx].size()]) {
			vs[idx] += str1[i];
			if (vs[idx].size() == str2.size()) {
				vs[idx] = "";
				if (idx > 0)idx--;
			}
		}
		else if(str1[i] == str2[0]) {
			vs[++idx] = str2[0];
		}
		else {
			for (int i = 0; i <= idx; i++) {
				str3 += vs[i];
				vs[i] = "";
			}
			str3 += str1[i];
			idx = 0;
		}
	}

	for (int i = 0; i <= idx; i++) {
		str3 += vs[i];
	}
	if (str3 == "")
		cout << "FRULA";
	else
		cout << str3;
}

