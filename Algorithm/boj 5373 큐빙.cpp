// https://www.acmicpc.net/problem/5373
// 20200605 1736
#include <iostream>
#include <vector>
#include <string>

#define FIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
#define F(i, n) for(int i = 0 ; i < n ; ++i)

/*
����� w, ������� y, �������� r, ���������� o, �ʷϻ��� g, �Ķ����� b.
*/

/*
U: �� ��, D: �Ʒ� ��, F: �� ��, B: �� ��, L: ���� ��, R: ������ ���̴�.
+�� ��쿡�� �ð� ���� (�� ���� �ٶ���� ���� ����),
-�� ��쿡�� �ݽð� �����̴�.
*/
enum AA{
	U,
	D,
	F,
	B,
	L,
	R
};
int t, n;
std::string tmp;
std::vector<std::string> rotate;
char cube[3][3];
int main() {
	
	std::cin >> t;
	while (t--) {

		rotate.clear();
		
		std::cin >> n;
		F(i, n) std::cin >> tmp, rotate.push_back(tmp);


	}

	// U�� ���� ��� (3x3)
	std::cout << 
	return 0;
}