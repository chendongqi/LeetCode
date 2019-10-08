#include "stdio.h"
#include "stdbool.h"

// 解决方案1 start @{
// 动态栈的形式
// LeetCode运行结果：
// 执行用时 :4 ms, 在所有 C 提交中击败了71.48% 的用户
// 内存消耗 :7.6 MB, 在所有 C 提交中击败了7.04%的用户
#if 0
#define EMPTY_TOP -1

typedef char Element;

typedef struct {
    int capacity;
    Element *data;
    int stackTop;
} SeqStack;

typedef SeqStack *Stack;

Stack createStack(int capacity);
void makeStackEmpty(Stack stack);
Element top(Stack stack);
int push(Stack stack, Element e);
Element pop(Stack stack);
bool isEmpty(Stack stack);
bool isFull(Stack stack);

Stack createStack(int capacity) {
    Stack S;
    S = (Stack) malloc(sizeof(SeqStack));
    if (S == NULL) {
        printf("Error: malloc stack error!!!\n");
        return NULL;
    }
    S->data = (Element*)malloc(sizeof(Element) * capacity);
    if(S->data == NULL) {
        printf("Error: malloc data error!!!\n");
        return NULL;
    }
    S->capacity = capacity;
    S->stackTop = EMPTY_TOP;
    return S;
}

void makeStackEmpty(Stack stack) {
    if(stack != NULL) {
        stack->stackTop = EMPTY_TOP;
    } else {
        printf("Error: stack is NULL!!!\n");
    }
}

Element top(Stack stack) {
    if (stack == NULL) {
        printf("Error: stack is NULL!!!\n");
        return NULL;
    } else if(stack->data == NULL) {
        printf("Error: stack data is NULL!!!\n");
        return NULL;
    } else if(isEmpty(stack)) {
        printf("Warning: stack data is empty!!!\n");
        return NULL;
    }  else {
        return stack->data[stack->stackTop];
    }
}

Element pop(Stack stack) {
    if (stack == NULL) {
        printf("Error: stack is NULL!!!\n");
        return NULL;
    } else if(stack->data == NULL) {
        printf("Error: stack data is NULL!!!\n");
        return NULL;
    } else if(isEmpty(stack)) {
        printf("Warning: stack data is empty!!!\n");
        return NULL;
    }  else {
        return stack->data[stack->stackTop--];
    }
}

int push(Stack stack, Element e) {
    if (stack ==NULL) {
        printf("Error: stack is NULL!!!\n");
        return -1;
    } else if (stack->data == NULL) {
        printf("Error: stack data is NULL!!!\n");
        return -2;
    } else if (isFull(stack)) {
        printf("Warning: stack is full!!!\n");
        return -3;
    } else {
        stack->data[++stack->stackTop] = e;
        return 0;
    }
}

bool isEmpty(Stack stack) {
    if (stack->stackTop == EMPTY_TOP)
        return true;
    else
        return false;
}

bool isFull(Stack stack) {
    if (stack->stackTop < stack->capacity - 1)
        return false;
    else
        return true;
}

bool isValid(char * s){
    int i = 0;
    Stack S = createStack(128);
    while(s[i] != '\0') {
        switch(s[i]) {
            case '(':
            case '[':
            case '{':
                push(S, s[i++]);
                break;
            case ')':
                if (pop(S) != '(')
                    return false;
                else {
                    i++;
                    break;
                }
            case ']':
                if (pop(S) != '[')
                    return false;
                else {
                    i++;
                    break;
                }
            case '}':
                if (pop(S) != '{')
                    return false;
                else {
                    i++;
                    break;
                }
            default:
                break;
        }        
    }
    if (isEmpty(S))
        return true;
    else
        return false;
}
#endif
// 解决方案1 end @}

// 解决方案2 start @{
// 静态栈的方式
// LeetCode运行结果：
// 执行用时 :4 ms, 在所有 C 提交中击败了71.48% 的用户
// 内存消耗 :7.9 MB, 在所有 C 提交中击败了5.73%的用户

#if 0

#define MAX_SIZE 10240
#define EMPTY_TOP -1

typedef char Element;
typedef struct {
    Element data[MAX_SIZE];
    int stackTop;
} SeqStack;

typedef SeqStack *Stack;

Stack createStack();
int push(Stack stack, Element e);
Element pop(Stack stack);
Element top(Stack stack);
bool isEmpty(Stack stack);
bool isFull(Stack stack);

Stack createStack() {
    Stack S = (Stack)malloc(sizeof(SeqStack));
    if(S == NULL) {
        printf("Error: malloc stack failed!!!\n");
        return NULL;
    }
    S->stackTop = EMPTY_TOP;
    return S;
}

