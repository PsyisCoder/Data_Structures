/*�����Ҫ��ܼ򵥣�������N�����ֵĺ͡��鷳���ǣ���Щ������������������/��ĸ
����ʽ�����ģ�������ĺ�Ҳ����������������ʽ��

�����ʽ��
�����һ�и���һ��������N����100�������һ�а���ʽa1/b1 a2/b2 ...����N������
������Ŀ��֤���з��Ӻͷ�ĸ���ڳ����ͷ�Χ�ڡ����⣬�����ķ���һ�������ڷ���ǰ�档

�����ʽ��
����������ֺ͵������ʽ ���� �������д���������� �������֣����з�������д��
����/��ĸ��Ҫ�����С�ڷ�ĸ��������û�й����ӡ�����������������Ϊ0����ֻ��
���������֡�

��������1��
5
2/5 4/15 1/30 -2/60 8/3
�������1��
3 1/3
��������2��
2
4/3 2/3
�������2��
2
��������3��
3
1/3 -1/6 1/8
�������3��
7/24
*/





#include<iostream>
using namespace std;
long long int gcd(long long int a, long long int b)
{
    return b ? gcd(b, a % b) : a;
}
int main()
{
    long long int n;
    cin >> n;
    long long int fenz = 0, fenm = 1, a, b, t;
    for (int i = 0; i < n; ++i)
    {
        scanf("%lld/%lld", &a, &b);

        fenz *= b;
        fenz += a * fenm;
        fenm *= b;
        t = gcd(fenz, fenm);
        fenz /= t;
        fenm /= t;
    }
    if (fenz % fenm == 0)
    {
        cout << fenz / fenm;
    }
    else if (fenz < fenm)
        cout << fenz << "/" << fenm;
    else
    {
        cout << fenz / fenm << " " << fenz % fenm << "/" << fenm;
    }
}