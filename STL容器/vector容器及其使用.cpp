#define _CRT_SECURE_NO_WARNINGS
/*
vector容器的一些操作：
v.push_back(k); 尾插元素；
v.insert(it, k); 在任意位置插入元素；
v.eraser(it, it + k); 删除任意元素；
v.size(); 容量；
v.clear(); 清空容器；
v.empty(); 判断容器是否为空；
reverse(v.begin(), v.end()); 反转任意段元素
sort(v.begin(), v.end()，cmp); sort排序默认由小到大, cmp可以自由规定排序规则。
*/

#include<iostream>
#include<vector>
using namespace std;
int main()
{
	//整形
	vector<int> vec;
	for (int i = 0; i < 5; ++i)
	{
		vec.push_back(i + 1);
	}
	//用vector迭代器遍历
	vector<int>::iterator it;
	for (it = vec.begin(); it != vec.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
	//用下标遍历
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
	//字符串型
	vector<string> text;
	text.push_back("hello");
	text.push_back("world");
	text.push_back("hehe");
	for (vector<string>::const_iterator iter = text.begin();

		iter != text.end(); ++iter)

		cout << *iter << endl;
	vec.clear();
}