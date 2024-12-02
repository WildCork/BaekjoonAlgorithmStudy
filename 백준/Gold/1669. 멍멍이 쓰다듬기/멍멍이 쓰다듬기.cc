#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<unordered_map>

using namespace std;

typedef long long ll;

#define endl '\n'

ll x, y;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> x >> y;
	
	ll right = sqrt((y - x) * 4), left = 0;
	ll result = 0;

	while (right - left > 0) {
		ll mid = (left + right) / 2;
		ll n = mid / 2;
		if (mid%2 == 0) {
			result = (n + 1) * n;
		}
		else {
			result = (n + 1) * (n + 1);
		}

		if (result > (y-x)) {
			right = mid;
		}
		else if(result < (y - x)){
			left = mid + 1;
		}
		else {
			right = mid;
			break;
		}
	}
	cout << right;
}