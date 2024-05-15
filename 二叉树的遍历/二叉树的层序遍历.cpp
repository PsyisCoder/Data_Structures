/*题目：
二叉树的层序遍历
给你二叉树的根节点 root ，返回其节点值的 层序遍历 。 （即逐层地，从左到右访问所有节点）。*/

/*
示例 1：
输入：root = [3,9,20,null,null,15,7]
输出：[[3],[9,20],[15,7]]

示例 2：
输入：root = [1]
输出：[[1]]

示例 3：
输入：root = []
输出：[]

示例 4：
输入：root = [3,9,20,11,12,15,7]
输出：[[3],[9,20],[11,12,15,7]]
*/



//代码实现：
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if (!root)
            return ret;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            int cl = q.size();
            ret.push_back(vector<int>());//插入一个向量组
            for (int i = 0; i < cl; ++i)//每一层有多少个元素就push多少次
            {
                auto tmp = q.front(); q.pop();
                ret.back().push_back(tmp->val);
                if (tmp->left)q.push(tmp->left);
                if (tmp->right)q.push(tmp->right);
            }
        }
        return ret;
    }
};