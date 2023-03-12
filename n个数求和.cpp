#include<iostream>

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
	int a[n];
	int sum = 0;

	//平凡算法
	for (int i = 0; i < n; i++)
		sum += a[i];

	//双路链式
	int Sum1 = 0;
	int Sum2 = 0;
	for (int i = 0; i < n; i += 2)
	{
		Sum1 += a[i];
		Sum2 += a[i + 1];
	}
	sum = Sum1 + Sum2;

	//递归
	recursion(n, a);




	//双重循环
	for (int m = n; m > 1; m /= 2) // log(n)个步骤
		for (int i = 0; i < m / 2; i++)
			a[i] = a[i * 2] + a[i * 2 + 1]; // 相邻元素相加连续存储到数组最前面，a[0]为最终结果



}