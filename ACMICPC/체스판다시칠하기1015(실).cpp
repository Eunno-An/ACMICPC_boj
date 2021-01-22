#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int compareBoard(char[][51], char[][8], int, int);
int main() {
	//입력
	int N, M;
	cin >> N >> M;
	char chessBoard[51][51];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> chessBoard[i][j];
		}
	}
	char chessBoard_first_white[8][8];
	char chessBoard_first_black[8][8];
	char line_first_white[8] = { 'W', 'B','W', 'B', 'W', 'B', 'W', 'B' };
	char line_first_black[8] = { 'B', 'W','B', 'W', 'B', 'W', 'B', 'W' };
	for (int i = 0; i < 8; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < 8; j++) {
				chessBoard_first_white[i][j] = line_first_white[j];
				chessBoard_first_black[i][j] = line_first_black[j];
			}
		}
		else {
			for (int j = 0; j < 8; j++) {
				chessBoard_first_white[i][j] = line_first_black[j];
				chessBoard_first_black[i][j] = line_first_white[j];
			}
		}
	}



	//출력

	int min_numberOfSquare = 2501;
	int count_notSame_White = 0, count_notSame_Black = 0;
	
	for (int i = 0; i + 7 < N; i++) {
		for (int j = 0; j + 7 < M; j++) {
			count_notSame_White = compareBoard(chessBoard, chessBoard_first_white, i, j);
			count_notSame_Black = compareBoard(chessBoard, chessBoard_first_black, i, j);
			
			if (min_numberOfSquare > count_notSame_White) {
				min_numberOfSquare = count_notSame_White;
			}
			if (min_numberOfSquare > count_notSame_Black) {
				min_numberOfSquare = count_notSame_Black;
			}
		}
	}
	cout << min_numberOfSquare << '\n';
	return 0;
}
int compareBoard(char chessBoard[][51], char chessBoard_comp[][8], int start_i, int start_j) {
	int count_notSame = 0;
	for (int i = start_i; i < start_i + 8; i++) {
		for (int j = start_j; j < start_j + 8; j++) {
			if (chessBoard[i][j] != chessBoard_comp[i-start_i][j-start_j]) {
				count_notSame++;
			}
		}
	}
	return count_notSame;
}