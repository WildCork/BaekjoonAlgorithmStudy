#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<unordered_set>
#include<numeric>

using namespace std;

typedef long long ll;

#define endl '\n'

unordered_set<int> us;
int n, m;

int Distance(pair<int, int>a, pair<int, int>b) {
	int abi = a.first - b.first;
	int abj = a.second - b.second;
	return abi * abi + abj * abj;
}

void dfs(int i, int j, vector<pair<int,int>> points) {
	if (points.size() == 3) {
		vector<int> distance;

		if (points[0].first == points[1].first && points[2].first == points[1].first) {
			return;
		}
		if (points[0].first != points[1].first && points[2].first != points[1].first) {
			double l1 = (double)(points[0].second - points[1].second)/(double)(points[0].first - points[1].first) / 1.0f;
			double l2 = (double)(points[2].second - points[1].second)/(double)(points[2].first - points[1].first) / 1.0f;
			if (l1 == l2) {
				return;
			}
		}

		for (int k = 0; k < 3; k++) {
			distance.push_back(Distance(points[k], points[(k+1) % 3]));
		}

		sort(distance.begin(), distance.end());

		us.insert(distance[0] * 201 * 201 + distance[1] * 201 + distance[2]);

		return;
	}
	for (int x = i; x <= n; x++) {
		if (x == i) {
			for (int y = j + 1; y <= m; y++) {
				points.push_back({x,y});
				dfs(x, y, points);
				points.pop_back();
			}
		}
		else {
			for (int y = 0; y <= m; y++) {
				points.push_back({ x,y });
				dfs(x, y, points);
				points.pop_back();
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	dfs(0, 0, {});
	cout << us.size();

	return 0;
}