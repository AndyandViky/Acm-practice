//
// Created by 杨霖 on 2019/1/16.
//

#include <cstdio>
using namespace std;

int N;
int main() {
    scanf("%d", &N);
    if (N == 1) {
        printf("%d", 0);
        return 0;
    }
    int count = 0;
    while(N != 1) {
        if(N%2 == 0) {
            N/=2;
        }
        else {
            N = (3*N+1)/2;
        }
        count++;
    }
    printf("%d", count);
    return 0;
}