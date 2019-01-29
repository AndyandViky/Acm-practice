//
// Created by 杨霖 on 2019/1/29.
// 对给定的一个字符串，找出有重复的字符，并给出其位置，如：abcaaAB12ab12 输出：a，1；a，4；a，5；a，10，b，2；b，11，1，8；1，12， 2，9；2，13。
//

#include <cstdio>
#include <string.h>
using namespace std;
#define MAXSIZE 100

int main() {
    char data[MAXSIZE] = "", result[MAXSIZE] = "";
    while(scanf("%s", &data) != EOF) {
        int i, j, count = 0, length = strlen(data), tags[MAXSIZE*5] = {0};
        // 找出重复元素
        for(i=0; i<length-1; i++) {
            int ascii = (int)data[i];
            for(j=i+1; j<length; j++) {
                if(data[i] == data[j] && tags[ascii] != 1) {
                    tags[ascii] = 1;
                    result[count++] = data[i];
                    break;
                }
            }
        }
        // 遍历输出重复元素的位置
        int rlength = strlen(result);
        for(i=0; i<rlength; i++) {
            char tempStr[MAXSIZE] = "", tempStr1[MAXSIZE] = "";
            for(j=0; j<length; j++) {
                if(result[i] == data[j]) {
                    char t[10];
                    sprintf(t, "%c:%d,", result[i], j);
                    strcat(tempStr, t);
                }
            }
            strncpy(tempStr1, tempStr, strlen(tempStr)-1);
            printf("%s\n", tempStr1);
        }
    }
    return 0;
}
