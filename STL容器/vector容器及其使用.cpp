#define _CRT_SECURE_NO_WARNINGS
/*
vector������һЩ������
v.push_back(k); β��Ԫ�أ�
v.insert(it, k); ������λ�ò���Ԫ�أ�
v.eraser(it, it + k); ɾ������Ԫ�أ�
v.size(); ������
v.clear(); ���������
v.empty(); �ж������Ƿ�Ϊ�գ�
reverse(v.begin(), v.end()); ��ת�����Ԫ��
sort(v.begin(), v.end()��cmp); sort����Ĭ����С����, cmp�������ɹ涨�������
*/

#include<iostream>
#include<vector>
using namespace std;
int main()
{
	//����
	vector<int> vec;
	for (int i = 0; i < 5; ++i)
	{
		vec.push_back(i + 1);
	}
	//��vector����������
	vector<int>::iterator it;
	for (it = vec.begin(); it != vec.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
	//���±����
	for (vector<int>::size_type ix=0; ix <vec.size(); ++ix)
	{
		vec[ix] = 0;
	}
	for (vector<int>::size_type ix = 0; ix < vec.size(); ++ix)
	{
		cout << vec[ix] << " ";
	}
	cout << endl;
	cout << vec.size();
	//�ַ�����
	vector<string> text;
	text.push_back("hello");
	text.push_back("world");
	text.push_back("hehe");
	for (vector<string>::const_iterator iter = text.begin();

		iter != text.end(); ++iter)

		cout << *iter << endl;
	vec.clear();
}