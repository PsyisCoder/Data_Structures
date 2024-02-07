#include"SList.h"
SLTNode* BuySListNode(SLTDataType x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (!newnode)
	{
		printf("malloc fail\n");
		exit(-1);//如果失败退出
	}
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}
void SListPrint(SLTNode* phead)
{
	SLTNode* cur = phead;
	while (cur)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}
void SListPushBack(SList* pphead, SLTDataType x)
{
	assert(pphead);//检查传入的二级指针是否为空，以防外一，容易查错
	SLTNode* newnode = BuySListNode(x);
	if (*pphead == NULL)//如果是空表要单独处理，并且不能直接把tmp接到newnode，
	                    //因为tmp和*pphead本质上不一样，但是访问到的数据是一样的
	{
		*pphead = newnode;
	}
	else
	{
		SLTNode* tmp = *pphead;
		while (tmp->next)
		{
			tmp = tmp->next;
		}
		tmp->next = newnode;
	}
}
void SListPushFront(SList* pphead, SLTDataType x)
{
	assert(pphead);//检查传入的二级指针是否为空，以防外一，容易查错
	SLTNode* newnode = BuySListNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}
void SListPopFront(SList* pphead)
{
	assert(pphead);//检查传入的二级指针是否为空，以防外一，容易查错
	assert(*pphead != NULL);
	SLTNode* tmp = (*pphead)->next;
	free(*pphead);
	*pphead = tmp;
}
void SListPopBack(SList* pphead)
{
	assert(pphead);//检查传入的二级指针是否为空，以防外一，容易查错
	assert(*pphead != NULL);
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead=NULL;
	}
	else
	{
		SLTNode* tmp = (*pphead);
		SLTNode* prev = NULL;
		while (tmp->next)
		{
			prev = tmp;
			tmp = tmp->next;
		}
		free(tmp);
		tmp = NULL;
		prev->next = NULL;
	}
}


SLTNode* SListFind(SList phead, SLTDataType x)
{
	SLTNode* cur = phead;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		else
		{
			cur = cur->next;
		}
	}
	return NULL;
}

void SListInsertAfter(SLTNode* pos, SLTDataType x)
{
	assert(pos);//一定不为空的就可以加断言
	SLTNode* newnode = BuySListNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

void SListInsert(SList* pphead, SLTNode* pos, SLTDataType x)
{
	assert(pphead);//检查传入的二级指针是否为空，以防外一，容易查错
	assert(pos);//一定不为空的就可以加断言
	SLTNode* newnode = BuySListNode(x);
	if (*pphead == pos)
	{
		*pphead = newnode;
		newnode->next = pos;
	}
	SLTNode* tmp = *pphead;
	while (tmp->next!=pos)
	{
		tmp = tmp->next;
	}
	tmp->next = newnode;
	newnode->next = pos;
}

void SListErase(SList* pphead, SLTNode* pos)
{
	assert(pphead);//检查传入的二级指针是否为空，以防外一，容易查错
	assert(pos);//一定不为空的就可以加断言
	if (*pphead == pos)
	{
		*pphead = (*pphead)->next;
		free(pos);
		pos = NULL;
		//也可以直接调用头删
		//SListPopFront(pphead);
	}
	else
	{
		SLTNode* tmp = *pphead;
		while (tmp->next != pos)
		{
			tmp = tmp->next;
		}
		tmp->next = pos->next;
		free(pos);
		pos = NULL;
	}
}

void SListEraseAfter(SLTNode* pos)
{
	assert(pos);//一定不为空的就可以加断言
	assert(pos->next);//如果是最后一个，这个接口就不能使用
	SLTNode* next = pos->next;
	pos->next = next->next;
	free(next);
}

void SListDestroy(SList* pphead)
{
	assert(pphead);//检查传入的二级指针是否为空，以防外一，容易查错
	SLTNode* tmp = *pphead;
	SLTNode* tmp2 = NULL;
	while (tmp)
	{
		tmp2 = tmp->next;
		free(tmp);
		tmp = tmp2;
	}
	*pphead = NULL;//需要把头指针置空，因为它是传址，会改变实参
}