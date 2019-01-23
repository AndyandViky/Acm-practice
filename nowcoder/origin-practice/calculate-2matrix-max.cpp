//
// Created by 杨霖 on 2019/1/23.
//

#include <cstdio>
using namespace std;
#define MAXSIZE 100

int N, M;
int result[MAXSIZE][MAXSIZE];
int main() {
    int i, j, count, max, index;
    scanf("%d %d", &M, &N);
    for(i=0; i<M; i++) {
        for(j=0; j<N; j++) {
            scanf("%d", &result[i][j]);
        }
    }
    for(i=0; i<M; i++) {
        count = 0;
        for(j=0; j<N; j++) {
            count += result[i][j];
        }
        max = result[i][0];
        index = 0;
        for(j=1; j<N; j++) {
            if(max < result[i][j]) {
                max = result[i][j];
                index = j;
            }
        }
        result[i][index] = count;
    }

    for(i=0; i<M; i++) {
        for(j=0; j<N; j++) {
            if(j != N-1) printf("%d ", result[i][j]);
            else printf("%d", result[i][j]);
        }
        if(i != M-1) printf("\n");
    }
    return 0;
}
