#include <iostream>

using namespace std;

int mTestArray[3] = {1, 2, 3};

/*
    compare times：
        n - 1 + n - 2 = 2n - 3
 */
void max2_1(const int *A, int lo, int hi, int &x1, int &x2) {
    int i;
    for (x1 = lo, i = lo + 1; i < hi; i++) {
        if (A[x1] < A[i]) {
            x1 = i;
        }
    }
    for (x2 = lo, i = lo + 1; i < x1; i++) {
        if (A[x2] < A[i]) {
            x2 = i;
        }
    }
    for (int i = x1 + 1; i < hi; i++) {
        if (A[x2] < A[i]) {
            x2 = i;
        }
    }
}

/*
    compare times:
        at best: 1 + n - 2 = n + 1
        at worst: 1 + 2 * (n - 2) * 2 = 2n - 3
 */
void max2_2(const int *A, int lo, int hi, int &x1, int &x2) {
    int i;
    if (A[x1 = lo] < A[x2 = lo + 1]) {
        swap(x1, x2);
    }
    for (i = lo + 2; i < hi; i++) {
        if (A[x2] < A[i]) {
            if (A[x1] < A[x2 = i]) {
                swap(x1, x2);
            }
        }
    }
}

/*
    compare times：
        T(2) = 1;
        T(3) <= 3;
        T(n) = 2 * T(n / 2) + 2 <= (5 / 3)n - 2;
 */
void max2_3(const int *A, int lo, int hi, int &x1, int &x2) {
    if (lo + 2 == hi) {
        x1 = lo;
        x2 = lo + 1;
        if (A[x1] < A[x2]) {
            swap(x1, x2);
        }
        return;
    }
    if (lo + 3 == hi) {
        x1 = lo;
        x2 = lo + 1;
        if (A[x1] < A[x2]) {
            swap(x1, x2);
        }
        if (A[lo + 2] >= A[x1]) {
            x2 = x1;
            x1 = lo + 2;
        } else {
            if (A[lo + 2] > A[x2]) {
                x2 = lo + 2;
            }
        }
        return;
    }
    int mi = (lo + hi) / 2;
    int x1L, x2L;
    int x1R, x2R;
    max2_3(A, lo, mi, x1L, x2L);
    max2_3(A, mi, hi, x1R, x2R);
    if (A[x1L] > A[x1R]) {
        x1 = x1L;
        x2 = (A[x2L] > A[x1R]) ? x2L : x1R;
    } else {
        x1 = x1R;
        x2 = (A[x1L] > A[x2R]) ? x1L : x2R;
    }
}

void test_max2_1() {
    int a;
    int b;
    max2_1(mTestArray, 0, 3, a, b);
    cout << mTestArray[a] << "\n" << mTestArray[b] << endl;
}

void test_max2_2() {
    int a;
    int b;
    max2_2(mTestArray, 0, 3, a, b);
    cout << mTestArray[a] << "\n" << mTestArray[b] << endl;
}

void test_max2_3() {
    int a;
    int b;
    max2_3(mTestArray, 0, 3, a, b);
    cout << mTestArray[a] << "\n" << mTestArray[b] << endl;
}
int main(int argc, const char * argv[]) {
    test_max2_1();
    test_max2_2();
    test_max2_3();
    return 0;
}