#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

typedef long long ll;

#define endl '\n'
#define MAXNUM 1000001

int n, m;
int crain[51];
int box[100001];

bool isCanLift(int mid) {
	for (int i = 0; i < n; i++) {
		int idxM = m - mid * (i + 1);
		int idxN = n - i - 1;
		if (box[idxM + mid - 1] > crain[idxN]) {
			return false;
		}
		if (idxM < 0) {
			return true;
		}
		if (box[idxM] > crain[idxN]) {
			return false;
		}
		if (idxM == 0) {
			return true;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> crain[i];
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> box[i];
	}
	sort(crain, crain + n);
	sort(box, box + m);

	if (crain[n-1] < box[m-1]) {
		cout << -1;
		return 0;
	}
	else {
		int left = 0, right = m;
		while (left < right) {
			int mid = (left + right)/2;
			if (isCanLift(mid)) {
				right = mid;
			}
			else {
				left = mid + 1;
			}
		}
		cout << right;
	}
}

