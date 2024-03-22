#define _CRT_SECURE_NO_WARNINGS

/*题目：gg有一个超市，超市里有2个员工，分别是送货的小a、摆货的小b，
超市有大厅和仓库。大厅里有个货架，货架只有一个口，可以放商品或者取商品；
仓库里有条传送带，会把放入前门的货品运送到后门。小a的工作是每天早上把
商品一个一个的送到仓库前门；小b的工作是每天早上把商品从仓库后门一个一个
的取出放到大厅的货架上，一般来说，都会把新取的货品放到货架最底层，
可是小b很懒，每次都把商品放到最前面；超市每天都有顾客来购物。
gg偶尔会在一天的营业结束后来超市抽查货品，如果发现货架上的第一个
商品是三天前进货的，gg会发怒，并把货架清空。

输入格式:
在第一行给出n（n<=100），代表总天数，接下来n行为每天发生的事情。

每行第一个数字代表第几天，题目保证天数依次有序

每行第二个数字代表小a今天得进货数量，范围0~1000

每行第三个数字代表小b今天往货架上放货得数量，范围0~1000

每行第四个数字代表顾客今天买走了多少商品，范围0~1000

每行第五个数字代表gg今天来了没有，1代表来了，0代表没来

数字间以空格分隔

数据不保证小b得取货量<=仓库剩余量，货架剩余量<=估计购买量

输出格式:
如果某天gg抽查时发怒了，则输出天数后加一串字符串"Wang!Wang!!Wang!!!"。

例：gg在第三天抽查时发怒了，则输出“3 Wang!Wang!!Wang!!!”.

输入样例:
在这里给出一组输入。例如：

5
1 10 4 3 0
2 10 4 4 0
3 0 5 5 0
4 0 1 1 1
5 0 0 0 0
输出样例:
在这里给出相应的输出。例如：

4 Wang!Wang!!Wang!!!*/


//题解：用队列和栈，注意判断栈和队列是否为空
#include<iostream>
#include<string>
#include<stack>
#include<queue>
using namespace std;
int main()
{
    int n;
    cin >> n;
    stack<int> hjia;
    queue<int> cku;
    int day, jin, chu, buy, come;
    while (n)
    {
        cin >> day >> jin >> chu >> buy >> come;
        while (jin)
        {
            cku.push(day);
            --jin;
        }
        while (chu && !cku.empty())
        {
            hjia.push(cku.front());
            cku.pop();
            --chu;
        }
        while (buy && !hjia.empty())
        {
            hjia.pop();
            --buy;
        }
        if (come == 1 && !hjia.empty())
        {
            //先要判断它非空才能相减，不然会发生段错误！！！！！！！
            if (day - hjia.top() >= 3)
            {
                cout << day << " Wang!Wang!!Wang!!!" << endl;
                while (!hjia.empty())
                {
                    hjia.pop();
                }
            }
        }
        --n;
    }
}