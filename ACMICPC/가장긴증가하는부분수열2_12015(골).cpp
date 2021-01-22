#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int N; // ���� A�� ũ��,  N (1 �� N �� 1,000,000)
vector<int> inputs; // ���� A
vector<int> lists;
int binarySearch(int left, int right, int target) {
	int mid;
	while (left < right) {
		mid = (left + right) / 2;
		if (lists[mid] < target) {
			left = mid + 1;
		}
		else {
			right = mid;
		}
	}
	return right;
}
int main() {
	cin >> N;
	int input;
	for (int i = 0; i < N; i++) {
		cin >> input;
		inputs.push_back(input);
	}
	//��� 1. N^2�� DP�� �ϴ� ��� -> Time Error
	//��� 2. NlogN(����Ž��), NlogN(���׸�Ʈ Ʈ��)
	lists.resize(N);
	int j = 0;
	lists[0] = inputs[0];
	for (int i = 0; i < N; i++) {
		if (lists[j] < inputs[i]) {
			lists[j + 1] = inputs[i];
			j += 1;
		}
		else {
			int idx = binarySearch(0, j, inputs[i]);
			lists[idx] = inputs[i];
		}
	}

	int count = 0;
	for (int i = 0; i < lists.size(); i++) {
		if (lists[i] != 0) {
			count++;
		}
	}
	cout << count << '\n';
	return 0;
}