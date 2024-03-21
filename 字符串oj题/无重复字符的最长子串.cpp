#define _CRT_SECURE_NO_WARNINGS

//题目：给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串的长度。



class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //创建一个无序哈希表看是否有重复
        unordered_set<char> occ;
        //记录字符串长度
        int n = s.size();
        //定义右指针，初始化为字符串的左端，定义一个最大子串长度，初始化为0
        int rk = -1, ans = 0;
        for (int i = 0; i < n; ++i)
        {
            //每次遍历完一个位置，都向后挪一个元素
            if (i != 0)
            {
                occ.erase(s[i - 1]);
            }
            //判断没有重复就继续插入
            while (rk + 1 < n && !occ.count(s[rk + 1]))
            {
                occ.insert(s[rk + 1]);
                ++rk;
            }
            //找最大值
            ans = max(ans, rk + 1 - i);
        }
        return ans;
    }
};