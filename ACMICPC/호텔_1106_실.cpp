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

int C, N;
vector<pair<int, int>> arr;
int arr_C[1101] = {};
// �׽�Ʈ ���̽� �ʱ�ȭ ��
void init()
{
	for (int i = 0; i < 1101; i++) {
		arr_C[i] = INT_MAX;
	}
}
bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();
	cin >> C >> N;
	if (C == 0 || N == 0) {
		cout << 0 << '\n';
		return 0;
	}
	pair<int, int> cost_client;
	//cost�� ���̸� num_client ��ŭ ���� �þ��.
	for (int i = 0; i < N; i++) {
		cin >> cost_client.first >> cost_client.second;
		arr_C[cost_client.second] = cost_client.first;
		arr.push_back(cost_client);
	}
	sort(arr.begin(), arr.end(), cmp);
	arr_C[0] = 0;
	for (int i = 1; i <= 1100; i++) {
		for (int j = 0; j < arr.size(); j++) {
			int cost = arr[j].first;
			int client_Num = arr[j].second;
			if (client_Num > i) {
				break;
			}
			//i�� 18 �̰� j�� 3 7 9 18
			arr_C[i] = min(arr_C[i - arr[j].second] + arr[j].first, arr_C[i]);
		}
	}
	int min_value = INT_MAX;
	for (int i = C; i <= 1100; i++) {
		if (min_value > arr_C[i]) {
			min_value = arr_C[i];
		}
	}
	cout << min_value << '\n';
	return 0;
}