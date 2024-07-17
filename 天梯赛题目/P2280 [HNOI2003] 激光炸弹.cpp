/*题目：https://www.luogu.com.cn/problem/P2280*/




//题解：使用二维前缀和与差分法
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define N 5005
using namespace std;
int n, m, ans;
int sum[N][N];
int main()
{
	cin >> n >> m;
	int x, y, v;
	for (int i = 1; i <= n; ++i)
	{
		cin >> x >> y >> v;
		sum[x+1][y+1] = v;
	}
	for (int i = 1; i <= 5000; ++i)
		for (int j = 1; j <= 5000; ++j)
			sum[i][j] += (sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1]);
	for (int i = m; i <= 5000; ++i)
		for (int j = m; j <= 5000; ++j)
			ans = max(ans, sum[i][j] - sum[i][j - m] - sum[i - m][j] + sum[i - m][j - m]);
	cout << ans;
}