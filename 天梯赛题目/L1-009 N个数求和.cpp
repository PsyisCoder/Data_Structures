/*本题的要求很简单，就是求N个数字的和。麻烦的是，这些数字是以有理数分子/分母
的形式给出的，你输出的和也必须是有理数的形式。

输入格式：
输入第一行给出一个正整数N（≤100）。随后一行按格式a1/b1 a2/b2 ...给出N个有理
数。题目保证所有分子和分母都在长整型范围内。另外，负数的符号一定出现在分子前面。

输出格式：
输出上述数字和的最简形式 —— 即将结果写成整数部分 分数部分，其中分数部分写成
分子/分母，要求分子小于分母，且它们没有公因子。如果结果的整数部分为0，则只输
出分数部分。

输入样例1：
5
2/5 4/15 1/30 -2/60 8/3
输出样例1：
3 1/3
输入样例2：
2
4/3 2/3
输出样例2：
2
输入样例3：
3
1/3 -1/6 1/8
输出样例3：
7/24
*/





#include<iostream>
using namespace std;
long long int gcd(long long int a, long long int b)
{
    return b ? gcd(b, a % b) : a;
}
int main()
{
    long long int n;
    cin >> n;
    long long int fenz = 0, fenm = 1, a, b, t;
    for (int i = 0; i < n; ++i)
    {
        scanf("%lld/%lld", &a, &b);

        fenz *= b;
        fenz += a * fenm;
        fenm *= b;
        t = gcd(fenz, fenm);
        fenz /= t;
        fenm /= t;
    }
    if (fenz % fenm == 0)
    {
        cout << fenz / fenm;
    }
    else if (fenz < fenm)
        cout << fenz << "/" << fenm;
    else
    {
        cout << fenz / fenm << " " << fenz % fenm << "/" << fenm;
    }
}