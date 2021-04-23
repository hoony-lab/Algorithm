#include <iostream>
#include <string>
#include <queue>
#include <map>
#define pii pair<int,int>
using namespace std;
map<int, int> m;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int t, n; cin >> t;
	priority_queue<pii, vector<pii>, greater<pii>> pq;

	while (t--) {
		cin >> n;

		// x�� 0�̶�� �迭���� ������ ���� ���� ���� ����ϰ� �� ���� �迭���� �����ϴ� ���
		if (!n) {
			// ���� �迭�� ��� �ִ� ����ε� ���� ���� ���� ����϶�� �� ��쿡�� 0�� ���
			if (pq.empty()) {
				cout << "\t0\n";
			}
			else {
				cout << "\t" <<  pq.top().second << '\n';
				pq.pop();
			}
		}
		// x�� �ڿ������ �迭�� x��� ���� �ִ�(�߰��ϴ�) ����
		else {
			pq.push({abs(n), n });
		}
	}
	return 0;
}