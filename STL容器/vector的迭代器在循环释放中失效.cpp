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
	vector<int> cond = { 1,2,3,3,3,3,4,5,6 };
	vector<int>::iterator it;
	for (it = cond.begin(); it != cond.end(); )
	{
		if (*it == 3)
			it=cond.erase(it);

			//cond.erase(it);
			/*迭代器在erase操作后，
			没有将循环变量i指向修改后的向量迭代器，就继续循环，
			再与end()比较时断言出现。*/
		else
			++it;
	}

	for (it = cond.begin(); it != cond.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}