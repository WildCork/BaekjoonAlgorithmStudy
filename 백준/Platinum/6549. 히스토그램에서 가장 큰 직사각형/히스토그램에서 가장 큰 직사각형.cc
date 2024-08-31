#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>

using namespace std;

typedef long long ll;
#define MAXNUM 100002

#define endl '\n'
int n, m;
ll a[MAXNUM];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	while (1) {
		cin >> n;
		if (n==0) {
			break;
		}
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		a[0] = a[n + 1] = 0;
		stack<ll>st;
		st.push(0);
		long long answer = 0;
		for (ll i = 1; i <= n+1; i++) {
			while (!st.empty() && a[st.top()] > a[i]) {
				ll h = a[st.top()];
				st.pop();
				ll w = i - st.top() - 1;
				answer = max(answer, h * w);
			}
			st.push(i);
		}
		cout << answer << endl;
	}
}