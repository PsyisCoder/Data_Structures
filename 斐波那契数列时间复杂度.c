#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stddef.h>
//쳲��������е�ʱ�临�Ӷ���O(2^N)
//쳲��������еĵݹ�д����ȫһ��ʵ��û�õ��㷨����Ϊ̫����
long long Fib(size_t N)
{
	if (N < 3)
		return 1;
	return Fib(N - 1) + Fib(N - 2);
}
int main()
{
	printf("%lld", Fib(40));
	return 0;
}