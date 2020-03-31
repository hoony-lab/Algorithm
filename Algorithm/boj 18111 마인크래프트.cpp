#include <iostream>
#include <vector>
#define ll long long

ll map[501][501];

int main() {
	int n, m, inventory, max_height = 0, min_height = 1e11;
	int answer = 1e11, answer_height = 0;

	std::cin >> n >> m >> inventory;

	for (int x = 0; x < n; ++x) {
		for (int y = 0; y < m; ++y) {
			std::cin >> map[x][y];

			if (map[x][y] > max_height) max_height = map[x][y];
			if (map[x][y] < min_height) min_height = map[x][y];
		}
	}

	for (int h = max_height; h >= min_height; --h) {
		int temp_remove = 0;
		int temp_add = 0;

		for (int x = 0; x < n; ++x) {
			for (int y = 0; y < m; ++y) {
				int temp = h - map[x][y];

				if (temp > 0)		temp_add += temp;
				else if(temp < 0)	temp_remove += temp * (-1);
			}
		}
		
		if (temp_add <= inventory + temp_remove) {
			int temp_time = temp_add + temp_remove * 2;

			if (answer > temp_time) {
				answer = temp_time;
				answer_height = h;
			}
			if (answer == temp_time)
				if (answer_height < h)
					answer_height = h;
		}
	}
	std::cout << answer << " " << answer_height;
	return 0;
}
/*
2�� ��� ����, �κ��丮 �ֱ�
1�� �κ��丮 ������, ��� ����

#include<iostream>
using namespace std;

int n, m, b, a[257], result = 1e9, hei, i, j, ret, bb;

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	for (cin >> n >> m >> b; i < n*m; i++) {
		cin >> j;
		a[j]++;
	}
	for (i = 256; ~i; i--) {
		ret = 0; bb = b;
		for (j = 256; j > i; j--) {
			ret += a[j] * (j - i) * 2;
			bb += a[j] * (j - i);
		}
		for (j = i - 1; ~j; j--) {
			ret += a[j] * (i - j);
			bb -= a[j] * (i - j);
		}
		if (bb < 0)continue;
		if (result > ret) {
			result = ret;
			hei = i;
		}
	}
	cout << result << ' ' << hei;
}
https://skyde47.tistory.com/62

*/