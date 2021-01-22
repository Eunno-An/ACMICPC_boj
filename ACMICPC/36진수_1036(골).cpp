
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
int N, K;
vector<string> original;
vector<string> inputs;
vector<pair<int, int>> sizes;
vector<char> erases;

// �׽�Ʈ ���̽� �ʱ�ȭ ��
void init()
{

}
bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) {
		return inputs[a.second] < inputs[b.second];
	}
	return a.first > b.first;
}
bool compare2(string a, string b) {
	return a.size() > b.size();
}
constexpr int trans_digit(char n) {
	if (n >= '0' && n <= '9')
		return n - '0';
	return n - 'A' + 10;
}
//dec(digit) -> 36
constexpr char rtrans_digit(int n) {
	if (n < 10)
		return static_cast<char>(n + '0');
	return static_cast<char>(n - 10 + 'A');
}
string add_36(string a, string b) {
	if (b.size() > a.size())
		swap(a, b);
	b = string(a.size() - b.size(), '0') + b;
	string ret;
	int carry = 0;
	for (auto it1 = a.rbegin(), it2 = b.rbegin(); it1 != a.rend(); ++it1, ++it2) {
		int sum = carry + trans_digit(*it1) + trans_digit(*it2);
		carry = sum / 36;
		sum %= 36;
		ret += rtrans_digit(sum);
	}
	if (carry)
		ret += '1';
	reverse(ret.begin(), ret.end());
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();
	cin >> N;
	int size_max = -1;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		inputs.push_back(s);
		pair<int, int> size_idx;
		size_idx.first = s.size();
		size_idx.second = i;
		sizes.push_back(size_idx);
	}
	original = inputs;
	cin >> K;
	if (N == 0) {
		cout << 0 << '\n';
		return 0;
	}
	if (K == 0) {
		string add = inputs[0];
		for (int i = 0; i < inputs.size() - 1; i++) {
			add = add_36(add, original[i + 1]);

		}
		cout << add << '\n';
		return 0;
	}
	while(1){
		
		sort(sizes.begin(), sizes.end(), compare);
		
		int size_i = sizes[0].first;
		int idx_i = sizes[0].second;
		char erase_char = inputs[idx_i][0];
		erases.push_back(erase_char);
		/*cout << "erase char is : " << inputs[idx_i][0] << '\n';*/
		inputs[idx_i].erase(0, 1);
		/*cout << "after char is : " << inputs[idx_i] << '\n';*/
		sizes[0].first -= 1;
		//for (int j = i + 1; j < sizes.size(); j++) {
		//	if (size_i == sizes[j].first) {
		//		int size_j = sizes[j].first;
		//		int idx_j = sizes[j].second;
		//		sum_x[size_j] += inputs[idx_j][0];
		//		nums.push_back(inputs[idx_j][0]);
		//		cout << "erase char is : " << inputs[idx_i][0] << '\n';
		//		inputs[idx_j].erase(0, 1);
		//		cout << "after char is : " << inputs[idx_i] << '\n';
		//		sizes[j].first -= 1;
		//	}
		//}

		
		K--;
		for (int k = 0; k < inputs.size(); k++) {
			string erase_num = inputs[k];
			for (int h = 0; h < erase_num.size(); h++) {
				if (erase_char == erase_num[h]) {
					//k��° string�� h��° ���ڸ� erase�Ѵ�.
					/*inputs[k].erase(h, 1);
					erase_num[h] = 'Z';*/
					erase_num.erase(h, 1);
				}
			}
			inputs[k] = erase_num;
		}
		/*for (int j = 0; j < sizes.size(); j++) {
			cout << inputs[sizes[j].second] << '\n';
		}*/
		if (K == 0) {
			break;
		}
		
	}
	for (int k = 0; k < erases.size(); k++) {
		char erase_char = erases[k];
		for (int i = 0; i < original.size(); i++) {
			for (int j = 0; j < original[i].size(); j++) {
				if (erase_char == original[i][j]) {
					original[i][j] = 'Z';
				}
			}
		}
	}
	
	sort(original.begin(), original.end(), compare2);
	/*for (int i = 0; i < original.size(); i++) {
		cout << original[i] << '\n';
	}*/
	string add = original[0];
	for (int i = 0; i < original.size()-1; i++) {
		add = add_36(add, original[i + 1]);

	}
	cout << add << '\n';
	






	return 0;
}