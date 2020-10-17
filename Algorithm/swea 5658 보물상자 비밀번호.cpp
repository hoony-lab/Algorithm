// 20201017 1730 - 1813
#include<iostream>
#include <string>
//#include <stdio.h>
#include <cstdio>
#include <memory.h>
#include <vector>
#include <algorithm>
#include <set>
#define MAX 7
#define F(i, n) for(int i = 0 ;i < n ; ++i)
#pragma warning (disable : 4996)
#define ll long long
using namespace std;
enum NUM { A = 10, B, C, D, E, F };
int n, k, ans;
string s;
set<string, greater<>> st;
vector<string> v;
string hex_to_dec(string str) {
	ll ret = 0;
	int idx = 0;
	for (int i = str.size() - 1; i >= 0; --i) {

		if ('0' <= str[i] && str[i] <= '9') {
			ll tmp = str[i] - '0';
			ret += (pow(16, idx) * tmp);
		}
		else {
			ll tmp = str[i] - 'A' + 10;
			ret += (pow(16, idx) * tmp);
		}
		idx++;
	}
	return to_string(ret);
}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	/*
   �Ʒ��� freopen �Լ��� input.txt �� read only �������� �� ��,
   ������ ǥ�� �Է�(Ű����) ��� input.txt ���Ϸκ��� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
   //�������� �ۼ��� �ڵ带 �׽�Ʈ �� ��, ���Ǹ� ���ؼ� input.txt�� �Է��� ������ ��,
   freopen �Լ��� �̿��ϸ� ���� cin �� ������ �� ǥ�� �Է� ��� ���Ϸκ��� �Է��� �޾ƿ� �� �ֽ��ϴ�.
   ���� �׽�Ʈ�� ������ ������ �Ʒ� �ּ��� ����� �� �Լ��� ����ϼŵ� �����ϴ�.
   freopen �Լ��� ����ϱ� ���ؼ��� #include <cstdio>, Ȥ�� #include <stdio.h> �� �ʿ��մϴ�.
   ��, ä���� ���� �ڵ带 �����Ͻ� ������ �ݵ�� freopen �Լ��� ����ų� �ּ� ó�� �ϼž� �մϴ�.
*/
	freopen("input.txt", "r", stdin);
	cin >> T;
	/*
	   ���� ���� �׽�Ʈ ���̽��� �־����Ƿ�, ������ ó���մϴ�.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		st.clear();
		v.clear();
		ans = 0;

		cin >> n >> k >> s;

		//  ���ڿ� ��� ����� �ڹ���
		int ssize = (int)s.size();
		int lock_len = ssize / 4;
		F(i, lock_len) {
			// ��ĭ �̵�
			string str = s.substr(ssize - i) + s.substr(0, ssize - i);
			// ��� ���ڿ� ����
			F(a, 4) {
				st.insert(str.substr(a * lock_len, lock_len));
				v.push_back(str.substr(a * lock_len, lock_len));
			}
		}

		sort(v.begin(), v.end(), greater<>());
		unique(v.begin(), v.end());

		cout << "#" << test_case << " " << hex_to_dec(v[k - 1]) << '\n';
	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}