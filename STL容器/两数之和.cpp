#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4786)
#include <iostream>
#include <list>
#include <algorithm>
#include <string>
//#include <iomanip.h>

using namespace std;

template <class T>void print(const T& Ele)
{
	cout << " " << Ele << ";" << endl;
}

// ��ʽ�����
void Print_D(double& Ele)
{
	cout.width(5);			// ���5
	cout.precision(1);		// ����1λС��
	cout << std::fixed << Ele << ", ";
}
void Print_I(int& Ele)
{
	cout << Ele << ",  ";
}

void main()
{
	//�϶���˫�����
	list<string>mylist_string;
	list<double>mylist_double(6);

	//---------��ʼ��mylist_string
	mylist_string.push_front("1:  Jack");
	mylist_string.push_front("2:  Tom");
	mylist_string.push_front("3:  Mike");

	//---------��ʼ��mylist_double
	mylist_double.push_front(10.0);
	mylist_double.push_front(20.0);
	mylist_double.push_front(30.0);
	mylist_double.push_front(40.0);
	mylist_double.push_front(50.0);

	//��������������������ʽ
	list<int> mylist_int(6, 0);			// 6��0��0 0 0 0 0 0
	list<double>mylist_double2(6, 0.0);	// 6��0.0��0.0 0.0 0.0 0.0 0.0 0.0
	list<int>elselist(mylist_int);		// ������˫����г�ʼ��
	list<double>Iterlist(mylist_double.begin(), mylist_double.end());	// ���������г�ʼ��

	//----������������е�Ԫ��
	cout << "��ӡ mylist_string:" << endl;
	list<string>::iterator iter_String;	// ������
	for (iter_String = mylist_string.begin(); iter_String != mylist_string.end(); iter_String++)
	{
		string temp = *iter_String;
		print(temp);
	}
	cout << "��ӡ mylist_double:" << endl;
	for_each(mylist_double.begin(), mylist_double.end(), Print_D);
	cout << endl;


	cout << "��ӡ mylist_double2:" << endl;
	for_each(mylist_double2.begin(), mylist_double2.end(), Print_D);
	cout << endl;

	cout << "��ӡ Iterlist:" << endl;
	for_each(Iterlist.begin(), Iterlist.end(), Print_D);
	cout << endl;

	cout << "��ӡ mylist_int:" << endl;
	for_each(mylist_int.begin(), mylist_int.end(), Print_I);
	cout << endl;

	cout << "��ӡ elselist:" << endl;
	for_each(elselist.begin(), elselist.end(), Print_I);
	cout << endl;

	//������������
	int size = mylist_string.size();
	int maxsize = mylist_string.size();
	mylist_string.resize(5);

	size = mylist_double.size();
	maxsize = mylist_double.max_size();
	mylist_double.resize(5);

	size = mylist_double2.size();
	maxsize = mylist_double2.max_size();
	mylist_double2.resize(5);

	size = Iterlist.size();
	maxsize = Iterlist.max_size();
	Iterlist.resize(5);

	size = mylist_int.size();
	maxsize = mylist_int.max_size();
	mylist_int.resize(5);

	size = elselist.size();
	maxsize = elselist.max_size();
	elselist.resize(5);

	//----�ٴ�������������е�Ԫ��
	cout << "��ӡ mylist_string:" << endl;
	for (iter_String = mylist_string.begin(); iter_String != mylist_string.end(); iter_String++)
	{
		string temp = *iter_String;
		print(temp);
	}
	cout << "��ӡ mylist_double:" << endl;
	for_each(mylist_double.begin(), mylist_double.end(), Print_D);
	cout << endl;

	cout << "��ӡ mylist_double2:" << endl;
	for_each(mylist_double2.begin(), mylist_double2.end(), Print_D);
	cout << endl;

	cout << "��ӡ Iterlist:" << endl;
	for_each(Iterlist.begin(), Iterlist.end(), Print_D);
	cout << endl;

	cout << "��ӡ mylist_int:" << endl;
	for_each(mylist_int.begin(), mylist_int.end(), Print_I);
	cout << endl;

	cout << "��ӡ elselist:" << endl;
	for_each(elselist.begin(), elselist.end(), Print_I);
	cout << endl;


	//ʹ�õ�������صĺ���
	list<double>::iterator Iter_D;
	list<double>::reverse_iterator Iter_rD;
	cout << "��ӡ mylist_double ����Ԫ�أ�" << endl;
	for_each(mylist_double.begin(), mylist_double.end(), Print_D);
	cout << endl;

	double tmp = 0.0;
	Iter_D = mylist_double.begin();
	tmp = *Iter_D;
	cout << "��ӡ mylist_double �� begin:" << endl;
	cout << tmp << endl;

	Iter_rD = mylist_double.rbegin();
	tmp = *Iter_rD;
	cout << "\r\n��ӡ mylist_double �� rbegin:" << endl;
	cout << tmp << endl;

	Iter_D = mylist_double.end();
	Iter_D--; // ����--��endΪָ�����һ��Ԫ������λ�ú�һ��λ��
	tmp = *Iter_D;
	cout << "��ӡ mylist_double �� end:" << endl;
	cout << tmp << endl;

	Iter_rD = mylist_double.rend();
	Iter_rD--; // ����--��rendΪָ���һ��Ԫ������λ��ǰһ��λ��
	tmp = *Iter_rD;
	cout << "��ӡ mylist_double �� rend:" << endl;
	cout << tmp << endl;

	tmp = mylist_double.front();
	cout << "��ӡ mylist_double �� front:" << endl;
	cout << tmp << endl; //
	//cout<<mylist_double.front()<<endl;

	tmp = mylist_double.back();
	cout << "��ӡ mylist_double �� back:" << endl;
	cout << tmp << endl;
}

