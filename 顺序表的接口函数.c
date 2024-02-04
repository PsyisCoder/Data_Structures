#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<errno.h>
#include<assert.h>
typedef int DataType;
//����һ��˳��������
typedef struct SeqList
{
	DataType* data;
	int size;
	int capacity;
}SL;
//˳����ʼ��
void SeqListInit(SL* ps)
{
	ps->data = NULL;
	ps->size = 0;
	ps->capacity = 0;
}
//�������
void SeqListCheckCapacity(SL* ps)
{
	if (ps->capacity == ps->size)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		DataType* tmp = (DataType*)realloc(ps->data, newcapacity * sizeof(DataType));
		if (tmp == NULL)
		{
			printf("%s\n", strerror(errno));
			exit(-1);
		}
		ps->data = tmp;
		ps->capacity = newcapacity;
	}
}
//β��
void SeqListPushBack(SL* ps,DataType x)
{
	//���ж�Ҫ��Ҫ���ݣ��ж���ֱ��β��
	SeqListCheckCapacity(ps);
	ps->data[ps->size] = x;
	ps->size++;
}
//βɾ
void SeqListPopBack(SL* ps)//Ҫ����sizeΪ0�����
{
	//����ķ�ʽ
	/*if (ps->size > 0)
	{
		ps->size--;
	}*/

	//�ֱ��ķ�ʽ
	assert(ps->size > 0);
	ps->size--;
}
//��ӡ˳���
void SeqListPrint(SL* ps)
{
	for (int i = 0; i < ps->size; ++i)
	{
		printf("%d ", ps->data[i]);
	}
	printf("\n");
}
//����˳���
void SeqListDestroy(SL* ps)
{
	free(ps->data);
	ps->data = NULL;
}
//ͷ��
void SeqListPushFront(SL* ps,DataType x)
{
	//���ж�����
	SeqListCheckCapacity(ps);
	int end = ps->size - 1;
	while (end >= 0)
	{
		ps->data[end + 1] = ps->data[end];
		end--;
	}
	ps->data[0] = x;
	ps->size++;
}
//ͷɾ
void SeqListPopFront(SL* ps)
{
	int front = 0;
	while (front < ps->size - 1)
	{
		ps->data[front] = ps->data[front + 1];
		front++;
	}
	assert(ps->size > 0);
	ps->size--;
}
//����1
void test1(SL* ps)
{
	SeqListInit(ps);
	SeqListPushBack(ps, 1);
	SeqListPushBack(ps, 2);
	SeqListPushBack(ps, 3);
	SeqListPushBack(ps, 4);
	SeqListPushBack(ps, 5);
	SeqListPrint(ps);
	SeqListPopBack(ps);
	SeqListPopBack(ps);
	SeqListPrint(ps);
	SeqListDestroy(ps);
}
void test2(SL* ps)
{
	SeqListInit(ps);
	SeqListPushBack(ps, 1);
	SeqListPushBack(ps, 2);
	SeqListPushBack(ps, 3);
	SeqListPushBack(ps, 4);
	SeqListPushBack(ps, 5);
	SeqListPrint(ps);
	SeqListPushFront(ps, 10);
	SeqListPushFront(ps, 20);
	SeqListPushFront(ps, 30);
	SeqListPrint(ps);
}
int main()
{
	SL list;
	//test1(&list);
	test2(&list);
}