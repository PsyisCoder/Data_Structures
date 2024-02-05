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
	assert(ps->size > 0);
	int front = 0;
	while (front < ps->size - 1)
	{
		ps->data[front] = ps->data[front + 1];
		front++;
	}
	ps->size--;
}
//找到了返回x下标，没找到返回-1
int SeqListFind(SL* ps, DataType x)
{
	for (int i = 0; i < ps->size; ++i)
	{
		if (ps->data[i] == x)
			return i;
	}
	return -1;
}
//指定pos下标位置插入
void SeqListInsert(SL* ps, int pos, DataType x)
{
	if(pos>=0&&pos<=ps->size)//这个地方是可以等于size的
	{
		//增容
		SeqListCheckCapacity(ps);
		//挪动数据
		int i = ps->size - 1;
		while (i >= pos)
		{
			ps->data[i + 1] = ps->data[i];
			i--;
		}
		ps->data[pos] = x;
		ps->size++;
	}
	else
	{
		printf("下标不合法\n");
		return;
	}
}
//删除pos位置的数据
void SeqListErase(SL* ps, int pos)
{
	assert(ps->size > 0);
	if(pos >= 0 && pos < ps->size)
	{
		int i = 0;
		for (i = pos; i < ps->size - 1; ++i)
		{
			ps->data[i] = ps->data[i + 1];
		}
		ps->size--;
	}
	else
	{
		printf("下标不合法\n");
	}
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
//测试2
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
	SeqListPopFront(ps);
	SeqListPopFront(ps);
	SeqListPopFront(ps);
	SeqListPrint(ps);
}
//测试3
void test3(SL* ps)
{
	SeqListInit(ps);
	SeqListPushBack(ps, 1);
	SeqListPushBack(ps, 2);
	SeqListPushBack(ps, 3);
	SeqListPushBack(ps, 4);
	SeqListPushBack(ps, 5);
	SeqListPrint(ps);
	SeqListInsert(ps, 2, 7);

SeqListInsert(ps, 2, 8);

SeqListInsert(ps, 0, -1);
SeqListInsert(ps, 8, -1);

SeqListPrint(ps);
SeqListDestroy(ps);
}
int main()
{
	SL list;
	//test1(&list);
	//test2(&list);
	test3(&list);
}