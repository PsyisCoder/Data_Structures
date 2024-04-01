/*删除一个字符串中的所有数字字符。

函数接口定义：
void delnum(char *s);
其中 s 是用户传入的参数。 函数的功能是删除指针 s 所指的字符串中的所有数字字符。

裁判测试程序样例：
#include "stdio.h"
void delnum(char *s);
int main ()
{ char item[80];
gets(item);
 delnum(item);
 printf("%s\n",item);
 return 0;
}

请在这里填写答案 
输入样例：
a0bc + d496df
输出样例：
abc + ddf
*/


//题解：如果一个一个查找是字符的再删除会超时
//      因此用直接查找它不是数字的依次覆盖到数组
void delnum(char* s)
{
    int i = 0, j = 0;
    while (s[i] != '\0')
    {
        if (s[i] > '9' || s[i] < '0') {
            s[j++] = s[i];
        }
        ++i;
    }
    s[j] = '\0';
}