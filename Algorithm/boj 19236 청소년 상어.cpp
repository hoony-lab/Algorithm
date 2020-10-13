#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define F(i, n, m) for(int i = m ; i < n ; ++i)
#define MAX 5
struct FISH { int x, y, way, idx; };
int dx[] = {-1,-1,0,-1,-1,-1,0,1};
int dy[] = {0,-1,-1,-1,0,1,1,1};
int ans, sum;
int map[MAX][MAX], dead_fish[MAX * MAX];
FISH fish[MAX * MAX];
FISH shark;

bool check(int x, int y) {
	return !(x < 0 || y < 0 || x >= 4 || y >= 4);
}
void print() {
	F(x, 4, 0) {
		F(y, 4, 0) {
			cout << map[x][y] << ' ';
		}cout << '\n';
	}cout << '\n';
}
void init() {
	F(i, 16, 0) {
		int idx, way;
		cin >> idx >> way;
		fish[i] = { i / 4, i % 4, way - 1, idx - 1 };
		map[i / 4][i % 4] = idx - 1;
	}
}

// û�ҳ� ���� (0, 0)�� �ִ� ����⸦ �԰�, (0, 0)�� ���� �ȴ�.
// ����� ������ (0, 0)�� �ִ� ������� ����� ����. ���� ����Ⱑ �̵��Ѵ�.
void eat_fish(int x, int y, int nx, int ny) {
	shark = { nx, ny, fish[map[nx][ny]].way };
	dead_fish[map[nx][ny]] = true;
	//ans += map[nx][ny];
	map[nx][ny] = -1;
}
void revive_fish(int x, int y, int nx, int ny, int way, int idx) {
	map[nx][ny] = idx;
	//ans -= map[nx][ny];
	dead_fish[map[nx][ny]] = false;
	shark = { x, y, way };
}
void move_fish() {
	F(i, 16, 0) {
		if (dead_fish[i]) continue;
		int tx = fish[i].x, ty = fish[i].y, tway = fish[i].way, tidx = fish[i].idx;
		
		// �̵��� �� �ִ� ĭ�� ���� ������ ������ 45�� �ݽð� ȸ��
		F(a, 8, 0) {
			int nway = (tway + a) % 8;
			int nx = tx + dx[nway], ny = ty + dx[nway];

			//  �̵��� �� ���� ĭ�� �� �ְų�, ������ ��踦 �Ѵ� ĭ�̴�
			if(!check(nx, ny) || (shark.x == nx && shark.y == ny)) continue;
			
			// ����Ⱑ �ٸ� ����Ⱑ �ִ� ĭ���� �̵��� ���� ������ ��ġ�� �ٲٴ� ������� �̵�
			int nidx = map[nx][ny];
			fish[tidx] = fish[nidx];
			fish[nidx] = { tidx, nway, tx, ty};
			break;
		}
	}
}

void dfs(int sum) {
	
	ans = max(ans, sum);

	int x = shark.x, y = shark.y, way = shark.way;

	// �ִ� 3ĭ���� �̵� ����
	bool done = false;
	F(a, 4, 1) {
		int nx = x + dx[way] * a, ny = y + dy[way] * a;
		if (!check(nx, ny)) break;

		// �̹� ������
		if (map[nx][ny] < 0) continue;
		done = true;
		int nway = fish[map[nx][ny]].way, nidx = map[nx][ny];

		// ???
		move_fish();

		// eat_fish(x, y, nx, ny);

		dfs(sum + nidx);

		// revive_fish(x, y, nx, ny, nway, nidx);

		//map[nx][ny] = nidx;
		//ans -= map[nx][ny];
		//dead_fish[map[nx][ny]] = false;
		//shark = { x, y, way };
	}
	
	// �� �� ���� ���� ???
}

int main() {

	init();
	int tmp = fish[map[0][0]].idx;
	eat_fish(0, 0, 0, 0);

	dfs(tmp);

	cout << ans;
	return 0;
}