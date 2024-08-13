#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>

using namespace std;

int main() {
	int w, h, x, y, t;
	cin >> w >> h >> x >> y >> t;
	x += t;
	y += t;
	x %= (w * 2);
	y %= (h * 2);
	if (x > w)	{
		x = 2 * w - x;
	}
	if (y > h)	{
		y = 2 * h - y;
	}
	cout << x << " " << y;
}