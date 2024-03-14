#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <list>
#include<algorithm>
using namespace std;

int main()
{
    int arr[] = {1,2,3,4,5,6,3,3,5,3};
    list<int> lst;
    lst.assign(arr, arr + 10);
    //删除lst里的所有值为三的元素
    for (list<int>::iterator it = lst.begin(); it != lst.end();)
    {
        if (*it == 3)
        {
            it = lst.erase(it);//删除后重新给迭代器赋值
        }
        else
            ++it;//如果没有删除，则迭代器自增，若删除了，迭代器就变成了野指针，自增会出问题
    }
    for (list<int>::iterator it = lst.begin(); it != lst.end();++it)
    {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}