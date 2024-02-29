/*二叉树作为FDS课程最核心的数据结构之一，要求每个人都掌握！
这是一道简单的二叉树问题！
我们将给出一颗二叉树，请你输出它的三种遍历，分别是先序遍历，中序遍历，后序遍历
输入格式:
二叉树将以这样的形式给出：
第一行给出一个正整数N（N <= 100)，表示二叉树上的节点个数！
接下来N行，每行包含三个整数，i，l，r，分别代表第i个节点的左右孩子！
如果它的左 / 右孩子为空，则在对应位置给出 - 1！
题目保证1是根节点！
输出格式 :
请你输出它的三种遍历！
第一行输出先序遍历，第二行输出中序遍历，第三行输出后序遍历！
每行末尾无多余空格！
输入样例 :
在这里给出一组输入。例如：
3
1 2 3
2 - 1 - 1
3 - 1 - 1
输出样例:
在这里给出相应的输出。例如：
1 2 3
2 1 3
2 3 1*/


//解:


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
//如果每层都定义一个flag=0的话那么每次递归的时候 flag都是从0开始 无法达到flag++de 效果 
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