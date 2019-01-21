//
// Created by 杨霖 on 2019/1/21.
//

#include "stdio.h"
#include <string.h>
using namespace std;
#define MAXSIZE 100
#define RESULTSIZE 8

char preC[MAXSIZE];
int preResult[RESULTSIZE];
void check(char pre) {
    int i, count = 0;
    int asPre = (int)pre; //获取ascii码
    // 转换为二进制
    for(i=0; i<RESULTSIZE; i++) {
        preResult[RESULTSIZE-1-i] = asPre%2;
        asPre /= 2;
    }
    // 计算1的个数
    for(i=0; i<RESULTSIZE; i++) {
        if(preResult[i] == 1) count++;
    }
    // 校验
    if(count%2 == 0) {
        for(i=0; i<RESULTSIZE; i++) {
            if(preResult[i] == 0) {
                preResult[i] = 1;
                break;
            }
        }
    }
    for(i=0; i<RESULTSIZE; i++) {
        printf("%d", preResult[i]);
    }
}
int main() {
    scanf("%s", preC);
    int length = strlen(preC);
    for(int i=0; i<length; i++) {
        check(preC[i]);
        if(i != length-1) printf("\n");
    };
    return 0;
}