Element pop(Stack stack) {
    if (stack == NULL) {
        printf("Error: stack is NULL!!!\n");
        return NULL;
    } else if (isEmpty(stack)) {
        printf("Warning: stack is empty!!!\n");
        return NULL;
    } else {
        return stack->data[stack->stackTop--];
    }
}

Element top(Stack stack) {
    if (stack == NULL) {
        printf("Error: stack is NULL!!!\n");
        return NULL;
    } else if (isEmpty(stack)) {
        printf("Warning: stack is empty!!!\n");
        return NULL;
    } else {
        return stack->data[stack->stackTop];
    }
}

int push(Stack stack, Element e) {
    if(stack == NULL) {
        printf("Error: stack is NULL!!!\n");
        return -1;
    } else if (isFull(stack)) {
        printf("Warning: stack is full!!!\n");
        return -2;
    } else {
        stack->data[++stack->stackTop] = e;
        return 0;
    }
}

bool isEmpty(Stack stack) {
    if (stack->stackTop == EMPTY_TOP)
        return true;
    else
        return false;
}

bool isFull(Stack stack) {
    if (stack->stackTop < MAX_SIZE - 1)
        return false;
    else
        return true;
}

bool isValid(char * s){
    int i = 0;
    Stack S = createStack();
    while(s[i] != '\0') {
        switch(s[i]) {
            case '(':
            case '[':
            case '{':
                push(S, s[i++]);
                break;
            case ')':
                if (pop(S) != '(')
                    return false;
                else {
                    i++;
                    break;
                }
            case ']':
                if (pop(S) != '[')
                    return false;
                else {
                    i++;
                    break;
                }
            case '}':
                if (pop(S) != '{')
                    return false;
                else {
                    i++;
                    break;
                }
            default:
                break;
        }        
    }
    if (isEmpty(S))
        return true;
    else
        return false;
}
#endif
// 解决方案二 end @}

// 解决方案三 start @{
// 使用链表来实现栈(采用头插法)，动态分配空间，内存方面会比数组实现优化一点
// LeetCode执行结果：
// 执行用时 :8 ms, 在所有 C 提交中击败了19.39% 的用户
// 内存消耗 :7 MB, 在所有 C 提交中击败了64.81%的用户

typedef char ElemType;
typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

LinkList createList() {
    LinkList S = (LinkList) malloc (sizeof(LNode));
    if (S == NULL) {
        printf("Error: malloc stack failed!!!\n");
        return NULL;
    }
    S->next = NULL;
    return S;
}

int push(LinkList S, ElemType e) {
    if (S == NULL) {
        printf("Error: Stack is NULL!!!\n");
        return -1;
    }
    LNode *topNode = (LNode*)malloc(sizeof(LNode));
    if (topNode == NULL) {
        printf("Error: maolloc node failed!!!\n");
        return -2;
    }
    topNode->data = e;
    topNode->next = S->next;
    S->next = topNode;
    return 0;
}

LNode* pop(LinkList S) {
    if (S == NULL) {
        printf("Error: Stack is NULL!!!\n");
        return NULL;
    } else if(S->next == NULL) {
        printf("Error: Stack is empty!!!!\n");
        return NULL;
    }
    LNode *topNode = S->next;
    S->next = topNode->next;
    return topNode;
}

bool isValid(char * s){
    LinkList LL = createList();
    if (LL == NULL) {
        printf("create linklist failed!!!\n");
        return false;
    }
    
    int i = 0;
    LNode *node;
    while(s[i] != '\0') {
        printf("come char is %c\n", s[i]);
        switch(s[i]) {
            case '(':
            case '[':
            case '{':
                push(LL, s[i++]);
                break;
            case ')':
                node = pop(LL);
                if(node == NULL)
                    return false;
                printf("data is %c\n", node->data);
                if(node->data != '(')
                    return false;
                i++;
                free(node);
                break;
            case ']':
                node = pop(LL);
                if(node == NULL)
                    return false;
                printf("data is %c\n", node->data);
                if(node->data != '[')
                    return false;
                i++;
                free(node);
                break;
            case '}':
                node = pop(LL);
                if(node == NULL)
                    return false;
                printf("data is %c\n", node->data);
                if(node->data != '{')
                    return false;
                i++;
                free(node);
                break;
            default:
                printf("Error: invalid input of %c\n", s[i]);
                return false;
        }
    }
    if (LL->next == NULL)
        return true;
    else
        return false;
}

// 解决方案三 end @{


int main() {
    char str[] = {"[]({}){{{}}}[([({})])]"};
    if (isValid(str))
        printf("result is true\n");
    else
        printf("result is false\n");
    return 0;
}
