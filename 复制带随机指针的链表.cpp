//#define _CRT_SECURE_NO_WARNINGS

// ���⣺���ƴ����ָ�������
/*����һ������Ϊ n ������ÿ���ڵ����һ���������ӵ����ָ�� random ��
��ָ�����ָ�������е��κνڵ��սڵ㡣
������������ ����� ���Ӧ�������� n �� ȫ�� �ڵ���ɣ�
����ÿ���½ڵ��ֵ����Ϊ���Ӧ��ԭ�ڵ��ֵ��
�½ڵ�� next ָ��� random ָ��Ҳ��Ӧָ���������е��½ڵ㣬
��ʹԭ����͸��������е���Щָ���ܹ���ʾ��ͬ������״̬��
���������е�ָ�붼��Ӧָ��ԭ�����еĽڵ� ��*/


//��
//����������һ��������ÿһ���ڵ����ӵ�ԭ�ڵ�ĺ���
//      ���ָ�����
struct Node* copyRandomList(struct Node* head) {
    struct Node* cur = head;
    //1�������ڵ����ԭ�ڵ�ĺ���
    while (cur)
    {
        struct Node* copy = (struct Node*)malloc(sizeof(struct Node));
        copy->val = cur->val;
        //����copy�ڵ�
        copy->next = cur->next;
        cur->next = copy;
        cur = copy->next;
    }
    //2������ԭ�ڵ㣬����copy�ڵ��random
    cur = head;
    while (cur)
    {
        struct Node* copy = cur->next;
        if (cur->random == NULL)
        {
            copy->random = cur->random;
        }
        else
        {
            copy->random = cur->random->next;
        }
        cur = copy->next;
    }
    //�Ͽ�����������ԭ�����ָ�����������ԭ����
    cur = head;
    struct Node* copyhead = NULL, * copytail = NULL;
    while (cur)
    {
        struct Node* copy = cur->next;
        struct Node* next = copy->next;
        if (copytail == NULL)
        {
            copyhead = copytail = copy;
        }
        else
        {
            copytail->next = copy;
            copytail = copy;
        }
        cur->next = next;
        cur = next;
    }
    return copyhead;
}