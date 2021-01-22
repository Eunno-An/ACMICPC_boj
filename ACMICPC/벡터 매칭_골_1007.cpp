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
���� ��ȸ ID
	579_013
	ZgdxHXStpraTGmCT

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
int T;
int N;
vector<pair<int, int>> inputs;
bool comb_idxs[21] = { false, };
double result = 9223372036854775807;
double temp;
// �׽�Ʈ ���̽� �ʱ�ȭ ��
void init()
{
	inputs.clear();
	for (int i = 0; i < N; i++) {
		comb_idxs[i] = false;
	}
	temp = 0;
	result = 9223372036854775807;
}
void vector_matching(int index, int r, int count) {
	if (r == count) {
		double sum_x = 0, sum_y = 0;
		double sum_minus_x = 0, sum_minus_y = 0;
		for (int i = 0; i < N; i++) {
			if (comb_idxs[i]) {
				sum_x += inputs[i].first;
				sum_y += inputs[i].second;
			}
			else {
				sum_x -= inputs[i].first;
				sum_y -= inputs[i].second;
			}
		}
		temp = sqrt(pow(sum_x, 2) + pow(sum_y, 2));
		if (temp < result) result = temp;
		return;
	}
	if (index == N) {
		return;
	}
	comb_idxs[index] = true;
	vector_matching(index + 1, r, count+1);
	comb_idxs[index] = false;
	vector_matching(index + 1, r, count);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	pair<int, int> input;
	while (T--) {
		cin >> N;
		

		init();
		for (int i = 0; i < N; i++) {
			cin >> input.first >> input.second;
			inputs.push_back(input);
		}
		
		if (N == 2) {
			cout << fixed << setprecision(12) << sqrt(pow(inputs[0].first - inputs[1].first, 2) + pow(inputs[0].second - inputs[1].second, 2)) << '\n';
			continue;
		}
		vector_matching(0, N / 2, 0);
		cout << fixed << setprecision(12) << result << '\n';
	}


	return 0;
}