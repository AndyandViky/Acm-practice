//
// Created by 杨霖 on 2019/2/20.
//

#include <cstdio>
using namespace std;

int main() {
    int n, i, cinData[1004] = {0}, count = 0;
    scanf("%d", &n);
    if(n == 0) {
        printf("N N N N N");
        return 0;
    }
    for(i=0; i<n; i++) {
        scanf("%d", &cinData[i]);
    }
    // 第一类
    for(i=0; i<n; i++) {
        if(cinData[i] % 5 == 0 && cinData[i] % 2 == 0) count+=cinData[i];
    }
    if(count == 0) printf("N ");
    else printf("%d ", count);

    // 第二类
    count = 0;
    bool isP = true;
    for(i=0; i<n; i++) {
        if(cinData[i] % 5 == 1) {
            if(isP) {
                count += cinData[i];
                isP = false;
            } else {
                count -= cinData[i];
                isP = true;
            }
        }
    }
    if(count == 0) printf("N ");
    else printf("%d ", count);

    // 第三类
    count = 0;
    for(i=0; i<n; i++) {
        if(cinData[i] % 5 == 2) count++;
    }
    if(count == 0) printf("N ");
    else printf("%d ", count);

    // 第四类
    count = 0;
    float count1 = 0.0;
    for(i=0; i<n; i++) {
        if(cinData[i] % 5 == 3) {
            count += cinData[i];
            count1++;
        }
    }
    if(count == 0) printf("N ");
    else printf("%.1f ", count/count1);

    // 第五类
    count = 0;
    for(i=0; i<n; i++) {
        if(cinData[i] % 5 == 4) {
            if(cinData[i] > count) count = cinData[i];
        }
    }
    if(count == 0) printf("N");
    else printf("%d", count);
    return 0;
}