#include <iostream>
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);    std::cout.tie(NULL);

    int t;
    std::cin >> t;

    while (t--) {
        long long n;
        std::cin >> n;
        if (n == 0) break;

        if (n % 2 == 0)
            std::cout << "O\n";
        else    std::cout << "E\n";
    }

    return 0;
    //¦���� Ȧ������ X������X ���� ������ O, 
    //�ƴϸ� E�� ����Ѵ�.
}