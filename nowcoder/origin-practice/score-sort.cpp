//
// Created by 杨霖 on 2019/1/21.
//

#include "cstdio"
#include "string.h"
using namespace std;
#define MAXSiZE 1000
#define NAMESIZE 100

typedef struct Students{
    char name[NAMESIZE];
    int age;
    int score;
}Students;
Students *students[MAXSiZE];
int N;
void sort(Students *arr[]) {
    int i, j;
    for(i=0; i<N-1; i++) {
        int k = i;
        for(j=i+1; j<N; j++) {
            if(arr[j]->score < arr[k]->score) k = j;
            else if(arr[j]->score == arr[k]->score) {
                if(strcmp(arr[j]->name, arr[k]->name) < 0) k = j;
                else if(strcmp(arr[j]->name, arr[k]->name) == 0) {
                    if(arr[j]->age < arr[k]->age) k = j;
                } else continue;
            } else continue;
        }
        Students *s = arr[i];
        arr[i] = arr[k];
        arr[k] = s;
    }
}
//bed 19 97
//bed 20 97
int main() {
    int i;
    scanf("%d", &N);
    for(i=0; i<N; i++) {
        students[i] = new Students;
        scanf("%s %d %d", &students[i]->name, &students[i]->age, &students[i]->score);
    }
    sort(students);

    for(i=0; i<N; i++) {
        printf("%s %d %d", students[i]->name, students[i]->age, students[i]->score);
        if(i != N-1) printf("\n");
    }

    return 0;
}
