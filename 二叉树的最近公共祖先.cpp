#define _CRT_SECURE_NO_WARNINGS
/*��Ŀ������һ��������, �ҵ�����������ָ���ڵ������������ȡ�

�ٶȰٿ�������������ȵĶ���Ϊ���������и��� T ��������� p��q��
����������ȱ�ʾΪһ����� x��
���� x �� p��q �������� x ����Ⱦ����ܴ�
��һ���ڵ�Ҳ���������Լ������ȣ�����
*/





//��⣺
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
    //������Ź������Ƚڵ�
    TreeNode* ans;
    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        //���rootΪ�գ������������϶�����pq������false
        if (!root) return false;
        //����bool���͵����Һ��ӣ�������ң���������p��q��ֵtrue��֮Ϊfalse
        bool lson = dfs(root->left, p, q);
        bool rson = dfs(root->right, p, q);
        //������Ҷ�Ϊ�棬���߱������p��q���������Ϊ�棬���ҵ�������Ĺ������ȣ�������ֵ��ans
        if ((lson && rson) || ((root->val == p->val) || (root->val == q->val) && (lson || rson)))
            ans = root;
        //������ң������к���p��q���������p��q���ͷ����棬����һ���lson��rson֪���Լ��������Ƿ���p��q
        return (lson || rson) || ((root->val == p->val) || (root->val == q->val));
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //Ѱ��p��q�������
        dfs(root, p, q);
        return ans;
    }
};