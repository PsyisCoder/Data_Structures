#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<deque>
//deque 是双端数组，操作与vector类似，头部插入效率高，
// 遍历效率低（因为空间不连续，要对[]运算符进行重载）
using namespace std;
int main()
{
	deque<int> d = { 10,20,30,40 };

	//在头部插入一个100
	d.push_front(100);
	deque<int>::iterator it;
	for (it = d.begin(); it != d.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	//删除头部元素
	d.pop_front();
	for (it = d.begin(); it != d.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
	return 0;
}