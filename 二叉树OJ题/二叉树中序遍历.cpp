#define _CRT_SECURE_NO_WARNINGS

//题目：给定一个二叉树的根节点 root ，返回 它的 中序 遍历 。

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
    void inorder(vector<int>& arr, TreeNode* root)
    {
        if (!root)
            return;
        inorder(arr, root->left);
        arr.push_back(root->val);
        inorder(arr, root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> arr;
        inorder(arr, root);
        return arr;
    }
};