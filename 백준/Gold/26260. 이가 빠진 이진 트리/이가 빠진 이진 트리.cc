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
int tree[1000000];
int arr[1000000];
	
void postorder(int idx) {
	if (idx * 2 <= n) {
		postorder(idx * 2);
	}
	if (idx * 2 + 1 <= n) {
		postorder(idx * 2 + 1);
	}
	cout << tree[idx] << " ";
}

void Push(int left, int right, int idx) {
	int mid = (left + right) / 2;
	tree[idx] = arr[mid];
	if (idx * 2 <= n) {
		Push(left,mid, idx*2);
	}
	if (idx * 2 + 1 <= n) {
		Push(mid + 1, right, idx * 2 + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	int idx = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] < 0) {
			idx = i;
		}
	}
	cin >> m;
	arr[idx] = m;
	sort(arr, arr + n);
	Push(0, n, 1);

	postorder(1);
}

