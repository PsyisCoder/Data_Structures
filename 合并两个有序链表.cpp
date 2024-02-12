//#define _CRT_SECURE_NO_WARNINGS

// ���⣺
/*��������������ϲ�Ϊһ���µ� ���� �������ء�
��������ͨ��ƴ�Ӹ�����������������нڵ���ɵġ�*/


//��

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* head, * tail;
    head = tail = NULL;
    //�������һ������Ϊ�գ�������һ��
    if (!list1)
        return list2;
    if (!list2)
        return list1;

    //��ȡһ��С��ȥ����һ��
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
    //��һ��Ϊ�գ�����һ������
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