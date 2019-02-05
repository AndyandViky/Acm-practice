//
// Created by 杨霖 on 2019/2/5.
//

#include <cstdio>
#include <cstring>
using namespace std;

int main() {
    int n, h, s, g, i;
    scanf("%d", &n);
    g = n%10;
    n /= 10;
    s = n%10;
    n /= 10;
    h = n%10;
    for(i=0; i<h; i++) {
        printf("B");
    }
    for(i=0; i<s; i++) {
        printf("S");
    }
    for(i=0; i<g; i++) {
        printf("%d", i+1);
    }
    return 0;
}

