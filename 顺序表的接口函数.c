#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<errno.h>
#include<assert.h>
typedef int DataType;
//创建一个顺序表的类型
typedef struct SeqList
{
	DataType* data;
	int size;
	int capacity;
}SL;
//顺序表初始化
void SeqListInit(SL* ps)
{
	ps->data = NULL;
	ps->size = 0;
	ps->capacity = 0;
}
//检查增容
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
//尾插
void SeqListPushBack(SL* ps,DataType x)
{
	//先判断要不要增容，判断完直接尾插
	SeqListCheckCapacity(ps);
	ps->data[ps->size] = x;
	ps->size++;
}
//尾删
void SeqListPopBack(SL* ps)//要考虑size为0的情况
{
	//温柔的方式
	/*if (ps->size > 0)
	{
		ps->size--;
	}*/

	//粗暴的方式
	assert(ps->size > 0);
	ps->size--;
}
//打印顺序表
void SeqListPrint(SL* ps)
{
	for (int i = 0; i < ps->size; ++i)
	{
		printf("%d ", ps->data[i]);
	}
	printf("\n");
}
//销毁顺序表
void SeqListDestroy(SL* ps)
{
	free(ps->data);
	ps->data = NULL;
}
//头插
void SeqListPushFront(SL* ps,DataType x)
{
	//先判断增容
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
//头删
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
//测试1
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