//#define _CRT_SECURE_NO_WARNINGS

// 问题：复制带随机指针的链表
/*给你一个长度为 n 的链表，每个节点包含一个额外增加的随机指针 random ，
该指针可以指向链表中的任何节点或空节点。
构造这个链表的 深拷贝。 深拷贝应该正好由 n 个 全新 节点组成，
其中每个新节点的值都设为其对应的原节点的值。
新节点的 next 指针和 random 指针也都应指向复制链表中的新节点，
并使原链表和复制链表中的这些指针能够表示相同的链表状态。
复制链表中的指针都不应指向原链表中的节点 。*/


//解
//方法：创建一个新链表将每一个节点连接到原节点的后面
//      最后恢复链表
struct Node* copyRandomList(struct Node* head) {
    struct Node* cur = head;
    //1、拷贝节点插入原节点的后面
    while (cur)
    {
        struct Node* copy = (struct Node*)malloc(sizeof(struct Node));
        copy->val = cur->val;
        //插入copy节点
        copy->next = cur->next;
        cur->next = copy;
        cur = copy->next;
    }
    //2、根据原节点，处理copy节点的random
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
    //断开复制链表与原链表，恢复复制链表与原链表
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