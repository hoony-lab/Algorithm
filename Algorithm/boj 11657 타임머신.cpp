#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>

using namespace std;
/*

A ���۵���
B ��������
C ���� �̵� �ð� (��������)

*/
#define MAX_EDGE 501

int N, M;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	vector<pair<int, int>> v[MAX_EDGE];

	int from, to, time;
	for (int i = 0; i < M; i++) {
		cin >> from >> to >> time;
		v[from].push_back({ to, time });
	}

	int min_time[501];
	for (int i = 1; i < N; i++)	min_time[i] = 1e9;

	//�����������

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < v[j].size(); k++)
			{
				int new_time = v[j] + v[j][k].second;
				int past_time = v[];

				if () return;
				v [[]] = new_time;
			}
		}
	}
}