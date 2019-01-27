//
// Created by 杨霖 on 2019/1/27.
//

#include <cstdio>
using namespace std;

int y, n;
int date[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main() {
    int i;
    scanf("%d %d", &y, &n);
    // 计算是否为闰年
    if(y%400 == 0) date[1] = 29;
    else if(y%4 == 0 && y%100 !=0) date[1] = 29;
    for(i=0; i<12; i++) {
        n -= date[i];
        if(n<=0) {
            n += date[i];
            break;
        }
    }
    i++;
    if(n<10 && i<10) printf("%d-0%d-0%d", y, i, n);
    if(n<10 && i>=10) printf("%d-%d-0%d", y, i, n);
    if(n>=10 && i<10) printf("%d-0%d-%d", y, i, n);
    if(n>=10 && i>=10) printf("%d-%d-%d", y, i, n);
    return 0;
}
