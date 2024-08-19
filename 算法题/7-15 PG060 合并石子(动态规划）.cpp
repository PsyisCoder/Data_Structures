/*在一个圆形操场的四周摆放着n堆石子，现要将石子有次序地合并成一堆。规定每次只能选相邻2堆石子合并成新的一堆，
并将新的一堆石子数记为该次合并的得分。试设计一个算法，计算出将n堆石子合并成一堆的最小得分和最大得分。

输入格式:
n表示n堆石子，下一行n个数，表示每堆石子的个数。可能有多组测试数据。

输出格式:
分别输出最小得分和最大得分，空格隔开。每组一行。

输入样例:
在这里给出一组输入。例如：

4
4  4  5  9
输出样例:
在这里给出相应的输出。例如：

43 54
*/


//AC代码：
#include<iostream>
#include<algorithm>
using namespace std;
int a[1001], dp[1001][1001], dp2[1001][1001], sum[1001];
int main()
{
    int n;
    while (cin >> n)
    {
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
            //因为是环形，所以在后面复制一份把环形变成链型
            a[i + n] = a[i];
        }
        //求前缀和
        for (int i = 1; i <= 2 * n; ++i)
        {
            sum[i] = sum[i - 1] + a[i];
        }




        //动态规划
        for (int len = 2; len <= n; ++len)//枚举区间长度
        {
            for (int i = 1; len + i - 1 <= 2 * n; ++i)//枚举起点
            {
                int j = i + len - 1;
                dp[i][j] = 1e8;
                dp2[i][j] = -1e8;
                for (int k = i; k < j; ++k)
                {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + sum[j] - sum[i - 1]);
                    dp2[i][j] = max(dp2[i][j], dp2[i][k] + dp2[k + 1][j] + sum[j] - sum[i - 1]);
                }
            }
        }




        //找到最值输出
        int Max = 0, Min = 1e8;
        for (int i = 1; i <= n; ++i)
        {
            Max = max(Max, dp2[i][i + n - 1]);
            Min = min(Min, dp[i][i + n - 1]);
        }
        cout << Min << " " << Max << endl;
    }
}