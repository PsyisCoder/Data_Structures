#define _CRT_SECURE_NO_WARNINGS
/*给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。

请你将两个数相加，并以相同形式返回一个表示和的链表。

你可以假设除了数字 0 之外，这两个数都不会以 0 开头。*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

/*题解：可以依次加链表中对应的两位，把进位记录下来，
在下一次相加中加上每一次的进位，然后依次保存在新的链表中*/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //创建新链表
        ListNode* head = NULL, * tail = NULL;

        int carry = 0;//表示进位

        //两个链表都遍历完就结束
        while (l1 || l2)
        {
            int n1 = l1 ? l1->val : 0;
            int n2 = l2 ? l2->val : 0;
            int sum = n1 + n2 + carry;
            if (!head)//如果为空链表
            {
                head = tail = new ListNode(sum % 10);
                tail->next = NULL;
            }
            else
            {
                tail->next = new ListNode(sum % 10);
                tail = tail->next;
                tail->next = NULL;
            }
            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
            carry = sum / 10;//记录进位
        }
        //如果出来后还要进位则也要加到链表里
        if (carry)
        {
            tail->next = new ListNode(carry);
            tail = tail->next;
            tail->next = NULL;
        }
        return head;
    }
};
