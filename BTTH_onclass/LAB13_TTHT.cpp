#include <stdio.h>
#include <stack>
#include <cctype>
using namespace std;
void TTHT(char TT[], char HT[]);
int THT(char HT[]);
int main()
{
    char TT[] = "a*((b+3)+5)*(4-7)+b-9", HT[100];
    TTHT(TT, HT);
    int KQ = THT(HT);
    printf("Ket qua cua bieu thuc o dang hau to la: %d", KQ);
    return 0;
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
    puts(HT);
}
int THT(char HT[])
{
    stack<int> s;
    for (int i = 0; HT[i] != '\0'; i++)
    {
        char ch = HT[i];
        if (isdigit(ch))
        {
            s.push(ch - '0');
        }
        else
        {
            int k2 = s.top();
            s.pop();
            int k1 = s.top();
            s.pop();
            switch (ch)
            {
            case '+':
                s.push(k1 + k2);
                break;
            case '-':
                s.push(k1 - k2);
                break;
            case '*':
                s.push(k1 * k2);
                break;
            case '/':
                s.push(k1 / k2);
                break;
            }
        }
    }
    return s.top();
}
