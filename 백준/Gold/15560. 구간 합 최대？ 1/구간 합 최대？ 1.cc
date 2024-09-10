#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

#define endl '\n'
#define INF -1000000

int n, q, u, v;
int c, a, b;

int arr1[1001];
int arr2[1001];

int find(int i) {
	int answer = 0;
	while (i > 0) {
		answer += arr2[i];
		i -= (i&-i);
	}
	return answer;
}

void update(int i, int val) {
	while(i <= n) {
		arr2[i] += val;
		i += (i&-i);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	
	cin >> n >> q >> u >> v;
	for (int i = 1; i <= n; i++) {
		cin >> arr1[i];
		update(i, arr1[i]);
	}

	for (int i = 0; i < q; i++) {
		cin >> c >> a >> b;
		if (c == 0) {
			int answer = INF;
			for (int j = a; j <= b; j++) {
				for (int k = j; k <= b; k++) {
					answer = max(answer, u*(find(k) - find(j - 1)) + v * (k - j));
				}
			}
			cout << answer << endl;
		}
		else {
			int differ = b - arr1[a];
			arr1[a] = b;
			update(a, differ);
		}
	}
}
