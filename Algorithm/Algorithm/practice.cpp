#include <iostream>
using namespace std;

#include <stdio.h>
#include <stdlib.h>

#pragma warning( disable : 4996)

//typedef unsigned char  vuint8
//typedef vuint8 bbb;


#define KKK static
typedef unsigned char TYPE;

#define AAA(aaa,bbb,ccc)    aaa bbb

int main() {
	AAA(KKK, TYPE, MM) vvv;
	static unsigned char aaaa;
	vvv = 120;
	aaaa = vvv + 1;

	//cout << "WHAT << " << vvv << " >>" <<  endl;
	//cout << "WHAT << " << aaaa << " >>" <<  endl;

	int eng, math, sci, studentID;

	scanf("%d", &studentID);
	scanf("%d", &eng);
	scanf("%d", &math);
	scanf("%d", &sci);
	printf("�й��� %d\n", studentID);

	printf("���� %d, ���� %d, ���� %d\n", eng, math, sci);
	printf("���� %d, ��� %.2f", eng + math + sci, (float)(eng + math + sci) / 3);

	
	system("pause");
}