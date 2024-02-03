#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stddef.h>
//斐波那契数列的时间复杂度是O(2^N)
//斐波那契数列的递归写法完全一个实际没用的算法，因为太慢了
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