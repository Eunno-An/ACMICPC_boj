#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
int main() {
	//�Է�
	//ù° �ٿ��� �̹� ������ �ܿ� ���� N(1 �� N �� 100)�� ������� ���� �� �� �ִ� 
	//�� �ð� T(1 �� T �� 10000)�� ������ ���̿� �ΰ� �־�����.
	//��° �ٺ��� N �ٿ� ���ļ� 
	//�� �ܿ� �� ���� ���� �ð� K(1 �� K �� 1000)�� �� �ܿ� ������ ���� S(1 �� S �� 1000)�� ������ ���̿� �ΰ� �־�����.
	
	int N, T;
	cin >> N >> T;
	vector<int> vector_studyTime;
	vector<int> vector_Score;
	vector_studyTime.push_back(-1);
	vector_Score.push_back(-1);
	for (int i = 0; i < N; i++) {
		int input_studyTime, input_Score;
		cin >> input_studyTime >> input_Score;
		vector_studyTime.push_back(input_studyTime);
		vector_Score.push_back(input_Score);
	}

	//���
	//ù° �ٿ� �ؼ��̰� ���� �� �ִ� �ִ� ������ ����Ѵ�.
	return 0;
}