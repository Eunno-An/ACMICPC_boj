#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
int count_fish(bool**, int start_x, int end_x, int start_y, int end_y);
int main() {
	//첫 번째 줄에는 모눈종이의 크기, 그물의 길이, 물고기의 수를 나타내는 세 개의 정수 N, l, M이 하나의 공백을 두고 주어진다. 
	//단, 2 ≤ N ≤ 10,000, 4 ≤ l ≤ 100, 1 ≤ M ≤100 이다. l은 l ≤ 4N - 4을 만족하는 짝수이다.
	int N, I, M;
	cin >> N >> I >> M;
	bool** matrix = new bool* [N];
	for (int i = 0; i < N; i++) {
		matrix[i] = new bool[N];
		for (int j = 0; j < N; j++) {
			matrix[i][j] = false;
		}
	}
	vector<pair<int, int>> vector_position;
	pair<int, int> pair_input;
	
	for (int i = 0; i < M; i++) {//O(M)
		cin >> pair_input.first >> pair_input.second;
		matrix[pair_input.first-1][pair_input.second-1] = true;
		vector_position.push_back(pair_input);
	}

	//worst case
	//I == 100 -> (1, 49) (2, 48) (3, 47) (4, 46) ... (49, 1) 49개
	//N * N 매트릭스 순회하면서 true인 것 찾는 경우 : O(N^2)
	//N^2 <= 10000 * 10000 = 0.1초
	//49 case를 다 돌으므로 4.9초 대략 걸림 -> Time out

	//M개의 position List만큼 도는 경우 -> O(M) 100개
	

	//출력
	int max_fish = 0;
	for (int i = 0; i < M; i++) {
		int x = vector_position[i].first - 1;
		int y = vector_position[i].second - 1;
		int temp_fish = 0;
		for (int j = 0; j < (I / 2 - 1); j++) {
			int row_x = (j + 1);
			int col_y = (I / 2) - row_x;
			for (int k = 0; k < 4; k++) {
				//if(x, y)가 왼쪽 위 모서리일 경우
				if (k == 0) {
					if (x + row_x > N - 1 || y + col_y > N - 1) {
						break;
					}
					temp_fish = count_fish(matrix, x, x + row_x, y, y + col_y);
				}
				//else if(x, y)가 왼쪽 아래 모서리일 경우
				else if (k == 1) {
					if (x - row_x< 0 || y + col_y > N - 1) {
						break;
					}
					temp_fish = count_fish(matrix, x - row_x, x, y, y + col_y);
				}

				//else if(x, y)가 오른쪽 위 모서리일 경우
				else if (k == 2) {
					if (x + row_x > N - 1 || y - col_y < 0) {
						break;
					}
					temp_fish = count_fish(matrix, x, x + row_x, y - col_y, y);
				}

				//else if(x, y)가 오른쪽 아래 모서리일 경우
				else {
					if (x - row_x< 0 || y - col_y < 0) {
						break;
					}
					temp_fish = count_fish(matrix, x - row_x, x, y - col_y, y);
				}
			}
			if (temp_fish > max_fish) {
				max_fish = temp_fish;
			}
		}
	}
	cout << max_fish << '\n';

	return 0;
}
int count_fish(bool** matrix, int start_x, int end_x, int start_y, int end_y) {
	int fish_in_matrix = 0;
	for (int i = start_x; i <= end_x; i++) {
		for (int j = start_y; j <= end_y; j++) {
			if (matrix[i][j] == true) {
				fish_in_matrix++;
			}
		}
	}
	return fish_in_matrix;	
};