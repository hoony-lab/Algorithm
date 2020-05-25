// 20200525 2311 2425
#include <iostream>
#include <vector>
#include <deque>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define F(i, n) for(int i = 0 ; i < n ; ++i)
#define FR(i, n, m) for(int i = m ; i >= n ; --i)
#define MAX 13
struct P { int x, y, w, upside_down; };
using vP = vector<P>;
using di = deque<int>;
int dx[] = { 0,0, -1, 1 }, dy[] = { 1,-1,0,0 };


vP v;
di chess[MAX][MAX];
int map[MAX][MAX];
int n, k, ans;

void move(int x, int y, int nx, int ny) {
	
}

bool check_bottom(int i, int x, int y, int ud) {
	if (ud) {
		if (chess[x][y].front() != i)	return false;
	}
	else {
		if (chess[x][y].back() == i)	return false;
	}
	return true;
}
bool check(int x, int y) {
	return !(x < 0 || y < 0 || x >= n || y >= n);
}

bool is_end() {
	F(i, k) if (chess[v.front().x][v.front().y].size() != k) return false;
	return true;
}

int main() {
	FIO;

	// init();
	// 0 white, 1 red, 2 blue
	cin >> n >> k; 
	F(x, n) F(y, n) cin >> map[x][y];
	F(i, k) {
		int x, y, w;	cin >> x >> y >> w;
		v.push_back({ x - 1, y - 1, w - 1, 0 });
		chess[x - 1][y - 1].push_back(i);
	}

	while (++ans) {
		if (ans > 1000) {
			cout << -1;
			return 0;
		}

		int vsize = (int)v.size();
		F(i, vsize) {
			int x = v[i].x, y = v[i].y, w = v[i].w, ud = v[i].upside_down;
			int nx = x + dx[w], ny = y + dy[w], nw = w & 1 ? w - 1 : w + 1;

			// �� �ؿ� �ִ� ü���� �ƴϸ� ��������
			if (!check_bottom(i, x, y, ud)) continue;

			// ������ �Ѿ�� �Ķ���
			if (!check(nx, ny) || map[nx][ny] == 2) {

				// �ݴ�� ���µ� ������ �Ѿ�ų� �Ķ���
				// 00 01 10 11
				// w = w & 1 ? w - 1 : w + 1;
				int nnx = nx + dx[nw], nny = ny + dy[nw];

				if (!check(nnx, nny) || map[nnx][nny] == 2) {
					v[i].w = nw;
				}
				else {
					v[i].x = nnx, v[i].y = nny;
				}
			}
			else if (map[nx][ny] == 1) {
				// �ϳ����� žó�� �̾Ҵٰ� �� �̱�
				di tmp;
				if (ud) {
					F(k, i) {
						tmp.push_front(chess[x][y].front());
						chess[x][y].pop_front();
					}
					chess[nx][ny].push_back(tmp.front());
					tmp.pop_front();
				}
				else {
					FR(k, i, vsize - 1) {
						tmp.push_back(chess[x][y].back());
						chess[x][y].pop_back();
					}
					chess[nx][ny].push_back(tmp.back());
					tmp.pop_back();
				}
				v[i].upside_down = ~ud;
			}

			if (is_end) {
				cout << ans;
				return 0;
			}
		}
	}

	return 0;
}