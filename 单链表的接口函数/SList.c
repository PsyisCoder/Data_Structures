#include"SList.h"
SLTNode* BuySListNode(SLTDataType x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (!newnode)
	{
		printf("malloc fail\n");
		exit(-1);//���ʧ���˳�
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
	assert(pphead);//��鴫��Ķ���ָ���Ƿ�Ϊ�գ��Է���һ�����ײ��
	SLTNode* newnode = BuySListNode(x);
	if (*pphead == NULL)//����ǿձ�Ҫ�����������Ҳ���ֱ�Ӱ�tmp�ӵ�newnode��
	                    //��Ϊtmp��*pphead�����ϲ�һ�������Ƿ��ʵ���������һ����
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
	assert(pphead);//��鴫��Ķ���ָ���Ƿ�Ϊ�գ��Է���һ�����ײ��
	SLTNode* newnode = BuySListNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}
void SListPopFront(SList* pphead)
{
	assert(pphead);//��鴫��Ķ���ָ���Ƿ�Ϊ�գ��Է���һ�����ײ��
	assert(*pphead != NULL);
	SLTNode* tmp = (*pphead)->next;
	free(*pphead);
	*pphead = tmp;
}
void SListPopBack(SList* pphead)
{
	assert(pphead);//��鴫��Ķ���ָ���Ƿ�Ϊ�գ��Է���һ�����ײ��
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
	assert(pos);//һ����Ϊ�յľͿ��ԼӶ���
	SLTNode* newnode = BuySListNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

void SListInsert(SList* pphead, SLTNode* pos, SLTDataType x)
{
	assert(pphead);//��鴫��Ķ���ָ���Ƿ�Ϊ�գ��Է���һ�����ײ��
	assert(pos);//һ����Ϊ�յľͿ��ԼӶ���
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
	assert(pphead);//��鴫��Ķ���ָ���Ƿ�Ϊ�գ��Է���һ�����ײ��
	assert(pos);//һ����Ϊ�յľͿ��ԼӶ���
	if (*pphead == pos)
	{
		*pphead = (*pphead)->next;
		free(pos);
		pos = NULL;
		//Ҳ����ֱ�ӵ���ͷɾ
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
	assert(pos);//һ����Ϊ�յľͿ��ԼӶ���
	assert(pos->next);//��������һ��������ӿھͲ���ʹ��
	SLTNode* next = pos->next;
	pos->next = next->next;
	free(next);
}

void SListDestroy(SList* pphead)
{
	assert(pphead);//��鴫��Ķ���ָ���Ƿ�Ϊ�գ��Է���һ�����ײ��
	SLTNode* tmp = *pphead;
	SLTNode* tmp2 = NULL;
	while (tmp)
	{
		tmp2 = tmp->next;
		free(tmp);
		tmp = tmp2;
	}
	*pphead = NULL;//��Ҫ��ͷָ���ÿգ���Ϊ���Ǵ�ַ����ı�ʵ��
}