#include"SList.h"
void test1()
{
	SList sl = NULL;
	SListPushBack(&sl, 1);
	SListPushBack(&sl, 2);
	SListPushBack(&sl, 3);
	SListPushBack(&sl, 4);
	SListPrint(sl);
	SListPushFront(&sl, 1);
	SListPushFront(&sl, 2);
	SListPushFront(&sl, 3);
	SListPushFront(&sl, 4);
	SListPopBack(&sl);
	SListPrint(sl);
}
void test2()
{
	SList sl = NULL;
	SListPushBack(&sl, 1);
	SListPushBack(&sl, 2);
	SListPushBack(&sl, 3);
	SListPushBack(&sl, 4);
	SListPrint(sl);
	SListPopBack(&sl);
	SListPrint(sl);
	SListPopFront(&sl);
	SListPopFront(&sl);
	SListPopFront(&sl);
	SListPrint(sl);
}
void test3()
{
	SList sl = NULL;
	SListPushFront(&sl, 1);
	SListPushFront(&sl, 2);
	SListPushFront(&sl, 3);
	SListPushFront(&sl, 4);
	SListPrint(sl);
	SLTNode* pos = SListFind(sl, 4);
	if (pos)
	{
		SListInsertAfter(pos, 40);
	}
	SListPrint(sl);
	SListDestroy(&sl);
}
int main()
{
	//test1();
	//test2();
	test3();
	return 0;
}