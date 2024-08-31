#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<unordered_map>
#include<unordered_set>

using namespace std;

typedef long long ll;

#define endl '\n'
int tc, n, m;
vector<string> miro;
unordered_set<char> keys;
vector<vector<pair<int, int>>> doors;
vector<vector<bool>> visited;
queue<pair<int, int>> q;
int di[4] = { 0,0,1,-1 };
int dj[4] = { 1,-1,0,0 };
int docCnt = 0;

void Check(int ni, int nj) {
	if (visited[ni][nj]) {
		return;
	}
	if (miro[ni][nj] != '*') {
		if (miro[ni][nj] == '.') {
			q.push({ ni,nj });
			visited[ni][nj] = true;
		}
		else if (miro[ni][nj] >= 'a' && miro[ni][nj] <= 'z') {
			q.push({ ni,nj });
			keys.insert(miro[ni][nj]);
			visited[ni][nj] = true;
		}
		else if (miro[ni][nj] >= 'A' && miro[ni][nj] <= 'Z') {
			doors[miro[ni][nj] - 'A'].push_back({ ni,nj });
		}
		else {
			docCnt++;
			q.push({ ni,nj });
			visited[ni][nj] = true;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> tc;
	for (int t = 0; t < tc; t++) {
		cin >> n >> m;
		docCnt = 0;
		keys.clear();
		doors.clear();
		visited.clear();

		miro.resize(n);
		visited.resize(n);
		doors.resize(26);
		for (int i = 0; i < n; i++) {
			cin >> miro[i];
			visited[i].resize(m);
		}
		string haveKey;
		cin >> haveKey;

		for (auto c : haveKey) {
			keys.insert(c);
		}

		for (int i = 0; i < n; i++) {
			Check(i, 0);
			Check(i, m - 1);
		}
		for (int i = 0; i < m; i++) {
			Check(n - 1, i);
			Check(0, i);
		}

		bool isEnd = false;
		while (!isEnd) {
			isEnd = true;

			while (!q.empty()) {
				auto f = q.front();
				q.pop();
				int fi = f.first, fj = f.second;
				for (int k = 0; k < 4; k++) {
					if (fi + di[k] >= 0 && fi + di[k] < n && fj + dj[k] >= 0 && fj + dj[k] < m) {
						int ni = fi + di[k], nj = fj + dj[k];
						if (!visited[ni][nj]) {
							if (miro[ni][nj] != '*') {
								if (miro[ni][nj] == '.') {
									q.push({ ni,nj });
									visited[ni][nj] = true;
								}
								else if (miro[ni][nj] >= 'a' && miro[ni][nj] <= 'z') {
									q.push({ ni,nj });
									keys.insert(miro[ni][nj]);
									visited[ni][nj] = true;
									isEnd = false;
								}
								else if (miro[ni][nj] >= 'A' && miro[ni][nj] <= 'Z') {
									doors[miro[ni][nj] - 'A'].push_back({ni,nj});
									isEnd = false;
								}
								else {
									docCnt++;
									q.push({ ni,nj });
									visited[ni][nj] = true;
								}
							}
						}
					}
				}
			}

			for (int i = 0; i < 26; i++) {
				if (!doors[i].empty() && keys.find('a'+i) != keys.end()) {
					for (auto it = doors[i].begin(); it != doors[i].end(); it++) {
						auto p = *it;
						visited[p.first][p.second] = true;
						miro[p.first][p.second] = '.';
						q.push({ p.first, p.second });
					}
					isEnd = false;
					doors[i].clear();
				}
			}
		}
		cout << docCnt << endl;
	}
}


/*
1
15 15
**$*.**********
****.*******$**
****B.$****b.**
$*****c*****.**
*C$.*****fD..**
*$*xd******.**$
$.C********A.**
**h********.AA.
***************
***.i**********
***.***.K$*****
*k.$$I.$*******
******.$..j***$
*******D*******
****$**F*******
za

*/