#define _CRT_SECURE_NO_WARNINGS
/*题目：请设计一个函数判断一棵二叉树是否 轴对称 。
*/





//题解：
/*方法一：递归
思路和算法

如果一个树的左子树与右子树镜像对称，那么这个树是对称的。

因此，该问题可以转化为：两个树在什么情况下互为镜像？

如果同时满足下面的条件，两个树互为镜像：

它们的两个根结点具有相同的值

每个树的右子树都与另一个树的左子树镜像对称

我们可以实现这样一个递归函数，通过「同步移动」两个指针的方法来遍历这棵树，ppp 指针和 qqq 指针一开始都指向这棵树的根，随后 ppp 右移时，qqq 左移，ppp 左移时，qqq 右移。每次检查当前 ppp 和 qqq 节点的值是否相等，如果相等再判断左右子树是否对称。

代码如下。
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool check(struct TreeNode* p, struct TreeNode* q)
{
    if (p == NULL && q == NULL) return true;
    if (p == NULL || q == NULL) return false;
    return p->val == q->val && check(p->left, q->right) && check(p->right, q->left);
}
bool checkSymmetricTree(struct TreeNode* root) {
    return check(root, root);
}
