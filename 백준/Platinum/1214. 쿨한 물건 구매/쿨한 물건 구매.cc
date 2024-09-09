#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

typedef long long ll;

#define endl '\n'
#define SWAP(a,b){ll tmp=a;a=b;b=tmp;} 

ll d, p, q;

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	cin >> d >> p >> q;
	if (p < q) {SWAP(p,q)}
	ll answer = (d / p + 1) * p, dummy;
	ll divider = d / p;
	for (ll i = 0; i <= q && i <= divider; i++) {
		dummy = p * i;
		ll differ = d - dummy;
		if (differ%q == 0) {
			answer = d;
			break;
		}
		else {
			dummy += (differ / q + 1)*q;
			answer = min(answer, dummy);
		}
	}
	cout << answer;
}

//121 9 10