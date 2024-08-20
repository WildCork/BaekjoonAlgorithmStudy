#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<unordered_set>
#include<map>

using namespace std;

#define endl '\n'
#define MAXNUM 100001

int n;
int ladder[3], dpMin[3], dpMax[3];
int leftVal, midVal, rightVal;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> ladder[j];
		}
		leftVal = min(dpMin[0], dpMin[1]) + ladder[0];
		rightVal = min(dpMin[2], dpMin[1]) + ladder[2];
		midVal = min(dpMin[0], min(dpMin[1], dpMin[2])) + ladder[1];
		dpMin[0] = leftVal;
		dpMin[1] = midVal;
		dpMin[2] = rightVal;
		leftVal = max(dpMax[0], dpMax[1]) + ladder[0];
		rightVal= max(dpMax[2], dpMax[1]) + ladder[2];
		midVal  = max(dpMax[0], max(dpMax[1], dpMax[2])) + ladder[1];
		dpMax[0] = leftVal;
		dpMax[1] = midVal;
		dpMax[2] = rightVal;
	}


	cout << *max_element(dpMax, dpMax + 3) << " ";
	cout << *min_element(dpMin, dpMin + 3) << " ";
}