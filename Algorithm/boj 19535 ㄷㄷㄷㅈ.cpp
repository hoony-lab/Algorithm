#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 300001
#define D cout << "D"
#define G cout << "G"
#define DG cout << "DUDUDUNGA"
int find_d() {

}
int find_g() {

}
int main() {
    int n, u, v;
    cin >> n;

    //vector<int> v(MAX); generate(v.begin(), v.end(), [num = 0]() mutable {return num++; });

    vector<int> graph[MAX];
    for (int i = 1; i < n; ++i) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        
        find_g();
        find_d();
    }

	return 0;
}

/*
 D-Ʈ�� : �������� �������� 3�躸�� ���� Ʈ��                �� > �� * 3
 G-Ʈ�� : �������� �������� 3�躸�� ���� Ʈ��                �� < �� * 3
 DUDUDUNGA-Ʈ�� : �������� �������� ��Ȯ�� 3�踸ŭ �ִ� Ʈ�� �� == �� * 3
 */