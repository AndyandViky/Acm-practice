//
// Created by 杨霖 on 2019/1/29.
// 输入n， 求y1=1!+3!+...m!(m是小于等于n的最大奇数） y2=2!+4!+...p!(p是小于等于n的最大偶数)。
//

#include <cstdio>
using namespace std;

int getStratum(int n) {
    int result = 1;
    for(int i=1; i<=n; i++) {
        result *= i;
    }
    return result;
}
int getOdd(int n, int count) {
    if(n > 0) {
        // 获取奇数
        if(n%2 == 0) n--;
        count = getOdd(n-2, count) + getStratum(n);
    }
    return count;
}
int getEven(int n, int count) {
    // 获取偶数
    if(n > 0) {
        if(n%2 != 0) n--;
        count = getEven(n-2, count) + getStratum(n);
    }
    return count;
}
int main() {
    int n;
    while(scanf("%d", &n) != EOF) {
        printf("%d ", getOdd(n, 0));
        printf("%d\n", getEven(n, 0));
    }
    return 0;
}

