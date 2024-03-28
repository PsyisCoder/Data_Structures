#include<iostream>
#include<vector>
#include<stack>
#include<cmath>
using namespace std;
int main()
{
    vector<string> digit;
    digit.push_back("ling");
    digit.push_back("yi");
    digit.push_back("er");
    digit.push_back("san");
    digit.push_back("si");
    digit.push_back("wu");
    digit.push_back("liu");
    digit.push_back("qi");
    digit.push_back("ba");
    digit.push_back("jiu");
    int n;
    cin >> n;
    if (n < 0)
    {
        cout << "fu"; n = -n;
    }
    stack<int> num;
    while (n % 10 != 0)
    {
        num.push(n % 10);
        n /= 10;
    }
    while (!num.empty())
    {
        cout << " " << digit[num.top()];
        num.pop();
    }
}