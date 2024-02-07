#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int SLTDataType;
typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
}SLTNode,*SList;
//打印
void SListPrint(SLTNode* phead);
//尾插
void SListPushBack(SList* pphead, SLTDataType x);
//头插
void SListPushFront(SList* pphead, SLTDataType x);
//头删
void SListPopFront(SList* pphead);
//尾删
void SListPopBack(SList* pphead);


//查找
SLTNode* SListFind(SList phead, SLTDataType x);
//在指定节点后面插入，这样更简单，更适合单链表，效率也更高
void SListInsertAfter(SLTNode* pos, SLTDataType x);
//指定节点前面插入
void SListInsert(SList* pphead, SLTNode* pos, SLTDataType x);
//指定节点删除
void SListErase(SList* pphead, SLTNode* pos);
//删除指定节点后面的值
void SListEraseAfter(SLTNode* pos);
//销毁链表
void SListDestroy(SList* pphead);