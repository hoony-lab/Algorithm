#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int t, n; cin >> t;
	priority_queue<int> pq;

	while (t--) {
		cin >> n;
		// x�� 0�̶�� �迭���� ���� ���� ���� ����ϰ� �� ���� �迭���� ����
		if (!n) {
			// ���� �迭�� ��� �ִ� ����ε� ���� ���� ���� ����϶�� �� ��쿡�� 0�� ���
			if (pq.empty()) {
				cout << "0\n";
			}
			else {
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		// x�� �ڿ������ �迭�� x��� ���� �ִ�(�߰��ϴ�) ����
		else {
			pq.push(n);
		}
	}
	return 0;
}