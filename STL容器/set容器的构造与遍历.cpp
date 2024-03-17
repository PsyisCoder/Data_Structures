#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<set>
using namespace std;
int main()
{
	set<int> s1;//set容器是默认升序排序的
	s1.insert(3);
	s1.insert(1);
	s1.insert(7);
	s1.insert(5);
	s1.insert(8);
	set<int>::iterator it;
	for (it = s1.begin(); it != s1.end(); ++it)
		cout << *it << " ";
	cout << endl;
	set<int>::reverse_iterator it2;//反向迭代器是reverse_iterator
	for (it2 = s1.rbegin(); it2 != s1.rend(); ++it2)
		cout << *it2 << " ";
	cout << endl;

	set<int> s2(s1);//调用拷贝构造函数
	set<int> s3;	//调用默认构造函数
	s3 = s2;		//等于号的重载
	for (it = s3.begin(); it != s3.end(); ++it)
		cout << *it << " ";
	cout << endl;
	return 0;
}