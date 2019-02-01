//
// Created by 杨霖 on 2019/2/1.
//

#include <cstdio>
#include <cstring>
using namespace std;

typedef struct Students {
    char name[12];
    char sno[12];
    int score;
    Students *next;
}Students;

int main() {
    int n, i, j;
    scanf("%d", &n);
    // n的大小未被限制， 初始化头
    Students *head;
    head = new Students;
    head->next = NULL;
    Students *temp = head;
    for(i=0; i<n; i++) {
        Students *student = new Students;
        student->next = NULL;
        scanf("%s %s %d", &student->name, &student->sno, &student->score);
        temp->next = student;
        temp = temp->next;
    }

    // 找出最大值
    Students *max = head->next;
    temp = max->next;
    while(temp) {
        if(max->score < temp->score) {
            max = temp;
        }
        temp = temp->next;
    }
    printf("%s %s\n", max->name, max->sno);
    // 找出最小值
    Students *min = head->next;
    temp = min->next;
    while(temp) {
        if(min->score > temp->score) {
            min = temp;
        }
        temp = temp->next;
    }
    printf("%s %s", min->name, min->sno);
    return 0;
}
