#define _CRT_SECURE_NO_WARNINGS

/*题目：给定两个整数集合，它们的相似度定义为：Nc/Nt×100%。其中Nc​是两个集合都有的不相等整数的个数，
Nt是两个集合一共有的不相等整数的个数。你的任务就是计算任意一对给定集合的相似度。

输入格式：
输入第一行给出一个正整数N（≤50），是集合的个数。随后N行，每行对应一个集合。每个集合首先给出一个
正整数M（≤10^4），是集合中元素的个数；然后跟M个[0,10^9]区间内的整数。之后一行给出一个正整数K（≤2000）
随后K行，每行对应一对需要计算相似度的集合的编号（集合从1到N编号）。数字间以空格分隔。

输出格式：
对每一对需要计算的集合，在一行中输出它们的相似度，为保留小数点后2位的百分比数字。

输入样例：
3
3 99 87 101
4 87 101 5 87
7 99 101 18 5 135 18 99
2
1 2
1 3
输出样例：
50.00%
33.33%*/

#include<iostream>
#include<set>
using namespace std;
int main()
{
    int n, f = 1;
    cin >> n;
    set<int> st[51];
    while (n--)
    {
        int size, x;
        cin >> size;
        while (size--)
        {
            cin >> x;
            st[f].insert(x);
            //依次向每个st插入size个数
        }
        f++;
    }
    int k;
    cin >> k;
    while (k--)
    {
        int a, b, sum = 0;
        cin >> a >> b;
        int p = st[a].size() + st[b].size();
        //用p减去a，b内相同的数的个数就是总的不相等整数的个数
        for (auto it : st[a])//auto遍历
        {
            if (st[b].find(it) != st[b].end())
            {
                //如果st[b]中存在则++
                sum++;
            }
        }
        double r = sum * 100.0 / (p - sum);
        printf("%.2lf%%\n", r);
    }
}