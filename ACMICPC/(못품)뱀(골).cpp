#include<iostream>
#include<vector>
#include<deque>
using namespace std;
int change_direction(int a, char b) {
	//a = 0 -> 3, 1 ->0, 2 ->1, 3 -> 2
	if (b == 'L') { // ¿ÞÂÊ
		return (a + 3) % 4;
	}
	//a = 0 -> 1, 1 -> 2, 2 -> 3, 3->0
	else if (b == 'D') {
		return (a + 1) % 4;
	}
}
pair<int, int> move_pos(int row, int col, int direction) {
	pair<int, int> temp;
	temp.first = row;
	temp.second = col;
	if (direction == 0) {
		temp.second++;
		return temp;
	}
	else if (direction == 1) {
		temp.first++;
		return temp;
	}
	else if (direction == 2) {
		temp.second--;
		return temp;
	}
	else if (direction == 3) {
		temp.first--;
		return temp;
	}
}
void move_snake(vector<vector<int>>& matrix, deque<pair<int, pair<int,int>>>& snake) {
	int tail_row = snake.front().second.first;
	int tail_col = snake.front().second.second;
	matrix[tail_row][tail_col] = 0;
	for (int i = 0; i < snake.size(); i++) {
		snake[i].second = move_pos(snake[i].second.first, snake[i].second.second, snake[i].first);
	}
	for (int i = 0; i < snake.size() - 1; i++) {
		snake[i].first = change_direction(snake[i].first, snake[i + 1].first);
	}
}
int main() {
	int N, K, row, col, L;
	int X;
	char C;
	cin >> N >> K;
	vector<vector<int>> mat(N, vector<int>(N, 0));

	int size_snake = 1;
	int direction = 0; // default = 0 (right), 1 = down, 2 = left, 3 = up
	for (int i = 0; i < K; i++) {
		cin >> row >> col;
		mat[row - 1][col - 1] = 1;
	}
	mat[0][0] = 2;
	pair<int, int> head_pos;
	head_pos.first = 0;
	head_pos.second = 0;
	bool flag = false;
	int count = 0;
	pair<int, pair<int, int>> move_info;
	move_info.first = 0;
	move_info.second = head_pos;
	deque<pair<int, pair<int, int>>> snake_info;
	snake_info.push_back(move_info);
	cin >> L;
	int tempX = 0;
	//XÀÇ Á¶°Ç º¯°æ! 3ÃÊ 15ÃÊ ÀÌ·¸°Ô µé¾î¿À¸é, ½ÇÁ¦·Î °è½ÑÇØ¾ß ÇÏ´Â°Ç 3ÃÊ 12ÃÊ!
	for (int i = 0; i < L; i++) {
		cin >> X >> C;
		if (i == 0) {
			tempX = X;
		}
		X = X - tempX;
		
		int direction = snake_info.back().first;
		if (direction == 0) {
			for (int j = 1; j <= X; j++) {
				head_pos = snake_info.back().second;
				if (head_pos.second +1 == N) {
					flag = true;
					break;
				}
				if (mat[head_pos.first][head_pos.second + 1] == 1) {
					//»ç°ú¿Í ´êÀ½
					pair<int, pair<int, int>> new_element;
					new_element.first = 0;
					new_element.second.first = head_pos.first;
					new_element.second.second = head_pos.second + 1;
					snake_info.push_back(new_element);
					count++;
				}
				else if (mat[head_pos.first][head_pos.second + 1] == 2) {
					//¹ì°ú ´êÀ½
					flag = true;
					break;
				}
				else {
					//ºóÄ­ ÁøÇà
					move_snake(mat, snake_info);
					count++;
				}
			}
		}
		else if (direction == 1) {
			for (int j = 1; j <= X; j++) {
				head_pos = snake_info.back().second;
				if (head_pos.first + 1 == N) {
					flag = true;
					break;
				}
				if (mat[head_pos.first+1][head_pos.second] == 1) {
					//»ç°ú¿Í ´êÀ½
					pair<int, pair<int, int>> new_element;
					new_element.first = 0;
					new_element.second.first = head_pos.first+1;
					new_element.second.second = head_pos.second;
					snake_info.push_back(new_element);
					count++;
				}
				else if (mat[head_pos.first+1][head_pos.second ] == 2) {
					//¹ì°ú ´êÀ½
					flag = true;
					break;
				}
				else {
					//ºóÄ­ ÁøÇà
					move_snake(mat, snake_info);
					count++;
				}
			}
		}
		else if (direction == 2) {
			for (int j = 1; j <= X; j++) {
				head_pos = snake_info.back().second;
				if (head_pos.second - 1 == -1) {
					flag = true;
					break;
				}
				if (mat[head_pos.first][head_pos.second - 1] == 1) {
					//»ç°ú¿Í ´êÀ½
					pair<int, pair<int, int>> new_element;
					new_element.first = 0;
					new_element.second.first = head_pos.first;
					new_element.second.second = head_pos.second - 1;
					snake_info.push_back(new_element);
					count++;
				}
				else if (mat[head_pos.first][head_pos.second - 1] == 2) {
					//¹ì°ú ´êÀ½
					flag = true;
					break;
				}
				else {
					//ºóÄ­ ÁøÇà
					move_snake(mat, snake_info);
					count++;
				}
			}
		}
		else if (direction == 3) {
			for (int j = 1; j <= X; j++) {
				head_pos = snake_info.back().second;
				if (head_pos.first - 1 == N) {
					flag = true;
					break;
				}
				if (mat[head_pos.first-1][head_pos.second] == 1) {
					//»ç°ú¿Í ´êÀ½
					pair<int, pair<int, int>> new_element;
					new_element.first = 0;
					new_element.second.first = head_pos.first - 1;
					new_element.second.second = head_pos.second;
					snake_info.push_back(new_element);
					count++;
				}
				else if (mat[head_pos.first - 1][head_pos.second] == 2) {
					//¹ì°ú ´êÀ½
					flag = true;
					break;
				}
				else {
					//ºóÄ­ ÁøÇà
					move_snake(mat, snake_info);
					count++;
				}
			}
		}
		if (flag) {
			break;
		}
	}
	cout << count << '\n';
	return 0;
}