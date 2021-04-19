#include <iostream>
#include <queue>
using namespace std;
#define F(i,n) for(int i = 0 ; i < n ; ++i)
int n, k, a, belt[1001], robot[1001], result, zero_durability_cnt;


void rotate() {
	for (int i = n * 2 - 1; i > 0; --i) swap(belt[i], belt[i - 1]);
}
void init() {
	cin >> n >> k; F(i, n * 2) cin >> belt[i];
}
void solve() {
	// ��Ʈ�� �� ĭ ȸ���Ѵ�.
	rotate();
	// ���� ���� ��Ʈ�� �ö� �κ�����, ��Ʈ�� ȸ���ϴ� �������� �� ĭ �̵��� �� �ִٸ� �̵��Ѵ�. ���� �̵��� �� ���ٸ� ������ �ִ´�.
	for (int i = n * 2 - 1; i >= 0; --i)
		if (robot[i] && belt[i]) {
			swap(robot[i], robot[(i + 1) % (n * 2)]);
			belt[i]--;
		}

	// �ö󰡴� ��ġ�� �κ��� ���ٸ� �κ��� �ϳ� �ø���.
	if (!robot[0] && belt[0]) {
		robot[0] = true;
		belt[0]--;
	}

	if (robot[n] && belt[0]) {
		robot[n] = false;
		belt[n]--;
	}

}
int main() {

	init();
	while (1) {
		solve();

		// �������� 0�� ĭ�� ������ K�� �̻��̶�� ������ �����Ѵ�. �׷��� �ʴٸ� 1������ ���ư���.
		zero_durability_cnt = 0;
		F(i, 2 * n) if (!belt[i]) zero_durability_cnt++;
		if (zero_durability_cnt >= k) {
			cout << result;
			return 0;
		}
	}
}

/*
3 2
1 2 1
2 1 2

1.
2 1 2
1 2 1

2.
3.
1 1 2	1 0 0
1 2 1	0 0 0


1.
1 1 1
2 1 2

2.
0 1 1	0 1 0
2 1 2	0 0 0

3.


1.
2 0 1
1 2 1

2.
3.



1.
1 2 0
2 1 1

2.

*/