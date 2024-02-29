#define _CRT_SECURE_NO_WARNINGS
/*��Ŀ������һ�ö������ĸ��ڵ� root�������ҷ�ת��ö�����������������ڵ㡣
*/





//��⣺

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
