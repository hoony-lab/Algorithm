#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define F(i, n) for(int i = 0 ; i < n ; ++i)
#define MAX 22

struct PASSENGER { int px, py, pxx, pyy, passenger_dest, passenger_taxi; };
struct P { int x, y; };

int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int n, m, fuel, taxi_x, taxi_y, px, py, pxx, pyy, map[MAX][MAX], ans, done[MAX * MAX], done_cnt;

vector<PASSENGER> v;

bool check(int x, int y) {
	return !(x < 0 || y < 0 || x >= n || y >= n);
}

// �°� - ������, �ý� �Ÿ�
int cal_passenger_dest_taxi_dist() {

	F(i, (int)v.size()) {
		//if (done[i]) continue;

		int x = v[i].px, y = v[i].py;
		int visit[MAX][MAX]{};

		queue<P> q;
		q.push({ x, y });
		visit[x][y] = 1;
		// �ϴ� ������ �ɷ� ����
		v[i].passenger_taxi = -1;
		v[i].passenger_dest = -1;

		while (!q.empty()) {
			int tx = q.front().x, ty = q.front().y;
			q.pop();

			// �ý� ���� �� �Ÿ� ����
			// �ýÿ� �°��� ���� ��ġ�� �� ������ �� �°������� �ִܰŸ��� 0
			if (tx == taxi_x && ty == taxi_y) 
				v[i].passenger_taxi = visit[tx][ty] - 1;

			// ������ ���� �� �Ÿ� ����
 			if (tx == v[i].pxx && ty == v[i].pyy)
				v[i].passenger_dest = visit[tx][ty] - 1;

			F(a, 4) {
				int nx = tx + dx[a], ny = ty + dy[a];
				if (!check(nx, ny) || visit[nx][ny] || map[nx][ny]) continue;
				
				q.push({ nx, ny });
				visit[nx][ny] = visit[tx][ty] + 1;
			}
		}
		// �ýð� �°����� �����ų� || �°��� ���������� ������
		if (v[i].passenger_taxi == -1 || v[i].passenger_dest == -1) {
			return 0;
		}

		//cout << x << ", " << y << " : " << v[i].passenger_taxi << ", " << v[i].passenger_dest << '\n';
	}
	return 1;
}

/// �ý� - �°��� �Ÿ�
// ���� ��ġ���� �ִܰŸ��� ���� ª�� �°���
// ���� �� ��ȣ�� ���� ���� �°���
// ���� �� ��ȣ�� ���� ���� �°���
int min_taxi_passenger_dist_idx() {
	int min_passenger_taxi_dist = MAX * MAX;
	int min_passenger_taxi_idx = MAX * MAX;

	F(i, (int)v.size()) {
		//if (done[i]) continue;

		if (min_passenger_taxi_dist > v[i].passenger_taxi) {
			min_passenger_taxi_dist = v[i].passenger_taxi;
			min_passenger_taxi_idx = i;
		}
		else if (min_passenger_taxi_dist == v[i].passenger_taxi) {
			if (v[min_passenger_taxi_idx].px == v[i].px) {
				if (v[min_passenger_taxi_idx].py > v[i].py) {
					min_passenger_taxi_dist = v[i].passenger_taxi;
					min_passenger_taxi_idx = i;
				}
			}
			else if (v[min_passenger_taxi_idx].px > v[i].px) {
				min_passenger_taxi_dist = v[i].passenger_taxi;
				min_passenger_taxi_idx = i;
			}
		}

	}

	if (v[min_passenger_taxi_idx].passenger_dest + v[min_passenger_taxi_idx].passenger_taxi > fuel)
		return MAX * MAX;
	else {
		done_cnt++;
		taxi_x = v[min_passenger_taxi_idx].pxx;
		taxi_y = v[min_passenger_taxi_idx].pyy;

		//done[min_passenger_taxi_idx] = true;
		
		//cout << "pick : " << min_passenger_taxi_idx << '\n';

		return min_passenger_taxi_idx;
	}
}

// �Է�
void init() {
	cin >> n >> m >> fuel;
	F(x, n) F(y, n) cin >> map[x][y];
	cin >> taxi_x >> taxi_y; taxi_x--, taxi_y--;
	F(i, m) {
		cin >> px >> py >> pxx >> pyy;
		v.push_back({ px - 1, py - 1, pxx - 1, pyy - 1 });
	}
}

int main() {

	init();

	F(i, m) {
		
		//cout << "done_cnt : " << done_cnt << " : start : " << taxi_x << ", " << taxi_y << " / " << fuel << '\n';

		if (!cal_passenger_dest_taxi_dist()) {
			cout << -1;
			return 0;
		}

		int idx = min_taxi_passenger_dist_idx();

		// ���� ���Ẹ�� �Ÿ��� �ָ�
		if (idx == MAX * MAX) {
			cout << -1;
			return 0;
		}

		// ����� �� ĭ �̵��� ������ 1��ŭ �Ҹ�
		// �� �°��� �������� ���������� �̵� >> �������� �Ҹ��� ���� ���� �� �谡 ����
		fuel = fuel - v[idx].passenger_taxi + v[idx].passenger_dest;
		v.erase(v.begin() + idx);
	}
	
	cout << fuel;

	return 0;
}
/*
6 3 100
0 0 1 0 0 0
0 0 1 0 0 0
0 0 0 1 0 0
0 0 0 1 0 0
0 0 0 0 1 0
0 0 0 1 0 0
1 2
2 2 2 2
3 2 3 2
4 2 4 2

>> 97

6 4 100
0 0 1 0 0 0
0 0 1 0 0 0
0 0 0 1 0 0
0 0 0 1 0 0
0 0 0 0 1 0
0 0 0 1 0 0
6 5
2 2 5 6
5 4 1 6
3 6 1 1
4 6 1 6

>> -1

6 4 15
0 0 1 0 0 0
0 0 1 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 1 0
0 0 0 1 0 0
6 5
2 2 5 6
5 4 1 6
4 2 3 5
1 6 5 4

>> 20

6 3 10
0 0 1 0 0 0
0 0 1 0 0 0
0 0 0 1 0 0
0 0 0 0 0 0
0 0 0 0 1 0
0 0 0 1 0 0
6 5
5 6 4 6
4 6 2 2
2 2 1 1

>> 17

6 3 17
0 0 1 0 0 0
0 0 1 0 0 0
0 0 0 1 0 0
0 0 0 1 0 0
0 0 0 0 1 0
0 0 0 1 0 0
6 5
5 6 4 6
2 2 1 1
4 6 1 3

>> -1

// �Ÿ��� ������ ���� ����
6 2 17
0 0 1 0 0 0
0 0 1 0 0 0
0 0 0 1 0 0
0 0 0 0 0 0
0 0 0 0 1 0
0 0 0 0 0 0
6 6
5 4 6 1
4 5 3 3

>> 18

// �Ÿ��� ���� ���� ������ ���� ����
6 3 17
0 0 1 0 0 0
0 0 1 0 0 0
0 0 0 1 0 0
0 0 0 0 0 0
0 0 0 0 1 0
0 0 0 0 0 0
6 5
4 4 6 1
4 6 3 6
5 3 1 1

>> 15
*/