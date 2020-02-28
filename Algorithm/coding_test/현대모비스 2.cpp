#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
/*
���� ����Ÿ��� ���������� �뿩
if(�Ÿ���������) ������ȣ�� �ռ��� �� �켱

�� ��� n
������ȣ ���ڿ� plates
����Ÿ� ���� odo
�����뿩 ���� k
���� �뿩�� ����Ÿ� drives
*/
string solution(int n, vector<string> plates, vector<int> odo, int k, vector<int> drives) {
	int min_odo, min_car;
	//���� ��ȣ + �ش� ���� ��������Ÿ�
	vector<pair<string, long long> > cars;
	for (int i = 0; i < n; ++i)
		cars.push_back({ plates[i], odo[i] });

	// ��������Ÿ� �켱, ���� ��ȣ ���� �ø����� ���� 16 18 19 20 20 24
	sort(cars.begin(), cars.end(), [](pair<string, int> v1, pair<string, int> v2) {
		if (v1.second == v2.second) return v1.first < v2.first;
		else return v1.second < v2.second;
	});

	min_odo = cars[0].second;
	min_car = 0;


	//k ���� ���� �뿩
	for (int time = 0; time < k + 1; ++time) {

		//for (int i = 0; i < n; ++i) {
		//	if (min_odo < cars[i].second) continue;

		//	if (min_odo > cars[i].second) {
		//		
		//		min_odo = cars[i].second;
		//		min_car = i;
		//	}
		//	else if (min_odo == cars[i].second) {
		//		if (cars[min_car].first > cars[i].first) {
		//			min_odo = cars[i].second;
		//			min_car = i;
		//			break;
		//		}
		//	}
		//}
		// ��������Ÿ� �켱, ���� ��ȣ ���� �ø����� ���� 16 18 19 20 20 24
		sort(cars.begin(), cars.begin()+n, [](pair<string, int> v1, pair<string, int> v2) {
			if (v1.second == v2.second) return v1.first < v2.first;
			else return v1.second < v2.second;
		});


		if (k != time) {
			cars[min_car].second += drives[time];
			//min_odo += drives[time];
		}
	}

	return cars[min_car].first;
}
int main() {
	cout << solution(6, { "AZ3618", "XP9657", "SP6823", "UH7515", "TV6621", "WZ8264" }, { 20,16,18,20,24,19 }, 8, { 3,7,5,8,6,5,10,2 }) << '\n';



}