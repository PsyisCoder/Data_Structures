#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

/*��Ŀ������Ҫ����ݸ�����һ�ö������ĺ�����������������������������ǰ����������

�����ʽ:
��һ�и��������� n (��30)�������н��ĸ�����������У�ÿ�и��� n ���������ֱ��Ӧ������������������������ּ��Կո�ָ�����Ŀ��֤������ȷ��Ӧһ�ö�������

�����ʽ:
��һ�������Preorder: �Լ�������ǰ�������������ּ���1���ո���ĩ�����ж���ո�

��������:
7
2 3 1 5 7 6 4
1 2 3 4 5 6 7
�������:
Preorder: 4 1 3 2 6 5 7
*/





//��⣺

void dfs(int n, int* last, int* in)
{
    //������ĳ���Ϊ0��ֹͣ
    if (n != 0)
    {
        //���ڵ�����
        printf(" %d", last[n - 1]);
        //�ҵ����ڵ�������������λ��
        int i;
        for (i = 0; i < n; i++)
            if (in[i] == last[n - 1])
                break;
        //��ڵ�ݹ�
        dfs(i, last, in);
        //�ҽڵ�ݹ�
        dfs(n - 1 - i, last + i, in + i + 1);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int last[31], in[31];
    for (int i = 0; i < n; i++)
        scanf("%d", &last[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &in[i]);

    printf("Preorder:");
    dfs(n, last, in);
    return 0;
}