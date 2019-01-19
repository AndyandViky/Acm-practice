//
// Created by 杨霖 on 2019/1/19.
//

#include <cstdio>
#include <string.h>
using namespace std;
#define MAXSIZE 202

char CHAR1[MAXSIZE], CHAR2[MAXSIZE];

int main() {
    int i = 0, j = 0 ;
    scanf("%s %s", CHAR1, CHAR2);
    while(true) {
        if(!CHAR1[i]) {
            if(!CHAR2[j]) {
                break;
            }
            else {
                CHAR1[i++] = CHAR2[j++];
            }
        } else i++;
    }
    printf("%s", CHAR1);
    return 0;
}
