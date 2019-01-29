//
// Created by 杨霖 on 2019/1/29.
// 输入一个整数，将其转换成八进制数输出。
// %o 八进制
// %x %X 十六进制
//

#include <cstdio>
using namespace std;

int main() {
    int n;
    while(scanf("%d", &n) != EOF) {
        printf("%o\n", n);
    }
    return 0;
}