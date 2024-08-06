#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

using namespace std;


long long Deci() {
	long double answer = 1;
	for (int i = 0; i < 10; i++)
	{
		answer *= 10;
	}
	return answer;
}

int main()
{
	cout << fixed;
	cout.precision(20);
	vector<vector<long double>> xy1(2), xy2(2);
	for (int i = 0; i < 2; i++)
	{
		xy1[i].resize(2); xy2[i].resize(2);
	}

	long long deci = Deci();

	cin >> xy1[0][0] >> xy1[0][1] >> xy1[1][0] >> xy1[1][1];
	cin >> xy2[0][0] >> xy2[0][1] >> xy2[1][0] >> xy2[1][1];

	sort(xy1.begin(), xy1.end()); sort(xy2.begin(), xy2.end());
	long double x, y;

	if (xy1[0][0] == xy1[1][0] && xy2[0][0] == xy2[1][0]) {
		if (xy1[1][0] == xy2[0][0]) {
			if (xy1[1][1] == xy2[0][1])
			{
				cout << 1 << endl;
				//cout << xy1[0][0] << " " << xy1[1][1];
			}
			else if (xy1[0][1] == xy2[1][1])
			{
				cout << 1 << endl;
				//cout << xy1[0][0] << " " << xy1[0][1];
			}
			else if (xy1[0][1] >= xy2[0][1] && xy1[0][1] <= xy2[1][1]) {
				cout << 1 << endl;
			}
			else if (xy1[1][1] >= xy2[0][1] && xy1[1][1] <= xy2[1][1]) {
				cout << 1 << endl;
			}
			else if (xy2[0][1] >= xy1[0][1] && xy2[0][1] <= xy1[1][1]) {
				cout << 1 << endl;
			}
			else if (xy2[1][1] >= xy1[0][1] && xy2[1][1] <= xy1[1][1]) {
				cout << 1 << endl;
			}
			else
			{
				cout << 0 << endl;
			}
		}
		else {
			cout << 0 << endl;
		}
	}
	else if (xy1[0][0] == xy1[1][0]) {
		if ((xy2[0][0] <= xy1[0][0]) && (xy2[1][0] >= xy1[0][0])) {
			y = ((xy1[0][0] - xy2[0][0]) * xy2[1][1] + (xy2[1][0] - xy1[0][0]) * xy2[0][1])
				/ (xy2[1][0] - xy2[0][0]);
			y = round(deci * y) / deci;
			if ((xy1[0][1] <= y) && (xy1[1][1] >= y)) {
				cout << 1 << endl;
				//cout << xy1[0][0] << " " << y << endl;
			}
			else {
				cout << 0 << endl;
			}
		}
		else {
			cout << 0 << endl;
		}
	}
	else if (xy2[0][0] == xy2[1][0]) {
		if ((xy1[0][0] <= xy2[0][0]) && (xy1[1][0] >= xy2[0][0])) {
			y = ((xy2[0][0] - xy1[0][0]) * xy1[1][1] + (xy1[1][0] - xy2[0][0]) * xy1[0][1])
				/ (xy1[1][0] - xy1[0][0]);
			y = round(deci * y) / deci;
			if ((xy2[0][1] <= y) && (xy2[1][1] >= y)) {
				cout << 1 << endl;
				//cout << xy2[0][0] << " " << y << endl;
			}
			else {
				cout << 0 << endl;
			}
		}
		else {
			cout << 0 << endl;
		}
	}
	else {
		long double m1 = (xy1[1][1] - xy1[0][1]) / (xy1[1][0] - xy1[0][0]);
		long double m2 = (xy2[1][1] - xy2[0][1]) / (xy2[1][0] - xy2[0][0]);

		long double k1 = xy1[0][1] - xy1[0][0] * m1;
		long double k2 = xy2[0][1] - xy2[0][0] * m2;

		if (m1 == m2)
		{
			if (k1 == k2)
			{
				if (xy1[1][0] == xy2[0][0]) {
					cout << 1 << endl;
					//cout << xy1[1][0] << " " << xy1[1][1];
				}
				else if (xy2[1][0] == xy1[0][0]) {
					cout << 1 << endl;
					//cout << xy2[1][0] << " " << xy2[1][1];
				}
				else if (xy1[0][0] >= xy2[0][0] && xy2[1][0] >= xy1[0][0])
				{
					cout << 1 << endl;
				}
				else if (xy2[0][0] >= xy1[0][0] && xy1[1][0] >= xy2[0][0])
				{
					cout << 1 << endl;
				}
				else if (xy1[1][0] >= xy2[0][0] && xy2[1][0] >= xy1[1][0])
				{
					cout << 1 << endl;
				}
				else if (xy2[1][0] >= xy1[0][0] && xy1[1][0] >= xy2[1][0])
				{
					cout << 1 << endl;
				}
				else
				{
					cout << 0 << endl;
				}
			}
			else
			{
				cout << 0 << endl;
			}
		}
		else
		{
			x = (k1 - k2) / (m2 - m1);
			y = m1 * x + k1;
			x = round(x * deci) / deci;

			if (xy1[0][0] <= x && x <= xy1[1][0] && xy2[0][0] <= x && x <= xy2[1][0])
			{
				cout << 1 << endl;
				//cout << x << " " << y << endl;
			}
			else
			{
				cout << 0 << endl;
			}
		}
	}

}
