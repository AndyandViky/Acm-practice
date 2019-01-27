//
// Created by 杨霖 on 2019/1/23.
//

#include <cstdio>
#include <string.h>
using namespace std;
#define MAXSIZE 2000

char A[MAXSIZE], B[MAXSIZE];
int main() {
    int i, j, s1 = false, s2 = false, rA = 0, rB = 0, carry = 1;
    scanf("%s %s", &A, &B);
    if(A[0] == '-') {
        strcpy(A, A+1);
        s1 = true;
    }
    if(B[0] == '-') {
        strcpy(B, B+1);
        s2 = true;
    }
    int len1 = strlen(A), len2 = strlen(B);
    // 预处理两个字符串，将 '，'去掉
    for(i=0; i<len1; i++) {
        if(A[i] == ',') {
            for(j=i; j<len1-1; j++)  {
                A[j] = A[j+1];
            }
            len1--;
        }
    }
    for(i=0; i<len2; i++) {
        if(B[i] == ',') {
            for(j=i; j<len2-1; j++)  {
                B[j] = B[j+1];
            }
            len2--;
        }
    }

    for(i=len1-1; i>=0; i--) {
        rA += carry*(A[i]-'0');
        carry *= 10;
    }
    carry = 1;
    for(i=len2-1; i>=0; i--) {
        rB += carry*(B[i]-'0');
        carry *= 10;
    }
    if(s1) rA = -rA;
    if(s2) rB = -rB;

    printf("%d", rA+rB);
    return 0;
}


