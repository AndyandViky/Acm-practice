
/**
 * 1001 A+B Format
 * Calculate a+b and output the sum in standard format -- that is,
 * the digits must be separated into groups of three by commas (unless there are less than four digits).
 * Sample Input:
 * -1000000 9
 * Sample Output:
 * -999,991
 * https://pintia.cn/problem-sets/994805342720868352/problems/994805528788582400
 */
#include <stdio.h>

int abs(int num) {
    return num<0?(-num):num;
}
int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    int c = a+b;
    if(c<0) printf("-");
    if(c==0) {
        printf("0");
        return 0;
    }
    c = abs(c);
    char result[10] = "0000000000";
    int i=0;
    while(c!=0) {
        result[i] = (char)(c%10+'0');
        c /= 10;
        i++;
    }
    for(int j=i-1; j>=0; j--) {
        if((j+1)%3 == 0 && j!=i-1) printf(",");
        printf("%c", result[j]);
    }
    return 0;
}









