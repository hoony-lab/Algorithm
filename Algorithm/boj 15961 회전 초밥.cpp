#include <iostream>
#include <set>
#define FIO std::ios_base::sync_with_stdio(false), std::cin.tie(NULL);
#define FOR(i, n) for(int i = 0 ; i < n ; ++i)
int n, d, k, coupon, sushi_belt[3000001], ans;
std::set<int> sushi;
/*
���ӵ� �ʹ��̸� ����
�ʹ��� ������ ���� ����
- ��� �ѹ� �����ϸ� �ʹ� �ϳ� ����
- ���� ��� �ʹ��� ������, ���� ���� ����
*/
void print() {
	for (auto a : sushi)
		std::cout << a << ", ";
	std::cout << '\n';
}
int main() {
	FIO;
	std::cin >> n >> d >> k >> coupon;
	FOR(i, n) std::cin >> sushi_belt[i];

	// sushi start num
	FOR(num, n) {

		sushi.clear();

		FOR(i, k) {
			int s = (num + i) % d;
			sushi.emplace(sushi_belt[s]);
		} 

		//std::cout << "ENTER at : " << num << '\n';
		//print();

		if (ans <= sushi.size()) {
			ans = sushi.size();
			if (!sushi.count(coupon)) ans++;
			if (ans == k + 1) break;
		}
	}
	std::cout << ans;

	return 0;
}
/*
8 50 4 7
2
7
9
7
9
7
30
7

*/