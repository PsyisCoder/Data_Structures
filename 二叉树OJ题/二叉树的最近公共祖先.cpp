#define _CRT_SECURE_NO_WARNINGS
/*题目：给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。

百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，
最近公共祖先表示为一个结点 x，
满足 x 是 p、q 的祖先且 x 的深度尽可能大
（一个节点也可以是它自己的祖先）。”
*/





//题解：
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    //用来存放公共祖先节点
    TreeNode* ans;
    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        //如果root为空，则它的子树肯定不含pq，返回false
        if (!root) return false;
        //定义bool类型的左右孩子，如果左（右）子树含有p或q则赋值true反之为false
        bool lson = dfs(root->left, p, q);
        bool rson = dfs(root->right, p, q);
        //如果左右都为真，或者本身就是p或q并且左或右为真，则找到了最近的公共祖先，把它赋值给ans
        if ((lson && rson) || ((root->val == p->val) || (root->val == q->val) && (lson || rson)))
            ans = root;
        //如果左（右）子树中含有p或q，或本身就是p或q，就返回真，让上一层的lson或rson知道自己子树中是否含有p或q
        return (lson || rson) || ((root->val == p->val) || (root->val == q->val));
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //寻找p，q最近祖先
        dfs(root, p, q);
        return ans;
    }
};