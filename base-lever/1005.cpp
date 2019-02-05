//
// Created by 杨霖 on 2019/2/5.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAXROW 100
#define MAXCOL 20

bool cmp(int arr[], int brr[], int n) {
    int i, index1 = 0, index2 = 0;
    for(i=0; i<n; i++) {
        if(arr[i] == 0) {
            index1 = i-1;
            break;
        }
    }
    for(i=0; i<n; i++) {
        if(brr[i] == 0) {
            index2 = i-1;
            break;
        }
    }
    if(index1 < index2) return false;
    else {
        while(index2 >= 0) {
            if(arr[index1--] != brr[index2--]) return false;
        }
    }
    return true;
}
int main() {
    int N, cinData[MAXROW] = {0}, i, j, count = 0, result[MAXROW], rCount = 0, midData[MAXROW][MAXCOL];
    for (i = 0; i < MAXROW; i++) {
        for (j = 0; j < MAXCOL; j++) {
            midData[i][j] = 0;
        }
    }
    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%d", &cinData[i]);
        midData[i][0] = cinData[i];
    }

    for (i = 0; i < N; i++) {
        count = 0;
        while (cinData[i] > 1) {
            if (cinData[i] % 2 == 0) {
                cinData[i] /= 2;
            } else {
                cinData[i] = (3 * cinData[i] + 1) / 2;
            }
            count++;
            midData[i][count] = cinData[i];
        }
    }
    // 找出所有结果数组中的差
    int tags[MAXCOL] = {0};
    for (i = 0; i < N; i++) {
        if (tags[i] == 1) continue;
        for (j = 0; j < N; j++) {
            if (i == j) continue;
            if (cmp(midData[i], midData[j], MAXCOL)) {
                tags[j] = 1;
            }
        }
    }
    for (i = 0; i < MAXCOL; i++) {
        if (tags[i] != 1) {
            result[rCount] = midData[i][0];
            rCount++;
        }
    }
    // 排序
    sort(result, result + rCount, greater<int>());
    for (i = 0; i < rCount; i++) {
        if (result[i] != 0) {
            if (result[i + 1] != 0) printf("%d ", result[i]);
            else printf("%d", result[i]);
        }
    }
    return 0;
}