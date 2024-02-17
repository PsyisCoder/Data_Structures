#include"Stack.h"
void StackInit(ST* ps)
{
	assert(ps);
	ps->arr = NULL;
	ps->capacity = 0;
	ps->top = -1;
}
void StackDestroy(ST* ps)
{
	assert(ps);
	free(ps->arr);
	ps->arr = NULL;
	ps->capacity = 0;
	ps->top = -1;
}
void StackPush(ST* ps, STDatatype x)
{
	assert(ps);
	if ((ps->top) + 1 == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : (ps->capacity) * 2;
		ST* tmp = (ST*)realloc(ps->arr, sizeof(ST) * newcapacity);
		if (!tmp)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		ps->arr = tmp;
		ps->capacity = newcapacity;
	}
	ps->top++;
	ps->arr[ps->top] = x;
}
void StackPop(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	ps->top--;
}
STDatatype StackTop(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	return ps->arr[ps->top];
}
int StackSize(ST* ps)
{
	assert(ps);
	return (ps->top) + 1;
}
bool StackEmpty(ST* ps)
{
	assert(ps);
	/*if (ps->top == -1)
		return true;
	else
		return false;*/
	return ps->top == -1;
}