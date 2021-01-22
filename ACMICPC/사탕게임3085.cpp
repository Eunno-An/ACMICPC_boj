#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
int maxCount = 0;
void function_copy(char**, char**);
void Bomboni(char**, char**, int, int, int);
int countMax(char*);
int N;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
//i, j
//���ʰ� �ٲ� ��� i, j <->i, j - 1 :: >> > (i, 0~N - 1), (0~N - 1, j - 1), (0~N - 1, j)�� ����
//�����ʰ� �ٲ� ��� i, j <->i, j + 1 :: >> > (i, 0~N - 1), (0~N - 1, j), (0~N - 1, j + 1)�� ����
//���ʰ� �ٲ� ��� i, j <->i - 1, j :: >> > (i - 1, 0~N - 1), (i, 0~N - 1), (0~N - 1, j)�� ����
//�Ʒ��ʰ� �ٲ� ���i, j <->i + 1, j :: >> > (i + 1, 0~N - 1), (i, 0~N - 1), (0~N - 1, j)�� ����.[
int main() {
	
	cin >> N;
	char** mat = new char* [N];
	char** temp = new char* [N];
	//2���� ��Ʈ���� �ʱ�ȭ
	for (int i = 0; i < N; i++) {
		mat[i] = new char[N];
		temp[i] = new char[N];
		memset(mat[i], '\0', sizeof(char) * N);
		memset(temp[i], '\0', sizeof(char) * N);
	}
	//2���� ��Ʈ���� �Է�
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> mat[i][j];
		}
	}
	function_copy(mat, temp);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < 4; k++) {
				Bomboni(mat, temp, i, j, k);
			}
		}
	}
	cout << maxCount << '\n';
	//�޸� ����
	for (int i = 0; i < N; i++) {
		delete[] mat[i];
		delete[] temp[i];
	}
	delete[] mat;
	delete[] temp;
	return 0;
}
void function_copy(char** mat, char** copy) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			copy[i][j] = mat[i][j];
		}
	}
}
void Bomboni(char** mat, char** copy, int x, int y, int direction) {
	if (x < 0 || x >= N || y < 0 || y >= N) { //invalid ������ ��� ����
		return;
	}
	if (direction == 0) {//�����ʰ� �ٲ� ���
		if (y + 1 >= N) {
			return;
		}
		char tmp = mat[x][y];
		copy[x][y] = copy[x][y + 1];
		copy[x][y + 1] = tmp;

		char* tmparr = new char[N];

		for (int i = 0; i < N; i++) {//���ڿ� �ҷ�����
			tmparr[i] = copy[x][i];//������ ���� ->
		}
		int tmpCount = countMax(tmparr);
		if (maxCount < tmpCount) {
			maxCount = tmpCount;
		}
		for (int i = 0; i < N; i++) {
			tmparr[i] = copy[i][y];//������ �Ʒ���, y��°
		}
		tmpCount = countMax(tmparr);
		if (maxCount < tmpCount) {
			maxCount = tmpCount;
		}
		for (int i = 0; i < N; i++) {
			tmparr[i] = copy[i][y + 1];
		}
		tmpCount = countMax(tmparr);
		if (maxCount < tmpCount) {
			maxCount = tmpCount;
		}
	}
	else if (direction == 1) {//�Ʒ��� �ٲ� ���
		if (x + 1 >= N) {
			return;
		}
		char tmp = mat[x][y];
		copy[x][y] = copy[x+1][y];
		copy[x+1][y] = tmp;
		char* tmparr = new char[N];

		for (int i = 0; i < N; i++) {//���ڿ� �ҷ�����
			tmparr[i] = copy[x+1][i];
		}
		int tmpCount = countMax(tmparr);
		if (maxCount < tmpCount) {
			maxCount = tmpCount;
		}
		for (int i = 0; i < N; i++) {
			tmparr[i] = copy[x][i];
		}
		tmpCount = countMax(tmparr);
		if (maxCount < tmpCount) {
			maxCount = tmpCount;
		}
		for (int i = 0; i < N; i++) {
			tmparr[i] = copy[i][y];
		}
		tmpCount = countMax(tmparr);
		if (maxCount < tmpCount) {
			maxCount = tmpCount;
		}
	}
	else if (direction == 2) {//���ʰ� �ٲ� ���
		if (y - 1 < 0) {
			return;
		}
		char tmp = mat[x][y];
		copy[x][y] = copy[x][y-1];
		copy[x][y-1] = tmp;
		char* tmparr = new char[N];

		for (int i = 0; i < N; i++) {//���ڿ� �ҷ�����
			tmparr[i] = copy[x][i];
		}
		int tmpCount = countMax(tmparr);
		if (maxCount < tmpCount) {
			maxCount = tmpCount;
		}
		for (int i = 0; i < N; i++) {
			tmparr[i] = copy[i][y-1];
		}
		tmpCount = countMax(tmparr);
		if (maxCount < tmpCount) {
			maxCount = tmpCount;
		}
		for (int i = 0; i < N; i++) {
			tmparr[i] = copy[i][y];
		}
		tmpCount = countMax(tmparr);
		if (maxCount < tmpCount) {
			maxCount = tmpCount;
		}
	}
	else if (direction == 3) {//���� �ٲ� ���
		if (x - 1 < 0) {
			return;
		}
		char tmp = mat[x][y];
		copy[x][y] = copy[x - 1][y];
		copy[x - 1][y] = tmp;
		char* tmparr = new char[N];

		for (int i = 0; i < N; i++) {//���ڿ� �ҷ�����
			tmparr[i] = copy[x - 1][i];
		}
		int tmpCount = countMax(tmparr);
		if (maxCount < tmpCount) {
			maxCount = tmpCount;
		}
		for (int i = 0; i < N; i++) {
			tmparr[i] = copy[x][i];
		}
		tmpCount = countMax(tmparr);
		if (maxCount < tmpCount) {
			maxCount = tmpCount;
		}
		for (int i = 0; i < N; i++) {
			tmparr[i] = copy[i][y];
		}
		tmpCount = countMax(tmparr);
		if (maxCount < tmpCount) {
			maxCount = tmpCount;
		}
	}
	function_copy(mat, copy);
}
int countMax(char* arr) {
	int count[4] = { 0, 0, 0, 0 };
	char input = '\0';
	int count_char = 0;
	int maxCount = 1;
	for (int i = 0; i < N; i++) {
		if (input != arr[i]) {
			input = arr[i];
			count_char = 1;
		}
		else {
			count_char++;
			if (maxCount < count_char) {
				maxCount = count_char;
			}
		}
	}
	return maxCount;
}


