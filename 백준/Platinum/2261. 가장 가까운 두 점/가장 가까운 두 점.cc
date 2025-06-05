#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int MAX = 2000000000;
vector<pair<int, int>> M;

bool compare(pair<int, int>a, pair<int, int>b)
{
	return a.first < b.first;
}

bool compare2(pair<int, int>a, pair<int, int>b)
{
	return a.second < b.second;
}


int Square(pair<int, int>a, pair<int, int>b)
{
	return (a.first - b.first) * (a.first - b.first)
		+ (a.second - b.second) * (a.second - b.second);
}

int MinSearch(int left, int right)
{
	if (right == left)
		return MAX;
	else if (right - left <= 1)
	{
		return Square(M[left], M[right]);
	}
	else
	{
		int answer = Square(M[left], M[right]);
		int mid = (right + left) / 2;
		int leftMin = MinSearch(left, mid);
		int rightMin = MinSearch(mid + 1, right);
		if (answer > leftMin)
			answer = leftMin;
		if (answer > rightMin)
			answer = rightMin;
		vector<pair<int, int>> N;
		for (int i = mid; i >= left; i--)
		{
			if ((M[i].first - M[mid].first) * (M[i].first - M[mid].first) >= answer)
				break;
			N.push_back({ M[i].second, M[i].first });
		}
		for (int i = mid + 1; i <= right; i++)
		{
			if ((M[i].first - M[mid].first) * (M[i].first - M[mid].first) >= answer)
				break;
			N.push_back({ M[i].second, M[i].first });
		}
		if (N.size() == 0)
			return answer;
		sort(N.begin(), N.end());
		for (size_t i = 0; i < N.size(); i++)
		{
			int iX = N[i].second, iY = N[i].first;
			for (size_t j = i + 1; j < N.size(); j++)
			{
				int jX = N[j].second, jY = N[j].first;
				int distY = iY  - jY;
				int distX =iX - jX;
				if (distY *distY >= answer)
					break; 
				if (distX * distX >= answer)
					continue;
				int dummy = Square(N[i],N[j]);
				if (answer > dummy)
					answer = dummy;
			}
		}
		return answer;
	}
}

int main()
{
	int n, x, y;
	cin >> n;
	M.resize(n);
	for (size_t i = 0; i < n; i++)
	{
		cin >> M[i].first >> M[i].second;
	}
	sort(M.begin(), M.end());
	cout << MinSearch(0, n - 1);
}

//4
//0 0
//0 10
//10 0
//10 10