#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int main() {
	int N, answer = 0;
	cin >> N;

	int cnt1 = 0;	int cnt2 = 0; int cnt3 = 0;
	for (int i = 1 ; i <= N; ++i)
	{
		if (i % 10 == 0) cnt3++;
		else if (i % 5 == 0) cnt2++;
		else if (i % 2 == 0) cnt1++;

		cout << cnt1 << ", " << cnt2 << ", " << cnt3 << '\n';
	}
	answer = min(cnt1, cnt2);
	answer += cnt3;

	cout << answer << '\n';
	


	
	return 0;
	/*

	//test2

	0�� ������ ���ϸ�Ǵ�
		n������ ������(2�ǹ��, 5�ǹ��) ¦�� ������ 0�� �Ѱ� ����
		10�ǹ���� ���α��ϱ�

		5 : 2, 4 / 5 > = 1
		10: 2, 4, 6, 8 / 5 / 10 > = 2
		15: 2, 4, 6, 8, , / 5, , 15 / 10 = 3
		20 : samesame / 5, , 15 / 10, 20 = 4


		//test4

		ordered_quests = quests.sorted(key = lambda x : �ͽù�)

		def �ͽù�(quests) :
		if quests[0][0] == quests[1][0]
			return quests[0][1] > quests[1][1]
			return quests[0][0] == quests[1][1]


			�ƴϸ� ������ķ� �����غ���, �� ������


			//test3
			answer = []

			for a in len(price) :
				for b in len(price) if b > a:
	if price[a] < price[b] :
		answer.append(price[b] - price[a])
		break; (���� ���������� ���� �� �˻�)
		if b == len(price)
			answer.append(-1)


*/

}