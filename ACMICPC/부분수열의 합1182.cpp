#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//http://swlock.blogspot.com/2016/03/dp-power-set-with-dp.html
void powerSet(vector<int>&, vector<bool>&, int);
int N, S;
int countSum = 0;
int main() {
	cin >> N >> S;
	vector<int> inputs(N);
	vector<bool> visit(N);
	
	for (int i = 0; i < N; i++) {
		cin >> inputs[i];
	}
	int index = 0;
	for (int i = 0; i < visit.size(); i++) {
		visit[i] = 1;
	}
	powerSet(inputs, visit, index);
	cout << countSum << '\n';
}
void powerSet(vector<int>& inputs, vector<bool>& visit, int index) {
	if (index == N) {
		int visitCount = 0;
		for (int i = 0; i < visit.size(); i++) {
			if (visit[i] == true) {
				break;
			}
			visitCount++;
		}
		if (visitCount == N) {
			return;
		}
		int sum = 0;
		for (int i = 0; i < inputs.size(); i++) {
			if (visit[i] == true) {
				sum += inputs[i];
			}
		}
		if (sum == S) {
			countSum++;
		}
		return ;
	}
	
	
	
	visit[index] = true;
	powerSet(inputs, visit, index+1);

	visit[index] = false;
	powerSet(inputs, visit, index+1);
}
//↓↓↓↓↓↓↓↓부분집합 구하는 알고리즘 (재귀)↓↓↓↓↓↓↓
//void powerSet(vector<int>&,  int);
//void print(vector<int>&);
//bool visited[3];
//int main() {
//	vector<int> arr;
//	vector<int> select;
//	arr.push_back(1);
//	arr.push_back(2);
//	arr.push_back(3);
//	int index = 0;
//	fill_n(visited, 3, false);
//	powerSet(arr, index);
//
//}
//void powerSet(vector<int>& arr, int index) {
//	if (index == 3) {
//		print(arr);
//		return;
//	}
//	visited[index] = 1;
//	powerSet(arr, index + 1);
//	visited[index] = 0;
//	powerSet(arr, index + 1);
//}
//
//void print(vector<int>& arr) {
//	for (int i = 0; i < arr.size(); i++) {
//		if (visited[i] == true) {
//			cout << arr[i] << ' ';
//		}
//	}
//	cout << '\n';
//}

//↓↓↓↓↓↓↓↓↓↓↓↓↓↓부분집합 구하는 알고리즘(비트마스크)↓↓↓↓↓↓↓
//flag값이 단조 증가 한다는 걸 생각할 수 있음. 111 -> 110 -> 101 -> 100 ..
//int datas[] = { 1, 2, 3, 4 };
//void powerSet(int n) {
//	int i, j;
//	int max = 1 << n;
//	for (int i = 0; i < max; i++) {
//		for (int j = 0; j < n; j++) {
//			if (i & (1 << j))
//				cout << datas[j];
//		}
//		cout << '\n';
//	}
//}
//int main() {
//	powerSet(sizeof(datas) / sizeof(int));
//	return 0;
//}

//↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓ DP ↓↓↓↓↓↓↓↓↓↓
