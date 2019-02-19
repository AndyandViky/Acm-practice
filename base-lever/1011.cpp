//
// Created by 杨霖 on 2019/2/19.
// 大整数（含负数）的相加
// int 型 最大 2147483647 最小 -2147483648
//

#include <cstdio>
using namespace std;

int main() {
    int n, i, a, b, c;
    scanf("%d", &n);
    for(i=0; i<n; i++) {
        scanf("%d %d %d", &a, &b, &c);
            if(a<0 && b<0 && c>0) printf("Case #%d: false\n", i+1);
            else if(a>0 && b>0 && c<0) printf("Case #%d: true\n", i+1);
            else {
                if(a+b > c) printf("Case #%d: true\n", i+1);
                else printf("Case #%d: false\n", i+1);
        }
    }
    return 0;
}