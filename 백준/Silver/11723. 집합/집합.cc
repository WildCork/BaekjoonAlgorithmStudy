#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

#define endl '\n'

int n;
bool visited[21] = {0};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	string order;
	int m;
	for (int i = 0; i < n; i++)
	{
		cin >> order;
		if (order == "add") {
			cin >> m;
			visited[m] = true;
		}
		else if (order == "remove") {
			cin >> m;
			visited[m] = false;
		}
		else if (order == "check") {
			cin >> m;
			cout << visited[m] << endl;
		}
		else if (order == "toggle") {
			cin >> m;
			visited[m] = !visited[m];
		}
		else if (order == "all") {
			for (int i = 1; i <= 20; i++) {
				visited[i] = true;
			}
		}
		else {
			for (int i = 1; i <= 20; i++) {
				visited[i] = false;
			}
		}
	}
}