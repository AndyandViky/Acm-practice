//
// Created by 杨霖 on 2019/1/13.
//

#include <stdio.h>
#define MAXSIZE 10

/**
 * 预处理多项式
 * @param arr
 */
int fix(int exponents[], int coefficients[], int n) {
    int j=0;
    for(int i=0; i<n-1; i++) {
        if(exponents[i] == exponents[i+1]) {
            coefficients[i] += coefficients[i+1];
            // 删除i+1位置
            for(int k=i+1; k<n-1; k++) {
                exponents[k] = exponents[k+1];
                coefficients[k] = coefficients[k+1];
            }
            j++;
        }
    }
    return n-j;
}
int main() {
    int k[2] = {0}, exponents1[MAXSIZE] = {0}, exponents2[MAXSIZE] = {0}, exponents3[MAXSIZE*2] = {0}, i, j;
    float coefficients1[MAXSIZE] = {0}, coefficients2[MAXSIZE] = {0}, coefficients3[MAXSIZE*2] = {0};
    scanf("%d", &k[0]);
    for(i=0; i<k[0]; i++) {
        scanf("%d %f", &exponents1[i], &coefficients1[i]);
    }
//    scanf("%d", &k[1]);
//    for(i=0; i<k[1]; i++) {
//        scanf("%d %f", &exponents2[i], &coefficients2[i]);
//    }

    // 预处理，将每行相同指数的先进行合并
    k[0] = fix(&exponents1, &coefficients1, k[0]);
    int count = 0;
//    i = 0;  // i代表k[0]索引， j代表k[1]索引
//    while(i<k[0] && j<k[1]) {
//        if(exponents1[i] > exponents2[j]) {
//            exponents3[count] = exponents1[i];
//            coefficients3[count] = coefficients1[i];
//            i++;
//            count++;
//        }
//        else if(exponents1[i] < exponents2[j]) {
//            exponents3[count] = exponents2[j];
//            coefficients3[count] = coefficients2[j];
//            j++;
//            count++;
//        }
//        else {
//            exponents3[count] = exponents1[i];
//            coefficients3[count] = coefficients1[i] + coefficients2[j];
//            count++;
//            i++;
//            j++;
//        }
//    }
//    if(i<k[0]) {
//        for(i; i<k[0]; i++) {
//            exponents3[count] = exponents1[i];
//            coefficients3[count] = coefficients1[i];
//            count++;
//        }
//    }
//    if(j<k[1]) {
//        for(j; j<k[1]; j++) {
//            exponents3[count] = exponents1[j];
//            coefficients3[count] = coefficients1[j];
//            count++;
//        }
//    }
//    printf("%d ", count);
//    for(i=0; i<count; i++) {
//        if(i!=count-1) {
//            printf("%d %.1f ", exponents3[i], coefficients3[i]);
//        }
//        else printf("%d %.1f", exponents3[i], coefficients3[i]);
//    }
    return 0;
}