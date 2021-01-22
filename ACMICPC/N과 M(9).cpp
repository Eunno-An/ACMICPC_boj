#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, M;
vector<int> arr;
vector<int> v;
int main() {
	cin >> N >> M;	
	arr.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	return 0;
}