#define _CRT_SECURE_NO_WARNINGS
/*题目：给定一棵二叉树的根节点 root，请左右翻转这棵二叉树，并返回其根节点。
*/





//题解：

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* mirrorTree(struct TreeNode* root) {
    if (root == NULL)
        return NULL;
    struct TreeNode* tmp;
    tmp = root->left;
    root->left = mirrorTree(root->right);
    root->right = mirrorTree(tmp);
    return root;
}
