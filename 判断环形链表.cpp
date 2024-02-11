//#define _CRT_SECURE_NO_WARNINGS

// ���⣺
/*����һ�������ͷ�ڵ� head ���ж��������Ƿ��л���
��������д��ڻ� ���򷵻� true �� ���򣬷��� false ��*/


//��

bool hasCycle(struct ListNode* head) {
    struct ListNode* slow, * fast;
    slow = fast = head;
    while (fast && fast->next)//�������������ָ��һ��������
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)//�ж�����ָ���λ���Ƿ���ͬ���������������������
        {
            return true;
        }
    }
    return false;
}