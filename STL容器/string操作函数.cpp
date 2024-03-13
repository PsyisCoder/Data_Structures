#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>

using namespace std;

int main()
{
    string str;
    getline(cin, str);                 // 删除从索引位置 5 开始的 6 个字符
    cout << "str 为：" << str << endl;
    if (!str.empty())
        cout << "字符串非空";
    string str2("hehehehe");
    str2.swap(str);
    cout << str << endl;

    return 0;
}