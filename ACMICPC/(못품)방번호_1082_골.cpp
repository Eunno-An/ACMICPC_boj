
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <climits>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include<iomanip>

using namespace std;

/*
- endl ��� '\n' ����ϱ�
- cin.tie(0) ���
- �׽�Ʈ ���̽� �ִ� ������ �� �������� �ʱ�ȭ �Ű澲��
- (A + B + C) % D = ((A + B) % D + C) % D
- ���ڿ� ��� ������ ���� ���ڿ� �����ؼ� �ڵ忡 �ֱ�
- ��ȣ ��� �����ϱ�
- ���ڿ��� �Լ��� �ѱ� �� const & �� ����ϱ�

- �־��� ��� int �� �ʰ��ϴ���, �迭 �ε��� �ʰ��ϴ��� Ȯ��
- n ���� Ȯ�� (0�� ���), ������� �����Ҽ� Ȯ��, �Ұ����̽� -1 ��� �� Ȯ��
- ū �迭 ���� �� ��������, ���� ���� �� �ʱ�ȭ, �迭 �뷮 max N + 5
*/

#define MOD 1000000007
#define INT_MAX 987654321
#define MAX 100005

typedef long long int ll;
typedef pair<int, int> pii;

int N;
vector<pair<int, int>> cost_N;
int my_money;
vector<int> max_result;
// �׽�Ʈ ���̽� �ʱ�ȭ ��
void init()
{

}
bool is_max(vector<int> a, vector<int> b) {
	// if true, a is bigger than b
	if (a.size() > b.size()) {
		return true;
	}
	if (a.size() < b.size()) {
		return false;
	}
	for (int i = 0; i < a.size(); i++) {
		if (a[i] < b[i]) {
			return false;
		}
	}
	return true;
}/*
calc(2, 21, 0, temp)
->calc(2, 21, 8, temp)
->calc(2, 21, 16, temp)->calc(2, 21, 24, temp) -> if :  calc(1, 21, 16, temp)->calc(1, 21, 23, temp) ->  if calc(0, 21, 16, temp)->calc(0, 21, 22, temp)->calc(-1, 21, 16, temp) : return
																																 

*/
// (2,) (2, ) (2,)
//            (1, )
//            (0, )
//            (-1,)
//       (1, )(1, )
//       (1, )(0, )
//            (-1, )
//       (0, )(0, )
//       (0, )(-1,)
//(2, )(1, )(1, )
//(2, )(1, )(0, )
//			(-1,)
void cal_max(int idx, int cost, int now_cost, vector<int> temp) { // ��ͷ� ¥����
	if (idx < 0) {
		bool flag = is_max(max_result, temp);
		if (!flag) {
			max_result = temp;
		}
		return;
	}
	if (cost < now_cost) {
		now_cost -= cost_N[idx].first;
		temp.pop_back();
		cal_max(idx-1, cost, now_cost, temp);
		return;
	}
	now_cost += cost_N[idx].first;
	temp.push_back(idx);
	for (int i = idx; i >= 0; i--) {
		cal_max(i, cost, now_cost, temp);
	}

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();
	cin >> N;
	pair<int, int> cost; // first = cost of number, second = number
	for (int i = 0; i < N; i++) {
		cin >> cost.first;
		cost.second = i;
		cost_N.push_back(cost);
	}
	cin >> my_money;
	vector<int> temp;
	cal_max(cost_N.size() - 1, my_money, 0, temp);
	for (int i = 0; i < max_result.size(); i++) {
		cout << max_result[i];
	}
	cout << '\n';


	return 0;
}