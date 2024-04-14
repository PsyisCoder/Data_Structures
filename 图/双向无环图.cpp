/*
9
2 1
1 3
1 4
1 9
2 8
2 10
2 6
3 7
3 5
*/
#include<iostream>
#include<vector>
using namespace std;
vector<int> Map[10000];
void DFS(int now, int last)
{
	for (int i = 0; i < Map[now].size(); ++i)
	{
		//由于它是双向无环图，因此除了向下找还可能向上寻找，因此：Map[now][i] != last
		if (last == -1 || Map[now][i] != last)
		{
			cout << last << " " << Map[now][i] << endl;
			DFS(Map[now][i], now);
		}
	}
}
int main()
{
	int n;
	cin >> n;
	for(int i=1;i<=n;++i)
	{
		int a, b;
		cin >> a >> b;
		//代表了它是双向无环图
		Map[a].push_back(b);
		Map[b].push_back(a);
	}
	DFS(1, -1);
}