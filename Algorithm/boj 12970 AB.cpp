#include <iostream>
#include <vector>
#define MIN(a, b) a < b ? a : b
using namespace std;

//���ڿ� S�� ���̴� N�̰�, 'A', 'B'�� �̷���� �ִ�.
//���ڿ� S���� 0 �� i < j < N �̸鼭
// s[i] == 'A' && s[j] == 'B'�� �����ϴ�(i, j) ���� K���� �ִ�.
int main() {
	int n, k;
	cin >> n >> k;

	// a + b == n , a * b >= k
	for (int a = 0; a <= n; a++) {
		int b = n - a;

		if (a * b < k) continue;

		vector<int> va(b + 1);
		for (int i = 0; i < a; i++) {
			int after = MIN(b, k);

			va[after] += 1;
			k -= after;
		}

		for (int i = b; i >= 0; i--) {
			for (int j = 0; j < va[i]; j++)
				cout << 'A';
			if (i > 0)
				cout << 'B';
		}
		return 0;
	}
	cout << -1;
	return 0;
}
