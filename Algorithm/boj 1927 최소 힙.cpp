#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int t, n; cin >> t;
	priority_queue<int, vector<int>, greater<int> > pq;
	/* 
	https://en.cppreference.com/w/cpp/container/priority_queue

	std::priority_queue<int> q;
	const auto data = {1,8,5,6,3,4,0,9,7,2};

	for(int n : data) q.push(n);

	print_queue(q);
	9 8 7 6 5 4 3 2 1 0
	>> default of pq's compare is "less" (�ּ���, ���� ū�� ����)


	std::priority_queue<int, std::vector<int>, std::greater<int>>
		q2(data.begin(), data.end());

	print_queue(q2);
	0 1 2 3 4 5 6 7 8 9
	*/
	
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