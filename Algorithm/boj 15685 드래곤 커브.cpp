// https://www.acmicpc.net/problem/15685
// 20200521 1419
//#include <iostream>
//#include <queue>
//#include <vector>
//using namespace std;
//using vii = vector<pair<int, int>>;
//#define F(i, n) for(int i = 0 ; i < n ; ++i)
//#define MAX 101
//// R U L D
//int dy[] = { 0,-1,0,1 }, dx[] = { 1,0,-1,0 };
//
//int map[MAX][MAX];
//int n, x, y, d, g;
//void print() {
//	F(y, 10) {
//		F(x, 10) {
//			cout << map[y][x];
//		}cout << '\n';
//	}cout << "\n\n";
//}
//int count_square() {
//	int ans = 0;
//	F(y, MAX) F(x, MAX) {
//		if (!map[y][x] || !map[y][x + 1] ||
//			!map[y + 1][x] || !map[y + 1][x + 1]) continue;
//		ans++;
//	}
//	return ans;
//}
//void check_square(int cmap[][MAX]) {
//	F(y, MAX) F(x, MAX) {
//		map[y][x] = map[y][x] | cmap[y][x];
//	}
//}
//void rotate(vii v) {
//	int y = v.back().first, x = v.back().second;
//	int way;
//	int vsize = v.size();
//	for(int i = vsize - 2; i >= 0 ; --i){
//
//		int by = v[i + 1].first, bx = v[i + 1].second;
//		int ty = v[i].first, tx = v[i].second;
//		
//		F(a, 4) {
//			if (dx[a] != tx - bx || dy[a] != ty - by) continue;
//
//			way = a - 1;
//			way = (way + 4) % 4;
//			
//			break;
//		}
//		int ny = y + dy[way], nx = x + dx[way];
//
//		v.push_back({ nx, ny });
//		map[ny][nx] = true;
//	}
//}
//int main() {
//	// x,y �巡�� Ŀ�� ������, d ����, g ����
//	int t; cin >> t;
//	while (t--) {
//		cin >> x >> y >> d >> g;
//
//		vii v;
//		int ny = y + dy[d], nx = x + dx[d];
//		v.push_back({ x, y });
//		v.push_back({ nx, ny });
//		map[y][x] = map[ny][nx] = true;
//
//		F(i, g) rotate(v);
//	}
//
//	print();
//
//	cout << count_square() << '\n';
//	return 0;
//}






#include <iostream>
#include <vector>
#define MAX 101
#define F(i, n) for(int i = 0 ; i < n ; ++i)
using namespace std;
using vi = vector<int>;
// R U L D
int dx[] = { 0, -1, 0, 1 }, dy[] = { 1, 0, -1, 0 };
int nx, ny;
bool map[MAX][MAX];
vi v;

void dragon_curve(vi &v) {

	int vsize = (int)v.size();

	for (int i = vsize - 1; i >= 0; i--) {
		int way = (v[i] + 1) % 4;

		nx += dx[way];
		ny += dy[way];

		map[nx][ny] = true;

		v.push_back(way);
	}
}

int count_square() {
	int ans = 0;
	F(x, MAX - 1) {
		F(y, MAX - 1) {
			if (!map[x][y] || !map[x][y + 1] ||
				!map[x + 1][y] || !map[x + 1][y + 1]) continue;
			ans++;
		}
	}
	return ans;
}


int main() {
	int t, x, y, d, g;	cin >> t;
	F(a, t) {
		cin >> y >> x >> d >> g;
		v.clear();

		map[x][y] = true;

		nx = x + dx[d];
		ny = y + dy[d];
		map[nx][ny] = true;

		v.push_back(d);

		F(i, g) dragon_curve(v);
	}

	cout << count_square();

	return 0;
}

// https://velog.io/@skyepodium/%EB%B0%B1%EC%A4%80-15685-%EB%93%9C%EB%9E%98%EA%B3%A4-%EC%BB%A4%EB%B8%8C
//#include <iostream>
//#include <vector>
//#define max_int 101
//using namespace std;
//
////�ð� ���⵵: O(n*2^g + xy)
////���� ���⵵: O(xy + n)
////����� �˰���: �ݺ���
////����� �ڷᱸ��: ����(����), 2���� �迭
//
//int n, x, y, d, g, result;
//
////������ ����
//int end_x, end_y;
//
//bool map[max_int][max_int];
//
////����, ����, ������, �Ʒ���
//int dx[] = { 0, -1, 0, 1 }, dy[] = { 1, 0, -1, 0 };
//
//
////���� ������ ���������� �����ϴ� ����
////stl ���þ��� �������ϱ� �ε����� ���� �� �� �ִ� ���͸� ����Ѵ�.
//vector<int> dragon;
//
////������ �����ϸ鼭 �巡�� Ŀ�긦 ����� �Լ�
//void make_generation(vector<int>& dragon) {
//
//    //���� ������ ũ�⸦ ���� ����� ���´�.
//    int size = (int)dragon.size();
//
//    //������ �ڿ��� ���� �����鼭
//    //���������� ���������� dir = (dragon[i] + 1)%4; ��Ģ�� ���� �����Ѵ�.
//    for (int i = size - 1; i >= 0; i--) {
//        int dir = (dragon[i] + 1) % 4;
//
//        //���� ������ ���������� �������� ���� x,y�� ã�� �̸� �����Ѵ�.
//        end_x = end_x + dx[dir];
//        end_y = end_y + dy[dir];
//
//        //������� �巡�� Ŀ�긦 ������ �����ش�.
//        map[end_x][end_y] = true;
//
//        //�������븦 ���� ���ÿ� ���������� �־��ش�.
//        dragon.push_back(dir);
//    }
//}
//
//int main() {
//
//    scanf_s("%d", &n);
//
//    for (int i = 0; i < n; i++) {
//        //x, y�� ������ �ٲ㼭 �Է¹޴´�.
//        int y, x, d, g;
//        scanf_s("%d %d %d %d", &y, &x, &d, &g);
//
//        //���� �巡�� Ŀ���� ������ ����ش�.
//        dragon.clear();
//
//        //���������� �巡�� Ŀ�갡 ���������Ƿ� ������ ǥ�����ش�.
//        map[x][y] = true;
//
//        //0����� �̸� ����� ���´�.
//        end_x = x + dx[d];
//        end_y = y + dy[d];
//
//        //0���븦 ���� ���Ŀ��� ������ ǥ�����ش�.
//        map[end_x][end_y] = true;
//
//        //0������ ���������� ���ÿ� �־��ش�.
//        dragon.push_back(d);
//
//        //�ݺ����� ���� 0���� �������� �巡�� Ŀ�긦 ����鼭 g������� �����.
//        for (int i = 0; i < g; i++) {
//
//            //�巡�� Ŀ�긦 ������
//            make_generation(dragon);
//        }
//
//    }
//
//    //100*100 2���� ����� 2�� for�� ����� �ܼ��� Ž��
//    //������ 4ĭ�� ��� true�̸�, 4ĭ�� ��� �巡�� Ŀ���� �Ϻ��ΰ�
//    //������ 1������Ų��.
//    for (int i = 0; i <= max_int - 2; i++) {
//        for (int j = 0; j <= max_int - 2; j++) {
//
//            //������ 4ĭ�� ���簢���� ��� �巡���� �Ϻ��̸�
//            if (map[i][j] == true && map[i][j + 1] == true && map[i + 1][j] == true && map[i + 1][j + 1] == true) {
//
//                //������ 1 ������Ų��.
//                result++;
//            }
//        }
//    }
//
//    //���� ���
//    printf("%d\n", result);
//    return 0;
//}