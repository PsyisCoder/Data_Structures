/*临沂大学有很多社团，一个学生可能会加入多个社团。为了活跃大学生业余生活，增强体育运动积极性，临沂大学读书社团决定举行大学生跳绳比赛，要求该社团成员必须参加。为了扩大影响，要求只要其他社团有一个人参加，那么该社团中的每一个人都必须参加。求参加比赛至少多少人？

输入格式:
输入第一行包含两个整数n和m，n（0 < n <= 30000）表示学生的数目，m（0 <= m <= 500）表示社团的数目。每个学生都有一个唯一的编号，编号取值为0到n-1，编号为0的社团是读书社团。
接下来有m个社团的名单，每个社团的名单在输入中为一行。每一行先输入一个数k表示社团总人数。接着是社团中k个成员的编号。

输出格式:
输出一个数占一行，表示参加比赛的总人数。

输入样例:
100 4 
2 1 2 
5 10 13 11 12 14 
2 0 1 
2 99 2 
输出样例:
4
*/


//题解：并查集
#include<iostream>
using namespace std;
int p[300001];
int find(int x)
{
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}
void join(int x, int y)
{
    x = find(x);
    y = find(y);
    p[x] = y;
}
int main()
{
    int n, m;
    int k, fir, num, F;
    int sum = 0;
    cin >> n >> m;
    //初始化一个并查集
    for (int i = 0; i < n; ++i)
    {
        p[i] = i;
    }
    //把同一社团的放到一个集合，并且把有人参加的社团的所有人都并到一起，这样最后只需找到父节点为F的即可
    for (int i = 0; i < m; ++i)
    {
        cin >> k;
        cin >> fir;
        if (i == 0)
            F = fir;
        for (int i = 1; i < k; ++i)
        {
            cin >> num;
            join(fir, num);
        }
    }
    //找到父节点为F的累加
    for (int i = 0; i < n; ++i)
    {
        if (find(i) == find(F))
            sum++;
    }
    cout << sum;
    return 0;
}