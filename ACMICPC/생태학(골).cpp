#include<iostream>
#include<string>
#include<map>
#include<algorithm>
#include<iomanip>
using namespace std;
int main() {
	map<string, int> trees;
	int size = 0;
	string input="";
	while (getline(cin, input)) { // 1,000,000
		trees[input]++;
		size++;
	}
	map<string, int>::iterator iter;
	for (iter = trees.begin(); iter != trees.end(); iter++) {
		cout << iter->first << ' ' << setprecision(4) << fixed  << (double)iter->second/size * 100<<  '\n';
	}
}