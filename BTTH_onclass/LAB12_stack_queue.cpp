#include <stdio.h>
#define MAX 100

int Stack[MAX]; // Mảng lưu trữ dữ liệu của stack
int k = -1;     // Chỉ số của phần tử được lấy ra đầu tiên hay phần tử cuối của danh sách

void createS()
{
    k = -1;
}
int emptyS()
{
    return k == -1;
}
void pushS(int x)
{
    if (k == MAX - 1)
        printf("\nStack full!");
    else
    {
        k++;
        Stack[k] = x;
    }
}
int topS()
{
    if (emptyS())
    {
        printf("\nStack empty!");
        return 0;
    }
    else
        return Stack[k];
}
void popS()
{
    if (emptyS())
        printf("\nStack rong!");
    else
        k--;
}
int main()
{
    createS();
    pushS(1);
    pushS(2);
    pushS(3);
    printf("x =%5d", topS());
    popS();
    printf("\nx =%5d", topS());
    return 0;
}