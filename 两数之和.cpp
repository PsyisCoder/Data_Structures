#define _CRT_SECURE_NO_WARNINGS


/*��Ŀ���������� �ǿ� ��������ʾ�����Ǹ�������������ÿλ���ֶ��ǰ��� ���� �ķ�ʽ�洢�ģ�����ÿ���ڵ�ֻ�ܴ洢 һλ ���֡�

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

/*����һ��ģ��
˼·���㷨

�����������������������洢���ֵ�λ���ģ��������������ͬһλ�õ����ֿ���ֱ����ӡ�

����ͬʱ��������������λ�������ǵĺͣ����뵱ǰλ�õĽ�λֵ��ӡ�������ԣ������ǰ����������Ӧλ�õ�����Ϊ n1,n2n1,n2n1,n2����λֵΪ carry\textit{carry}carry�������ǵĺ�Ϊ n1+n2+carryn1+n2+\textit{carry}n1+n2+carry�����У���������Ӧλ�õ�����Ϊ (n1+n2+carry)?mod?10(n1+n2+\textit{carry}) \bmod 10(n1+n2+carry)mod10�����µĽ�λֵΪ ?n1+n2+carry10?\lfloor\frac{n1+n2+\textit{carry}}{10}\rfloor? 
10
n1+n2+carry
?
 ?��

�����������ĳ��Ȳ�ͬ���������Ϊ���ȶ̵�����ĺ��������ɸ� 000 ��

���⣬������������������ carry>0\textit{carry} > 0carry>0������Ҫ�ڴ�����ĺ��渽��һ���ڵ㣬�ڵ��ֵΪ carry\textit{carry}carry��

*/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = nullptr, * tail = nullptr;
        int carry = 0;
        while (l1 || l2) {
            int n1 = l1 ? l1->val : 0;
            int n2 = l2 ? l2->val : 0;
            int sum = n1 + n2 + carry;
            if (!head) {
                head = tail = new ListNode(sum % 10);
            }
            else {
                tail->next = new ListNode(sum % 10);
                tail = tail->next;
            }
            carry = sum / 10;
            if (l1) {
                l1 = l1->next;
            }
            if (l2) {
                l2 = l2->next;
            }
        }
        if (carry > 0) {
            tail->next = new ListNode(carry);
        }
        return head;
    }
};
