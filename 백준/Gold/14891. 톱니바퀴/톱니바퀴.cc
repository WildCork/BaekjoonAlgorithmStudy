#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;

#define endl '\n'

int n, a, b;

vector<string> tobni(4);
void Turn(int idx, int dir){
	if (dir > 0) {
		tobni[idx].insert(tobni[idx].begin(), tobni[idx].back());
		tobni[idx].pop_back();
	}
	else {
		tobni[idx].insert(tobni[idx].end(), tobni[idx].front());
		tobni[idx].erase(tobni[idx].begin());
	}
}

void MatchTurn(int idx, int dir, int horizon) {
	if (horizon > 0) {
		if (idx < 3 && tobni[idx][2] != tobni[idx + 1][6]) {
			MatchTurn(idx+1, -dir, horizon);
		}
		Turn(idx, dir);
	}
	else {
		if (idx > 0 && tobni[idx][6] != tobni[idx - 1][2]) {
			MatchTurn(idx - 1, -dir, horizon);
		}
		Turn(idx,dir);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 0; i < 4; i++) {
		cin >> tobni[i];
	}

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		a--;
		if (a > 0 && tobni[a][6] != tobni[a - 1][2]) {
			MatchTurn(a - 1, -b, -1);
		}
		if (a < 3 && tobni[a][2] != tobni[a + 1][6]) {
			MatchTurn(a + 1, -b, 1);
		}
		Turn(a, b);
	}
	cout << (tobni[0][0] - '0')
		+ (tobni[1][0] - '0') * 2
		+ (tobni[2][0] - '0') * 4
		+ (tobni[3][0] - '0') * 8;
}
