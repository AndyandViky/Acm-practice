//
// Created by 杨霖 on 2019/2/20.
// 获取区间中的素数
//

#include <cstdio>
#include <cmath>
using namespace std;

void getS(int result[], int &count, int max) {
    int i = 2, j;
    bool isS = true;
    while(true) {
        if(count == max) break;
        int mid = sqrt(i);
        for(j=2; j<=mid; j++) {
            if(i % j == 0) {
                isS = false;
                break;
            }
        }
        if(isS) result[count++] = i;
        isS = true;
        i++;
    }
}
int main() {
    int n, m, result[10000] = { 0 }, count = 0, printC = 0;
    scanf("%d %d", &m, &n);
    getS(result, count, n);
    if(m == 0) m = 1;
    for(int i=m-1; i<count; i++) {
        printC++;
        if(printC % 10 != 0 && i != count-1)
            printf("%d ", result[i]);
        else if(i == count-1)
            printf("%d", result[i]);
        else printf("%d\n", result[i]);
    }
    return 0;
}
