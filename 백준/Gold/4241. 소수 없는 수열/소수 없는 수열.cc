#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

#define endl '\n'

int a, b, c;
int isComposite[10001];

vector<int> answer;
vector<int> visited;

void dfs(vector<int> dummy) {
	if (dummy.size() == b - a + 1) {
		answer = dummy;
	}
	if (answer.size() > 0) {
		return;
	}
	for (int i = a; i <= b; i++) {
		int sum = i;
		bool isAllComposite = true;
		if (visited[i-a] == false) {
			visited[i-a] = true;
			for (int j = dummy.size() - 1; j + c > dummy.size() &&  j >= 0; j--) {
				sum += dummy[j];
				if (isComposite[sum] == 0) {
					isAllComposite = false;
					break;
				}
			}
			if (isAllComposite) {
				dummy.push_back(i);
				dfs(dummy);
				dummy.pop_back();
			}
			visited[i-a] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	for (int i = 2; i <= 100; i++) {
		for (int j = 2; i * j <= 10000; j++) {
			isComposite[i*j] = 1;
		}
	}
	while (1) {
		cin >> a >> b >> c;
		if (a == 0) {
			break;
		}
		visited.clear();
		visited.resize(b - a + 1);
		answer.clear();
		dfs({});
		if (answer.empty()) {
			cout << "No anti-prime sequence exists." << endl;
		}
		else {
			cout << answer[0];
			for (int i = 1; i < answer.size(); i++) {
				cout << "," << answer[i];
			}
			cout << endl;
		}
	}

}