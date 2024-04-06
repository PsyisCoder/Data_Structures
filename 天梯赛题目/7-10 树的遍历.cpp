/*给定一棵二叉树的后序遍历和中序遍历，请你输出其层序遍历的序列。
这里假设键值都是互不相等的正整数。

输入格式：
输入第一行给出一个正整数N（≤30），是二叉树中结点的个数。第二行
给出其后序遍历序列。第三行给出其中序遍历序列。数字间以空格分隔。

输出格式：
在一行中输出该树的层序遍历的序列。数字间以1个空格分隔，行首尾不得有多余空格。

输入样例：
7
2 3 1 5 7 6 4
1 2 3 4 5 6 7
输出样例：
4 1 6 3 5 7 2
*/






//题解：先使用后序遍历建树，在层序遍历


#include <iostream>
using namespace std;
int post[31], inorder[31];
int flag = 1;
typedef struct node
{
	int data;
	node* lchild;
	node* rchild;
}*TNode;
TNode Create(int root, int start, int end)
{
	TNode T;
	int i;
	if (end < start)return NULL;
	T = (TNode)malloc(sizeof(struct node));
	T->data = post[root];
	for (i = start; post[root] != inorder[i]; i++);
	T->lchild = Create(root - 1 - (end - i), start, i - 1);
	T->rchild = Create(root - 1, i + 1, end);
	return T;
}
void Level(TNode T)
{
	int front = -1, rear = 0;
	TNode queue[31];
	if (!T)return;
	queue[rear] = T;//从尾部插入
	while (rear > front)
	{
		if (flag)
		{
			cout << queue[++front]->data;
			flag = 0;
		}
		else cout << " " << queue[++front]->data;
		if (queue[front]->lchild)queue[++rear] = queue[front]->lchild;
		if (queue[front]->rchild)queue[++rear] = queue[front]->rchild;
	}
}
int main()
{
	int i, N;
	TNode T;
	cin >> N;
	for (i = 0; i < N; i++)
		cin >> post[i];
	for (i = 0; i < N; i++)
		cin >> inorder[i];
	T = Create(N - 1, 0, N - 1);
	Level(T);
}
