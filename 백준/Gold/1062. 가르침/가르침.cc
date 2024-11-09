#include<iostream>
#include<algorithm>
#include<queue>
#include<list>
#include<unordered_set>
#include<set>
#include<numeric>

using namespace std;

typedef long long ll;

#define endl '\n'
#define MAXNUM 1000000

int n, k;

vector<ll> arr;
unordered_set<ll> us;
int answer = 0;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		string str;
		ll l = 0;
		cin >> str;
		for (int j = 0; j < str.size(); j++) {
			l = l | ((ll)1 << (str[j] - 'a'));
		}
		arr.push_back(l);
	}

	vector<int> com(26);
	for (int i = 0; i <k; i++) {
		com[i] = 1;
	}
	do {
		ll dummy = 0;
		for (int i = 0; i < 26; i++) {
			if (com[i]) {
				dummy = dummy | ((ll)1 << i);
			}
		}
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if ((dummy | arr[i]) == dummy) {
				cnt++;
			}
		}
		answer = max(answer, cnt);

	} while (prev_permutation(com.begin(), com.end()));

	cout << answer;
	return 0;
}