//题目：给你一个单链表的头节点 head ，请你判断该链表是否为回文链表
// 如果是，返回 true ；否则，返回 false 

//解:用栈解决






/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef int STDatatype;
typedef struct Stack
{
	STDatatype* arr;
	int top;
	int capacity;
}ST;

void StackInit(ST* ps);
void StackDestroy(ST* ps);
void StackPush(ST* ps, STDatatype x);
void StackPop(ST* ps);
STDatatype StackTop(ST* ps);
int StackSize(ST* ps);
bool StackEmpty(ST* ps);


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

bool isPalindrome(struct ListNode* head) {
	ST st;
	StackInit(&st);
	struct ListNode* cur = head;
	while (cur)
	{
		StackPush(&st, cur->val);
		cur = cur->next;
	}
	cur = head;
	while (!StackEmpty(&st))
	{
		if (cur->val != StackTop(&st))
		{
			return false;
		}
		else
		{
			StackPop(&st);
			cur = cur->next;
		}
	}
	return true;
}