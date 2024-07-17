/*题目：https://www.luogu.com.cn/problem/P1168*/

//题解：每次插入再排序时间消耗太大，用二分法插入（upper_bound或者lower_bound）
// (前者是返回第一个大于val的地址，后者是返回第一个大于等于val的地址)
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
#define N 100005
vector<int>A;
int n;
int main()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		int x;
		cin >> x;
		A.insert(lower_bound(A.begin(), A.end(), x),x);//二分找出地址再插入
		if (i % 2 == 1)
		{
			cout << A[(A.size() - 1) >> 1] << endl;
		}
	}
}