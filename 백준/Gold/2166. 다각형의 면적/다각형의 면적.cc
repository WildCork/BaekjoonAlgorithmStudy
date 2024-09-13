#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>

#define endl '\n'

using namespace std;

typedef long long ll;

int n;
double arrX[10000];
double arrY[10000];

int main() {
	ios_base::sync_with_stdio(false);
	cout.precision(1);
	cout << fixed;
	cout.tie(NULL);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arrX[i] >> arrY[i];
	}
	double area = 0;
	double part = 0;
	for (int i = 0; i < n; i++) {
		if (i == n - 1) {
			part = (arrY[i] + arrY[0])*(arrX[0] - arrX[i]) / 2.0f;
			area += part;
			break;
		}
		part = (arrY[i] + arrY[i + 1])*(arrX[i + 1] - arrX[i]) / 2.0f;
		area += part;
	}
	cout << abs(area);
}
