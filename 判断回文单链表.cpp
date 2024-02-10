//#define _CRT_SECURE_NO_WARNINGS

// ���⣺
/*����һ������� ͷ�ڵ� head �����ж����Ƿ�Ϊ��������
���һ�������ǻ��ģ���ô����ڵ����д�ǰ���󿴺ʹӺ���ǰ������ͬ�ġ�*/


//��

bool isPalindrome(struct ListNode* head) {

    //���м�ڵ�
    struct ListNode* mid, * entire;
    mid = entire = head;
    while (entire && entire->next)
    {
        mid = mid->next;
        entire = entire->next->next;
    }
    //����
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
    //�Ƚ�
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