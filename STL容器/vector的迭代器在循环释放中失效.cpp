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
	vector<int> cond = { 1,2,3,3,3,3,4,5,6 };
	vector<int>::iterator it;
	for (it = cond.begin(); it != cond.end(); )
	{
		if (*it == 3)
			it=cond.erase(it);

			//cond.erase(it);
			/*��������erase������
			û�н�ѭ������iָ���޸ĺ���������������ͼ���ѭ����
			����end()�Ƚ�ʱ���Գ��֡�*/
		else
			++it;
	}

	for (it = cond.begin(); it != cond.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}