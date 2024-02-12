//#define _CRT_SECURE_NO_WARNINGS

// 问题：
/*将两个升序链表合并为一个新的 升序 链表并返回。
新链表是通过拼接给定的两个链表的所有节点组成的。*/


//解

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* head, * tail;
    head = tail = NULL;
    //如果其中一个链表为空，返回另一个
    if (!list1)
        return list2;
    if (!list2)
        return list1;

    //先取一个小的去做第一个
    if (list1->val < list2->val)
    {
        head = tail = list1;
        list1 = list1->next;
    }
    else
    {
        head = tail = list2;
        list2 = list2->next;
    }
    while (list1 && list2)
    {
        if (list1->val < list2->val)
        {
            tail->next = list1;
            tail = list1;
            list1 = list1->next;
        }
        else
        {
            tail->next = list2;
            tail = list2;
            list2 = list2->next;
        }
    }
    //当一个为空，把另一个接上
    if (list1)
    {
        tail->next = list1;
    }
    if (list2)
    {
        tail->next = list2;
    }
    return head;
}