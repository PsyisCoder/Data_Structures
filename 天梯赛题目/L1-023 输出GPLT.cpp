/*给定一个长度不超过10000的、仅由英文字母构成的字符串。请将字符重新调整顺序，按GPLTGPLT....这样的顺序输出，并忽略其它字符。当然，四种字符（不区分大小写）的个数不一定是一样多的，若某种字符已经输出完，则余下的字符仍按GPLT的顺序打印，直到所有字符都被输出。

输入格式：
输入在一行中给出一个长度不超过10000的、仅由英文字母构成的非空字符串。

输出格式：
在一行中按题目要求输出排序后的字符串。题目保证输出非空。

输入样例：
pcTclnGloRgLrtLhgljkLhGFauPewSKgt
输出样例：
GPLTGPLTGLTGLGLL
*/






//题解：
//思路：直接记录GPTL各个字母出现的次数，然后按顺序输出


#include<bits/stdc++.h>
using namespace std;
int main()
{
    string arr;
    cin >> arr;
    int g = 0, p = 0, t = 0, l = 0, i = 0;
    while (arr[i] != '\0')
    {
        switch (arr[i])
        {
        case 'G':case 'g':g++; break;
        case 'P':case 'p':p++; break;
        case 'L':case 'l':l++; break;
        case 'T':case 't':t++; break;
        }
        ++i;
    }
    while (g | p | l | t)//按位或，gplt中有一个不为0就继续输出
    {
        if (g) { cout << "G"; g--; }
        if (p) { cout << "P"; p--; }
        if (l) { cout << "L"; l--; }
        if (t) { cout << "T"; t--; }
    }
}