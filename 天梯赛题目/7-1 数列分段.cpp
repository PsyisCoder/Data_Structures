/*题目描述
对于给定的一个长度为N的正整数数列A-iA−i，现要将其分成M(M≤N)段，并要求每段连续，且每段和的最大值最小。

关于最大值最小：

例如一数列4 2 4 5 1要分成3段

将其如下分段：

[4 2][4 5][1]

第一段和为6，第2段和为9，第3段和为1，和最大值为9。

将其如下分段：

[4][2 4][5 1]

第一段和为4，第2段和为6，第3段和为6，和最大值为6。

并且无论如何分段，最大值不会小于6。

所以可以得到要将数列4 2 4 5 1要分成3段，每段和的最大值最小为6。

 

输入输出格式
输入格式：

第1行包含两个正整数N，M。

第2行包含N个空格隔开的非负整数A_i，含义如题目所述。

输出格式：

一个正整数，即每段和最大值最小为多少。

输入样例#1： 
5 3
4 2 4 5 1
输出样例#1： 
6

*/



//二分法和贪心算法
#include<iostream>
using namespace std;
#define int long long//因为题目要求的数据范围，所以要使用longlong
int n, m;
int arr[100002];
int r, l;
int sum, now;
bool judge(int mid)
{
    sum = 0; now = 0;
    for (int i = 0; i < n; ++i)
    {
        if (now + arr[i] <= mid)
        {
            now += arr[i];
        }
        else
        {
            sum += 1;
            now = arr[i];
        }
    }
    return sum >= m;
}
signed main()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
        r += arr[i];
        l = arr[i] > l ? arr[i] : l;//把单个值的最大值给到左边，因为每段和的最大值一定不小于它
    }
    int mid;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (judge(mid))
            l = mid + 1;
        else
            r = mid - 1;
    }
    cout << l << endl;
}