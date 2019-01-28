//
// Created by 杨霖 on 2019/1/28.
//

#include <cstdio>
#include <string.h>
using namespace std;

int main() {
    char result[1000];
    while(scanf("%s", &result) != EOF) {
        int length = strlen(result);
        bool isT = false;
        for(int i=0; i<length; i++) {
            if(result[i] != result[length-i-1]) {
                printf("No!\n");
                isT = true;
                break;
            }
        }
        if(!isT) printf("Yes!\n");
    }
    return 0;
}

