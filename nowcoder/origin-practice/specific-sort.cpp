//
// Created by 杨霖 on 2019/1/19.
//

#include <iostream>
#include <algorithm>
using namespace std;

int n, arr[1000];
int main() {
    int i, max, index = 0;
    scanf("%d", &n);
    for(i = 0; i < n; i++) scanf("%d", &arr[i]);
    // 挑出最大的
    max = arr[0];
    for(i = 1; i < n; i++) {
        if(max < arr[i]) {
            max = arr[i];
            index = i;
        }
    }
    // 删除最大的数
    for(i = index; i < n-1; i++) {
        arr[i] = arr[i+1];
    }
    printf("%d\n", max);
    if(n-1 == 0) printf("%d", -1);
    else {
        sort(arr, arr+n-1);
        for(i = 0; i < n-1; i++) printf("%d ", arr[i]);
    }
    return 0;
}


