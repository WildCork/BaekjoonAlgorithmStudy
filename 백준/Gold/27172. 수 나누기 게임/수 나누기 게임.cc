#include<iostream>
#include<algorithm>
#include<vector>
#include<list>

using namespace std;

int n;
bool visited[1000001] = { false };
int score[1000001] = { 0 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	vector<int> numbers(n);
	for (int i = 0; i < n; i++)	{
		cin >> numbers[i];
		visited[numbers[i]] = 1;
	}
	int maxNum = *max_element(numbers.begin(), numbers.end());

	for (int i = 0; i < numbers.size(); i++) {
		for (int j = 2; numbers[i] * j <= maxNum; j++) {
			if (visited[numbers[i] * j]) {
				score[numbers[i] * j]--;
				score[numbers[i]]++;
			}
		}
	}

	for (int i = 0; i < numbers.size(); i++)
	{
		cout << score[numbers[i]] << " ";
	}
}