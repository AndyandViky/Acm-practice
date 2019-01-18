//
// Created by 杨霖 on 2019/1/18.
//

#include <cstdio>
#include "string.h"
using namespace std;
#define MAXSIZE 10000

int main() {
    int i = 0, j = 0, count = 0;
    char phrase[MAXSIZE], tempC;
    while(true) {
        scanf("%c", &tempC);
        phrase[i++] = tempC;
        if(tempC == '.') break;
    }
    while(phrase[j]) {
        count++;
        if(phrase[j] == '.') {
            printf("%d", count-1);
            break;
        };  //最后一个 . 退出循环
        if(phrase[j] == ' ') {
            printf("%d ", count-1);
            count = 0;
        }
        j++;
    }
    return 0;
}

