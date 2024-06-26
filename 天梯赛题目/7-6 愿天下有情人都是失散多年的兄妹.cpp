﻿/*呵呵。大家都知道五服以内不得通婚，即两个人最近的共同祖先如果在五代以内
（即本人、父母、祖父母、曾祖父母、高祖父母）则不可通婚。本题就请你帮助一
对有情人判断一下，他们究竟是否可以成婚？

输入格式：
输入第一行给出一个正整数N（2 ≤ N ≤10 
4
 ），随后N行，每行按以下格式给出一个人的信息：

本人ID 性别 父亲ID 母亲ID
其中ID是5位数字，每人不同；性别M代表男性、F代表女性。如果某人的父亲或母亲
已经不可考，则相应的ID位置上标记为-1。

接下来给出一个正整数K，随后K行，每行给出一对有情人的ID，其间以空格分隔。

注意：题目保证两个人是同辈，每人只有一个性别，并且血缘关系网中没有乱伦或隔
辈成婚的情况。

输出格式：
对每一对有情人，判断他们的关系是否可以通婚：如果两人是同性，输出Never Mind
；如果是异性并且关系出了五服，输出Yes；如果异性关系未出五服，输出No。

输入样例：
24
00001 M 01111 -1
00002 F 02222 03333
00003 M 02222 03333
00004 F 04444 03333
00005 M 04444 05555
00006 F 04444 05555
00007 F 06666 07777
00008 M 06666 07777
00009 M 00001 00002
00010 M 00003 00006
00011 F 00005 00007
00012 F 00008 08888
00013 F 00009 00011
00014 M 00010 09999
00015 M 00010 09999
00016 M 10000 00012
00017 F -1 00012
00018 F 11000 00013
00019 F 11100 00018
00020 F 00015 11110
00021 M 11100 00020
00022 M 00016 -1
00023 M 10012 00017
00024 M 00022 10013
9
00021 00024
00019 00024
00011 00012
00022 00018
00001 00004
00013 00016
00017 00015
00019 00021
00010 00011
输出样例：
Never Mind
Yes
Never Mind
No
Yes
No
Yes
No
No
*/






//题解：
#include<bits/stdc++.h>
using namespace std;
#define MAX 100000
char sex[MAX];
int father[MAX], mother[MAX];
int judge(int a, int b, int num)
{
    //a或b有一个无从考证，就可以结婚
    if (a == -1 || b == -1)
        return 1;
    //两人的父或母存在相同的就属于近亲结婚
    if ((mother[a] != -1 && mother[a] == mother[b]) || (father[a] != -1 && father[a] == father[b]))
        return 0;
    //前两种都不是（既不是无从考证，也不是父母相同），就num++
    num++;
    //如果五代之内递归过程中有近亲了就会直接返回，没有就继续
    if (num < 4)
        //一假则假
        return judge(mother[a], mother[b], num) && judge(mother[a], father[b], num) && judge(father[a], father[b], num) && judge(father[a], mother[b], num);
    else
        return 1;
}
int main()
{
    //把不存在的父母都赋值为（不可考）也就是-1
    memset(father, -1, sizeof(father));
    memset(mother, -1, sizeof(mother));
    int n, k;
    cin >> n;
    while (n--)
    {
        int id;
        cin >> id;
        cin >> sex[id] >> father[id] >> mother[id];
        //防止有重婚的情况，使得重婚父母的性别不可知
        sex[mother[id]] = 'F';
        sex[father[id]] = 'M';
    }
    cin >> k;
    while (k--)
    {
        int a, b;
        cin >> a >> b;
        if (sex[a] == sex[b])
            cout << "Never Mind" << endl;
        else
        {
            if (judge(a, b, 0))
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
}