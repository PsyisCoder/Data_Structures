//#define _CRT_SECURE_NO_WARNINGS

// 问题：
/*给定一个链表的 头节点 head ，请判断其是否为回文链表。
如果一个链表是回文，那么链表节点序列从前往后看和从后往前看是相同的。*/


//解

bool isPalindrome(struct ListNode* head) {

    //找中间节点
    struct ListNode* mid, * entire;
    mid = entire = head;
    while (entire && entire->next)
    {
        mid = mid->next;
        entire = entire->next->next;
    }
    //逆置
    struct ListNode* n1, * n2, * n3;
    n1 = NULL, n2 = mid, n3 = mid->next;
    while (n2)
    {
        n2->next = n1;
        n1 = n2;
        n2 = n3;
        if (n3)
            n3 = n3->next;
    }
    //比较
    struct ListNode* cur = head;
    struct ListNode* newcur = n1;
    while (newcur)
    {
        if (cur->val != newcur->val)
        {
            return false;
        }
        else
        {
            cur = cur->next;
            newcur = newcur->next;
        }
    }
    return true;
}