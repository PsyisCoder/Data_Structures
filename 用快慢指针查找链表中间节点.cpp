//#define _CRT_SECURE_NO_WARNINGS

// 问题：
//给你单链表的头结点 head ，请你找出并返回链表的中间结点。
//如果有两个中间结点，则返回第二个中间结点。


//解
/*使用快慢指针找到中间节点：slow每次走一步，fast每次走两步，因此走到底时slow走的路程就是
fast的1/2，因此就用slow找到了中间值*/

struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode* slow, * fast;
    slow = head, fast = head;
    while (fast != NULL && fast->next != NULL)//节点数为奇数时，fast指向最后一个时就找到了
                                              //节点数为偶数时，fast指向空指针时就找到了
    {
        slow = slow->next;
        fast = (fast->next)->next;
    }
    return slow;
}