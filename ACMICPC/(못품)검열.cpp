#include<iostream>
#include<string>
#include<vector>
using namespace std;
string A, T;
vector<int> vector_fail;
//abccab
void fail() {
	for (int i = 1, j = 0; i < A.size(); i++) {
		while (j > 0 && A[i] != A[j]) j = vector_fail[j - 1];
		if (A[i] == A[j]) vector_fail[i] = ++j;
	}
}
int main() {
	cin >> A >> T;
	vector_fail.resize(A.size());
	//1. T�� A�� ������ �˰��� ����: O(T)
	//2. T���� ó�� �����ϴ� A�� ã�� ��, �����Ѵ�.O(A)
	//3. T�� A�� ������ �˰����� �����Ѵ�: O(T)
	//4. T���� ���������� �����ϴ� A�� ã�� ��, �����Ѵ�: O(T)
	//5. 1������ ���ư���.
	fail();
	vector<int> result;
	for (int i = 0, j = 0; i < T.size(); i++) {
		while (j > 0 && T[i] != A[j]) j = vector_fail[j - 1];
		if (T[i] == A[j]) {
			if (j == A.size() - 1) {
				result.push_back(i);
			}
		}
	}
	for (int i = 0; i < result.size(); i++) {
		cout << i << ' ';
	}
	//12,000 * O(T) -> time over
	//kmp�� b-m �־�� �ҵ�.

	return 0;
}