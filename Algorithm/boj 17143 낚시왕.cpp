/*
20201011 1900
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define F(i, n) for(int i = 0 ; i < n ; ++i)
#define MAX 101
// x, y ��� ��ġ / s �ӷ� / d �̵� ���� / z ũ��
struct SHARK { int x, y, s, d, z, idx; };
vector<SHARK> shark;
// �� �Ʒ� ���� ��
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };
int xxx, yyy, m, rr, cc, ss, dd, zz, king = -1;
vector<int> map[MAX][MAX];

// ĭ�� �������� ��踦 �Ѵ� ��쿡�� ������ �ݴ�� �ٲ㼭 �ӷ��� ������ä�� �̵��Ѵ�.
bool check(int x, int y) {
	return !(x < 0 || y < 0 || x >= xxx || y >= yyy);
}
// ���ÿ��� ���� ������ ���� ������ ĭ�� �̵��ϸ� �̵��� �����.

// ���ÿ��� ���������� �� ĭ �̵��Ѵ�.
// ���ÿ��� �ִ� ���� �ִ� ��� �߿��� ���� ���� ����� �� ��´�.�� ������ �����ǿ��� ���� �� �������.
// �� �̵��Ѵ�.

void init() {
	cin >> xxx >> yyy >> m;
	shark.resize(m);
	F(i, m) {
		cin >> rr >> cc >> ss >> dd >> zz;
		shark.push_back({ rr - 1, cc - 1, ss, dd - 1, zz });
		map[rr - 1][cc - 1].push_back(i + 1);				// i ��° �ε��� >> i + 1�� ǥ��
	}
}

void move_king() {
	king++;
}

void find_catch_shark () {
	int x = 0, idx;
	while (check(x, king)) {
		if (map[x][king].front()) break;
		else x++;
	}

	// �� ã���� �� �ƹ��͵� ����
	if (!check(x, king)) return;

	// ������ �� � ��� ��ȣ���� Ž��
	F(i, (int)shark.size()) {
		if (shark[i].x == x && shark[i].y == king) {
			idx = i; break;
		}
	}

	map[shark[idx].x][shark[idx].y].clear();
	shark.erase(shark.begin() + idx);
}

void move_shark() {

}

bool cmp(int a, int b) {
	return shark[shark[a].idx].s > shark[shark[b].idx].s;
}

void eat_shark() {
	// ?
	F(x, xxx) F(y, yyy) {
		if (map[x][y].size() > 1) {

			sort(map[x][y].begin(), map[x][y].end(), cmp);
			 v
			int max_shark_idx = map[x][y].front();
			map[x][y].clear();
			map[x][y].push_back(max_shark_idx);
		}
	}

	
}

int main() {
	init();

	F(i, yyy) {
		move_king();
		find_catch_shark();
		move_shark();
		eat_shark();
	}
	return 0;
}