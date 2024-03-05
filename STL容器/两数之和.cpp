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

// 格式化输出
void Print_D(double& Ele)
{
	cout.width(5);			// 宽度5
	cout.precision(1);		// 保留1位小数
	cout << std::fixed << Ele << ", ";
}
void Print_I(int& Ele)
{
	cout << Ele << ",  ";
}

void main()
{
	//上定义双向队列
	list<string>mylist_string;
	list<double>mylist_double(6);

	//---------初始化mylist_string
	mylist_string.push_front("1:  Jack");
	mylist_string.push_front("2:  Tom");
	mylist_string.push_front("3:  Mike");

	//---------初始化mylist_double
	mylist_double.push_front(10.0);
	mylist_double.push_front(20.0);
	mylist_double.push_front(30.0);
	mylist_double.push_front(40.0);
	mylist_double.push_front(50.0);

	//下述是三种容器定义形式
	list<int> mylist_int(6, 0);			// 6个0：0 0 0 0 0 0
	list<double>mylist_double2(6, 0.0);	// 6个0.0：0.0 0.0 0.0 0.0 0.0 0.0
	list<int>elselist(mylist_int);		// 以其它双向队列初始化
	list<double>Iterlist(mylist_double.begin(), mylist_double.end());	// 以其他队列初始化

	//----输出各个容器中的元素
	cout << "打印 mylist_string:" << endl;
	list<string>::iterator iter_String;	// 迭代器
	for (iter_String = mylist_string.begin(); iter_String != mylist_string.end(); iter_String++)
	{
		string temp = *iter_String;
		print(temp);
	}
	cout << "打印 mylist_double:" << endl;
	for_each(mylist_double.begin(), mylist_double.end(), Print_D);
	cout << endl;


	cout << "打印 mylist_double2:" << endl;
	for_each(mylist_double2.begin(), mylist_double2.end(), Print_D);
	cout << endl;

	cout << "打印 Iterlist:" << endl;
	for_each(Iterlist.begin(), Iterlist.end(), Print_D);
	cout << endl;

	cout << "打印 mylist_int:" << endl;
	for_each(mylist_int.begin(), mylist_int.end(), Print_I);
	cout << endl;

	cout << "打印 elselist:" << endl;
	for_each(elselist.begin(), elselist.end(), Print_I);
	cout << endl;

	//各容器的容量
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

	//----再次输出各个容器中的元素
	cout << "打印 mylist_string:" << endl;
	for (iter_String = mylist_string.begin(); iter_String != mylist_string.end(); iter_String++)
	{
		string temp = *iter_String;
		print(temp);
	}
	cout << "打印 mylist_double:" << endl;
	for_each(mylist_double.begin(), mylist_double.end(), Print_D);
	cout << endl;

	cout << "打印 mylist_double2:" << endl;
	for_each(mylist_double2.begin(), mylist_double2.end(), Print_D);
	cout << endl;

	cout << "打印 Iterlist:" << endl;
	for_each(Iterlist.begin(), Iterlist.end(), Print_D);
	cout << endl;

	cout << "打印 mylist_int:" << endl;
	for_each(mylist_int.begin(), mylist_int.end(), Print_I);
	cout << endl;

	cout << "打印 elselist:" << endl;
	for_each(elselist.begin(), elselist.end(), Print_I);
	cout << endl;


	//使用迭代器相关的函数
	list<double>::iterator Iter_D;
	list<double>::reverse_iterator Iter_rD;
	cout << "打印 mylist_double 所有元素：" << endl;
	for_each(mylist_double.begin(), mylist_double.end(), Print_D);
	cout << endl;

	double tmp = 0.0;
	Iter_D = mylist_double.begin();
	tmp = *Iter_D;
	cout << "打印 mylist_double 的 begin:" << endl;
	cout << tmp << endl;

	Iter_rD = mylist_double.rbegin();
	tmp = *Iter_rD;
	cout << "\r\n打印 mylist_double 的 rbegin:" << endl;
	cout << tmp << endl;

	Iter_D = mylist_double.end();
	Iter_D--; // 必须--，end为指向最后一个元素所在位置后一个位置
	tmp = *Iter_D;
	cout << "打印 mylist_double 的 end:" << endl;
	cout << tmp << endl;

	Iter_rD = mylist_double.rend();
	Iter_rD--; // 必须--，rend为指向第一个元素所在位置前一个位置
	tmp = *Iter_rD;
	cout << "打印 mylist_double 的 rend:" << endl;
	cout << tmp << endl;

	tmp = mylist_double.front();
	cout << "打印 mylist_double 的 front:" << endl;
	cout << tmp << endl; //
	//cout<<mylist_double.front()<<endl;

	tmp = mylist_double.back();
	cout << "打印 mylist_double 的 back:" << endl;
	cout << tmp << endl;
}

