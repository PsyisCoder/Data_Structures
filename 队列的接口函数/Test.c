#include"Queue.h"
//
//void TestStack()
//{
//	ST st;
//	StackInit(&st);
//	StackPush(&st, 1);
//	StackPush(&st, 2);
//	StackPush(&st, 3);
//	StackPush(&st, 4);
//
//	StackPop(&st);
//	StackPop(&st);
//	StackPop(&st);
//	StackPop(&st);
//	StackPop(&st);
//}



void QueueTest()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePop(&q);
	QueuePop(&q);
	QueuePop(&q);
	QueuePop(&q);
}



int main()
{
	//TestStack();
	QueueTest();
	return 0;
}