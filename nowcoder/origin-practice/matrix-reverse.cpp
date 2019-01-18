//
// Created by 杨霖 on 2019/1/18.
//

#include <cstdio>
using namespace std;
#define MAXSIZE 100

int N;

void print(int arr[][MAXSIZE]) {
    int i, j;
    for(i=0; i<N; i++) {
        for(j=0; j<N; j++) {
            if(j==N-1) printf("%d", arr[i][j]);
            else printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int i, j, matrix[MAXSIZE][MAXSIZE];
    scanf("%d", &N);
    for(i=0; i<N; i++) {
        for(j=0; j<N; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // reverse
    for(i=0; i<N; i++) {
        for(j=i; j<N; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
    print(matrix);
    return 0;
}