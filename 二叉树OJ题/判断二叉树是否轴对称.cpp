#define _CRT_SECURE_NO_WARNINGS
/*��Ŀ�������һ�������ж�һ�ö������Ƿ� ��Գ� ��
*/





//��⣺
/*����һ���ݹ�
˼·���㷨

���һ������������������������Գƣ���ô������ǶԳƵġ�

��ˣ����������ת��Ϊ����������ʲô����»�Ϊ����

���ͬʱ�����������������������Ϊ����

���ǵ���������������ͬ��ֵ

ÿ������������������һ����������������Գ�

���ǿ���ʵ������һ���ݹ麯����ͨ����ͬ���ƶ�������ָ��ķ����������������ppp ָ��� qqq ָ��һ��ʼ��ָ��������ĸ������ ppp ����ʱ��qqq ���ƣ�ppp ����ʱ��qqq ���ơ�ÿ�μ�鵱ǰ ppp �� qqq �ڵ��ֵ�Ƿ���ȣ����������ж����������Ƿ�Գơ�

�������¡�
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool check(struct TreeNode* p, struct TreeNode* q)
{
    if (p == NULL && q == NULL) return true;
    if (p == NULL || q == NULL) return false;
    return p->val == q->val && check(p->left, q->right) && check(p->right, q->left);
}
bool checkSymmetricTree(struct TreeNode* root) {
    return check(root, root);
}
