//
// Created by 杨霖 on 2019/1/23.
//

#include <cstdio>
using namespace std;
#define MAXSIZE 100

int N;
int result[MAXSIZE][MAXSIZE];
int main() {
    int i, j;
    scanf("%d", &N);
    for(i=0; i<N; i++) {
        for(j=0; j<N; j++) {
            scanf("%d", &result[i][j]);
        }
    }

    // 判断矩阵的转制是否相同与原矩阵
    for(i=0; i<N; i++) {
        for(j=i; j<N; j++) {
            if(result[i][j] != result[j][i]) {
                printf("No!");
                return 0;
            }
        }
    }
    printf("Yes!");
    return 0;
}