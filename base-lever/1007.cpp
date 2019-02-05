//
// Created by 杨霖 on 2019/2/6.
//

#include <cstdio>
#include <cmath>
using namespace std;
#define MAX 1000000

bool judgeS(int n) {
    int k = (int)sqrt( (double)n );
    for(int i=2; i<=k; i++) {
        if(n % i == 0) return false;
    }
    return true;
}
int main() {
    int n, result[MAX] = {0}, count = 0, i;
    scanf("%d", &n);
    if(n < 2) {
        printf("%d", 0);
        return 0;
    }
    for(i=2; i<=n; i++) {
        if(judgeS(i)) {
            result[count++] = i;
        }
    }
    int c = 0;
    for(i=0; i<count-1; i++) {
        if(result[i+1] - result[i] == 2) c++;
    }
    printf("%d", c);
    return 0;
}

