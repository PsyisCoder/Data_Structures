#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>

using namespace std;

int main()
{
    string str;
    getline(cin, str);                 // ɾ��������λ�� 5 ��ʼ�� 6 ���ַ�
    cout << "str Ϊ��" << str << endl;
    if (!str.empty())
        cout << "�ַ����ǿ�";
    string str2("hehehehe");
    str2.swap(str);
    cout << str << endl;

    return 0;
}