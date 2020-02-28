//#include<iostream>
//#include<queue>
//#include<memory.h>
//
////�ʱ� �Է� ����
//const int MAX = 301;
//int n, m;
//
////�� �迭 ����, �湮 üũ �迭 ����
//int arr[MAX][MAX];
//int check[MAX][MAX];
//int ice[MAX][MAX];
//
//bool inside(int x, int y) {
//	return (x >= 0 && x < n) && (y >= 0 && y < m);
//}
//
////��� ���ϰ� 0���� Ȯ��
//bool zeroCheck() {
//	for (int i = 0; i < n; i++) 
//		for (int j = 0; j < m; j++) 
//			if (arr[i][j] != 0) return false;
//	return true;
//}
//
//
//
//int main() {
//	std::ios_base::sync_with_stdio(false);
//	std::cin.tie();
//	std::cout.tie();
//
//	std::cin >> n >> m;
//	memset(arr, 0, sizeof(arr));
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < m; j++)
//			std::cin >> arr[i][j];
//
//	//4��� Ȯ�� �迭 �� �Լ�
//	int dx[4] = { 0,0,-1,1 };
//	int dy[4] = { 1,-1,0,0 };
//
//	int cnt = 0;
//	bool zeroC = 0;
//	int groupCheckCnt;
//	while (true) {
//		//���ϰ� �������� �ִ��� Ȯ��.
//		groupCheckCnt = 0;
//
//		//groupCheck();
//		for (int i = 1; i < n - 1; i++) {
//			for (int j = 1; j < m - 1; j++) {
//				if (arr[i][j] != 0 && check[i][j] == 0) {
//					std::queue <std::pair<int, int>> q;
//					check[i][j] = 1;
//
//					groupCheckCnt++;
//					q.push({ i,j });
//
//					//groupCheckBFS();
//					while (!q.empty()) {
//						int x = q.front().first;
//						int y = q.front().second;
//						q.pop();
//
//						check[x][y] = 1;
//
//						for (int i = 0; i < 4; i++) {
//							int nx = x + dx[i];
//							int ny = y + dy[i];
//							if (inside(nx, ny) && arr[nx][ny] != 0 && check[nx][ny] == 0) {
//								q.push({ nx,ny });
//							}
//						}
//					}
//
//				}
//			}
//		}
//		if (groupCheckCnt >= 2) break;
//
//		//��� 0���� Ȯ��
//		zeroC = zeroCheck();
//		if (zeroC) {
//			cnt = 0;
//			break;
//		}
//
//		memset(check, 0, sizeof(check));
//		memset(ice, 0, sizeof(ice));
//
//		//iceBFS();
//		for (int i = 1; i < n - 1; i++) {
//			for (int j = 1; j < m - 1; j++) {
//				if (arr[i][j] != 0) {
//
//					for (int k = 0; k < 4; k++) {
//						int nx = i + dx[k];
//						int ny = j + dy[k];
//						if (arr[nx][ny] == 0) {
//							ice[i][j] += 1;
//						}
//					}
//				}
//			}
//		}
//
//		//ice�迭�� ����arr�迭�� �ֱ�
//		//iceArrSum();
//		for (int i = 1; i < n - 1; i++) {
//			for (int j = 1; j < m - 1; j++) {
//				arr[i][j] -= ice[i][j];
//				if (arr[i][j] < 0) {
//					arr[i][j] = 0;
//				}
//			}
//		}
//
//		cnt++;
//
//		//cout << '\n';
//		//for (int i = 0; i < n; i++) {
//		//	for (int j = 0; j < m; j++) {
//		//		cout << arr[i][j] << " ";
//		//	}
//		//	cout << '\n';
//		//}
//		//cout << '\n';
//	}
//
//	std::cout << cnt;
//
//
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
////#include<iostream>
////#include<queue>
////#include<algorithm>
////#include<memory.h>
////using namespace std;
////
//////�ʱ� �Է� ����
////const int MAX = 305;
////int n, m;
////
//////�� �迭 ����, �湮 üũ �迭 ����
////int arr[MAX][MAX];
////int check[MAX][MAX];
//////���� �迭
////int ice[MAX][MAX] = { 0, };
////
//////��ǥ�� �����ϴ� ����ü
////typedef struct coor {
////	int x;
////	int y;
////	coor() {};
////	coor(int _x, int _y) : x(_x), y(_y) {};
////}coor;
////
//////coor ����ü�� �̿��� queue����
////queue <coor> q;
////
//////4��� Ȯ�� �迭 �� �Լ�
////int dx[4] = { 0,0,-1,1 };
////int dy[4] = { 1,-1,0,0 };
////bool inside(int x, int y) {
////	return (x >= 0 && x < n) && (y >= 0 && y < m);
////}
////
//////��� Ȯ���ϴ� BFS 
////void groupCheckBFS() {
////	while (!q.empty()) {
////		int x = q.front().x;
////		int y = q.front().y;
////		q.pop();
////
////		check[x][y] = 1;
////
////		int nx, ny;
////		for (int i = 0; i < 4; i++) {
////			nx = x + dx[i];
////			ny = y + dy[i];
////			if (inside(nx, ny) && arr[nx][ny] != 0 && check[nx][ny] == 0) {
////				q.push(coor(nx, ny));
////			}
////		}
////	}
////}
////
//////�� ����� �ִ��� Ȯ��
////int groupCheckCnt = 0;
////
////void groupCheck() {
////	for (int i = 1; i < n - 1; i++) {
////		for (int j = 1; j < m - 1; j++) {
////			if (arr[i][j] != 0 && check[i][j] == 0) {
////				groupCheckCnt++;
////				q.push(coor(i, j));
////				groupCheckBFS();
////			}
////		}
////	}
////}
////
//////check �迭 �ʱ�ȭ
////void resetCheck() {
////	for (int i = 0; i < n; i++) {
////		for (int j = 0; j < m; j++) {
////			check[i][j] = 0;
////		}
////	}
////}
////
//////������ �ֺ� 0�� Ȯ���ϰ� -1�ϴ� BFS;
////void iceBFS() {
////	while (!q.empty()) {
////		int x = q.front().x;
////		int y = q.front().y;
////		q.pop();
////
////		check[x][y] = 1;
////
////		int nx, ny;
////		for (int i = 0; i < 4; i++) {
////			nx = x + dx[i];
////			ny = y + dy[i];
////			if (arr[nx][ny] == 0) {
////				ice[x][y] += 1;
////				//cout<<x<<","<<y<<","<<arr[x][y]<<",X:"<<nx<<",Y:"<<ny<<"   "<<check[x][y]<<endl;
////			}
////			else if (inside(nx, ny) && arr[nx][ny] != 0 && check[nx][ny] == 0) {
////				check[nx][ny] = 1;
////				q.push(coor(nx, ny));
////			}
////		}
////
////	}
////}
////
//////���� �ִ� �� üũ
////void iceCheck() {
////	for (int i = 1; i < n - 1; i++) {
////		for (int j = 1; j < m - 1; j++) {
////			if (arr[i][j] != 0 && check[i][j] == 0) {
////				q.push(coor(i, j));
////				iceBFS();
////			}
////		}
////	}
////}
////
////void iceArrSum() {
////	for (int i = 1; i < n - 1; i++) {
////		for (int j = 1; j < m - 1; j++) {
////			arr[i][j] -= ice[i][j];
////			if (arr[i][j] < 0) {
////				arr[i][j] = 0;
////			}
////		}
////	}
////}
////
//////��� ���ϰ� 0���� Ȯ��
////bool zeroCheck() {
////	for (int i = 0; i < n; i++) {
////		for (int j = 0; j < m; j++) {
////			if (arr[i][j] != 0) return false;
////		}
////	}
////	return true;
////}
////
////int main() {
////
////	cin >> n >> m;
////	for (int i = 0; i < n; i++) {
////		for (int j = 0; j < m; j++) {
////			cin >> arr[i][j];
////		}
////	}
////
////	int cnt = 0;
////	bool zeroC = 0;
////	while (true) {
////		//���ϰ� �������� �ִ��� Ȯ��.
////		groupCheckCnt = 0;
////		groupCheck();
////		if (groupCheckCnt >= 2) break;
////
////		//��� 0���� Ȯ��
////		if (zeroCheck() == true) {
////			cnt = 0;
////			break;
////		}
////
////		///resetCheck();
////		memset(check, 0, sizeof(check));
////
////		//���ϸ� ã�� �� BFS�� ���� �� �ֺ��� �ٴ��ִ��� Ȯ��
////		iceCheck();
////		//ice�迭�� ����arr�迭�� �ֱ�
////		iceArrSum();
////
////		resetCheck();
////		cnt++;
////	}
////
////	cout << cnt << endl;
////	return 0;
////}
////
////
////
////
////
////////190724 14;46
//////#include <iostream>
//////#include <vector>
//////#include <queue>
//////#include <memory.h>
//////#include <math.h>
//////
//////#define MAX_LEN 987654321
//////int dy[] = { -1,0,1,0 };
//////int dx[] = { 0,1,0,-1 };
//////
//////int w, h, cnt, len, result, sum;
//////int ssy, ssx;
//////char map[21][21];
//////int visited[21][21];
//////int dist[11][11]; 
//////int num[21][21];
//////bool invalidMap, visit[11];
//////std::queue<std::pair<int, int>> q;
//////std::vector<std::pair<int, int>> v;
//////
//////void dfs(int a, int c, int prevLen) {
//////	if (!visit[a]) {
//////		//std::cout << "visiting : " << a << ", cnt : " << c <<  '\n';
//////		visit[a] = true;
//////
//////		for (int i = 0; i < len - 1; i++) {
//////			if (visit[i]) continue;
//////			sum += dist[a][i];
//////		
//////			//std::cout << "-> " << i << ", + dist" << a << i << ": " << dist[v.size()-1][i] <<'\n';
//////
//////			c++;
//////			dfs(i, c, dist[a][i]);
//////			c--;
//////		}
//////		
//////		visit[a] = false;
//////		if (c == len) {
//////			if (result > sum)
//////				result = sum;
//////		}
//////		sum -= prevLen;
//////	}
//////}
//////
//////int main() {
//////
//////	std::ios_base::sync_with_stdio(false);
//////	std::cin.tie();
//////	std::cout.tie();
//////
//////	while (1) {
//////
//////		memset(map, 0, sizeof(map));
//////		memset(dist, 0, sizeof(dist));
//////		memset(num, 0, sizeof(num));
//////		memset(visit, false, sizeof(visit));
//////		v.clear();
//////		invalidMap = true;
//////
//////		std::cin >> w >> h;
//////		if (!(w | h)) break;
//////
//////		cnt = 0;
//////		for (int y = 0; y < h; y++){ 
//////			for (int x = 0; x < w; x++) {
//////				std::cin >> map[y][x];
//////				
//////				if (map[y][x] == '*') {
//////					v.push_back({ y,x });
//////					num[y][x] = cnt++;
//////				}
//////				else if (map[y][x] == 'o') {
//////					ssy = y;
//////					ssx = x;
//////				}
//////			}
//////		}
//////
//////		//startPos is at v's end
//////		v.push_back({ ssy,ssx });
//////		num[ssy][ssx] = cnt;
//////		len = v.size();
//////		//bfs, length of each edge
//////		for (int i = 0; i < len; i++) {
//////			int sy = v.at(i).first;
//////			int sx = v.at(i).second;
//////			q.push({ sy, sx });
//////
//////			memset(visited, 0, sizeof(visited));
//////			visited[sy][sx] = 1;
//////
//////			while (!q.empty()) {
//////				int ty = q.front().first;
//////				int tx = q.front().second;
//////				q.pop();
//////
//////				for (int a = 0; a < 4; a++) {
//////					int ny = dy[a] + ty;
//////					int nx = dx[a] + tx;
//////
//////					if (ny < 0 || nx < 0 || ny >= h || nx >= w || map[ny][nx] == 'x' || visited[ny][nx]) continue;
//////
//////					visited[ny][nx] = visited[ty][tx] + 1;
//////					q.push({ ny, nx });
//////
//////					if (map[ny][nx] == '*' || map[ny][nx] == 'o') {
//////						dist[i][num[ny][nx]] = visited[ny][nx] - 1;
//////						dist[num[ny][nx]][i] = visited[ny][nx] - 1;
//////						if (map[ny][nx] == 'o') {
//////							invalidMap = false;
//////						}
//////					}
//////				}
//////			}
//////
//////			//for (int y = 0; y < h; y++)
//////			//{
//////			//	for (int x = 0; x < w; x++)
//////			//	{
//////			//		std::cout << visited[y][x];
//////			//	}std::cout << '\n';
//////			//}std::cout << '\n';
//////		}
//////
//////		//for (int i = 0; i < v.size(); i++)
//////		//{
//////		//	for (int j = 0; j < v.size(); j++)
//////		//	{
//////		//	std::cout << i <<" to " << j << ", " << dist[i][j] << '\n';
//////
//////		//	}
//////		//}
//////
//////		if (invalidMap) std::cout << -1 << '\n';
//////		else {
//////
//////			//dfs, shortest length from startPoint
//////			result = MAX_LEN;
//////			dfs(len - 1,1, 0);
//////
//////			std::cout << result << '\n';
//////		}
//////	}
//////}