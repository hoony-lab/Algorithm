/*
20201011 1307

*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define F(i, n) for(int i = 0 ; i < n ;++i)
#define MAX 21
// �� �Ʒ� �� ��
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int visit[MAX][MAX], map[MAX][MAX], smell[MAX][MAX], ss[MAX * MAX];
int _way, t[5];
int n, m, k, ans;
struct P { int x, y; };
struct SHARK { int idx, x, y, way, iway; vector<int> w[4]; };
vector<SHARK> shark, move_shark;

bool check(int x, int y) {
	return !(x < 0 || y < 0 || x >= n || y >= n);
}
void bfs(int x, int y) {
	queue<P> q;
	q.push({x, y});
	visit[x][y] = true;
	while (!q.empty()) {
		int tx = q.front().x, ty = q.front().y;
		q.pop();

		F(a, 4) {
			int nx = tx + dx[a], ny = ty + dy[a];
			if (!check(nx, ny)) continue;
			q.push({ nx, ny });
			visit[nx][ny] = visit[tx][ty] + 1;
		}

	}
}

bool cmp(SHARK s1, SHARK s2) {
	int x1 = s1.x, y1 = s1.y, x2 = s2.x, y2 = s2.y;

	// �Ѵ� ��ĭ || �Ѵ� ����ĭ
	if ((map[x1][y1] == 0 && map[x2][y2] == 0) || map[x1][y1] != 0 && map[x2][y2] != 0)
		return s1.iway < s2.iway;

	//  ���� �ϳ� ��ĭ
	if (map[x1][y1] == 0 || map[x2][y2] == 0)
		return map[x1][y1] == 0;
}

void tic_toc() {
	F(x, n) F(y, n) if (smell[x][y]) smell[x][y]--, map[x][y] = 0;
}

void init() {
	cin >> n >> m >> k;
	shark.resize(m);
	F(x, n) F(y, n) {
		cin >> map[x][y];
		if (map[x][y]) {
			smell[x][y] = k;
			shark[map[x][y] - 1].x = x, shark[map[x][y] - 1].y = y;
			shark[map[x][y] - 1].idx = map[x][y] - 1;
		}
	}
	F(i, m) cin >> shark[i].way, shark[i].way--;	// ���� ��� ����
	F(i, m) {			// ��� ��ȣ
		F(a, 4) {		// ���� ��ȣ
			F(aa, 4) {	// �� ����
				cin >> t[aa];
				shark[i].w[aa].push_back(t[aa] - 1);
			}
		}
	}
}
int main() {
	init();

	//do {
	//	tik_toc();
	//} while (1);
	do {
		// �ð� �߰�
		if (++ans > 1000) {
			cout << -1;
			return 0;
		}
		int ssize = (int)shark.size();
		cout << "SHARK_SIZE : " << ssize << '\n';

		F(i, ssize) {
			bool done = false;
			int iway = 0;
			int tx = shark[i].x, ty = shark[i].y, tway = shark[i].way;

			vector<SHARK> possible_shark(1);

			for (int nway : shark[i].w[tway]) {
				int nx = tx + dx[nway], ny = ty + dx[nway];

				if (!check(nx, ny) || (map[nx][ny] != 0  && map[nx][ny] != i)) continue;

				// �� ĭ, Ž�� ���� (�ֿ켱 ����)
				if (map[nx][ny] == 0) {
					possible_shark.push_back({ nx, ny, tway, iway});
					break;
				}

				// �ڱ� ���� ĭ, ��� Ž�� (����å)
				if (map[nx][ny] == i) {
					possible_shark.push_back({ i, nx, ny, tway, iway });
				}

				iway++;
			}

			// ���� ���� �� �ֿ켱 ���� ���
			sort(possible_shark.begin(), possible_shark.end(), cmp);


				// �̹� �ٸ��� ������ �ڸ��� ����
				if (smell[nx][ny] == k + 1) break;
				
				done = true;
				shark[i].x = nx, shark[i].y = ny, shark[i].way = way;
				smell[nx][ny] = k + 1;
				map[nx][ny] = i;
				break;
			// �ٸ�ĭ�� �̵� ��������
			if (!done)
				shark.erase(shark.begin() + i);
		}

		// ��ü ���� ����
		tic_toc();

	} while (shark.size() > 1);

	cout << ans;
	return 0;
}
/*
5 4 4
0 0 0 0 3
0 2 0 0 0
1 0 0 0 4
0 0 0 0 0
0 0 0 0 0

4 4 3 1

2 3 1 4
4 1 2 3
3 4 2 1
4 3 1 2

2 4 3 1
2 1 3 4
3 4 1 2
4 1 2 3

4 3 2 1
1 4 3 2
1 3 2 4
3 2 1 4

3 4 1 2
3 2 4 1
1 4 2 3
1 4 2 3
*/