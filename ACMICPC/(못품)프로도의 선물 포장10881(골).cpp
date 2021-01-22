#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

int calculate_two_one(vector<int>&);
int calculate_three(vector<int>&);
int main() {
	int T;
	cin >> T;
	int A, B;

	for (int i = 0; i < T; i++) {
		vector<int> presents;
		vector<int> temp;

		for (int j = 0; j < 3; j++) {
			cin >> A >> B;
			presents.push_back(A);
			presents.push_back(B);
		}
		temp = presents;
		int min_Three = calculate_three(presents);
		presents = temp;
		int min_Two = calculate_two_one(presents);
		int min_area = min_Three > min_Two ? min_Two : min_Three;
		cout << min_area << '\n';
	}

	return 0;
}
int calculate_three(vector<int>& presents) {
	int min_area = 7501;
	int temp_area = 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				temp_area = (presents[0] + presents[2] + presents[4]) * max(max(presents[1], presents[3]), max(presents[3], presents[5]));
				if (min_area > temp_area) {
					min_area = temp_area;
				}
				swap(presents[4], presents[5]);
			}
			swap(presents[2], presents[3]);
		}
		swap(presents[0], presents[1]);
	}
	return min_area;
}
int calculate_two_one(vector<int>& presents) {
	int min_area = 7501;
	int temp_area = 0;
	int base_hori = presents[0] + presents[2];
	int base_verti = max(presents[1], presents[3]);

	//a, b���� c�� �ö� �ִ� ��� 

	//���� ���� �� ���
	//b������ c�� �ö� �ִ� ���, a������ c�� �ö� �ִ� ���, (a, b) ���� c�� �ö�� �ִ� ��� 
	//�� ������ ������ max ���� ���ϸ� �ȴ�.
	//�� ���� = max(max(b�� ����, c�� ����) + a�� ����, max(a�� ����, c�� ����) + b�� ����, max(c�� ����, a ���� + b����))
	//���� = max(max(b+c�� ����, a�� ����), max(a+c�� ����, b�� ����), max(max(a�� ����, b�� ����) + c�� ����)

	//a ���� b, c�� �ö�� �ִ� ���

	//b���� a, c�� �ö�� �ִ� ���

	//c ���� a, b�� �ö�� �ִ� ���
	//c�� 90�� ȸ�� ��Ų ��쵵 �Ȱ��� �����ϸ� �ȴ�.
	vector<int> temp;
	temp = presents;
	for (int k = 0; k < 2; k++) {
		for (int j = 0; j < 2; j++) {
			for (int i = 0; i < 3; i++) {
				int row_1 = 0, row_2 = 0, row_3 = 0, row_4 = 0, row_5 = 0;
				int col_1 = 0, col_2 = 0, col_3 = 0, col_4 = 0, col_5 = 0;
				row_1 = max(presents[2], presents[4]) + presents[0];
				row_2 = max(presents[0], presents[4]) + presents[2];
				row_3 = max(presents[4], presents[0] + presents[2]);
				row_4 = max(presents[0] + presents[2], presents[4]);
			
				col_1 = max(presents[3] + presents[5], presents[1]);
				col_2 = max(presents[1] + presents[5], presents[3]);
				col_3 = max(presents[1], presents[3]) + presents[5];
				col_4 = min(presents[1] + presents[5], presents[3] + presents[5]);

				int area_1 = row_1 * col_1;
				int area_2 = row_2 * col_2;
				int area_3 = row_3 * col_3;
				int area_4 = row_4 * col_4;
				
				vector<int> areaList;
				areaList.push_back(area_1);
				areaList.push_back(area_2);
				areaList.push_back(area_3);
				areaList.push_back(area_4);
				
				temp_area = areaList[0];
				for (int h = 1; h < 4; h++) {
					if (temp_area > areaList[h]) {
						temp_area = areaList[h];
					}
				}
				if (temp_area < min_area) {
					min_area = temp_area;
				}
				presents = temp;
				swap(presents[2 * i], presents[4]);
				swap(presents[2 * i + 1], presents[5]);
				swap(presents[4], presents[5]);
			}
			swap(presents[2], presents[3]);
		}
		swap(presents[0], presents[1]);
	}
	return min_area;
}