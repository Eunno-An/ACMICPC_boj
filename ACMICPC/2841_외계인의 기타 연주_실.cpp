
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
int N, P;

// �׽�Ʈ ���̽� �ʱ�ȭ ��
void init()
{

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();
	stack<int> s1, s2, s3, s4, s5, s6;
	cin >> N >> P;
	int input1, input2;
	int count = 0;
	for (int i = 0; i < N; i++) {
		cin >> input1 >> input2;
		if(input1 == 1){
			if (s1.empty()) {
				s1.push(input2);
				count++;
			}
			
			else {
				while (s1.top() > input2) {
					s1.pop();
					count++;
					if (s1.empty()) {
						break;
					}
				}
				if (!s1.empty() && s1.top() == input2) {
					continue;
				}
				s1.push(input2);
				count++;
			}
		}
		else if(input1 == 2){
			if (s2.empty()) {
				s2.push(input2);
				count++;
			}
			else {
				while (s2.top() > input2) {
					s2.pop();
					count++;
					if (s2.empty()) {
						break;
					}
				}
				if (!s2.empty() && s2.top() == input2) {
					continue;
				}
				s2.push(input2);
				count++;
			}
		}
		else if(input1 == 3){
			if (s3.empty()) {
				s3.push(input2);
				count++;
			}
			else {
				while (s3.top() > input2) {
					s3.pop();
					count++;
					if (s3.empty()) {
						break;
					}
				}
				if (!s3.empty() && s3.top() == input2) {
					continue;
				}
				s3.push(input2);
				count++;
		}
			}
		else if(input1 == 4){
			if (s4.empty()) {
				s4.push(input2);
				count++;
			}
			else {
				while (s4.top() > input2) {
					s4.pop();
					count++;
					if (s4.empty()) {
						break;
					}
				}
				if (!s4.empty() && s4.top() == input2) {
					continue;
				}
				s4.push(input2);
				count++;
			}
		}
		else if(input1 == 5){
			if (s5.empty()) {
				s5.push(input2);
				count++;
			}
			else {
				while (s5.top() > input2) {
					s5.pop();
					count++;
					if (s5.empty()) {
						break;
					}
				}
				if (!s5.empty() && s5.top() == input2) {
					continue;
				}
				s5.push(input2);
				count++;
			}
		}
		else {
			if (s6.empty()) {
				s6.push(input2);
				count++;
			}
			else {
				while (s6.top() > input2) {
					s6.pop();
					count++;
					if (s6.empty()) {
						break;
					}
				}
				if (!s6.empty() && s6.top() == input2) {
					continue;
				}
				s6.push(input2);
				count++;
			}
		}
	}
	cout << count << '\n';
	return 0;
}