#include <iostream>
#include <string>
using namespace std;

//���ڿ� S�� ���̴� N�̰�, 'A', 'B'�� �̷���� �ִ�.
//���ڿ� S���� 0 �� i < j < N �̸鼭
// s[i] == 'A' && s[j] == 'B'�� �����ϴ�(i, j) ���� K���� �ִ�.
int main() {
	string ans;
	int n, k;
	cin >> n >> k;


	if (k > (n/2) * (n/2))
		cout << "-1";
	else if (k == 0) {
		cout << "B";
		for (int i = 0; i < n - 1; i++)
			cout << "A";
	}
	else cout << ans;
		return 0;
}