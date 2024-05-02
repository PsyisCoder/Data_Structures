/*
本题要求编写程序，输入若干英文单词，对这些单词按长度从小到大排序后输出。
如果长度相同，按照输入的顺序不变。

输入格式：
输入为若干英文单词，每行一个，以#作为输入结束标志。其中英文单词总数不超过20
个，英文单词为长度小于10的仅由小写英文字母组成的字符串。

输出格式：
输出为排序后的结果，每个单词后面都额外输出一个空格。

输入样例：
blue
red
yellow
green
purple
#
输出样例：
red blue green yellow purple
*/
//题解：
//使用冒泡排序，或者用sort但是要记录输入的顺序

//注意：直接使用sort可能会出错，因为sort不稳定，不能保证按照输入的顺序不变



#include<bits/stdc++.h>
using namespace std;
struct eng
{
    int n;//顺序
    string dan;
};
bool cmp(struct eng a, struct eng b)
{
    return a.dan.size() == b.dan.size() ? a.n < b.n : a.dan.size() < b.dan.size();
}
int main()
{
    struct eng arr[30];
    struct eng a;
    getline(cin, a.dan);
    int i = 0;
    while (a.dan != "#")
    {
        a.n = i;
        arr[i] = a;
        i++;
        getline(cin, a.dan);
    }
    sort(arr, arr + i, cmp);
    for (int j = 0; j < i; ++j)
    {
        cout << arr[j].dan << " ";
    }
}