#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
/*begin��end����
	��ÿ��������������һ������Ϊbegin��end�ĺ���,���ڷ��ص������������������Ԫ��	�Ļ�,��begin���ص�Ԫ��ָ���һ��Ԫ�ء�
	vector<int>:iterator iter=v.begin();//��v��Ϊ��,iterָ��v[0]
	��end���صĵ�����ָ�����һ��Ԫ�ص���һ��,��vΪ��,begin��end���ص���ͬ	++iter;//ʹ����������ָ����һ��Ԫ��
	== �� != ���������Ƚ�����������,������������ָ��ͬһ��Ԫ��,���������,������	��*/
int main()
{
	vector<int> vecIntA;
	int arr[] = { 10,20,30,40,50 };
	vecIntA.assign(arr, arr + 5);
	//����һ������������
	vector<int>::iterator it;
	//�õ�����itָ��vecIntA�ĵ�һ��Ԫ��
	it = vecIntA.begin();
	cout << *it << endl;
	//ͨ��ѭ���ķ�ʽʹ�õ���������vecIntA�е�����Ԫ��
	for (it = vecIntA.begin(); it != vecIntA.end(); ++it)
		cout << *it <<" ";
	cout << endl;	

	return 0;
}