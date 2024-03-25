#define _CRT_SECURE_NO_WARNINGS
/*到底应该怎样理解进制呢？首先得有“一个”的数量概念，然后就是这样的：

把用来表示数量的符号依次排列，例如： q w e r

然后定义最前面的符号为“零”，即“没有”，后面的符号表示的数量依次比前一个符号多“一个”

进制就这样产生了： 例如当我们数数，依次数到 q w e r ，再往后数一个，符号不够用了，那么就写成 wq

并且，我们把这种进制命名为“wq”进制。

感觉怪异吗？ 那么请换成我们熟悉的所谓“10”进制看看：

我们的用于表示数量的符号依次是： 0 1 2 3 4 5 6 7 8 9 ， 当数到9，再往后数“一个”时，就数到了 10

看这幅漫画（来源于网络），看看能不能理解“进制”的概念？
base10.jpg


现在，给定表示数量的符号（这些符号就形成了某种进制），以及该种进制下的两个不超过100位的正整数，请计算两数之和。

输入格式:
第一行给定表示数量的符号，每个符号为一个字符、各不相同且中间没有空格，最多有30个符号且符号的可能范围是：数字0-9、大小写字母、!、@、#、$、%、^、&、*、(、)

接下来两行每行给出一个该进制下的不超过100位的正整数

输出格式:
在一行中输出该进制下的两数之和。

输入样例1:
0123456789
123
12
输出样例1:
135
输入样例2:
abcd
bcd
bc
输出样例2:
cab
*/

/*题解：重在对题目的理解，此处用符号代替了一般的数字，应该理解到我们所写的数字只是形式而已，
比如 1+ 1 = 2，我们可以写为啊啊啊啊 一 + 一 = 二。我们可以取字符的下标为其实际代表的数字，
此处用map便于查找。然后就是字符串加法，没什么难度。*/
#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
int main()
{
    int radix, res;
    string str, num1, num2, result = "";
    cin >> str >> num1 >> num2;
    map<char, int> m;
    //翻转字符串便于遍历时相加
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    for (int i = 0; i < str.size(); ++i)
    {
        m[str[i]] = i;
    }
    radix = str.size();//求出进制数
    int i, carry = 0;

    //两个字符串都满足的时候
    for (i = 0; i < num1.size() && i < num2.size(); ++i)
    {
        //每一位相加后的数字
        res = m[num1[i]] + m[num2[i]] + carry;
        //转换成字符存到result里
        result += str[res % radix];
        //记录进位
        if (res / radix == 1) carry = 1;
        else carry = 0;
    }

    //短字符串已经遍历完成时，单独处理没遍历的字符串
    for (; i < num1.size(); ++i)
    {
        res = m[num1[i]] + carry;
        result += str[res % radix];
        if (res / radix == 1) carry = 1;
        else carry = 0;
    }
    for (; i < num2.size(); ++i)
    {
        res = m[num2[i]] + carry;
        result += str[res % radix];
        if (res / radix == 1) carry = 1;
        else carry = 0;
    }
    if (carry == 1) result += str[1];
    //翻转回来在输出
    reverse(result.begin(), result.end());
    cout << result;
}