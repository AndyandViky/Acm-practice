//
// Created by 杨霖 on 2019/1/16.
//
#include "stdio.h"

int main() {
    int n, m, i, length;
    char root[2], child[100][2];
    while(1) {
        scanf("%d %d", &n, &m);
        if(n==0) return 0;
        getchar();
        scanf("%s %d", &root, &length);
        for(i=0; i<length; i++) {
            scanf("%s", &child[i]);
        }
        if(length == 0) printf("%d %d", 1, 0);
        printf("%d %d", 0, length);
    }
}