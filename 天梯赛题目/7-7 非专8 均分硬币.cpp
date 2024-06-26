/*有 N 堆硬币，编号分别为 1,2,…,N。每堆中都有若干枚相同的硬币，
题目保证所有硬币的总数为 N 的倍数。可以在任意一堆中取若枚硬币，
然后移动到另一堆中。
现在要求在编号为 1 堆中取的硬币，只能移到其右边的堆中；在编号为
N 的堆中取的硬币，只能移到其左边的堆中；在其他堆中取的硬币，可
以移到相邻左边或右边的堆中。请你找出一种移动方法，用最少的移动
次数使每堆中硬币数都一样多。

输入格式:
第一行一个整数 N，表示硬币堆数。第二行 N 个整数，分别表示每堆纸牌初始时的纸牌数。

输出格式:
共一行，即所有堆均达到相等时的最少移动次数。

输入样例:
4
9 8 17 6
输出样例:
3
数据范围
对于 100%，1≤N≤100，硬币的总数不超过1000000。
*/




/*题解：重点在第三个循环！*/
#include<iostream>
using namespace std;
int main()
{
    int arr[101], ans = 0, n, ave = 0;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
        ave += arr[i];
    }
    ave /= n;
    for (int i = 0; i < n; ++i)//每一项与平均值做差
    {
        arr[i] -= ave;
    }
    for (int i = 0; i < n; ++i)//不等于0的就是需要操作的，从第一个开始，如果不等于0，
                                //就把它加到后一个，操作次数++，依次循环就找到最小次数
    {
        if (arr[i] == 0)
            continue;
        arr[i + 1] += arr[i];
        ans++;
    }
    cout << ans;
}