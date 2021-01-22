#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
bool ok(int x, int y, int dx, int dy);
bool samePos(int, int, int, int);
int main() {
	//�Է�
	string position_king;
	string position_rock;
	int N;// 1 <= N <= 50

	//if(stage[i][j] == -1) -> empty
	//else if(stage[i][j] == 0) -> rock
	//else if(stage[i][j] == 1) -> king

	int stage[8][8];
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			stage[i][j] = -1;
		}
	}
	cin >> position_king >> position_rock >> N;
	int king_row = 0, rock_row = 0;
	int king_col = 0, rock_col = 0;

	king_col = int(position_king[0]) - 65;
	rock_col = int(position_rock[0]) - 65;
	king_row = 8 - (int(position_king[1]) - 48);
	rock_row = 8 - (int(position_rock[1]) - 48);

	string tempInput;

	//�� -> x����, �Ʒ� -> x����
	//���� -> y����, ������ -> y ����
	for (int i = 0; i < N; i++) {
		cin >> tempInput;

		if (tempInput == "R") {//�� ĭ ������
			if (samePos(king_row, king_col + 1, rock_row, rock_col)) {
				if (ok(rock_row, rock_col, 0, 1)) {
					king_col++;
					rock_col++;
				}
				else {
					continue;
				}
			}
			else {
				if (ok(king_row, king_col, 0, 1)) {//king�� ������ �� �ִ� �����ΰ�
					king_col++;
				}
				else {
					continue;
				}
			}
		}
		else if (tempInput == "L") {//�� ĭ ����
			if (samePos(king_row, king_col - 1, rock_row, rock_col)) {
				if (ok(rock_row, rock_col, 0, -1)) {
					king_col--;
					rock_col--;
				}
				else {
					continue;
				}
			}
			else {
				if (ok(king_row, king_col, 0, -1)) {//king�� ������ �� �ִ� �����ΰ�
					king_col--;
				}
				else {
					continue;
				}
			}
		}
		else if (tempInput == "B") {//�� ĭ �Ʒ���
			if (samePos(king_row + 1, king_col, rock_row, rock_col)) {
				if (ok(rock_row, rock_col, 1, 0)) {
					king_row++;
					rock_row++;
				}
				else {
					continue;
				}
			}
			else {
				if (ok(king_row, king_col, 1, 0)) {//king�� ������ �� �ִ� �����ΰ�
					king_row++;
				}
				else {
					continue;
				}
			}
		}
		else if (tempInput == "T") {//�� ĭ ����
			if (samePos(king_row - 1, king_col, rock_row, rock_col)) {
				if (ok(rock_row, rock_col, -1, 0)) {
					king_row--;
					rock_row--;
				}
				else {
					continue;
				}
			}
			else {
				if (ok(king_row, king_col, -1, 0)) {//king�� ������ �� �ִ� �����ΰ�
					king_row--;
				}
				else {
					continue;
				}
			}
		}
		else if (tempInput == "RT") {//������ �� �밢������
			if (samePos(king_row - 1, king_col + 1, rock_row, rock_col)) {
				if (ok(rock_row, rock_col, -1, 1)) {
					king_row--;
					rock_row--;
					king_col++;
					rock_col++;
				}
				else {
					continue;
				}
			}
			else {
				if (ok(king_row, king_col, -1, 1)) {//king�� ������ �� �ִ� �����ΰ�
					king_row--;
					king_col++;
				}
				else {
					continue;
				}
			}
		}
		else if (tempInput == "LT") {//���� �� �밢��
			if (samePos(king_row - 1, king_col - 1, rock_row, rock_col)) {
				if (ok(rock_row, rock_col, -1, -1)) {
					king_row--;
					rock_row--;
					king_col--;
					rock_col--;
				}
				else {
					continue;
				}
			}
			else {
				if (ok(king_row, king_col, -1, -1)) {//king�� ������ �� �ִ� �����ΰ�
					king_row--;
					king_col--;
				}
				else {
					continue;
				}
			}continue;
		}
		else if (tempInput == "RB") {//������ �Ʒ� �밢��
			if (samePos(king_row + 1, king_col + 1, rock_row, rock_col)) {
				if (ok(rock_row, rock_col, 1, 1)) {
					king_col++;
					rock_col++;
					king_row++;
					rock_row++;
				}
				else {
					continue;
				}
			}
			else {
				if (ok(king_row, king_col, 1, 1)) {//king�� ������ �� �ִ� �����ΰ�
					king_col++;
					king_row++;
				}
				else {
					continue;
				}
			}
		}
		else if (tempInput == "LB") {//���� �Ʒ� �밢��
			if (samePos(king_row + 1, king_col - 1, rock_row, rock_col)) {
				if (ok(rock_row, rock_col, 1, -1)) {
					king_row++;
					rock_row++;
					king_col--;
					rock_col--;
				}
				else {
					continue;
				}
			}
			else {
				if (ok(king_row, king_col, 1, -1)) {//king�� ������ �� �ִ� �����ΰ�
					king_row++;
					king_col--;
				}
				else {
					continue;
				}
			}

		}

	}

	int final_king_row = 8 - king_row;
	int final_rock_row = 8 - rock_row;
	char final_king_col = char(king_col + 65);
	char final_rock_col = char(rock_col + 65);

	//���
	cout << final_king_col << final_king_row << '\n' << final_rock_col << final_rock_row << '\n';
	return 0;

}


bool ok(int x, int y, int dx, int dy) {
	if (x + dx > 7 || x + dx < 0 || y + dy > 7 || y + dy < 0) {
		return false;
	}
	return true;
}
bool samePos(int kx, int ky, int rx, int ry) {
	if (kx == rx && ky == ry) {
		return true;
	}
	return false;
}