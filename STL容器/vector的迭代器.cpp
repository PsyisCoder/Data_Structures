#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
/*begin和end函数
	◎每种容器都定义了一队命名为begin和end的函数,用于返回迭代器。如果容器中有元素	的话,由begin返回的元素指向第一个元素。
	vector<int>:iterator iter=v.begin();//若v不为空,iter指向v[0]
	由end返回的迭代器指向最后一个元素的下一个,若v为空,begin和end返回的相同	++iter;//使迭代器自增指向下一个元素
	== 和 != 操作符来比较两个迭代器,若两个迭代器指向同一个元素,则它们相等,否则不相	等*/
int main()
{
	vector<int> vecIntA;
	int arr[] = { 10,20,30,40,50 };
	vecIntA.assign(arr, arr + 5);
	//构造一个迭代器对象
	vector<int>::iterator it;
	//让迭代器it指向vecIntA的第一个元素
	it = vecIntA.begin();
	cout << *it << endl;
	//通过循环的方式使用迭代器遍历vecIntA中的所有元素
	for (it = vecIntA.begin(); it != vecIntA.end(); ++it)
		cout << *it <<" ";
	cout << endl;	

	return 0;
}