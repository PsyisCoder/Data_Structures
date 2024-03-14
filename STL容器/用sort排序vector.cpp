#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main()
{
    int arr1[] = { 7,6,5,4,3,2,1 };
    vector<int> arr2;
    arr2.assign(arr1, arr1 + 7);
    vector<int>::iterator it;
    for (it = arr2.begin(); it != arr2.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
    sort(arr2.begin(),arr2.end());
    for (it = arr2.begin(); it != arr2.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}