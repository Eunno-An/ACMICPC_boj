
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

// �׽�Ʈ ���̽� �ʱ�ȭ ��
void init()
{

}

bool compare(int a, int b) {
	return a > b;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();
	cin >> N;
	int pos_x, pos_y, length_fense;
	vector<int> vector_length;
	int max_x = -1, max_y = -1;
	int min_x = INT_MAX, min_y=INT_MAX;
	for (int i = 0; i < N; i++) {
		cin >> pos_x >> pos_y >> length_fense;
		if (pos_x > max_x) {
			max_x = pos_x;
		}
		if (pos_x < min_x) {
			min_x = pos_x;
		}
		if (pos_y > max_y) {
			max_y = pos_y;
		}
		if (pos_y < min_y) {
			min_y = pos_y;
		}
		vector_length.push_back(length_fense);
	}
	sort(vector_length.begin(), vector_length.end(), compare);
	int need_fense = ((max_x - min_x) + (max_y - min_y)) * 2;
	int count = 0;
	for (int i = 0; i < vector_length.size(); i++) {
		if (vector_length[i] == 0) {
			break;
		}
		need_fense -= vector_length[i];
		
		if (need_fense < 0) {
			break;
		}
		count++;
	}
	cout << count << '\n';

	return 0;
}