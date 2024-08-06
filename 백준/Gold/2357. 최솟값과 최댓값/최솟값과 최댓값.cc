#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

#define endl '\n'

int n, m;
vector<int> nums;

struct SegmentTree {
	int left, right;
	SegmentTree(int left, int right) {
		this->left = left;
		this->right = right;
	}
	int minVal, maxVal;
	SegmentTree* leftNode = NULL;
	SegmentTree* rightNode = NULL;
};

SegmentTree* dfs(int left, int right) {
	SegmentTree* node = new SegmentTree(left, right);
	if (right > left + 1)	{
		auto mid = (left + right) / 2;
		node->leftNode = dfs(left, mid);
		node->rightNode = dfs(mid, right);
		node->minVal = min(node->leftNode->minVal, node->rightNode->minVal);
		node->maxVal = max(node->leftNode->maxVal, node->rightNode->maxVal);
	}
	else {
		node->maxVal = node->minVal = nums[left];
	}
	return node;
}

int finMin(int left, int right, int minLeft, int maxRight, SegmentTree* node) {
	auto mid = (minLeft + maxRight) / 2;
	if (left <= minLeft && right >= maxRight) {
		return node->minVal;
	}
	else if (mid <= left) {
		return finMin(left, right, mid, maxRight, node->rightNode);
	}
	else if (mid >= right) {
		return finMin(left, right, minLeft, mid, node->leftNode);
	}

	return min(finMin(left, right, mid, maxRight, node->rightNode), 
		finMin(left, right, minLeft, mid, node->leftNode));
}

int finMax(int left, int right, int minLeft, int maxRight, SegmentTree* node) {
	auto mid = (minLeft + maxRight) / 2;
	if (left <= minLeft && right >= maxRight) {
		return node->maxVal;
	}
	else if (mid <= left) {
		return finMax(left, right, mid, maxRight, node->rightNode);
	}
	else if (mid >= right) {
		return finMax(left, right, minLeft, mid, node->leftNode);
	}
	return max(finMax(left, right, mid, maxRight, node->rightNode),
				finMax(left, right, minLeft, mid, node->leftNode));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	nums.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	SegmentTree* root = dfs(0, n);

	int a, b;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		cout << finMin(a - 1, b, 0, n, root) << " " << finMax(a - 1, b, 0, n, root) << endl;
	}
}
