#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <map>
#define F(i, n) for(int i = 0 ; i < n ; ++i)
struct P { int x,y,d; };
using namespace std;
int dx[] = { 0,0,-1,0,1 };
int dy[] = { 0,1,0,-1,0 };
int w, h, n;
long long ans;
map<int, P> kunai;
vector<vector<int>> m, visit;
void print(vector<vector<int>> m) {
	F(x, h) { F(y, w) { cout << m[x][y] << " "; } cout << '\n'; }cout << '\n';
}
bool check(int x, int y) {
	return !(x < 0 || y < 0 || x >= h || y >= w);
}

int main() {
	cin >> w >> h >> n;
	vector<vector<int>> tm(h, vector<int>(w, 0)), tv(h, vector<int>(w, 0));
	m = tm, visit = tv;
	
	F(i, n) {
		int x, y, d;
		cin >> x >> y >> d;
		
		// �ʿ� ���� ��� ��ġ�� ���̹�ȣ
		m[y - 1][x - 1] = i + 1;
		// ���̹�ȣ�� �ش��ϴ� map
		kunai[i + 1] = { y - 1, x - 1, d + 1 };
		// ��ĥ�� ���簢��, �ٷ� ī��Ʈ
		visit[y - 1][x - 1] = i + 1, ans++;
	}

	// ����� �ð�
	while (1) {
		cout << "\t===TIME===\n";
		print(m);
		print(visit);
		map<int, P> tkunai = kunai;

		for(pair<int, P> ku : tkunai) {
			int tx = ku.second.x, ty = ku.second.y, td = ku.second.d, ti = ku.first;
			int nx = tx + dx[td], ny = ty + dy[td];

			// �� ��
			if (!check(nx, ny)) {
				kunai.erase(ti);
				continue;
			}
			// �� ��: 0
			if()

			// �� �� : ���ֺ���





			cout << "\tstart : " << tx << ", " << ty << ", " << td << '\n';
			// ������ ���̸� �о�
			if (td == 0) continue;
			
			int nx = tx + dx[td], ny = ty + dy[td], ni = m[nx][ny];
			cout << "\t\tgo : " << nx << ", " << ny << ", " << '\n';
			// ���ڸ��� ���� ������ �о�

			if (!check(nx, ny)) continue;
			cout << "\t\t\tgo : " << nx << ", " << ny << ", " << '\n';

			bool gonna_meet = false;
			F(a, 5) if(a) {
				// ���� ������ ������ : �Ѵ� �Ҹ�
				if (td == a && kunai[ni].d == (td + 2 - 1) % 4 + 1) {
					cout << "\t\t\tmeet : " << a << ", " << kunai[ni].d << '\n';
					kunai[i + 1].d = 0;
					//kunai[ni].d = 0;
					m[tx][ty] = 0, m[nx][ny] = 0;
					visit[nx][ny] += i + 1, ans++;
					
					gonna_meet = true;
				}
			}

			if (!gonna_meet) {
				// ���� ������ �ٸ���
				kunai[i + 1] = { nx, ny, td };
				m[tx][ty] = 0, m[nx][ny] = i + 1;

				// ù �湮
				if (!visit[nx][ny]) {
					visit[nx][ny] += i + 1, ans++;
				}
			}
			
		}
	}

	cout << ans;
	return 0;
}