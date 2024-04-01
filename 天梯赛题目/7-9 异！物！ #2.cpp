/*顶镇同学的房间里有个储物箱，他的储物箱有个特点，第一个物品只能放在箱子底部，
往后的物品都只能堆在前一个物品的上方，取一次物品时只能从储物箱的最上方取。今天
他想整理他的储物箱里面的东西（方便起见，用整数数字来替代这些物品）。他会把东西
拿出来，也会把已经拿出来的东西放进去，也会拿他充满芝士的雪豹机器人检测是否有异
物。检测到有异物的标准如下：

若此时储物箱内的数字的最大值超过了限定的最大值，则表明有异物。
你需要编写程序来模拟他整理东西时的情景。

输入格式:
第一行，两个整数，T(1≤T≤1×10^5),max(−2^60≤max≤2^60)，代表顶镇操作的次数和限
定的最大值。
接下来T行，每行给出一个操作，格式如下：

Put X，表示把一个整数X(−2^60≤X≤2^60)放入储物箱中；
Take，表示取一次物品；
Check，表示检测储物箱中是否有异物。
输出格式:
对输入中的每个操作，按照要求执行操作。对每个 Take，在一行中输出取出的数字；
对每个 Check，在一行中输出此刻储物箱中是否有异物，若有则输出YI WU!，否则输
出此时储物箱中所有数字的最大值。若执行 Take 或 Check 时储物箱是空的，则对应
输出 MaMaShengDe，并且不执行该操作。题目保证至少有一行输出。

输入样例:
10 25
Take
Put 11
Put 45
Check
Put 14
Check
Take
Check
Take
Take
输出样例:
MaMaShengDe
YI WU!
YI WU!
14
YI WU!
45
11
*/





#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int t, thing;
    int max, max2 = -pow(2, 60) - 1;
    stack<int> box, Max_box;
    string doing;
    cin >> t >> max;
    while (t--)
    {
        cin >> doing;
        if (doing == "Put")
        {
            cin >> thing;
            box.push(thing);
            if (thing > max2)
                max2 = thing;
            Max_box.push(max2);
        }
        if (doing == "Take")
        {
            if (!box.empty())
            {
                cout << box.top() << endl;
                box.pop();
                Max_box.pop();
                if (!Max_box.empty())
                    max2 = Max_box.top();
                else
                    max2 = -pow(2, 60) - 1;
            }
            else
            {
                cout << "MaMaShengDe" << endl;
            }
        }
        if (doing == "Check")
        {
            if (!box.empty())
            {
                if (Max_box.top() > max)
                    cout << "YI WU!" << endl;
                else
                    cout << Max_box.top() << endl;
            }
            else
                cout << "MaMaShengDe" << endl;
        }
    }
    return 0;
}