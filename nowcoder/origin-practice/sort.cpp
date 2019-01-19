//
// Created by 杨霖 on 2019/1/19.
//

#include <iostream>
#include <algorithm>
using namespace std;

int n, arr[100];
int main() {
    int i;
    scanf("%d", &n);
    for(i = 0; i < n; i++) scanf("%d", &arr[i]);
    sort(arr, arr+n);
    for(i = 0; i < n; i++) printf("%d ", arr[i]);
    return 0;
}
