#include <iostream>

using namespace std;

int mTestArray[3] = {1, 2, 3};

/*
    最low的方式
    比较次数：n - 1 + n - 2 = 2n - 3
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

void test_max2_1() {
    int a;
    int b;
    int &x1 = a;
    int &x2 = b;
    max2_1(mTestArray, 0, 3, x1, x2);
    cout << mTestArray[x1] << "\n" << mTestArray[x2];
}

int main(int argc, const char * argv[]) {
    test_max2_1();
    return 0;
}