//
// Created by 杨霖 on 2019/1/22.
//

#include <cstdio>
using namespace std;

int N;
int main() {
    scanf("%d", &N);
    int num = N*N;
    while(N != 0) {
        int temp1 = N%10, temp2 = num%10;
        if(temp1 != temp2) {
            printf("No!");
            return 0;
        }
        num /= 10;
        N /= 10;
    }
    printf("Yes!");
    return 0;
}

