#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <climits>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <sstream>
#include <deque>
#include <stack>
#include <map>
#include <memory>
#include <set>


using namespace std;

/*
백준 대회 ID
579_013
ZgdxHXStpraTGmCT

- endl 대신 '\n' 사용하기
- cin.tie(0) 사용
- 테스트 케이스 있는 문제일 시 전역변수 초기화 신경쓰기
- (A + B + C) % D = ((A + B) % D + C) % D
- 문자열 출력 문제는 정답 문자열 복사해서 코드에 넣기
- 괄호 사용 유의하기
- 문자열은 함수로 넘길 때 const & 잘 사용하기

- 최악의 경우 int 값 초과하는지, 배열 인덱스 초과하는지 확인
- n 범위 확인 (0인 경우), 양수음수 정수소수 확인, 불가케이스 -1 출력 등 확인
- 큰 배열 선언 시 전역선언, 테케 많을 시 초기화, 배열 용량 max N + 5
*/

#define MOD 1000000007
#define INT_MAX 987654321
#define MAX 100005

typedef long long int ll;
typedef pair<int, int> pii;


class album;
album* albums[100005];
int ptr = 0;

// 테스트 케이스 초기화 시
void init()
{

}

class photo
{

};

class album
{
	string _name;
	album* mother;
	map<string, album*> dir;
	vector<string> ls;
	set<string> photos;
	vector<string> photols;
	album* this_ptr;

public:

	album(string name) : _name(name), mother(nullptr) {
		this_ptr = this;
	}
	album(string name, album* mother) : _name(name), mother(mother) {
		this_ptr = this;
	}

	bool mk(string nm) {
		if (dir.find(nm) == dir.end()) {
			dir[nm] = c(nm, this_ptr);
			ls.push_back(nm);
			sort(ls.begin(), ls.end());
			return true;
		}
		return false;
	}

	// (album, photo)
	pair<int, int> rm(string nm) {
		auto r = lower_bound(ls.begin(), ls.end(), nm);
		if (ls.size() == 0 || ls.end() == r || *r != nm)
			return pair<int, int>(0, 0);
		auto x = pair<int, int>(dir[*r]->salbum() + 1, dir[*r]->sphoto());
		ls.erase(r);
		dir.erase(nm);
		return x;
	}

	pair<int, int> rm(int op) {
		if (op < 0) {
			return rm(ls.front());
		}
		else if (op > 0) {
			return rm(ls.back());
		}
		else {
			auto r = pair<int, int>(salbum(), sphoto() - photos.size());
			dir.clear();
			ls.clear();
			return r;
		}
	}

	bool insert(string photo) {
		if (photos.find(photo) == photos.end()) {
			photos.insert(photo);
			photols.push_back(photo);
			sort(photols.begin(), photols.end());
			return true;
		}
		return false;
	}

	int _delete(string photo) {
		if (photos.find(photo) == photos.end())
			return 0;
		photos.erase(photo);
		photols.erase(lower_bound(photols.begin(), photols.end(), photo));
		return 1;
	}

	int _delete(int op) {
		if (op < 0) {
			_delete(photols.front());
		}
		else if (op > 0) {
			_delete(photols.back());
		}
		else {
			int i = photos.size();
			photos.clear();
			photols.clear();
			return i;
		}
	}

	const string& name() const {
		return _name;
	}

	album* ca(string album) {
		if (album == "..")
		{
			if (mother == nullptr)
				return this;
			return mother;
		}
		auto r = lower_bound(ls.begin(), ls.end(), album);
		if (ls.size() == 0 || ls.end() == r || *r != album)
			return this_ptr;
		return dir[*r];
	}

private:
	album* c(string name, album* mother) {
		return albums[ptr++] = new album(name, mother);
	}

	int salbum() const {
		int ss = 0;
		for (auto& s : dir) {
			ss += s.second->salbum();
			ss += 1;
		}
		return ss;
	}

	int sphoto() const {
		int ss = 0;
		for (auto& s : dir) {
			ss += s.second->sphoto();
		}
		return ss + photos.size();
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	auto top = albums[ptr++] = new album("album");
	auto top_ptr = top;

	auto cur = top_ptr;

	for (int i = 0; i < n; i++) {
		string command, param;
		cin >> command >> param;

		if (command == "mkalb")
		{
			if (!cur->mk(param))
				cout << "duplicated album name\n";
		}
		else if (command == "ca")
		{
			if (param == "/")
				cur = top_ptr;
			else
				cur = cur->ca(param);
			cout << cur->name() << '\n';
		}
		else if (command == "insert")
		{
			if (!cur->insert(param))
				cout << "duplicated photo name\n";
		}
		else if (command == "delete")
		{
			if (!param.empty() && param.find_first_not_of("-0123456789") == std::string::npos)
				cout << cur->_delete(stoi(param.c_str())) << '\n';
			else
				cout << cur->_delete(param) << '\n';
		}
		else if (command == "rmalb")
		{
			pair<int, int> result;
			if (!param.empty() && param.find_first_not_of("-0123456789") == std::string::npos)
				result = cur->rm(stoi(param.c_str()));
			else
				result = cur->rm(param);
			cout << result.first << ' ' << result.second << '\n';
		}
	}

	/*while (ptr >= 0)
	delete albums[--ptr];*/

	return 0;
}
