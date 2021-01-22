
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
long long k;
ll print_k(ll idx) {
	if (idx <= 1) {
		return 0;
	}
	int p = 0;
	while (1) {
		ll result = (long long)pow(2, p);
		if (idx < result) {
			break;
		}
		p += 1;
	}
	return 1 - print_k(idx - pow(2,p-1));
}
long long getV(long long a) {
	long long v = 1;
	while (v * 2 < a) v *= 2;
	return a - v;
}

//1: cnt 1, 0 -> 1
//2 : cnt 1, 1 cnt 2, 0 -> 2
//3 : cnt 1, 1 cnt 2, 0
//4 : cnt 1, 2 cnt 2, 1 cnt 3, 0 -> 3
//5 : cnt 1, 1 cnt 2, 0
//6 : cnt 1, 2 cnt 2, 1 cnt 3, 0
//7 : cnt 1, 3 cnt 2, 1 cnt 3, 0
//8 : cnt 1, 4 cnt 2, 2 cnt 3, 1 cnt 4, 0 -> 4
//9 : cnt 1, 1 cnt 2, 0
//10 : cnt 1, 2 cnt 2, 1 cnt 3, 0
//11 : cnt 1, 3 cnt 2, 1 cnt 3, 0
//12 : cnt 1, 4 cnt 2, 2 cnt 3, 1 cnt 4, 0
//13 : cnt 1, 5 cnt 2, 1 cnt 3, 0
//14 : cnt 1, 6 cnt 2, 2 cnt 3, 1 cnt 4, 0
//15 : cnt 1, 7 cnt 2, 3 cnt 3, 1 cnt 4, 0
//16 : cnt 1, 8 cnt 2, 4 cnt 3, 2 cnt 4, 1 cnt 5, 0 -> 5

//1 2 2 3
//2 3 3 4
//2 3 3 4 3 4 4 5
//3 4 4 5 4 5 5 6
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s = "1";
	
	cin >> k;
	int cnt = 0;
	while (k != 0) {
		cnt++;
		k = getV(k);
	}
	//k���� k���� ���� 2�� �������� ���鼭 1�� �Ǳ���� �󸶳� �ɷȴ���?
	if (cnt % 2 == 1) {
		cout << 0;
	}
	else
		cout << 1;
	

	return 0;
}