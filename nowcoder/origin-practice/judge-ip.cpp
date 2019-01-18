//
// Created by 杨霖 on 2019/1/18.
//

#include <cstdio>
#include "string.h"
#include "stdlib.h"
using namespace std;

int main() {
    char data[1000], *temp;
    scanf("%s", &data);
    for(int i = 0; i < 4; i++) {
        temp = strtok(data, ".");
        int sigle = atoi(temp);
        strcpy(data, data+strlen(temp) + 1);
        if(sigle < 0 || sigle > 255) {
            printf("No!\n");
            return 0;
        }
    }
    printf("Yes!\n");
    return 0;
}