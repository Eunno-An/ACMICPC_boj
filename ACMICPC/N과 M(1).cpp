//이건 조합 구하는 코드
#include<iostream>
#define MAX 8
using namespace std;

int Arr[MAX];
bool Select[MAX];
int N, M;
void Print() {
	for (int i = 0; i < N; i++) {
		if (Select[i] == true) {
			cout << Arr[i] << " ";
		}
	}
	cout << '\n';
}
void dfs(int idx, int cnt) {
	if (cnt == M) {
		Print();
		return;
	}
	for (int i = idx; i < N; i++) {
		if (Select[i]) continue;
		Select[i] = true;
		dfs(i, cnt + 1);
		Select[i] = false;
	}
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		Arr[i] = i + 1;
	}
	dfs(0, 0);
	return 0;
}
//#include<iostream>
//#include<vector>
//using namespace std;
//int Arr[8];
//bool Select[8];
//vector<int> v;
//int N, M;
//void Print() {
//	for (int i = 0; i < v.size(); i++) {
//		if (v[i] == 0) {
//			continue;
//		}
//		cout << v[i] << " ";
//	}
//	cout << '\n';
//}
//void dfs(int cnt){
//	if (cnt == M) {
//		Print();
//		return;
//	}
//	for (int i = 0; i < N; i ++) {
//		if (Select[i]) continue;
//		Select[i] = true;
//		v.push_back(Arr[i]);
//		dfs(cnt + 1);
//		v.pop_back();
//		Select[i] = false;
//	}
//}
//int main() {
//	cin >> N >> M;
//	v.resize(N);
//	for (int i = 0; i < N; i++) {
//		Arr[i] = i + 1;
//	}
//	dfs(0);
//	return 0;
//}