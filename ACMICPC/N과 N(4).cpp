#include<iostream>
#include<vector>
//�ߺ� ���� �̸鼭 �������� �ʴ� ����
using namespace std;
int M, N;
vector<int> arr;
void function(int a, int b, vector<int>& v, int idx) {
	if (v.size() == b) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = idx; i < a; i++) {
		v.push_back(i + 1);
		function(a, b, v, i);
		v.pop_back();
	}
}
int main() {
	cin >> M >> N;
	function(M, N, arr, 0);
	return 0;
}