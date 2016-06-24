#include <stdio.h>

/*
 将一个字符移到字符串尾部
 */
void leftOne(char* s, int n) {
    // 保存第一个字符
    char t = s[0];
    for (int i = 1; i < n; i++) {
        s[i - 1] = s[i];
    }
    s[n - 1] = t;
}

/*
 将 m 个字符一道字符串尾部
 */
void leftMOne (char* s, int n, int m) {
    while (m--) {
        leftOne(s, n);
    }
}

int main(int argc, const char * arg[]) {
    char *s = "abcdef";
    leftMOne(s, strlen(s), 3);
    return 0;
}