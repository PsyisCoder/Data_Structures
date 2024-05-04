/*给定一句英语，要求你编写程序，将句中所有单词的顺序颠倒输出。

输入格式：
测试输入包含一个测试用例，在一行内给出总长度不超过500 000的字符串
。字符串由若干单词和若干空格组成，其中单词是由英文字母（大小写有区分）
组成的字符串，单词之间用若干个空格分开。

输出格式：
每个测试用例的输出占一行，输出倒序后的句子，并且保证单词间只有1个空格。

输入样例：
Hello World   Here I Come
输出样例：
Come I Here World Hello*/




//题解：
#include<iostream>
using namespace std;
string arr[1000000], str;//在全局可以开辟这么多空间
                        //但在main函数内不行
int main()
{

    int i = 0;
    while (cin >> str)
    {
        arr[i++] = str;
    }
    for (int j = i - 1; j >= 0; --j)
    {
        cout << arr[j];
        if (j != 0)
            cout << " ";
    }
}