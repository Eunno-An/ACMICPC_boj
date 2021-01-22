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


class album;
album* albums[100005];
int ptr = 0;

// �׽�Ʈ ���̽� �ʱ�ȭ ��
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
