/*# 刺杀大使

## 题目描述

某组织正在策划一起对某大使的刺杀行动。他们来到了使馆，准备完成此次刺杀，要进入使馆首先必须通过使馆前的防御迷阵。

迷阵由 n*m 个相同的小房间组成，每个房间与相邻四个房间之间有门可通行。在第 n 行的 m 个房间里有 
m 个机关，这些机关必须全部打开才可以进入大使馆。而第 1 行的 m 个房间有 m 扇向外打开的门，是迷阵的入口。
除了第 1 行和第 n 行的房间外，每个房间都被使馆的安保人员安装了激光杀伤装置，将会对进入房间的人造成一定的伤害。
第 i 行第 j 列 造成的伤害值为 pi,pj（第 1 行和第 n 行的 p 值全部为 0）。

现在某组织打算以最小伤害代价进入迷阵，打开全部机关，显然，他们可以选 择任意多的人从任意的门进入，但必须到达第 n
行的每个房间。一个士兵受到的伤害值为他到达某个机关的路径上所有房间的伤害值中的最大值，整个部队受到的伤害值为所有
士兵的伤害值中的最大值。现在，这个恐怖组织掌握了迷阵的情况，他们需要提前知道怎么安排士兵的行进路线可以使得整个部队
的伤害值最小。

## 输入格式

第一行有两个整数 n,m，表示迷阵的大小。

接下来 n 行，每行 m 个数，第 i 行第 j 列的数表示 pi,pj。

## 输出格式

输出一个数，表示最小伤害代价。

## 样例 #1

### 样例输入 #1

```
4 2
0 0 
3 5 
2 4 
0 0
```

### 样例输出 #1

```
3
```

## 提示

- 50% 的数据，n,m <= 100；
- 100% 的数据，n,m <= 1000$，pi,pj <= 1000。*/



/*解题思路
解法1：二分答案+BFS
1.求最大值的最小值对于出现这种要求的题目，应该首先考虑能否用二分答案进行求解，因为这是二分答案的典型用法。
2.分析题目意思：找出从第一行到第n行的一条路径，使得经过的点的最大值最小；
3.这样我们就可以把二分答案的mid值作为BFS的一个条件，判断是否到达第n行；如果可以，说明此时mid值>=ans，
往左边([l,mid])搜索，否则搜索[mid+1,r]；                        */
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int p[1000][1000];
int n, m;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
bool bfs(int maxnum)
{
	//判断最大值为maxnum的能否通过
	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));
	bool vid[1000][1000];
	memset(vid, 0, sizeof(vid));
	vid[0][0] = 1;
	while (!q.empty())
	{
		pair<int, int> temp = q.front();
		q.pop();
		int x = temp.first;
		int y = temp.second;
		if (x == n - 1)
		{
			return true;
		}
		for (int i = 0; i < 4; ++i)
		{
			int fx = x + dx[i];
			int fy = y + dy[i];
			if (fx<0 || fx>n - 1 || fy<0 || fy>m - 1 || p[fx][fy] > maxnum) continue;
			if (!vid[fx][fy])
			{
				vid[fx][fy] = 1;
				q.push(make_pair(fx, fy));
			}
		}
	}
	return false;
}
int main()
{
	cin >> n >> m;
	int l = 1000, r = 0,ans;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> p[i][j];
			if (i != 0 && i != n - 1)
			{
				l = min(l, p[i][j]);
				r = max(r, p[i][j]);
			}
		}
	}
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		if (bfs(mid))
		{
			ans = mid;
			r = mid-1;
		}
		else
		{
			l = mid + 1;
		}
	}
	cout << ans;
}