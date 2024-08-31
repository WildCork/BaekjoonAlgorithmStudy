#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<unordered_map>
#include<unordered_set>

using namespace std;

typedef long long ll;

#define endl '\n'
int n,m;
vector<string> miro;
vector<vector<int>> visited;
int di[4]={0,0,1,-1};
int dj[4]={1,-1,0,0};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	miro.resize(n);
	visited.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> miro[i];
		visited[i].resize(m);
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visited[i][j] == 0) {
				cnt++;
				int ni = i, nj = j;
				vector<pair<int, int>> nodes;
				while (visited[ni][nj] == 0) {
					nodes.push_back({ ni,nj });
					visited[ni][nj] = cnt;
					switch (miro[ni][nj]) {
					case 'U':
						ni--;
						break;
					case 'D':
						ni++;
						break;
					case 'R':
						nj++;
						break;
					case 'L':
						nj--;
						break;
					default:
						break;
					}
				}
				if (visited[ni][nj] != cnt) {
					for (int k = 0; k < nodes.size(); k++) {
						auto f = nodes[k];
						visited[f.first][f.second] = visited[ni][nj];
					}
					cnt--;
				}
			}
		}
	}
	cout << cnt;
}
