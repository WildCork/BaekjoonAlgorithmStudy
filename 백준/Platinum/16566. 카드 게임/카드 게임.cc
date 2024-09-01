#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

#define endl '\n'
#define MAXNUM 4000000

typedef long long ll;
int cards[MAXNUM];
int visited[MAXNUM];

int n, m, k, dummy;

int nextIndex(int i) {
	if (visited[i] < 0) {
		return visited[i] = i;
	}
	return visited[i] = nextIndex(visited[i] + 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> k;

	for (int i = 0; i < m; i++) {
		cin >> cards[i];
	}
	sort(cards, cards + m);
	fill(visited, visited + n, -1);

	int answer = 0;

	for (int i = 0; i < k; i++) {
		cin >> dummy;
		cout << cards[nextIndex(upper_bound(cards, cards + m, dummy) - cards)] << endl;
	}

}
