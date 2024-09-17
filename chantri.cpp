#include <stdio.h>

int KeoTheo(int p, int q);
int Hoi(int p, int q);
int TuongDuong(int p, int q);

int main()
{
    int VT[4], VP[4], n = 4;
    int count = 0;
    printf("| p | q | p → q | q → p | ( p → q )^( q → p) | p ↔ q|\n");
    printf("______________________________________________________\n");
    for (int p = 0; p <= 1; p++)
    {
        for (int q = 0; q <= 1; q++)
        {
            int vetrai = Hoi(KeoTheo(p, q), KeoTheo(q, p));
            int vephai = TuongDuong(p, q);
            VT[count] = vetrai;
            VP[count] = vephai;
            printf("| %d | %d |   %d   |   %d   |          %d         |  %d  |  \n", p, q, KeoTheo(p, q), KeoTheo(q, p), Hoi(KeoTheo(p, q), KeoTheo(q, p)), TuongDuong(p, q));
            count++;
        }
    }
    printf("______________________________________________________\n\n");
    int check = 1;
    for (int i = 0; i < 4; i++)
    {
        if (VT[i] != VP[i])
        {
            check = 0;
            break;
        }
    }
    if (check)
    {
        printf("Mệnh đề ( p → q )^( q → p) = p ↔ q là đúng\n");
    }
    return 0;
}
int KeoTheo(int p, int q)
{
    if (q && !p)
        return 0;
    return 1;
}
int Hoi(int p, int q)
{
    if (p && q)
        return 1;
    return 0;
}
int TuongDuong(int p, int q)
{
    if (p == q)
        return 1;
    return 0;
}
