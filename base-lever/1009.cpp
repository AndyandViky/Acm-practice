//
// Created by 杨霖 on 2019/2/6.
//

#include <cstdio>
#include <cstring>
using namespace std;
#define MAX 90

int main() {
    char cinData[MAX] = "", result[MAX][MAX];
    int i = 0, j = 0, k = 0, count = 0;
    for(i=0; i<MAX; i++) {
        for(j=0; j<MAX; j++) {
            result[i][j] = '0';
        }
    }
    while(true) {
        char c = getchar();
        if(c == '\n') break;
        cinData[count++] = c;
    }

    for(i=0, j=0; i<count; i++) {
        if(cinData[i] == ' ') {
            j++;
            k = 0;
        } else result[j][k++] = cinData[i];
    }

    for(i=j; i>=0; i--) {
        for(k=0; k<MAX; k++) {
            if(result[i][k] == '0') break;
            printf("%c", result[i][k]);
        }
        if(i != 0) printf(" ");
    }
    return 0;
}
