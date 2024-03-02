#define _CRT_SECURE_NO_WARNINGS
/*��Ŀ������һ�ö������ĸ��ڵ㣬�жϸ����ǲ���ƽ���������
���ĳ������������ڵ���������������������1��
��ô������һ��ƽ���������
*/





//��⣺
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    //�������ĸ߶�
    int height(TreeNode* root)
    {
        if (!root) return 0;
        return max(height(root->left), height(root->right)) + 1;
    }

    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        return abs(height(root->left) - height(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
};