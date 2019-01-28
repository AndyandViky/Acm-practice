//
// Created by 杨霖 on 2019/1/28.
//

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int myCompare(char [],char []);
void mySwap(char [],char []);

int main(void){
    char data[100][1000];
    int n;
    while(scanf("%d",&n) != EOF){
        int i=0;
        int j=0;
        for(; i<n; i++) scanf("%s", data[i]);
        for(i=0; i<n; i++){
            for(j=i+1; j<n; j++){
                if(myCompare(data[i],data[j]) == 0) mySwap(data[i], data[j]);
            }
        }
        for(i=0; i<n; i++) printf("%s\n", data[i]);
    }
    return 0;
}


int myCompare(char s1[], char s2[]){
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    if(len1 < len2) return 1;//s1<=s2;
    else if(len1 > len2) return 0;//s1>s2;
    else {
        if(strcmp(s1, s2) <= 0) return 1;
        else return 0;
    }
}
void mySwap(char s1[], char s2[]){
    char temp[1000];
    strcpy(temp, s1);
    strcpy(s1, s2);
    strcpy(s2, temp);
}