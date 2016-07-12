#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#define PARENT(i) (i) / 2
#define LEFT(i) 2 * (i) + 1
#define RIGHT(i) 2 * (i + 1)
#define ARRAY_SIZE(a) ( (sizeof(a)) / (sizeof(a[0])) )

void swap(int *a, int *b) {
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

void max_heapify(int *arr, int index, int len) {
    int l = LEFT(index);
    int r = RIGHT(index);
    int largest;
    if(l < len && arr[l] > arr[index])
        largest = l;
    else
        largest = index;
    if(r < len && arr[r] > arr[largest])
        largest = r;
    if(largest != index){ //将最大元素提升，并递归
        swap(&arr[largest], &arr[index]);
        max_heapify(arr, largest, len);
    }
}

/*
 建堆
 一棵树有 n 个结点，从第（n / 2 + 1）个结点到第 n 个结点，是叶子结点，不需要进行堆的维护。
 注：第 (n + 1) 个数，下标是 n。
 */
void build_max_heap(int *arr, int len) {
    int i;
    if (arr == NULL || len <= 1)
        return;
    for (i = len / 2 - 1; i >= 0; --i)
        max_heapify(arr, i, len);
}

void heap_sort(int *arr, int len) {
    
    int i;
    if (arr == NULL || len <= 1)
        return;
    build_max_heap(arr, len);

    for (i = len - 1; i >= 1; --i) {
        swap(&arr[0], &arr[i]);
        max_heapify(arr, 0, --len);
    }
}

int main() {
    int arr[] = {1, 4, 2, 9, 8, 12, 14, 80, 0};
    int i;
    heap_sort(arr, ARRAY_SIZE(arr));
    for (i = 0; i < ARRAY_SIZE(arr); ++i)
        printf("%d ", arr[i]);
    return 0;
}