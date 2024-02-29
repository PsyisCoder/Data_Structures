#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

/*题目：本题要求根据给定的一棵二叉树的后序遍历和中序遍历结果，输出该树的前序遍历结果。

输入格式:
第一行给出正整数 n (≤30)，是树中结点的个数。随后两行，每行给出 n 个整数，分别对应后序遍历和中序遍历结果，数字间以空格分隔。题目保证输入正确对应一棵二叉树。

输出格式:
在一行中输出Preorder: 以及该树的前序遍历结果。数字间有1个空格，行末不得有多余空格。

输入样例:
7
2 3 1 5 7 6 4
1 2 3 4 5 6 7
输出样例:
Preorder: 4 1 3 2 6 5 7
*/





//题解：

void dfs(int n, int* last, int* in)
{
    //如果树的长度为0就停止
    if (n != 0)
    {
        //根节点的输出
        printf(" %d", last[n - 1]);
        //找到根节点在中序遍历里的位置
        int i;
        for (i = 0; i < n; i++)
            if (in[i] == last[n - 1])
                break;
        //左节点递归
        dfs(i, last, in);
        //右节点递归
        dfs(n - 1 - i, last + i, in + i + 1);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int last[31], in[31];
    for (int i = 0; i < n; i++)
        scanf("%d", &last[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &in[i]);

    printf("Preorder:");
    dfs(n, last, in);
    return 0;
}