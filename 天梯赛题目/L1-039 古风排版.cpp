/*
中国的古人写文字，是从右向左竖向排版的。本题就请你编写程序，把一段文字按古风排版。

输入格式：
输入在第一行给出一个正整数N（<100），是每一列的字符数。第二行给出一个长度不超过1000的非空字符串，以回车结束。

输出格式：
按古风格式排版给定的字符串，每列N个字符（除了最后一列可能不足N个）。

输入样例：
4
This is a test case
输出样例：
asa T
st ih
e tsi
 ce s
*/
//题解：

//思路：放到二维数组里，通过行列关系输出
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, k = 0;
    cin >> n;
    string s1;
    getchar();
    getline(cin, s1);
    char s2[101][101];
    if (s1.size() % n == 0)
        m = s1.size() / n;
    else
        m = s1.size() / n + 1;
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (k < s1.size())
            {
                s2[i][j] = s1[k];
                k++;
            }
            else
                s2[i][j] = ' ';
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = m - 1; j >= 0; --j)//按原来的列输出
        {
            cout << s2[j][i];
        }
        cout << endl;
    }
}