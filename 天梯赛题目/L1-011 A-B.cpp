/*本题要求你计算A−B。不过麻烦的是，A和B都是字符串 —— 即从字符串A中把字符串B
所包含的字符全删掉，剩下的字符组成的就是字符串A−B。

输入格式：
输入在2行中先后给出字符串A和B。两字符串的长度都不超过10 
4
 ，并且保证每个字符串都是由可见的ASCII码和空白字符组成，最后以换行符结束。

输出格式：
在一行中打印出A−B的结果字符串。

输入样例：
I love GPLT!  It's a fun game!
aeiou
输出样例：
I lv GPLT!  It's  fn gm!
*/






//题解：可以使用remove与erase来解决此问题
//remove返回一个迭代器同时返回一个迭代器。
// 在该迭代器之前的所有元素，保留原容器的顺序，
// 并且不存在被删除的元素，而该迭代器到容器的末尾则不变。

#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a, b;
    getline(cin, a);
    getline(cin, b);
    for (int i = 0; i < b.size(); ++i)
    {
        a.erase(remove(a.begin(), a.end(), b[i]), a.end());
    }
    cout << a;
}