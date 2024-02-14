//#define _CRT_SECURE_NO_WARNINGS

// 问题：
/*给定一个链表，返回链表开始入环的第一个节点。 
从链表的头节点开始沿着 next 指针进入环的第一个节点为环的入口节点。
如果链表无环，则返回 null。*/


//解
//方法：公式法：从相遇点开始走，一个从头开始走，一定会在入环点相遇
struct ListNode* detectCycle(struct ListNode* head) {
    struct ListNode* slow, * fast;
    slow = fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
        {
            //相遇
            struct ListNode* meet = fast;
            struct ListNode* cur = head;
            while (meet != cur)
            {
                meet = meet->next;
                cur = cur->next;
            }
            return meet;
        }
    }
    return NULL;
}