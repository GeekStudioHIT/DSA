#include <iostream>

using namespace std;

int mTestArray[3] = {1, 2, 3};

/*
    compare times：n - 1 + n - 2 = 2n - 3
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

void test_max2_1() {
    int a;
    int b;
    int &x1 = a;
    int &x2 = b;
    max2_1(mTestArray, 0, 3, x1, x2);
    cout << mTestArray[x1] << "\n" << mTestArray[x2] << endl;
}

void test_max2_2() {
    int a;
    int b;
    int &x1 = a;
    int &x2 = b;
    max2_2(mTestArray, 0, 3, x1, x2);
    cout << mTestArray[x1] << "\n" << mTestArray[x2] << endl;
}

int main(int argc, const char * argv[]) {
    test_max2_1();
    test_max2_2();
    return 0;
}