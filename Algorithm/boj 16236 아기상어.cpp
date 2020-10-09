#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>
using namespace std;
#define F(i,n) for(int i=0;i<n;++i)
#define MAX 21
struct FISH { int x, y, dist; };
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1};

// ���� ó���� �Ʊ� ����� ũ��� 2
int baby_size = 2, feed, yy, xx, ans;
int n, map[MAX][MAX], visit[MAX][MAX];
vector<FISH> v;
bool check(int x, int y) {
	return !(x < 0 || y < 0 || x >= n || y >= n);
}
bool comp(FISH f1, FISH f2) {
	if (f1.dist < f2.dist)
		return true;

	if (f1.dist == f2.dist) {
		if (f1.x == f2.x) {
			return f1.y < f2.y;
		}
		return f1.x < f2.x;
	}
	return false;
}

void eat_fish() {
	// ���� �� �ִ� ����Ⱑ 1�������� ���ٸ�, �Ÿ��� ���� ����� ����⸦ ������ ����.
	//	�Ÿ��� �Ʊ� �� �ִ� ĭ���� ����Ⱑ �ִ� ĭ���� �̵��� ��, �������ϴ� ĭ�� ������ �ּڰ��̴�.
	//	�Ÿ��� ����� ����Ⱑ ���ٸ�, ���� ���� �ִ� �����, �׷��� ����Ⱑ �����������, ���� ���ʿ� �ִ� ����⸦ �Դ´�.
	sort(v.begin(), v.end(), comp);
	// ������ ���� ǥ��
	map[v.front().x][v.front().y] = 0;
	// �������� �ɸ� �ð�
	ans += v.front().dist;
	// �Ʊ� �� ���� �� �ִ� ����Ⱑ �ִ� ĭ���� �̵�
	xx = v.front().x, yy = v.front().y;

	//cout << "ERASE_FISH : " << v.front().x << ", " << v.front().y << " : " << v.front().dist << " , ANS : " << ans << '\n';
	// ����⸦ ������, �� ĭ�� �� ĭ�� �ȴ�.
	v.erase(v.begin());

	// �Ʊ� ���� �ڽ��� ũ��� ���� ���� ����⸦ ���� �� ���� ũ�Ⱑ 1 ����
	if (++feed == baby_size) {
		baby_size++;
		//cout << "SIZE UP SIZE UP SIZE UP: " << baby_size << '\n';
		// ����ġ �ʱ�ȭ
		feed = 0;
	}
}

void baby_to_fish_dist() {
	v.clear();

	int visit[MAX][MAX]{};
	queue<FISH> q;
	q.push({ xx, yy, 1 });
	visit[xx][yy] = 1;

	int find_first_fish_dist = MAX * MAX;
	while (!q.empty()) {
		int tx = q.front().x, ty = q.front().y, tdist = q.front().dist;
		q.pop();
		//if (find_first_fish_dist > tdist) continue;
		//cout << "search : " << tx << ", " << ty << " / " << tdist << '\n';
		F(a, 4) {
			int nx = tx + dx[a], ny = ty + dy[a];
		
			if (!check(nx, ny) || baby_size < map[nx][ny] || visit[nx][ny] || find_first_fish_dist < visit[tx][ty]) continue;

			q.push({ nx, ny, visit[tx][ty] });
			visit[nx][ny] = visit[tx][ty] + 1;

			//cout << "!!PUSH!! : " << nx << ", " << ny << '\n';

			// �Ÿ��� ���������
			if (map[nx][ny] != 0 && baby_size > map[nx][ny]) {
				v.push_back({ nx, ny, visit[nx][ny] - 1 });
				find_first_fish_dist = visit[nx][ny] - 1;
			} 
		}
	}
}

int main() {
	cin >> n;
	F(x, n) F(y, n) {
		cin >> map[x][y];
		if (map[x][y] && map[x][y] != 9) v.push_back({ x,y, -1 });
		if (map[x][y] == 9) xx = x, yy = y, map[x][y] = 0;
	}

	while(1){
		baby_to_fish_dist();

		if (v.empty()) break;
		//cout << "SAME_FISH_CNT : " << v.size() << " / FISH_DIST : " <<  v.front().dist << '\n';
		//for (FISH f : v)cout << f.x << ", " << f.y << " : " << f.dist << '\n';
		
		eat_fish();
	}

	cout << ans;
	return 0;
}
/*
6
5 4 3 2 3 4
4 3 2 3 4 5
3 2 9 5 6 6
2 0 0 3 4 5
3 2 0 6 5 4
6 6 6 6 6 6

>> 60
*/