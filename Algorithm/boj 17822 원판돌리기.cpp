#include <iostream>
#include <queue>
#define FIO std::ios_base::sync_with_stdio(false), std::cin.tie(NULL);
#define FOR(i, n) for(int i = 0 ; i < n ; ++i)
#define MAX 51
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
int n, m, t, cir[MAX][MAX], xi, di, ki, state[MAX], sum[MAX], ans;

int check_di(int dir) {
	if (di == 1)	return (dir + 1) % 4;
	else			return (dir + 3) % 4;
}

void print(int map[][MAX]) {
	for (int x = 1; x <= n; x++) {
		for (int y = 0; y < m; y++)
			std::cout << map[x][y] << " ";
		std::cout << '\n';
	}std::cout << "\n\n";
}
int main() {
	FIO;

	std::cin >> n >> m >> t;
	for (int x = 1; x <= n; x++) for (int y = 0; y < m; y++)
		std::cin >> cir[x][y], sum[x] += cir[x][y];

	while (t--) {
		std::cin >> xi >> di >> ki;

		// xi �� ����
		int tmp_cir[MAX][MAX] = { 0, };
		for (int i = xi; i <= n; i += xi) {

			int adj = false;

			// di ����, ki �� �ݺ�
			if (di == 0)	state[xi] = (1 * ki) % m;
			else			state[xi] = (3 * ki) % m;

			// �����ϸ鼭 ���� ���� ����
			for (int num = 0; num < m; ++num) {
				int tx, ty = (num + state[xi]) % m;

				// ������ ��ȣ �˻�
				for (int a = 0; a < 4; ++a) {
					int nx = xi + dx[a];
					int ny = (ty + dy[a]) % m;

					if (nx < 1 || nx > n || cir[nx][ny] < -1e6) continue;
					if (cir[nx][ny] != cir[xi][ty]) continue;

					adj = true;
					tmp_cir[nx][ny] = tmp_cir[xi][ty] = 1e8 /*-cir[tx][ty];*/;
				}
			}

			// ������ ���� �� �� ������
			if (adj) continue;

			// ��պ��� ū�� - 1, ������ + 1
			for (int y = 0; y < m; y++) {
				if (cir[xi][(y + state[xi]) % m] > sum[xi] / m)
					sum[xi]--, cir[xi][(y + state[xi]) % m] -= 1;
				else	sum[xi]++, cir[xi][(y + state[xi]) % m] += 1;
			}

			print(tmp_cir);

		}
		// �����ϸ鼭 ���� �� �����
		for (int x = 1; x <= n; x++) for (int y = 0; y < m; y++)
			cir[x][y] -= tmp_cir[x][y];
	}

	// ��� ������ �� ���ϱ�
	for (int x = 1; x <= n; x++) for (int y = 0; y < m; y++)
		if (cir[x][y] > -1e6) ans += cir[x][y];

	print(cir);

	std::cout << ans << '\n';
	return 0;
}