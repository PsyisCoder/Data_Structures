/*给定一个有 n 个正整数的数组 a 和一个整数 sum ,求选择数组 a 中部分数字和为 sum 的方案数。
若两种选取方案有一个数字的下标不一样，则认为是不同的方案。

输入格式:
输入分两行，第1行为两个正整数n(1≤n≤1000)、sum（1≤sum≤1000）,第2行为n个正整数a[i],用空格分隔。

输出格式:
输出所求的方案数。

输入样例:
在这里给出一组输入。例如：

5 15
5 5 10 2 3
输出样例:
在这里给出相应的输出。例如：

4
*/

#include<iostream>
using namespace std;
#define int long long
int n, sum, dp[1010][1010], r, arr[1010], a, b;
void init()
{
    for (int i = 0; i < sum; ++i)
    {
        dp[0][i] = 0;
    }
    dp[0][0] = 1;//这样只有在物品大小等于背包大小时才算是一次情况
}
signed main()
{

    cin >> n >> sum;
    init();
    for (int i = 1; i <= n; ++i)
    {
        cin >> arr[i];
    }
    //背包算法：
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= sum; ++j)
        {
            dp[i][j] = dp[i - 1][j];//这个代表不加上本次，在i=1或2时就是0，代表没有情况
            if (arr[i] <= j)
            {
                dp[i][j] += dp[i - 1][j - arr[i]];//如果此次物品大小小于背包大小，就加上剩余背包大小的最优解
            }
        }
    }
    cout << dp[n][sum] << endl;
}