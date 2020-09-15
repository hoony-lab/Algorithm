#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 100001
#define SUCCESS cout << "King-God-Emperor"
#define FAIL cout << "Lier!"

// �Է��� ù �ٿ��� �ǹ� ������ ���� N
// �ǹ� ���� ������ ���� M
// ������ ���� ������ ���� K
int n, m, k, ans;
int construct[MAX], condition[MAX];
vector<int> vec[MAX], vec2[MAX];

// 1 a(���찡 a�� �ǹ��� 1�� �Ǽ���)
// 2 a(������ a�� �ǹ��� 1�� �ı���)

int find_condition(int v) {
	for (int building : vec[v])
		if (!construct[building]) return 0;
	return 1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> m >> k;

	int u, v;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		vec[u].push_back(v);	// >>
		vec2[v].push_back(u);	// <<
	}

	for (int i = 0; i < k; i++) {
		cin >> u >> v;

		// construct
		if (u == 1) {
			// �Ǽ��� �� ���� �ǹ��� �Ǽ��ϰų�
			//if (!find_condition(v)) {
			if (condition[v] != vec2[v].size()) {
				FAIL;
				return 0;
			}
			else {
				construct[v]++;
				for (int building : vec[v])
					condition[building]++;
			}
		}
		// destroy
		else if (u == 2) {
			// �Ǽ����� ���� �ǹ��� �ı��Ǿ��ٸ�
			if (!construct[v]) {
				FAIL;
				return 0;
			}
			else {
				construct[v]--;
				for (int building : vec[v])
					condition[building]--;
			}
		}

	}
	SUCCESS;
	return 0;
}