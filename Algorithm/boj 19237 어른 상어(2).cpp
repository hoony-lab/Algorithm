#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <memory.h>
#include <map>
#define F(i, n) for(int i = 0 ; i < n ; ++i)
using namespace std;
// 1 2 3 4 >> 0 1 2 3
struct SHARK { int x, y, d, dir[4][4]; };
map<int, SHARK> shark;

struct SMAP { int shark_num, smell_time; };
SMAP smell_map[21][21];

int dx[] = {-1, 1, 0, 0};
int dy[] = { 0,0,-1,1 };
int n, m, smell, d, time;

// 1 2 3 .. >> 0 1 2 ..
//int shark_dir[401][4][4];

vector<int> shark_map[21][21], new_shark_map[21][21];

bool is_only_one_shark = false;

bool check(int x, int y) {
	return !(x < 0 || y < 0 || x >= n || y >= n);
}
void print(vector<int> map[][21]) {
	F(x, n) {
		F(y, n) {
			if(shark_map[x][y].size() && shark_map[x][y].front() >= 0) cout << shark_map[x][y].front() << " ";
			else cout << "x ";
		}cout << '\n';
	}cout << "\n\n";
}
void print(SMAP map[][21]) {
	F(x, n) {
		F(y, n) {
			if (map[x][y].smell_time) cout << map[x][y].shark_num << "," << map[x][y].smell_time << "\t";
			else cout << "x\t";
		}cout << '\n';
	}cout << "\n\n";
}
void move() {
	F(x, n) F(y, n) new_shark_map[x][y].clear();

	// ������� ��� �̵�
	for (pair<int, SHARK> sh : shark) {
		SHARK s = sh.second;
		int i = sh.first, tx = s.x, ty = s.y, td = s.d, nd, nx, ny;
		bool has_way_without_smell = false;

		//cout << "shark : " << i << ": " << tx << ", " << ty << ", " << td;

		// check 4 way first: ��ĭ 
		F(a, 4) {
			nd = s.dir[td][a], nx = tx + dx[nd], ny = ty + dy[nd];
			if (!check(nx, ny) || smell_map[nx][ny].smell_time) continue;

			// 0. �ʿ� ���ο� ��� �ڸ� ǥ��
			new_shark_map[nx][ny].push_back(i);
			shark[i].x = nx, shark[i].y = ny, shark[i].d = nd;
			//cout << " move to : " << nx << ", " << ny << " (empty)\n";
			has_way_without_smell = true;
			break;
		}

		// check 4 way first: ����ĭ �߿��� �ڱⰡ ��������
		if (!has_way_without_smell) {

			F(a, 4) {
				nd = s.dir[td][a], nx = tx + dx[nd], ny = ty + dy[nd];
				if (!check(nx, ny) || smell_map[nx][ny].smell_time == 0) continue;

				if (smell_map[nx][ny].shark_num == i) {
					new_shark_map[nx][ny].push_back(i);
					shark[i].x = nx, shark[i].y = ny, shark[i].d = nd;
					//cout << " move to : " << nx << ", " << ny << " (smell)\n";
					break;
				}
			}
			
		}
	}

	// ���� ���� ��� ���� 1�� ����, ������ 0 �̸� ����ȣ/���� ���� ����
	F(x, n) F(y, n) {
		if (smell_map[x][y].smell_time)			smell_map[x][y].smell_time--;
		if (smell_map[x][y].smell_time == 0)	smell_map[x][y].shark_num = 0;
	}

	// ��ġ�� ���� ���� ����
	F(x, n) F(y, n) if (new_shark_map[x][y].size() > 1) {
		sort(new_shark_map[x][y].begin(), new_shark_map[x][y].end());
		int lowest_shark_num = new_shark_map[x][y].front();

		// ��ġ�� ���� ��ȣ ��� ����
		F(i, (int)new_shark_map[x][y].size()) {
			if (!i) {
				//cout << "lowest : " << i;
				continue;
			}
			//cout << ", " << i;
			shark.erase(new_shark_map[x][y][i]);
		}
		//cout << '\n';
		new_shark_map[x][y].clear();
		new_shark_map[x][y].push_back(lowest_shark_num);
	}

	// 1. �����ʿ� ����ȣ/���� ǥ��
	for (pair<int, SHARK> sh : shark)
		smell_map[sh.second.x][sh.second.y] = { sh.first, smell };
	
	if (shark.size() == 1) is_only_one_shark = true;

	F(x, n) F(y, n) shark_map[x][y] = new_shark_map[x][y];
	//memcpy(shark_map, new_shark_map, sizeof(shark_map));
	//print(shark_map);
	//print(smell_map);
}

void init() {
	cin >> n >> m >> smell;
	F(x, n) F(y, n) {
		cin >> d, d--;
		shark_map[x][y].push_back(d);

		if (d >= 0) {
			shark[d] = { x, y };
			smell_map[x][y] = {d, smell};
		}
		
	}
	F(a, m) {
		cin >> d, d--;
		shark[a].d = d;
	}
	F(i, m) F(a, 4) F(b, 4) {
		cin >> d, d--;

		// i��° ����� a ������ �켱���� 4����
		shark[i].dir[a][b] = d;
	}
}

int main() {
	
	init();
	//print(shark_map);
	//print(smell_map);

	while (!is_only_one_shark) {
		if (time++ >= 1000) {
			cout << -1;
			return 0;
		}
		//cout << "time : " << time << '\n';
		move();
	}

	cout << time;
	return 0;
}