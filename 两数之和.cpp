#define _CRT_SECURE_NO_WARNINGS
/*�������� �ǿ� ��������ʾ�����Ǹ�������������ÿλ���ֶ��ǰ��� ���� �ķ�ʽ�洢�ģ�����ÿ���ڵ�ֻ�ܴ洢 һλ ���֡�

���㽫��������ӣ�������ͬ��ʽ����һ����ʾ�͵�����

����Լ���������� 0 ֮�⣬���������������� 0 ��ͷ��*/


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

/*��⣺�������μ������ж�Ӧ����λ���ѽ�λ��¼������
����һ������м���ÿһ�εĽ�λ��Ȼ�����α������µ�������*/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //����������
        ListNode* head = NULL, * tail = NULL;

        int carry = 0;//��ʾ��λ

        //��������������ͽ���
        while (l1 || l2)
        {
            int n1 = l1 ? l1->val : 0;
            int n2 = l2 ? l2->val : 0;
            int sum = n1 + n2 + carry;
            if (!head)//���Ϊ������
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
            carry = sum / 10;//��¼��λ
        }
        //���������Ҫ��λ��ҲҪ�ӵ�������
        if (carry)
        {
            tail->next = new ListNode(carry);
            tail = tail->next;
            tail->next = NULL;
        }
        return head;
    }
};
