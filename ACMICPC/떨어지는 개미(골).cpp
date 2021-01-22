#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
//나의 문제
//개미들의 최종 방향을 생각했음. direction 배열을 만들어서, 규칙을 정해서 swap했음.
//최종적인 개미들의 움직임은 알 수 있음
//예로 들어
//내가 짠 코드: 미래의 개미들의 움직임을 생각하고, 기존 p에서 id가 음수인지 양수인지 따진다. 
//여기서 오류가 발생되는데
//7 15 1
//1 7
//3 - 4
//6 - 5
//8 3
//10 - 1
//11 - 2
//13 - 6
//이 예시에서 올바른 순서로 출력하지 못한다.

//내가 생각하지 않은 것은 개미들이 방향이 바뀌면, 그만큼 거리도 바뀌는데, 기존의 거리로 계산해서 정렬한 것이다.

//올바른 답은, 기존의 거리로 계산해서 정렬하고, 그때그때 마다 id를 보고, 
//만약 id가 음수이면 왼쪽으로 떨어질 것이고, 양수이면 오른쪽으로 떨어질 것이다.


bool compare(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.first == b.first)
		return a.second < b.second;
	return a.first < b.first;
}
void print_Directions(vector<int>& directions) {
	for (int i = 0; i < directions.size(); i++) {
		cout << directions[i] << ' ';
	}
	cout << '\n';
};
void print_Ants(vector<pair<int, int>>& ants) {
	cout << "ants[i].first is: ";
	for (int i = 0; i < ants.size(); i++) {
		cout << ants[i].first << ' ';
	}
	cout << "\nants[i].second is : ";
	for (int i = 0; i < ants.size(); i++) {
		cout << ants[i].second << ' ';
	}
	cout << '\n';
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//입력이 무엇인지, 출력이 무엇인지 정의하라
	//입력: 개미의 ID와 막대 상의 위치
	//1. ID: 개미마다 다르며, ID의 부호는 바라보는 방향이다.
	//2. 두 개미가 한 점에서 충돌하는 경우, 두 개미는 행진하는 방향을 반대로 바꾸고, 행진을 계속한다.
	int T; // testcase
	cin >> T;
	for (int i = 0; i < T; i++) {
		int N, L, k; //N: 개미의 마리수, L: 막대의 길이, k: 몇번째로 떨어지는 개미
		//(1 ≤ pi ≤ L - 1, 3 ≤ N ≤ 100,000, 10 ≤ L ≤ 5,000,000, 1 ≤ k ≤ N)
		cin >> N >> L >> k;
		vector<int> ids;
		vector<int> positions;
		vector<pair<int, int>> ants;
		for (int j = 0; j < N; j++) {
			int p, a;
			//-10^9 <= a <= 10^9
			cin >> p >> a;
			ids.push_back(a);
			positions.push_back(p); //p는 항상 증가하는 순서로 주어진다.
			pair<int, int> moving_ants;
			moving_ants.first = ids[j] < 0 ? positions[j] : L - positions[j];
			moving_ants.second = ids[j];
			ants.push_back(moving_ants);
		}
		sort(ants.begin(), ants.end()); // O(NlogN)
		//print_Ants(ants);
		vector<int> fallList;
		int start = 0;
		int end = ids.size() - 1;
		for (int j = 0; j < ants.size(); j++) {
			int front = ids[start], back = ids[end];
			if (j != ants.size() - 1 && ants[j].first == ants[j + 1].first) {
				if (front < back) {
					fallList.push_back(front);
					fallList.push_back(back);
				}
				else {
					fallList.push_back(back);
					fallList.push_back(front);
				}
				end--; start++; j++;
			}
			else if (ants[j].second < 0) {
				fallList.push_back(front);
				start++;
			}
			else {
				fallList.push_back(back);
				end--;
			}
		}
		cout << fallList[k - 1] << '\n';
	}
	//출력: 개미가 떨어지는 순서
	//동시에 떨어질 경우, 왼쪽 개미가 먼저 떨어진다.(ID가 작은 것부터)
	return 0;
}
