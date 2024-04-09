/*题的目标很简单，就是求两个正整数A和B的和，其中A和B都在区间[1,1000]。
稍微有点麻烦的是，输入并不保证是两个正整数。

输入格式：
输入在一行给出A和B，其间以空格分开。问题是A和B不一定是满足要求的正整数，
有时候可能是超出范围的数字、负数、带小数点的实数、甚至是一堆乱码。

注意：我们把输入中出现的第1个空格认为是A和B的分隔。题目保证至少存在一个
空格，并且B不是一个空字符串。

输出格式：
如果输入的确是两个正整数，则按格式A + B = 和输出。如果某个输入不合要求，
则在相应位置输出?，显然此时和也是?。

输入样例1：
123 456
输出样例1：
123 + 456 = 579
输入样例2：
22. 18
输出样例2：
? + 18 = ?
输入样例3：
-100 blabla bla...33
输出样例3：
? + ? = ?
*/


//题解：

/*题目要点：1.由于a可以为空而b不可以为空，因此a数的输入方式不能接受空格，但是b可以接受空格
           2.在遍历b的时候要从第二个元素开始，因为b接受了a与b之间的空格



*/

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;
int main()
{
    char a[30], b[30];
    scanf("%s", a);
    //pta不能使用gets，因此用以下的方式输入
    for (int i = 0; i < 30; ++i)
    {
        b[i] = getchar();
        if (b[i] == '\n')
        {
            b[i] = '\0';
            break;
        }
    }
    int flag1 = 1, flag2 = 1;





    //判断是否有非法字符
    for (int i = 0; a[i] != '\0'; ++i)
    {
        if (a[i] < '0' || a[i]>'9')
        {
            flag1 = 0; break;
        }
    }
    //getchar会接受前面的空格，因此从第二个元素开始遍历，当时也因为从第一个元素遍历而导致频繁出错
    for (int i = 1; b[i] != '\0'; ++i)
    {
        if (b[i] < '0' || b[i]>'9')
        {
            flag2 = 0; break;
        }
    }





    if (flag1 == 0 && flag2 == 0)
        printf("? + ? = ?\n");
    if (flag1 == 0 && flag2 != 0)
        printf("? + %s = ?\n", b + 1);
    if (flag1 != 0 && flag2 == 0)
        printf("%s + ? = ?\n", a);
    if (flag1 != 0 && flag2 != 0)
    {
        int s1 = 0, s2 = 0;
        for (int i = 0; i < strlen(a); ++i)
        {
            s1 += pow(10, strlen(a) - 1 - i) * (a[i] - '0');
        }
        for (int i = 1; i < strlen(b); ++i)
        {
            s2 += pow(10, strlen(b) - 1 - i) * (b[i] - '0');
        }
        //判断有没有超出范围，当时就没有考虑到范围问题
        if (s1 <= 1000 && s1 >= 1 && s2 <= 1000 && s2 >= 1)
            printf("%d + %d = %d\n", s1, s2, s1 + s2);
        else if ((s1 > 1000 || s1 < 1) && s2 <= 1000 && s2 >= 1)
            printf("? + %d = ?\n", s2);
        else if ((s2 > 1000 || s2 < 1) && s1 <= 1000 && s1 >= 1)
            printf("%d + ? = ?\n", s1);
        else if ((s1 > 1000 || s1 < 1) && (s2 > 1000 || s2 < 1))
            printf("? + ? = ?\n");
    }
}