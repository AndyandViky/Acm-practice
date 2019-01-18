//
// Created by 杨霖 on 2019/1/17.
//

//
// Created by 杨霖 on 2019/1/17.
//

#include <cstdio>
#include "string.h"
using namespace std;
#define MAXSIZE 100

char strNumber[MAXSIZE];
char englishN[10][6] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};

int main() {
    int i, j=0, result=0;
    scanf("%s", strNumber);
    int length = strlen(strNumber);
    for(i=0; i<length; i++) {
        int temp = (int)strNumber[i]-48;
        result += temp;
    }
    // 判断是否为0
    if(result == 0) {
        printf("%s", englishN[0]);
        return 0;
    }
    // 划分位数
    int pathResult[MAXSIZE];
    while(result!=0) {
        int rt = result%10;
        result /= 10;
        pathResult[j++] = rt;
    }
    for(i=j-1; i>=0; i--) {
        if(i!=0) printf("%s ", englishN[pathResult[i]]);
        else printf("%s", englishN[pathResult[i]]);
    }
    return 0;
}