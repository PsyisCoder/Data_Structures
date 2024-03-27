#include<iostream>
using namespace std;
struct people
{
    int id, n1, n2;
};
int main()
{
    int n;
    cin >> n;
    struct people std[1001];
    for (int i = 0; i < n; ++i)
    {
        cin >> std[i].id >> std[i].n1 >> std[i].n2;
    }
    int m;
    int cha;
    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        cin >> cha;
        for (int j = 0; j < n; ++j)
        {
            if (cha == std[j].n1)
                cout << std[j].id << " " << std[j].n2 << endl;
        }
    }
    return 0;
}