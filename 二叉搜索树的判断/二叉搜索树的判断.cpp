
//二叉搜索树的判断


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
    long long PreValue = LLONG_MIN;
    bool isValidBST(TreeNode* root) {
        if (!root)
        {
            return true;
        }
        bool isLeftBST = isValidBST(root->left);
        if (!isLeftBST)
        {
            return false;
        }
        if (root->val <= PreValue)
        {
            return false;
        }
        else
        {
            PreValue = root->val;
        }
        return isValidBST(root->right);
    }
};