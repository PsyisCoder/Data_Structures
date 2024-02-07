#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
struct ListNode
{
	int val;
	struct ListNode* next;
};
int main()
{
	//快速创建一个链表调试OJ题目
	struct ListNode* n1 = (ListNode*)malloc(sizeof(ListNode));
	struct ListNode* n2 = (ListNode*)malloc(sizeof(ListNode));
	struct ListNode* n3 = (ListNode*)malloc(sizeof(ListNode));
	struct ListNode* n4 = (ListNode*)malloc(sizeof(ListNode));
	n1->val = 7;
	n2->val = 7;
	n3->val = 7;
	n4->val = 7;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = NULL;

	//可以把函数嵌在这里进行调试


	return 0;
}