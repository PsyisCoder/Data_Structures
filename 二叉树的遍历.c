/*��������ΪFDS�γ�����ĵ����ݽṹ֮һ��Ҫ��ÿ���˶����գ�
����һ���򵥵Ķ��������⣡
���ǽ�����һ�Ŷ���������������������ֱ������ֱ����������������������������
�����ʽ:
������������������ʽ������
��һ�и���һ��������N��N <= 100)����ʾ�������ϵĽڵ������
������N�У�ÿ�а�������������i��l��r���ֱ�����i���ڵ�����Һ��ӣ�
��������� / �Һ���Ϊ�գ����ڶ�Ӧλ�ø��� - 1��
��Ŀ��֤1�Ǹ��ڵ㣡
�����ʽ :
��������������ֱ�����
��һ���������������ڶ���������������������������������
ÿ��ĩβ�޶���ո�
�������� :
���������һ�����롣���磺
3
1 2 3
2 - 1 - 1
3 - 1 - 1
�������:
�����������Ӧ����������磺
1 2 3
2 1 3
2 3 1*/


//��:


#include<bits/stdc++.h>
using namespace std;
typedef int Elementyple;
typedef struct TNode* BiTree;
typedef struct TNode {
    Elementyple Data;
    struct TNode* Left;
    struct TNode* Right;
}tnode;
int N;
BiTree createNode() {
    BiTree node = new TNode;
    node->Left = NULL;
    node->Right = NULL;
    return node;
}
BiTree CreaTree(int number[10000][15], int x) {
    if (x == -1)
        return NULL;
    BiTree BT;
    // BT=(BiTree)malloc(sizeof(struct TNode));
    BT = createNode();
    BT->Data = x;
    BT->Left = CreaTree(number, number[x][0]);
    BT->Right = CreaTree(number, number[x][1]);
    return BT;
}
int flag = 0;
//���ÿ�㶼����һ��flag=0�Ļ���ôÿ�εݹ��ʱ�� flag���Ǵ�0��ʼ �޷��ﵽflag++de Ч�� 
void PreorderTraversal(BiTree BT) {
    if (BT) {
        flag++;
        if (flag == N)
            printf("%d", BT->Data);
        else
            printf("%d ", BT->Data);
        PreorderTraversal(BT->Left);
        PreorderTraversal(BT->Right);
    }
}
void InorderTraversal(BiTree BT) {
    if (BT) {
        InorderTraversal(BT->Left);
        flag++;
        if (flag == 2 * N)
            printf("%d", BT->Data);
        else
            printf("%d ", BT->Data);
        InorderTraversal(BT->Right);

    }
}
void PostorderTraversal(BiTree BT) {
    if (BT) {
        PostorderTraversal(BT->Left);
        PostorderTraversal(BT->Right);
        flag++;
        if (flag == 3 * N)
            printf("%d", BT->Data);
        else
            printf("%d ", BT->Data);
    }
}

int main() {
    int i, a[10000][15], b[10000];
    scanf("%d", &N);
    for (i = 1; i <= N; i++) {
        scanf("%d%d%d", &b[i], &a[i][0], &a[i][1]);
    }
    BiTree BT;
    BT = CreaTree(a, 1);
    PreorderTraversal(BT);
    printf("\n");
    InorderTraversal(BT);
    printf("\n");
    PostorderTraversal(BT);

}