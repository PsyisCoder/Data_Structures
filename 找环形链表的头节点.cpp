//#define _CRT_SECURE_NO_WARNINGS

// ���⣺
/*����һ��������������ʼ�뻷�ĵ�һ���ڵ㡣 
�������ͷ�ڵ㿪ʼ���� next ָ����뻷�ĵ�һ���ڵ�Ϊ������ڽڵ㡣
��������޻����򷵻� null��*/


//��
//��������ʽ�����������㿪ʼ�ߣ�һ����ͷ��ʼ�ߣ�һ�������뻷������
struct ListNode* detectCycle(struct ListNode* head) {
    struct ListNode* slow, * fast;
    slow = fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
        {
            //����
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