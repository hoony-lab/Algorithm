#include <list>
#include <iostream>
#include <vector>
#include <string>
#include <memory.h>
#include <algorithm>
using namespace std;

long long answer;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	answer = 0;

	int n, k, strlen;
	string str;
	vector<int> vv[21];
	list<int> l;
	cin >> n >> k;

	for (int i = 0; i < n; ++i) {
		cin >> str;
		//strlen = str.length() - 1;
		//vv[strlen].push_back(i);

		l.push_back(strlen);


	}

	//sort(v.begin(), v.end(), [](pair<string, int> v1, pair<string, int> v2) {
	//	if (v1.first.size() == v2.first.size())
	//		return v1.second < v2.second;
	//	return v1.first.size() < v2.first.size();
	//});

	for (int i = 0; i < 21; ++i) {
		if (vv[i].size() < 2) continue;

		int ind = 0;
		while (ind < vv[i].size() - 1) {

			for (int j = ind+1; j < vv[i].size(); ++j) {

				//if (abs(v[i].second - v[j].second > k)) break;
				//if (v[i].first.size() != v[j].first.size()) break;
				if (vv[i][j] - vv[i][ind] > k) break;
				//if (vv[i][.size() == vv[j].size())
					answer++;
			}
			ind++;
		}
	}
	cout << answer << '\n';

	return 0;
}






/*

#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

vector<int> q[25];
char str[21];

int main()
{
	int n, k;
	long long int cnt = 0;
	long long int tmp = 0;
	int charlen;

	scanf("%d %d", &n, &k);

	// �̸��� �Է� �޾��� �� �̸� ���̿� �ش��ϴ�
	// q ���Ϳ� �̸��� �ƴ� �� �̸��� ���� ������ �־��ش�.
	for (int i = 0; i < n; i++)
	{
		scanf("%s", str);

		charlen = strlen(str);
		q[charlen].push_back(i);
	}

	for (int i = 2; i <= 20; i++)
	{
		int idxlen = q[i].size();
		int left = 0, right = 0;

		// ť�� ����ִ� ��� ���� ť�� ����.
		if (!idxlen)
			continue;

		// left�� idxlen(�ش��ϴ� ť�� ũ��)�� ������ �� ����
		while(left < idxlen - 1)
		{
			// right�� ���� �������� �ʾҰ�, ���� ģ���� �ش� �� ��
			if (right < idxlen - 1 && q[i][right] - q[i][left] <= k)
			{
					// right�� ��ĭ �Ű��ְ� tmp++
					right++;
					tmp++;

					// right�� ��ĭ �Ű��� �� q[][right] - q[][left] == k�� ��
					if (q[i][right] - q[i][left] == k)
					{

						// ��Ƶ� tmp�� �����ְ� left�� ��ĭ �ű�⿡ tmp�� �ϳ� ���ش�.
						cnt += tmp;
						tmp--;
						left++;
					}
			}

			// �׿� ���
			else
			{
				// q[][right] - q[][left] <= k �϶��� �����ش�.
				if (q[i][right] - q[i][left] <= k)
					cnt += tmp;

				// �װ� �ƴ϶�� tmp -1�� �� ���� �����ش�.
				else
					cnt += tmp - 1;

				tmp--;
				left++;
			}
		}

		// �ش��ϴ� ť�� ������ tmp = 0���� �ʱ�ȭ
		tmp = 0;
	}

	printf("%lld", cnt);

	return 0;
}


��ó: https://www.crocus.co.kr/601 [Crocus]

*/





/*

#include <iostream>
#include <deque>
#include <string>
using namespace std;
int N, K;
int table[21];
long counter = 0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	deque<int> ds;
	
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		int len = s.length();

		if (ds.size() > K) {
			table[ds.front()]--;
			ds.pop_front();
		}
		if (!ds.empty())
		{
			counter += table[len];
		}
		ds.push_back(len);
		table[len]++;

	}
	cout << counter;
}

*/