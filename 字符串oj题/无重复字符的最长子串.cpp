#define _CRT_SECURE_NO_WARNINGS

//��Ŀ������һ���ַ��� s �������ҳ����в������ظ��ַ��� ��Ӵ��ĳ��ȡ�



class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //����һ�������ϣ���Ƿ����ظ�
        unordered_set<char> occ;
        //��¼�ַ�������
        int n = s.size();
        //������ָ�룬��ʼ��Ϊ�ַ�������ˣ�����һ������Ӵ����ȣ���ʼ��Ϊ0
        int rk = -1, ans = 0;
        for (int i = 0; i < n; ++i)
        {
            //ÿ�α�����һ��λ�ã������Ųһ��Ԫ��
            if (i != 0)
            {
                occ.erase(s[i - 1]);
            }
            //�ж�û���ظ��ͼ�������
            while (rk + 1 < n && !occ.count(s[rk + 1]))
            {
                occ.insert(s[rk + 1]);
                ++rk;
            }
            //�����ֵ
            ans = max(ans, rk + 1 - i);
        }
        return ans;
    }
};