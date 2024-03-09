#define _CRT_SECURE_NO_WARNINGS
/*��Ŀ���������ö����� root �� subRoot ��
���� root ���Ƿ������ subRoot ������ͬ�ṹ�ͽڵ�ֵ��������
������ڣ����� true �����򣬷��� false ��
������ tree ��һ���������� tree ��ĳ���ڵ������ڵ�����к���ڵ㡣
tree Ҳ���Կ����������һ��������*/




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
        //����ߵ��սڵ��ˣ��ͷ���false
        if (!o)return false;
        return check(o, j) || def(o->left, j) || def(o->right, j);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return def(root, subRoot);
    }
};