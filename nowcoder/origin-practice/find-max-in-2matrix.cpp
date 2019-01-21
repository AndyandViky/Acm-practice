//
// Created by 杨霖 on 2019/1/21.
//

#include <cstdio>
#include <limits>
using namespace std;
#define RAW 4
#define CLOUM 5
#define MININTEGER (numeric_limits<int>::min)() // 记住

int cinData[RAW][CLOUM] = {0};
int result[2][CLOUM] = {0};
int main() {
    int i, j;
    for(i=0; i<RAW; i++) {
        for(j=0; j<CLOUM; j++) {
            scanf("%d", &cinData[i][j]);
        }
    }
    int max1, max2;
    for(j=0; j<CLOUM; j++) {
        max1 = cinData[0][j];
        max2 = MININTEGER;
        int tag = 0, tag1 = -1;
        for(i=1; i<RAW; i++) {
            if(max1 < cinData[i][j]) {
                max1 = cinData[i][j];
                tag = i;
            }
        }
        for(i=0; i<RAW; i++) {
            if(max2 < cinData[i][j] && i != tag) {
                max2 = cinData[i][j];
                tag1 = i;
            }
        }
        if(tag < tag1) {
            result[0][j] = max1;
            result[1][j] = max2;
        } else {
            result[0][j] = max2;
            result[1][j] = max1;
        }
    }

    for(i=0; i<2; i++) {
        for(j=0; j<CLOUM; j++) {
            if(j != CLOUM-1) printf("%d ", result[i][j]);
            else printf("%d", result[i][j]);
        }
        if(i != 1) printf("\n");
    }
    return 0;
}
