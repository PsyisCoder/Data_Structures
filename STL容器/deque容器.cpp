#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<deque>
//deque ��˫�����飬������vector���ƣ�ͷ������Ч�ʸߣ�
// ����Ч�ʵͣ���Ϊ�ռ䲻������Ҫ��[]������������أ�
using namespace std;
int main()
{
	deque<int> d = { 10,20,30,40 };

	//��ͷ������һ��100
	d.push_front(100);
	deque<int>::iterator it;
	for (it = d.begin(); it != d.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	//ɾ��ͷ��Ԫ��
	d.pop_front();
	for (it = d.begin(); it != d.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
	return 0;
}