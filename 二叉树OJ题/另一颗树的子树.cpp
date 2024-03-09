#define _CRT_SECURE_NO_WARNINGS
/*题目：给你两棵二叉树 root 和 subRoot 。
检验 root 中是否包含和 subRoot 具有相同结构和节点值的子树。
如果存在，返回 true ；否则，返回 false 。
二叉树 tree 的一棵子树包括 tree 的某个节点和这个节点的所有后代节点。
tree 也可以看做它自身的一棵子树。*/




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
    bool check(TreeNode* o, TreeNode* j)
    {
        if (!o && !j)return true;
        if (o && !j || !o && j || o->val != j->val)return false;
        return check(o->left, j->left) && check(o->right, j->right);
    }
    bool def(TreeNode* o, TreeNode* j)
    {
        //如果走到空节点了，就返回false
        if (!o)return false;
        return check(o, j) || def(o->left, j) || def(o->right, j);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return def(root, subRoot);
    }
};