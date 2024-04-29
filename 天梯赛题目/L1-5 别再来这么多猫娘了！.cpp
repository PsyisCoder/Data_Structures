/*
以 GPT 技术为核心的人工智能系统出现后迅速引领了行业的变革，不仅用于大量的
语言工作（如邮件编写或文章生成等工作），还被应用在一些较特殊的领域——例如去
年就有同学尝试使用 ChatGPT 作弊并被当场逮捕（全校被取消成绩）。相信聪明的
你一定不会犯一样的错误！

言归正传，对于 GPT 类的 AI，一个使用方式受到不少年轻用户的欢迎——将 AI 变成猫娘：


image.png
部分公司使用 AI 进行网络营销，网友同样乐于使用“变猫娘”的方式进行反击。注意：
图中内容与题目无关，如无法看到图片不影响解题。


当然，由于训练数据里并不区分道德或伦理倾向，因此如果不加审查，AI 会生成大量
的、不一定符合社会公序良俗的内容。尽管关于这个问题仍有争论，但至少在比赛中，
我们还是期望 AI 能用于对人类更有帮助的方向上，少来一点猫娘。

因此你的工作是实现一个审查内容的代码，用于对 AI 生成的内容的初步审定。更具体
地说，你会得到一段由大小写字母、数字、空格及 ASCII 码范围内的标点符号的文字，
以及若干个违禁词以及警告阈值，你需要首先检查内容里有多少违禁词，如果少于阈值
个，则简单地将违禁词替换为<censored>；如果大于等于阈值个，则直接输出一段警告
并输出有几个违禁词。

输入格式:
输入第一行是一个正整数 N (1≤N≤100)，表示违禁词的数量。接下来的 N 行，每行一
个长度不超过 10 的、只包含大小写字母、数字及 ASCII 码范围内的标点符号的单词，
表示应当屏蔽的违禁词。
然后的一行是一个非负整数 k (0≤k≤100)，表示违禁词的阈值。
最后是一行不超过 5000 个字符的字符串，表示需要检查的文字。
从左到右处理文本，违禁词则按照输入顺序依次处理；对于有重叠的情况，无论计数还是
替换，查找完成后从违禁词末尾继续处理。

输出格式:
如果违禁词数量小于阈值，则输出替换后的文本；否则先输出一行一个数字，表示违禁词
的数量，然后输出He Xie Ni Quan Jia!。

输入样例1:
5
MaoNiang
SeQing
BaoLi
WeiGui
BuHeShi
4
BianCheng MaoNiang ba! WeiGui De Hua Ye Keyi Shuo! BuYao BaoLi NeiRong.

输出样例1:
BianCheng <censored> ba! <censored> De Hua Ye Keyi Shuo! BuYao <censored> NeiRong.
输入样例2:
5
MaoNiang
SeQing
BaoLi
WeiGui
BuHeShi
3
BianCheng MaoNiang ba! WeiGui De Hua Ye Keyi Shuo! BuYao BaoLi NeiRong.

输出样例2:
3
He Xie Ni Quan Jia!
输入样例3:
2
AA
BB
3
AAABBB

输出样例3:
<censored>A<censored>B
输入样例4:
2
AB
BB
3
AAABBB

输出样例4:
AA<censored><censored>
输入样例5:
2
BB
AB
3
AAABBB

输出样例5:
AAA<censored>B
*/
//题解：

//整体思路：就是简单的查找替换
//难点：违禁词可能是另一个违禁词的字串，如果在查找时不做处理，在后期删除的时
// 候可能会出现把另一个违禁词的字串删掉的现象
//因此，需要在查找之前把需要代换的违禁词统一一下，在后期删除时才不会出错



#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, k, sum = 0;
    string wei[100], str;
    cin >> n; getchar();
    for (int i = 0; i < n; ++i)
    {
        //当时考虑了是不是违禁词有空格的问题，结果这两种输入方式都可以，所以和空格没关系
        //getline(cin,wei[i]);
        cin >> wei[i];
    }
    cin >> k; getchar();
    getline(cin, str);
    //查找违禁词
    for (int i = 0; i < n; ++i)
    {
        while (str.find(wei[i]) != -1)
        {
            sum++;
            str.replace(str.find(wei[i]), wei[i].size(), "_");
        }
    }
    if (sum < k)
    {
        //替换
        while (str.find("_") != -1)
        {
            str.replace(str.find("_"), 1, "<censored>");
        }
        cout << str << endl;
    }
    else
    {
        cout << sum << endl << "He Xie Ni Quan Jia!" << endl;
    }
}