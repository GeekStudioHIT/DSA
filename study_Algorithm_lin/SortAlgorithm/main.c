//数据结构向量、列表两节中的排序算法

#include <stdio.h>
#include <stdlib.h>

void bubbleSort (int a[], int n);
int bubble (int a[], int n);
void mergeSort(int a[], int lo, int hi);
void merge (int a[], int lo, int mi, int hi);
int main()
{
    int n;
    printf("Please input n:");
    scanf("%d", &n);
    int a[n];
    printf("Please input a[]:");
    int i;
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    //bubbleSort(a, n);//起泡排序算法
    mergeSort(a, 0, n);
    for(i = 0; i < n; i++)
        printf("%d\n", a[i]);
    return 0;
}

//起泡排序算法
void bubbleSort (int a[], int n)
{
    while (!bubble(a, n--));
}
int bubble (int a[], int n)
{
    int sorted = 1;
    int i = 0;
    while(++i < n)
    {
        if (a[i - 1] > a[i])
        {
            sorted = 0;
            int sw = a[i - 1];
            a[i - 1] = a[i];
            a[i] = sw;
        }
    }
    return sorted;
}
//归并排序算法
void mergeSort(int a[], int lo, int hi)
{
    if (hi - lo < 2)
        return;
    int mi = (lo + hi)/2;
    mergeSort(a, lo, mi);
    mergeSort(a, mi, hi);
    merge(a, lo, mi , hi);
}

void merge (int a[], int lo, int mi, int hi)
{
    int *A = &a[lo];
    int lb = mi - lo;
    int b[lb];
    int i = 0;
    while (i < lb)
    {
        b[i] = *(A + i);
        i++;
    }

    int lc = hi - mi;
    int *c = &a[mi];
    int j = 0, k = 0;
    i = 0;
    while ((j <lb)||(k < lc))
    {
        if ((j < lb)&&(lc <= k || (b[j] <= *(c + k))))
            *(A + i++) = b[j++];
        if ((k < lc)&&((lb <= j || (*(c + k) < b[j]))))
            *(A + i++) = *(c + k++);
    }

}
