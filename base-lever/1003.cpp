//
// Created by 杨霖 on 2019/1/17.
//

#include <cstdio>
#include <string.h>
using namespace std;

int main() {
    int n, i, j;
    char cinData[10][100];
    bool isFalse;
    scanf("%d", &n);
    for(i=0; i<n; i++) {
        scanf("%s", &cinData[i]);
    }
    for(i=0; i<n; i++) {
        int len = strlen(cinData[i]);
        isFalse = false;
        for(j=0; j<len; j++) {
            if(cinData[i][j] != 'P' && cinData[i][j] != 'A' && cinData[i][j] != 'T') {
                printf("NO\n");
                isFalse = true;
                break;
            }
        }
        if(!isFalse) {
            if(strstr(cinData[i], "PAT") || strstr(cinData[i], "PAAT"))
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    return 0;
}
