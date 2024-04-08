﻿/*当芸芸众生忙着在朋友圈中发照片的时候，总有一些人因为太帅而没有朋友。
本题就要求你找出那些帅到没有朋友的人。

输入格式：
输入第一行给出一个正整数N（≤100），是已知朋友圈的个数；随后N行，每行
首先给出一个正整数K（≤1000），为朋友圈中的人数，然后列出一个朋友圈内
的所有人——为方便起见，每人对应一个ID号，为5位数字（从00000到99999），
ID间以空格分隔；之后给出一个正整数M（≤10000），为待查询的人数；随后一
行中列出M个待查询的ID，以空格分隔。

注意：没有朋友的人可以是根本没安装“朋友圈”，也可以是只有自己一个人在朋
友圈的人。虽然有个别自恋狂会自己把自己反复加进朋友圈，但题目保证所有K超
过1的朋友圈里都至少有2个不同的人。

输出格式：
按输入的顺序输出那些帅到没朋友的人。ID间用1个空格分隔，行的首尾不得有多
余空格。如果没有人太帅，则输出No one is handsome。

注意：同一个人可以被查询多次，但只输出一次。

输入样例1：
3
3 11111 22222 55555
2 33333 44444
4 55555 66666 99999 77777
8
55555 44444 10000 88888 22222 11111 23333 88888
输出样例1：
10000 88888 23333
输入样例2：
3
3 11111 22222 55555
2 33333 44444
4 55555 66666 99999 77777
4
55555 44444 22222 11111
输出样例2：
No one is handsome
*/






//题解：


#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[100001] = { 0 };//用数组下标做id，数组值为1则有朋友，0则没朋友
    while (n--)
    {
        int k, x;
        cin >> k;
        for (int i = 0; i < k; ++i)
        {
            cin >> x;
            if (k > 1)//只要k>1就有朋友
            {
                arr[x] = 1;//有朋友赋值为1
            }
        }
    }
    int m;
    cin >> m;
    int cha, sum = 0;
    for (int i = 0; i < m; ++i)
    {
        cin >> cha;
        if (arr[cha] == 0)
        {
            if (sum == 0)
            {
                cout << setw(5) << setfill('0') << cha; arr[cha] = 1;
            }
            else
            {
                cout << " " << setw(5) << setfill('0') << cha;
                arr[cha] = 1;
            }
            sum++;
        }
    }
    if (sum == 0)
        cout << "No one is handsome";
}