#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<unordered_set>
#include<map>

using namespace std;

#define endl '\n'
#define MAXNUM 100001

int n, k, w, v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> k;
	vector<int> bag1(k + 1), bag2(k + 1);
	for (int i = 0; i < n; i++) {
		cin >> w >> v;
		for (int j = w; j <= k; j++) {
			bag2[j] = max(bag1[j], bag1[j - w] + v);
		}
		bag1 = bag2;
		/*for (int j = 0; j <= k; j++) {
			cout << bag1[j] << " ";
		}
		cout << endl;*/
	}
	cout << bag1.back();
}