#include <iostream>
#define F(i, n) for(int i = 0 ; i < n ; ++i)
#define MAX 101
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };
int n, m, map[MAX][MAX], ans;

int main() {
	std::cin >> n >> m;
	F(x, n) F(y, n) std::cin >> map[x][y];
	
	// ���� ������
	// bfs();


	// �ٸ� �����غ���
	// bfs();

	std::cout << ans;
	return 0;
}