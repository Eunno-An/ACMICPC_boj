#include <iostream>
using namespace std;

int main() {
	while (1) {
		int n, num[15], zero = 0, one = 0;
		cin >> n;
		if (n == 0)
			break;
		for (int i = 0; i < n; i++) {
			cin >> num[i];
			if (num[i] == 0)
				zero++;
			else
				one++;
		}
		//���� (->��������)
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				if (num[i] > num[j]) {
					int tmp = num[i];
					num[i] = num[j];
					num[j] = tmp;
				}
			}
		}
		int a = num[zero], b = num[zero + 1];
		//0�� ¦����
		if (zero % 2 == 0) {
			//0�� �ƴ� ���ڰ� ¦����
			if (one % 2 == 0) {
				for (int i = 0; i < zero / 2; i++)
					a *= 10;
				for (int i = 0; i < zero / 2; i++)
					b *= 10;

				for (int i = zero + 2; i < n; i += 2)
					a = a * 10 + num[i];
				for (int i = zero + 3; i < n; i += 2)
					b = b * 10 + num[i];
			}
			//0�� �ƴ� ���ڰ� Ȧ����
			if (one % 2 == 1) {
				for (int i = 0; i < zero / 2; i++)
					a *= 10;
				for (int i = 0; i < zero / 2; i++)
					b *= 10;

				for (int i = zero + 2; i < n; i += 2)
					a = a * 10 + num[i];
				for (int i = zero + 3; i < n; i += 2)
					b = b * 10 + num[i];
			}
		}

		//0�� Ȧ����
		if (zero % 2 == 1) {
			//0�� �ƴ� ���ڰ� ¦����
			if (one % 2 == 0) {
				for (int i = 0; i < zero / 2 + 1; i++)
					a *= 10;
				for (int i = 0; i < zero / 2; i++)
					b *= 10;

				for (int i = zero + 2; i < n; i += 2)
					a = a * 10 + num[i];
				for (int i = zero + 3; i < n; i += 2)
					b = b * 10 + num[i];
			}
			//0�� �ƴ� ���ڰ� Ȧ����
			if (one % 2 == 1) {
				for (int i = 0; i < zero / 2; i++)
					a *= 10;
				for (int i = 0; i < zero / 2 + 1; i++)
					b *= 10;

				for (int i = zero + 2; i < n; i += 2)
					a = a * 10 + num[i];
				for (int i = zero + 3; i < n; i += 2)
					b = b * 10 + num[i];
			}
		}
		cout << a + b << '\n';
	}
	return 0;
}
