#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<unordered_set>

using namespace std;

typedef long long ll;

#define endl '\n'

int n,m,a,b;

struct pair_hash {
	template <class T1, class T2>
	size_t operator () (const pair<T1, T2>& p) const {
		auto hash1 = hash<T1>{}(p.first);
		auto hash2 = hash<T2>{}(p.second);
		return hash1*20000001+ hash2;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	unordered_set<pair<ll, ll>, pair_hash> starM, starN;
	
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		starM.insert({a,b});
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		starN.insert({ a,b });
	}
	for (auto it2 = starN.begin(); it2 != starN.end(); it2++) {
		ll differX = -starM.begin()->first + it2->first;
		ll differY = -starM.begin()->second + it2->second;
		bool isCheck = true;
		for (auto it1 = starM.begin(); it1 != starM.end(); it1++) {
			if (starN.count({it1->first+differX, it1->second + differY}) == 0) {
				isCheck = false;
				break;
			}
		}
		if (isCheck) {
			cout << differX << " " << differY << endl;
			break;
		}
	}
}

