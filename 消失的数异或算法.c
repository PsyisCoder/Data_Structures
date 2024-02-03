#define _CRT_SECURE_NO_WARNINGS
/*题目 : 数组nums包含从0到n的所有整数，但其中缺了一个。请编写代码找出那个缺失的整数.
示例 1：
输入 : [3, 0, 1]
输出 : 2
示例2 :
	输入：[9, 6, 4, 2, 3, 5, 7, 0, 1]
	输出 : 8*/
//用异或的算法解决：
//时间复杂度是O(N)  空间复杂度是O(1)
#include<stdio.h>
int missingNumber(int* nums, int numsSize)
{
	//可以理解成两个数组异或就会找出两个数组间的差异，也即是消失的数
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
	printf("输入：");
	int num[100] = { 0 };
	int size=0;
	scanf("%d", &size);
	for (int i = 0; i < size-1; ++i)
	{
		scanf("%d ", &num[i]);
	}
	printf("%d", missingNumber(num, size));
}