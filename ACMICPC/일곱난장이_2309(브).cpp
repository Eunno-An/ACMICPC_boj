
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

int alphabet[26];
int temp_alphabet[26];
int N, K;
vector<string> inputs;
vector<int> count_idx;
vector<pair<int, int>> learn_counts;
vector<string> sorted_string;
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
	cin >> N >> K;
	string input;
	for (int i = 0; i < N; i++) {
		cin >> input; //ó������ index�� 4 �̻� input.size()-4 ������ a, n, t, c, i�� �������ϴ�.
		input.erase(remove(input.begin() + 4, input.end() - 4, 'a'), input.end() - 4);
		input.erase(remove(input.begin() + 4, input.end() - 4, 'n'), input.end() - 4);
		input.erase(remove(input.begin() + 4, input.end() - 4, 't'), input.end() - 4);
		input.erase(remove(input.begin() + 4, input.end() - 4, 'c'), input.end() - 4);
		input.erase(remove(input.begin() + 4, input.end() - 4, 'i'), input.end() - 4);
		//cout << input << '\n';
		inputs.push_back(input);
	}

	alphabet[(int)'a' - 97] = 1;
	alphabet[(int)'n' - 97] = 1;
	alphabet[(int)'t' - 97] = 1;
	alphabet[(int)'i' - 97] = 1;
	alphabet[(int)'c' - 97] = 1;

	int result = 0;
	int count = K - 5;
	for (int i = 0; i < inputs.size(); i++) {//�� �࿡�� ���� ����� �� ���ڰ� K-5�� �������� �������ν� ��� �� �ִ� �������� �Ǻ��մϴ�.
		int learn_count = 0;
		for (int j = 0; j < 26; j++) {
			temp_alphabet[j] = 0;
		}
		string temp = inputs[i];
		for (int j = 4; j < temp.size() - 4; j++) {
			
			if (temp_alphabet[(int)temp[j] - 97] == 0 && alphabet[(int)temp[j] - 97] == 0) { // a, n, t, c, i�� �� �ְų�, �̹� �ѹ� ��� ���ڸ�, ����ٰ� ǥ���մϴ�.
				temp_alphabet[(int)temp[j] - 97] = 1;
				learn_count++;//����� �� count�� ������ŵ�ϴ�.
			}

		}
		if (learn_count <= count) {
			pair<int, int> input_pair;
			input_pair.first = learn_count;
			input_pair.second = i;
			learn_counts.push_back(input_pair);
		}
	}
	cout << learn_counts.size() << '\n';
	for (int i = 0; i < learn_counts.size(); i++) {//O(N)
		sort(learn_counts.begin()+i, learn_counts.end());//�Ź� �ٽ� sort�� �������μ� ���� �ּҺ������ ���� �ִ� ���ڰ� �������� Ȯ���մϴ�.
		sorted_string.clear()
		for (int j = 0; j < learn_counts.size(); j++) {
			int idx = learn_counts[j].second;
			sorted_string.push_back(inputs[idx]);
		}
		int learn_count = learn_counts[i].first;
		int learn_idx = learn_counts[i].second;
		
		
		string learn_string = inputs[learn_idx];
		//cout << "The string we will learn is :" << learn_string << '\n';
		count -= learn_count;
		if (count < 0) {
			break;
		}
		//cout << "Check the alphabet in 4 < j < learn_string.size()-4" << '\n';
		for (int j = 4; j < learn_string.size() - 4; j++) {
			if (alphabet[(int)learn_string[j] - 97] == 0) {
				alphabet[(int)learn_string[j] - 97] = 1;//� ���ڸ� ���� ���ϴ�. �׷��� �ٸ� �ܾ�鿡�� �� ���ڰ� �ִ��� Ȯ�� �մϴ�.
				//cout << "The alphabet " << learn_string[j] << "is new alphabet we will learn\n";
				for (int k = i + 1; k < learn_counts.size(); k++) {//O(N)
					int next_learn_count = learn_counts[k].first;
					int next_learn_idx = learn_counts[k].second;
					string next_string = inputs[next_learn_idx];
					//cout << "next_string we will check is " << next_string << '\n';
					//cout << "We should check another string has : " << learn_string[j] << '\n';
					for (int l = 4; l < next_string.size() - 4; l++) {
						if (next_string[l] == learn_string[j]) {
							//cout << "We find same character between next_string and learn_string\n";
							if (next_learn_count > 0) {
								//cout << "If next_learn_count is over zero, we down the learn_counts[k].first\n";
								learn_counts[k].first -= 1;
								inputs[next_learn_idx].erase(std::remove(inputs[next_learn_idx].begin(), inputs[next_learn_idx].end(), next_string[l]), inputs[next_learn_idx].end());
								//cout << inputs[next_learn_idx] << '\n';
								break;
							}
						}
					}
				}
			}
		}
		
		result += 1;
	}
	cout << result << '\n';


	return 0;
}