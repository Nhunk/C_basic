#include <stdio.h>
#include <stack>
using namespace std;

struct node
{
    char data;
    node *left, *right;
};

void TTHT(char TT[], char HT[]);
node *TaoNode(char a);
node *BSTHT(char a[], int n);
void LRN(node *T);

int main()
{
    char TT[] = "(1+2)/3-((4-5)*6)", HT[100];

    // Đổi biểu thức từ trung tố sang hậu tố
    TTHT(TT, HT);

    // Tạo cây nhị phân từ biểu thức hậu tố
    node *T = BSTHT(HT, 11);

    // Duyệt hậu tự cây nhị phân vừa tạo
    printf("Duyet hau tu cay: ");
    LRN(T);
}
void TTHT(char TT[], char HT[])
{
    int n = 0;
    stack<char> s;
    for (int i = 0; TT[i] != '\0'; i++)
    {
        char ch = TT[i];
        switch (ch)
        {
        case '(':
            s.push(ch);
            break;
        case ')':
            while (!s.empty() && s.top() != '(')
            {
                HT[n++] = s.top();
                s.pop();
            }
            s.pop();
            break;
        case '+':
        case '-':
            while (!s.empty() && s.top() != '(' && s.top() != ')')
            {
                HT[n++] = s.top();
                s.pop();
            }
            s.push(ch);
            break;
        case '*':
        case '/':
            while (!s.empty() && (s.top() == '*' || s.top() == '/'))
            {
                HT[n++] = s.top();
                s.pop();
            }
            s.push(ch);
            break;
        default:
            HT[n++] = ch;
        }
    }
    while (!s.empty())
    {
        HT[n++] = s.top();
        s.pop();
    }
    HT[n] = '\0';
    printf("Bieu thuc doi sang hau to: ");
    puts(HT);
}
node *TaoNode(char a)
{
    node *p = new node;
    p->data = a;
    p->left = NULL;
    p->right = NULL;
    return p;
}
node *BSTHT(char a[], int n)
{
    stack<node *> s;
    for (int i = 0; i < n; i++)
    {
        if (a[i] >= '0' && a[i] <= '9')
        {
            s.push(TaoNode(a[i]));
        }
        else
        {
            node *p = TaoNode(a[i]);
            p->right = s.top();
            s.pop();
            p->left = s.top();
            s.pop();
            s.push(p);
        }
    }
    return s.top();
}
void LRN(node *T)
{
    if (T != NULL)
    {
        LRN(T->left);
        LRN(T->right);
        printf("%3c", T->data);
    }
}