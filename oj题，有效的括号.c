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
//以上是栈的接口函数

/*题目：给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
每个右括号都有一个对应的相同类型的左括号*/

/*示例 1：

输入：s = "()"
输出：true
示例 2：

输入：s = "()[]{}"
输出：true
示例 3：

输入：s = "(]"
输出：false
 */


bool isValid(char* s) {
    //自己创建一个栈
    ST st;
    StackInit(&st);
    while (*s)
    {
        //如果是左括号就入栈
        if (*s == '('
            || *s == '['
            || *s == '{')
        {
            StackPush(&st, *s);
            ++s;
        }
        //如果是右括号就出栈与右括号比较，看是否匹配
        else
        {
            //遇到右括号了，但是栈里没有数据，说明
            //前面没有左括号，不匹配，返回false
            if (StackEmpty(&st))
            {
                //返回前要销毁栈，否则会造成内存泄漏
                StackDestroy(&st);
                return false;
            }
            int Top = StackTop(&st);
            StackPop(&st);
            if ((*s == ')' && Top != '(')
                || (*s == '}' && Top != '{')
                || (*s == ']' && Top != '['))
            {
                //返回前要销毁栈，否则会造成内存泄漏
                StackDestroy(&st);
                return false;
            }
            else
            {
                ++s;
            }
        }
    }
    //如果栈内有数据说明没有匹配完，说明不匹配
    //用bool类型记录返回值
    //如果为空返回真，否则返回假
    bool ret = StackSize(&st) == 0;
    StackDestroy(&st);
    return ret;
}