#include<iostream>
#include<string>
#include<set>
using namespace std;
//set���� �ϸ� �ð��ʰ�
//�׳� map�� �ð��ʰ�
//https://stackoverflow.com/questions/222658/multiset-map-and-hash-map-complexity

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); // �ð��ʰ� ���� �̰� �� �Ẹ��.. �̰� �ȽἭ Ʋ�ȳ�..
	int T, N, M;
	cin >> T;
	while (T--) {
		set<int> note1;
		cin >> N;
		int input;
		for (int i = 0; i < N; i++) {
			cin >> input;
			note1.insert(input);
		}
		cin >> M;
		for (int i = 0; i < M; i++) {
			cin >> input;
			if (note1.count(input)) {
				cout << "1\n";
			}
			else {
				cout << "0\n";
			}
		}
	}
	return 0;
}