#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main() {
	//�Է�
	int K;//��ź�� ��� �ִ� ����� ��ȣ
	cin >> K;
	int N;//������ ����
	cin >> N;
	vector<int> T(N);//i��° ������ ����ϱ���� �ɸ� �ð�
	vector<char> Z(N);//�� �÷��̾��� ���
	//(T = ����� ����, N = Ʋ��, P = ��ŵ)
	for (int i = 0; i < N; i++) {
		cin >> T[i] >> Z[i];
	}
	
	//��� �˰���
	int remain = 210; // 3�� 30�ʰ� ������ ����
	int start = K; // ���� ��ȣ. ����� 1���� �����Ͽ� 8���� ����
	while (remain > 0) {
		for (int i = 0; i < N; i++) {
			remain -= T[i];
			if (remain <= 0) {
				break;
			}
			if (Z[i] == 'T') {
				if (start == 8) {
					start = 1;
					continue;
				}
				start++;
			}
		}
		
	}

	//���
	cout << start << '\n';
	return 0;
}