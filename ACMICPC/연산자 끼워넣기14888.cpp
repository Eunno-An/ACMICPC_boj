#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
void Permutation(vector<int>& array, int Start, int End);
void HeapPermutation(vector<int>& array, int size, int n);
int main() {
	int result = 0;
	//입력
	int N;
	cin >> N;//수의 개수

	vector<int> inputs(N);
	vector<int> operators(4);
	
	for (int i = 0; i < N; i++) {//1 <= inputs[i] <= 100
		cin >> inputs[i];//수열의 요소
	}
	for (int i = 0; i < 4; i++) {
		cin >> operators[i];//각각의 연산자의 개수(+, -, *, /)
	}
	//출력
	int maximum = -1000000001;
	int minimum = 1000000001;
	
	//출력 알고리즘
	//operators를 순회하면서 operators에 대한 수를 각각 1~4에 대응한다.
	//그 다음 벡터에 넣는다.
	vector<int> permutations;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < operators[i]; j++) {
			permutations.push_back(i + 1);
		}
	}
	
	do {
		result = inputs[0];
		for (int i = 0; i < permutations.size(); i++) {
			if (permutations[i] == 1) {
				result += inputs[i + 1];
			}
			else if (permutations[i] == 2) {
				result -= inputs[i + 1];
			}
			else if (permutations[i] == 3) {
				result *= inputs[i + 1];
			}
			else if (permutations[i] == 4) {
				result /= inputs[i + 1];
			}
		}
		if (result > maximum) {
			maximum = result;
		}
		if (result < minimum) {
			minimum = result;
		}
		
	} while (next_permutation(permutations.begin(), permutations.end()));
	
	cout << maximum << '\n' << minimum << '\n';

	return 0;
}