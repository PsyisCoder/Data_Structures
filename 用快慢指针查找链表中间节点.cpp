//#define _CRT_SECURE_NO_WARNINGS

// ���⣺
//���㵥�����ͷ��� head �������ҳ�������������м��㡣
//����������м��㣬�򷵻صڶ����м��㡣


//��
/*ʹ�ÿ���ָ���ҵ��м�ڵ㣺slowÿ����һ����fastÿ��������������ߵ���ʱslow�ߵ�·�̾���
fast��1/2����˾���slow�ҵ����м�ֵ*/

struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode* slow, * fast;
    slow = head, fast = head;
    while (fast != NULL && fast->next != NULL)//�ڵ���Ϊ����ʱ��fastָ�����һ��ʱ���ҵ���
                                              //�ڵ���Ϊż��ʱ��fastָ���ָ��ʱ���ҵ���
    {
        slow = slow->next;
        fast = (fast->next)->next;
    }
    return slow;
}