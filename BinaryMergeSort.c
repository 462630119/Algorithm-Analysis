#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include<math.h>
#define MAX 0x11111111

void Merge(int* A, int p, int q, int r)
{   
    int n1 = q - p + 1;
    int n2 = r - q;
    assert(n1 >= 0 && n2 >= 0);
    int* ltmp = (int*)malloc(sizeof(int) * (n1 + 1));
    int* rtmp = (int*)malloc(sizeof(int) * (n2 + 1));
    int i, j, k;
    for(i = p, j = 0; i <= q; i++, j++)
    {
        ltmp[j] = A[i];     
    }
    for(i = q+1, j = 0; i <= r; i++, j++)
    {
        rtmp[j] = A[i];
    }

    ltmp[n1] = MAX;
    rtmp[n2] = MAX;

    for(i = 0, j = 0, k = p; k <= r; k++)
    {
        if(ltmp[i] <= rtmp[j])
        {
            A[k] =  ltmp[i];
            i++;
        }
        else
        {
            A[k] =  rtmp[j];
            j++;
        }
    }
    free(ltmp);
    free(rtmp);
}

void MergeSort(int* A, int p, int r)
{
    assert(A);
    if(r > p)
    {
        int q = (p + r) / 2;
        MergeSort(A, p, q);
        MergeSort(A, q + 1, r);
        Merge(A, p, q, r);
    }
}

int main()
{
    int A[10] = {9, 8, 7, 3, 4, 5, 6, 1, 2, 0};
    int k;
    MergeSort(A, 0, 9);
    for(k = 0; k < 10; k++)
    {
        printf("%d\n", A[k]);
    }

    return 0;
}
————————————————
版权声明：本文为CSDN博主「Eric2016_Lv」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/Eric2016_Lv/article/details/52727385
