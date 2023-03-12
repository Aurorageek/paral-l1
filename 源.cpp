#include<iostream>
#include<windows.h>
#include<stdlib.h>
using namespace std;

const int n = 100;
void row_sum(int n, int a[100], int b[100][100], int sum[100])
{
    for (int i = 0; i < n; i++)
    {
        sum[i] = 0;
    }
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n; i++)
            sum[i] += b[j][i] * a[j];

    }

}
void column_sum(int n, int a[100], int b[100][100], int sum[100])
{
    for (int i = 0; i < n; i++)
    {
        sum[i] = 0;
        for (int j = 0; j < n; j++)
        {
            sum[i] += b[j][i] * a[j];
        }
    }

}

int main(void)
{
    long long head, tail, freq; // timers
    // similar to CLOCKS_PER_SEC
    QueryPerformanceFrequency((LARGE_INTEGER*)&freq);
    // start time
    QueryPerformanceCounter((LARGE_INTEGER*)&head);

    int sum[100];
    int a[100];
    int b[100][100];

    for (int i = 0; i < n; i++)
    {
        a[i] = i;
        for (int j = 0; j < n; j++)
        {
            b[i][j] = i + j;
        }
    };
    column_sum(100, a, b, sum);
    row_sum(100, a, b, sum);
    // end time
    QueryPerformanceCounter((LARGE_INTEGER*)&tail);
    cout << "col" << (tail - head) * 1000.0 / freq << "ms" << endl;
    return 0;
}