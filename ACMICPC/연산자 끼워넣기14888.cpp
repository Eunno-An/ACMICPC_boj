#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
void Permutation(vector<int>& array, int Start, int End);
void HeapPermutation(vector<int>& array, int size, int n);
int main() {
	int result = 0;
	//�Է�
	int N;
	cin >> N;//���� ����

	vector<int> inputs(N);
	vector<int> operators(4);
	
	for (int i = 0; i < N; i++) {//1 <= inputs[i] <= 100
		cin >> inputs[i];//������ ���
	}
	for (int i = 0; i < 4; i++) {
		cin >> operators[i];//������ �������� ����(+, -, *, /)
	}
	//���
	int maximum = -1000000001;
	int minimum = 1000000001;
	
	//��� �˰���
	//operators�� ��ȸ�ϸ鼭 operators�� ���� ���� ���� 1~4�� �����Ѵ�.
	//�� ���� ���Ϳ� �ִ´�.
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