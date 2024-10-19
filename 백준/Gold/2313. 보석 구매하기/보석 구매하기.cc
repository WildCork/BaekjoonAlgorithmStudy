#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

typedef long long ll;

#define endl '\n'

int t, n, d;
int arr[100], acc[100];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	int answer = 0;
	vector<int> points, cntVec;
	for (int tc = 0; tc < t; tc++) {
		cin >> n;
		vector<int>acc(1);
		for (int i = 0; i < n; i++) {
			cin >> d;
			acc.push_back(acc.back() + d);
		}
		int endPoint = 1;
		int startPoint = 0;
		int maxAnswer = acc[1] - acc[0];
		for (int i = 0; i < n; i++) {
			auto it = max_element(acc.begin() + i + 1, acc.end());
			int dis = distance(acc.begin(), it);
			int maxVal = *it;
			if (maxVal - acc[i] > maxAnswer) {
				endPoint = dis;
				startPoint = i;
				maxAnswer = maxVal - acc[i];
			}
			else if (maxVal - acc[i] == maxAnswer && (dis - i) < endPoint-startPoint) {
				endPoint = dis;
				startPoint = i;
			}
			else if (maxVal - acc[i] == maxAnswer && (dis - i) == endPoint - startPoint) {
				for (int j = 0; j < dis-i; j++) {
					if (acc[i + j] < acc[startPoint + j]) {
						break;
					}
					else if (acc[i + j] > acc[startPoint + j]) {
						endPoint = dis;
						startPoint = i;
						break;
					}
				}
			}
		}
		answer += maxAnswer;
		points.push_back(startPoint);
		cntVec.push_back(endPoint);
	}
	cout << answer << endl;
	for (int i = 0; i < t; i++) {
		cout << points[i] + 1 << " " << cntVec[i] << endl;
	}
}

