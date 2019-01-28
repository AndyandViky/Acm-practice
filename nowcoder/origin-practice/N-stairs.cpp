//
// Created by 杨霖 on 2019/1/28.
//

#include <cstdio>
using namespace std;

int main() {
    int n, result[90];
    result[0] = 1, result[1] = 2;
    while(scanf("%d", &n) != EOF) {
        if(n != 1 && n != 2) {
            for(int i=2; i<n; i++) {
                result[i] = result[i-1] + result[i-2];
            }
        }
        printf("%d\n", result[n-1]);
    }
    return 0;
}
