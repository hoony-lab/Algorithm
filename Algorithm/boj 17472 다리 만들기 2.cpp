#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define F(i, n) for(int i = 0 ; i < n ; ++i)
#define MAX 101
struct P { int x, y; };

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };
int n, m, num, map[MAX][MAX], ans, visit[MAX][MAX];
vector<vector<int>> v;

bool check(int x, int y) {
	return !(x < 0 || y < 0 || x >= n || y >= m);
}

void bfs(int x, int y, int num) {
	queue<P> q;
	q.push({ x, y }); visit[x][y] = num;
	
	while (!q.empty()) {
		int tx = q.front().x, ty = q.front().y;
		F(a, 4) {
			int nx = tx + dx[a], ny = ty + dy[a];

			if (!check(nx, ny) || visit[nx][ny]) continue;
			q.push({ nx, ny }); visit[nx][ny] = num;
		}
	}
}

// A ������ B ���� Len
void len_bridge(int x, int y, int num, int way) {
	int len = 1;
	x += dx[way],y += dy[way];

	while (check(x, y)) {
		if (map[x][y]) {
			if (len > 2) {
				v[num][map[x][y]] = min(v[num][map[x][y]], len);
			}
			return;
		}

		len++;
		x += dx[way], y += dy[way];
	}
}

int main() {
	std::cin >> n >> m;
	F(x, n) F(y, n) std::cin >> map[x][y];
	
	// ���� ������ bfs();
	F(x, n) F(y, n) if (map[x][y] || visit[x][y])
			bfs(x, y, ++num);
	
	F(x, n) F(y, n) 
		map[x][y] = visit[x][y];

	memset(visit, 0, sizeof(visit));



	// �ٸ� �����غ���
	F(x, n) F(y, n) {
		if (!map[x][y]) continue;

		// ����ĭ�� �ٴ��϶�
		F(a, 4) {
			int nx = x + dx[a], ny = y + dy[a];
			if (!check(nx,ny) || map[nx][ny]) continue;
				len_bridge(nx, ny, map[nx][ny], a);
		}
	}

	// ��� �� �����ϱ�
	F(x, n) F(y, n) {

	}

	std::cout << ans;
	return 0;
}