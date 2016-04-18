/*
    二分递归，数组求和
 */

#include <stdio.h>

int sum(int *A, int lo, int hi) {
    if (lo == hi) {
        return A[lo];
    }
    int mi = (lo + hi) >> 1;
    return sum(A, lo, mi) + sum(A, mi + 1, hi);
}

int main() {
    int A[3] = {1, 2, 3};
    printf("%d\n", sum(A, 0, 2));
    return 0;
}