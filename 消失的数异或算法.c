#define _CRT_SECURE_NO_WARNINGS
/*��Ŀ : ����nums������0��n������������������ȱ��һ�������д�����ҳ��Ǹ�ȱʧ������.
ʾ�� 1��
���� : [3, 0, 1]
��� : 2
ʾ��2 :
	���룺[9, 6, 4, 2, 3, 5, 7, 0, 1]
	��� : 8*/
//�������㷨�����
//ʱ�临�Ӷ���O(N)  �ռ临�Ӷ���O(1)
#include<stdio.h>
int missingNumber(int* nums, int numsSize)
{
	//�������������������ͻ��ҳ����������Ĳ��죬Ҳ������ʧ����
	int ret = 0;
	for (int i = 0; i <= numsSize; ++i)
	{
		ret ^= i;	
	}
	for (int i = 0; i < numsSize; ++i)
	{
		ret ^= nums[i];
	}
	return ret;
}
int main()
{
	printf("���룺");
	int num[100] = { 0 };
	int size=0;
	scanf("%d", &size);
	for (int i = 0; i < size-1; ++i)
	{
		scanf("%d ", &num[i]);
	}
	printf("%d", missingNumber(num, size));
}