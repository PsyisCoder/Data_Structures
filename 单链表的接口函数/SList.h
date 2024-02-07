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
//��ӡ
void SListPrint(SLTNode* phead);
//β��
void SListPushBack(SList* pphead, SLTDataType x);
//ͷ��
void SListPushFront(SList* pphead, SLTDataType x);
//ͷɾ
void SListPopFront(SList* pphead);
//βɾ
void SListPopBack(SList* pphead);


//����
SLTNode* SListFind(SList phead, SLTDataType x);
//��ָ���ڵ������룬�������򵥣����ʺϵ�����Ч��Ҳ����
void SListInsertAfter(SLTNode* pos, SLTDataType x);
//ָ���ڵ�ǰ�����
void SListInsert(SList* pphead, SLTNode* pos, SLTDataType x);
//ָ���ڵ�ɾ��
void SListErase(SList* pphead, SLTNode* pos);
//ɾ��ָ���ڵ�����ֵ
void SListEraseAfter(SLTNode* pos);
//��������
void SListDestroy(SList* pphead);