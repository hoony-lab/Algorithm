#include "Gready.h"
using namespace std;

void Gready::q1541()
{
	int num[51], operCnt = 0, numCnt = 0;
	char oper[51];
	string str;
	while (char c = getchar() != EOF) {
		if (c == '-' || c == '+') {
			num[numCnt++] = stoi(str);
			oper[operCnt++] = c;
			operCnt++;
		}
		str.append(&c);
	}
	int tryNum = operCnt + numCnt;

	while (tryNum--) {

	}
}

//int minLen;
//queue<int> q;
//vector<int> v;
//int n, map[23][23], visited[23][23];

void Gready::q1507()
{
	int minLen;
	queue<int> q;
	vector<int> v;
	int n, map[23][23], visited[23][23];

	cin >> n;

	for (int x = 1; x <= n; x++) {
		for (int y = 1; y <= n; y++) {
			cin >> map[x][y];
			visited[x][y] = 0;
		}
	}

	for (int x = 1; x < n; x++) {
		for (int y = x + 1; y <= n; y++) {

			for (int i = y + 1; i <= n; i++)
			{
				if (map[x][y] > 1) {

				}
			}
		}
	}

	//����	��� �ٸ�
	//�߻�	�ϴ޸� ���� �Ƹ� ����
	//�ο��	�ʰ��� ���� 


	//���	������ �ǻ�
	//���	ƮŸ ��� �ɳ� �ǻ� ���� ���̰�


	//�߻�	�ϴ޸� ���� �Ƹ� ����
	//��		���ٳ� ��
	//����	�ϴ޸� ���� ���ٳ�
	//������  �Ƹ� �� ���� ��� ���̰�
	//		���� ���̰� ���

	//6���� ���� �ǿ��� ���� ��þ� ������ ����
	//	��� �ٸ�(�˻�)

}

void Gready::q11047()
{
	//long long n, k;
	//cin >> n >> k;

	//int worth[11], dp[11], result = 0;
	//for (int i = 0; i < n; i++)
	//	cin >> worth[i];
	//
	//sort(worth, worth + n);

	//for (int i = n - 1; i >= 0; i--) {
	//	//if (worth[i] == k) {
	//	//	result = 1;
	//	//	break;
	//	//}
	//	if (worth[i] > k) continue;
	//	else {
	//		result += (k / worth[i]);
	//		k %= worth[i];
	//		
	//	}
	//}
	//cout << result;

		//5585
	int n, result = 0;
	cin >> n;
	int worth[6] = { 1,5,10,50,100,500 };
	n = 1000 - n;
	for (int i = 5; i >= 0; i--) {
		result += (n / worth[i]);
		n %= worth[i];
	}
	cout << result;
}

void Gready::q2217()
{
	int n;
	cin >> n;
	
	int rope[100001];
	for (int i = 0; i < n; i++)
		cin >> rope[i];
	//???

}

void Gready::q10610()
{
	vector<int> v;
	string n, str;
	long long result = 0, sum = 0;
	cin >> n;

	bool noZero = true;

	//while (n>0) {
	//	
	//	int res = n % 10;
	//	if (res == 0) noZero = false;
	//	sum += res;
	//	n /= 10;
	//	v.push_back(res);
	//}

	for (int i = 0; i < n.size(); i++)
	{
		if (n[i] == '0') noZero = false;
		int res = n[i] - '0';
		sum += res;
		v.push_back(res);
	}

	if(noZero || sum%3 != 0) cout << -1;
	else {
		sort(v.begin(), v.end());
		string str;
		for (int i = v.size() - 1; i >= 0; i--)
			str.append(to_string(v.at(i)));
		cout << str;
	}
}

void Gready::q2875()
{
	//2��1��, nm / �ݵ�� k����
	int n, m, k;
	cin >> n >> m >> k;

	int result = 0;

	int ppl = n + m;
	int team = ppl / 3;


}
