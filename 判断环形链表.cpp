//#define _CRT_SECURE_NO_WARNINGS

// 问题：
/*给你一个链表的头节点 head ，判断链表中是否有环。
如果链表中存在环 ，则返回 true 。 否则，返回 false 。*/


//解

bool hasCycle(struct ListNode* head) {
    struct ListNode* slow, * fast;
    slow = fast = head;
    while (fast && fast->next)//如果带环，快慢指针一定会相遇
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)//判断他俩指向的位置是否相同，而不是他俩所存的数据
        {
            return true;
        }
    }
    return false;
}