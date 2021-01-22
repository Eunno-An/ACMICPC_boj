
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

int arr[51][51];
int temp[51][51];
int N, M;
int K;
// �׽�Ʈ ���̽� �ʱ�ȭ ��
void init()
{

}

int main()
{
	
	init();
	cin >> N >> M;
	int a;
	vector<int> count_row_zero;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &a);
			arr[i][j] = a;	
		}
	}
	cin >> K;
	//1. Ư�� ���� 0���� ������ (������ ų �� �ִ��� �ƴ��� Ȯ��)
	int count_zero = 0;
	int result = 0;
	int max_result = -1;
	vector<int> idx_able;
	for (int i = 0; i < N; i++) {
		count_zero = 0;
		result = 0;
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 0) {
				count_zero++;
			}
		}
		if (count_zero <= K && count_zero % 2 == K % 2) {
			for (int j = 0; j < N; j++) {
				int row_match_count = 0;
				for (int k = 0; k < M; k++) {
					if (arr[j][k] == arr[i][k]) {
						row_match_count++;
					}
				}
				if (row_match_count == M) {
					result++;
				}
			}
		}
		max_result = max_result < result ? result : max_result;
	}
	cout << max_result << '\n';
	return 0;
}