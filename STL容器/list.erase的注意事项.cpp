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
    //ɾ��lst�������ֵΪ����Ԫ��
    for (list<int>::iterator it = lst.begin(); it != lst.end();)
    {
        if (*it == 3)
        {
            it = lst.erase(it);//ɾ�������¸���������ֵ
        }
        else
            ++it;//���û��ɾ�������������������ɾ���ˣ��������ͱ����Ұָ�룬�����������
    }
    for (list<int>::iterator it = lst.begin(); it != lst.end();++it)
    {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}