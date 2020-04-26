//https://programmers.co.kr/learn/courses/30/lessons/42894
#include <iostream>
#include <vector>
#include <cstring>
#include <set>

#define F(i, n) for(int i = 0 ; i < n ; ++i)
#define BLOCKMAX 201
using namespace std;

// �� J L �� ��
// start from the top, left to right
int blockx[5][4] = {
	{0, 1, 1, 1},
	{0, 1, 2, 2},
	{0, 1, 2, 2},
	{0, 1, 1, 1},
	{0, 1, 1, 1} };
int blocky[5][4] = {
	{0, 0, 1, 2},
	{0, 0, 0, -1},
	{0, 0, 0, 1},
	{0, -2, -1, 0},
	{0, -1, 0, 1} };

int n, answer;
vector<vector<int>> map;
vector<pair<int, int>> block[BLOCKMAX];
set<int> block_num;

void print_map() {
	F(x, n) {
		F(y, n) {
			cout << map[x][y] << " ";
		}cout << "\n";
	}cout << "\n\n";
}
void print_block() {
	for (int num : block_num) {
		cout << num << "\t<\t";
		for (auto pos : block[num]) {
			cout << pos.first << ", " << pos.second << "  ||  ";
		}
		cout << '\n';
	}cout << "\n\n";
}


bool check(int x, int y) {
	return !(x < 0 || y < 0 || x >= n || y >= n);
}

void erase_block(int num) {
	for (auto pos : block[num]) map[pos.first][pos.second] = 0;
	block_num.erase(num); answer++;
}

bool is_block_opened(int num) {
	int x = block[num][0].first;
	int y = block[num][0].second;

	for (auto pos : block[num]) {
		int nx = pos.first, ny = pos.second;

		while (check(nx, ny)) {
			if (map[nx][ny] == 0 || map[nx][ny] == map[x][y]) {
				nx--; continue;
			}
			return false;
		}
	}
	return true;
}

void check_shape(int x, int y) {

	F(a, 5) {
		bool fail = false;
		F(b, 4) {
			int nx = x + blockx[a][b];
			int ny = y + blocky[a][b];

			if (!check(nx, ny) || map[x][y] != map[nx][ny])
				fail = true;
		}
		if (!fail) {
			// if its possible shape
			block_num.insert(map[x][y]);
			F(b, 4)
				block[map[x][y]].push_back(
					make_pair(x + blockx[a][b], y + blocky[a][b]));
			
			//std::cout << " shape : " << x << " , " << y << " :: " << a << '\n';
			return;
		}
	}
	return;
}

void solve() {
	
	print_block();

	bool flag;
	do {
		flag = false;
		for (int num : block_num) {
			if (!is_block_opened(num)) continue;

			erase_block(num);

			print_map();

			flag = true;
			break;
		}
	} while (flag);

	print_block();
}


int solution(vector<vector<int>> board) {
	map = board;
	n = board.size();
	answer = 0;

	F(x, n) F(y, n) {
		if (!map[x][y] || block_num.count(map[x][y])) continue;
		check_shape(x, y);
	}

	solve();

	return answer;
}






int main() {

	vector<vector<int>> board = {
		{11, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{11, 11, 11, 10, 10, 10, 0, 0, 0, 0},
		{0, 0, 12, 0, 0, 10, 0, 0, 0, 0},
		{0, 0, 12, 0, 0, 0, 0, 0, 0, 0},
		{7, 12, 12, 9, 0, 0, 4, 0, 0, 8},
		{7, 7, 7, 9, 0, 4, 4, 0, 8, 8},
		{0, 0, 9, 9, 3, 0, 4, 0, 0, 8},
		{0, 0, 0, 2, 3, 0, 0, 0, 5, 5},
		{1, 2, 2, 2, 3, 3, 0, 0, 0, 5},
		{1, 1, 1, 0, 0, 0, 0, 0, 0, 5}
	};
	cout << solution(board);	// 2

	return 0;
}