//
// Created by 杨霖 on 2019/2/6.
//

#include <cstdio>
using namespace std;
#define MAXSIZE 200

void reverse(int arr[], int begin, int end) {
    int len = (end+begin)/2;
    for(int i=begin; i<=len; i++) {
        int temp = arr[i];
        arr[i] = arr[end+begin-i];
        arr[end+begin-i] = temp;
     }
}

int main() {
    int n, m, result[MAXSIZE] = {0}, i;
    scanf("%d %d", &n, &m);
    for(i=0; i<n; i++) scanf("%d", &result[i]);

    if(n == 1) {
        printf("%d", result[0]);
        return 0;
    }
    if(m > n) {
        m = m%n;
    }
    if(m != n && m != 0) {
        reverse(result, 0, n-m-1);
        reverse(result, n-m, n-1);
        reverse(result, 0, n-1);
    }

    for(i=0; i<n; i++) {
        if(i != n-1) printf("%d ", result[i]);
        else printf("%d", result[i]);
    }
    return 0;
}