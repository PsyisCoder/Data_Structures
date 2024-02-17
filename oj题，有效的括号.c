#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
typedef char STDatatype;
typedef struct Stack
{
    STDatatype* arr;
    int top;
    int capacity;
}ST;

void StackInit(ST* ps);
void StackDestroy(ST* ps);
void StackPush(ST* ps, STDatatype x);
void StackPop(ST* ps);
STDatatype StackTop(ST* ps);
int StackSize(ST* ps);
bool StackEmpty(ST* ps);

void StackInit(ST* ps)
{
    assert(ps);
    ps->arr = NULL;
    ps->capacity = 0;
    ps->top = -1;
}
void StackDestroy(ST* ps)
{
    assert(ps);
    free(ps->arr);
    ps->arr = NULL;
    ps->capacity = 0;
    ps->top = -1;
}
void StackPush(ST* ps, STDatatype x)
{
    assert(ps);
    if ((ps->top) + 1 == ps->capacity)
    {
        int newcapacity = ps->capacity == 0 ? 4 : (ps->capacity) * 2;
        ST* tmp = (ST*)realloc(ps->arr, sizeof(ST) * newcapacity);
        if (!tmp)
        {
            printf("realloc fail\n");
            exit(-1);
        }
        ps->arr = tmp;
        ps->capacity = newcapacity;
    }
    ps->top++;
    ps->arr[ps->top] = x;
}
void StackPop(ST* ps)
{
    assert(ps);
    assert(!StackEmpty(ps));
    ps->top--;
}
STDatatype StackTop(ST* ps)
{
    assert(ps);
    assert(!StackEmpty(ps));
    return ps->arr[ps->top];
}
int StackSize(ST* ps)
{
    assert(ps);
    return (ps->top) + 1;
}
bool StackEmpty(ST* ps)
{
    assert(ps);
    return ps->top == -1;
}
//������ջ�Ľӿں���

/*��Ŀ������һ��ֻ���� '('��')'��'{'��'}'��'['��']' ���ַ��� s ���ж��ַ����Ƿ���Ч��

��Ч�ַ��������㣺

�����ű�������ͬ���͵������űպϡ�
�����ű�������ȷ��˳��պϡ�
ÿ�������Ŷ���һ����Ӧ����ͬ���͵�������*/

/*ʾ�� 1��

���룺s = "()"
�����true
ʾ�� 2��

���룺s = "()[]{}"
�����true
ʾ�� 3��

���룺s = "(]"
�����false
 */


bool isValid(char* s) {
    //�Լ�����һ��ջ
    ST st;
    StackInit(&st);
    while (*s)
    {
        //����������ž���ջ
        if (*s == '('
            || *s == '['
            || *s == '{')
        {
            StackPush(&st, *s);
            ++s;
        }
        //����������žͳ�ջ�������űȽϣ����Ƿ�ƥ��
        else
        {
            //�����������ˣ�����ջ��û�����ݣ�˵��
            //ǰ��û�������ţ���ƥ�䣬����false
            if (StackEmpty(&st))
            {
                //����ǰҪ����ջ�����������ڴ�й©
                StackDestroy(&st);
                return false;
            }
            int Top = StackTop(&st);
            StackPop(&st);
            if ((*s == ')' && Top != '(')
                || (*s == '}' && Top != '{')
                || (*s == ']' && Top != '['))
            {
                //����ǰҪ����ջ�����������ڴ�й©
                StackDestroy(&st);
                return false;
            }
            else
            {
                ++s;
            }
        }
    }
    //���ջ��������˵��û��ƥ���꣬˵����ƥ��
    //��bool���ͼ�¼����ֵ
    //���Ϊ�շ����棬���򷵻ؼ�
    bool ret = StackSize(&st) == 0;
    StackDestroy(&st);
    return ret;
}