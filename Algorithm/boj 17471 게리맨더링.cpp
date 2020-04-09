#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

int n, people[11], connect[11][11], ans = 987654321;
vector<int> region[2];

void compareRegion() {
    bool inRegion[2][11]; //�� ���ű� ���� ������ T�� ǥ�� 
    bool visited[2][11]; //�湮���� -> ���� �˻簡 ������ �� F��� ������� �ʴ� �����δ�. 

    memset(inRegion, false, sizeof(inRegion));
    memset(visited, false, sizeof(visited));

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < region[i].size(); j++) {
            inRegion[i][region[i][j]] = true; //������ ���ű� ���� �������� T�� ǥ�� 
        }
    }

    int countPeople[2];
    countPeople[0] = countPeople[1] = 0;

    for (int i = 0; i < 2; i++) {
        if (region[i].size() == 1)
        {
            //���ű� ���� ������ 1���̸� �α����� �� ������ �α����̴�. 
            countPeople[i] = people[region[i][0]];
            continue;
        }

        //���� �˻� 
        queue<int> q;

        q.push(region[i][0]);
        visited[i][region[i][0]] = true;

        while (!q.empty()) {
            int now = q.front();
            q.pop();

            for (int j = 0; j < n; j++) {
                //����� ������ Ȯ�� (���� ���ű� ���� �ִ�)
                if (connect[now][j] && inRegion[i][j] && !visited[i][j]) {
                    visited[i][j] = true;
                    q.push(j);
                }
            }
        }

        //�α��� ���ϱ� 
        for (int j = 0; j < region[i].size(); j++) {
            if (!visited[i][region[i][j]]) return; //������� �ʴ� ������ 
            countPeople[i] += people[region[i][j]];
        }
    }
    int res = abs(countPeople[0] - countPeople[1]);
    if (ans > res) ans = res;
}

void dfs(int cnt) {
    if (cnt == n) {
        //n���� ������ ��� ���� 
        if (region[0].size() > 0 && region[1].size() > 0) {
            compareRegion();
        }
        return;
    }

    for (int i = 0; i < 2; i++)
    {
        region[i].push_back(cnt);
        dfs(cnt + 1);
        region[i].pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> people[i]; //�α��� 
    }

    for (int i = 0; i < n; i++) {
        int tmp; //���� �� 
        cin >> tmp;

        for (int j = 0; j < tmp; j++) {
            int b;
            cin >> b;

            connect[i][b - 1] = 1;
            connect[b - 1][i] = 1;
        }
    }

    //�� ���ű��� ������ ������. 
    dfs(0);

    if (ans == 987654321) cout << -1 << '\n';
    else cout << ans << '\n';

    return 0;
}