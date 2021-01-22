#include<iostream>
#include<vector>
using namespace std;
void pointing(int x, int y, int N, vector<vector<int>>& arr, int state) {
	if (state) {
		for (int i = x; i < x + N; i++) {
			for (int j = y; j < y + N; j++) {
				arr[i][j] = 0;
			}
		}
	}
	else {
		if (N == 1) {
			arr[x][y] = 1;
		}	
		else {
			int m = N / 3;
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					if (i == 1 && j == 1) {
						pointing(x + m * i, y + m * j, m, arr, 1);
					}
					else {
						pointing(x + m * i, y + m * j, m, arr, 0);
					}
				}
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;
	vector<vector<int>> arr(N);
	for (int i = 0; i < N; i++) {
		arr[i].resize(N);
	}
	pointing(0, 0, N, arr, 0);
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == 0) {
				cout << ' ';
			}
			else if(arr[i][j] == 1) {
				cout << '*';
			}
		}
		cout << '\n';
	}
}