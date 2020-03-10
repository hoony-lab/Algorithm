#include <iostream>

/*
���� ��� (binomial coefficient)
n���� ���� �ٸ� �͵� �߿��� k����
�����ϴ� ����(combination)�� ����� ��

nCk = n! / (k! * (n-k)!)

���丮�� ǥ���� �ݺ�/��ͷ� ǥ���ϴ°� �ٽ�
*/

int cache[100][100] = { 0, };
int fact[100];

long long func(int n, int k) {
	if (n == 0 || n == k) return 1;
	if (cache[n][k] != 0) return cache[n][k];

	cache[n][k] = func(n-1, k-1) + func(n-1,k);
	
	return cache[n][k];
}

void factorial(int n) {
	fact[0] = 1;

	for (int i = 1; i <= n; i++)
		fact[i] = fact[i - 1] * i;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);	std::cout.tie(NULL);

	int n, k, ans = 0;
	std::cin >> n >> k;

	factorial(n);

	std::cout << fact[n] / fact[k] / fact[n-k];
	
}