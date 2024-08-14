#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>

using namespace std;

#define endl '\n'

string str;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string str = "";
	cin >> str;
	
	int cuts[100000] = {0};
	int answer = 0;
	int len = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(')
		{
			if (str[i + 1] == ')') {
				for (int j = 0; j < len; j++) {
					cuts[j]++;
				}
			}
			else {
				len++;
			}
		}
		else if(str[i-1] != '('){
			answer += cuts[len - 1] + 1;
			cuts[len - 1] = 0;
			len--;
		}
	}
	cout << answer;
}