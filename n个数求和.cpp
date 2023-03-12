#include<iostream>
#include<windows.h>
#include<stdlib.h>
using namespace std;

const int n = 1000;


void recursion(int n, int* a)
{
	if (n == 1)
		return;
	else
	{
		for (int i = 0; i < n / 2; i++)
		{
			a[i] += a[n - i - 1];
		}
		n = n / 2;
		recursion(n, a);
	}
}
int main()
{

	long long head, tail, freq; // timers
	// similar to CLOCKS_PER_SEC
	QueryPerformanceFrequency((LARGE_INTEGER*) & freq);
	// start time
	QueryPerformanceCounter((LARGE_INTEGER*) & head);
	int a[n];
	int sum = 0;

	//ƽ���㷨
	for (int i = 0; i < n; i++)
		sum += a[i];

	//˫·��ʽ
	int Sum1 = 0;
	int Sum2 = 0;
	for (int i = 0; i < n; i += 2)
	{
		Sum1 += a[i];
		Sum2 += a[i + 1];
	}
	sum = Sum1 + Sum2;

	//�ݹ�
	recursion(n, a);




	//˫��ѭ��
	for (int m = n; m > 1; m /= 2) // log(n)������
		for (int i = 0; i < m / 2; i++)
			a[i] = a[i * 2] + a[i * 2 + 1]; // ����Ԫ����������洢��������ǰ�棬a[0]Ϊ���ս��

	// end time
	QueryPerformanceCounter((LARGE_INTEGER *)&tail);
	cout << "col" << (tail-head)* 1000.0 / freq<< "ms" << endl;

}