#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//1. update가 구간으로 주어진다. -> Lazy Propagation?

class Event {
public:
	int x1, y1, y2, state;
};
int N;
vector<Event> vector_event;
vector<pair<int, int>> seg_tree;

bool operator<(const Event& p1, const Event& p2) {
	return p1.x1 < p2.x1;
}

void init_tree(int start, int end, int nodeNum) {
	if (start == end) {
		seg_tree[nodeNum].first = 0;
		seg_tree[nodeNum].second = 0;
		return;
	}
	int mid = (start + end) / 2;
	init_tree(start, mid, nodeNum * 2);
	init_tree(mid + 1, end, nodeNum * 2 + 1);
}
void update(int start, int end, int nodeNum, int nodeL, int nodeR, int value) {
		
		if (end < nodeL || nodeR < start) {
			return ;
		}
		if (nodeL <= start && end <= nodeR) {
			seg_tree[nodeNum].second += value;
		}
		else {
			int mid = (start + end) / 2;
			update(start, mid, nodeNum * 2, nodeL, nodeR, value);
			update(mid + 1, end, nodeNum * 2 + 1, nodeL, nodeR, value);
		}
		if (seg_tree[nodeNum].second) {
			seg_tree[nodeNum].first = end - start + 1;
		}
		else {
			if (start == end) seg_tree[nodeNum].first = 0;
			else seg_tree[nodeNum].first = seg_tree[nodeNum * 2].first + seg_tree[nodeNum * 2 + 1].first;
		}

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	seg_tree.resize(120000);
	cin >> N;
	int x1, x2, y1, y2;
	for (int i = 0; i < N; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		Event tempEvent_start = Event();
		Event tempEvent_end = Event();
		//y좌표 하나가 나타내는 것이 y~ y+1의 구간을 나타내는 것이므로 -1해주어야 함.
		tempEvent_start.x1 = x1; tempEvent_start.y1 = y1; tempEvent_start.y2 = y2-1; tempEvent_start.state = 1;
		tempEvent_end.x1 = x2; tempEvent_end.y1 = y1; tempEvent_end.y2 = y2-1; tempEvent_end.state = -1;
		vector_event.push_back(tempEvent_start);
		vector_event.push_back(tempEvent_end);
	}
	sort(vector_event.begin(), vector_event.end());
	init_tree(0, 30000, 1);

	int result = 0;
	int last = 0;
	for (int i = 0; i < vector_event.size(); i++) {
		
		if (i) {
			int dx = vector_event[i].x1 - last;
			result += dx * seg_tree[1].first;
			/*cout << "dx is : " << dx << '\n';
			cout << "seg_tree[1].first is : " << seg_tree[1].first << '\n';
			cout << "result is : " << result << '\n';*/
		}
		update(0, 30000, 1, vector_event[i].y1, vector_event[i].y2, vector_event[i].state);
		last = vector_event[i].x1;
		
		
	}
	cout << result << '\n';
	
	return 0;
}