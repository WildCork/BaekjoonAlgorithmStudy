#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<unordered_map>
#include<unordered_set>

using namespace std;

typedef long long ll;

#define endl '\n'
int g, p, idx;
vector<int> gate;

int nextGate(int i) {
	if (gate[i] == 0) {
		return gate[i] = i;
	}
	return gate[i] = nextGate(gate[i] - 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> g >> p;
	gate.resize(g+1);
	int cnt = 0;
	for (int i = 0; i < p; i++) {
		cin >> idx;
		if (gate[idx] = nextGate(idx)) {
			cnt++;
		}
		else {
			break;
		}
	}
	cout << cnt<< endl;
}
