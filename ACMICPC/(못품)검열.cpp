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
	//1. T에 A가 없으면 알고리즘 종료: O(T)
	//2. T에서 처음 등장하는 A를 찾은 뒤, 삭제한다.O(A)
	//3. T에 A가 없으면 알고리즘을 종료한다: O(T)
	//4. T에서 마지막으로 등장하는 A를 찾은 뒤, 삭제한다: O(T)
	//5. 1번으로 돌아간다.
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
	//kmp나 b-m 있어야 할듯.

	return 0;
}