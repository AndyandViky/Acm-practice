//
// Created by 杨霖 on 2019/1/22.
//

#include "cstdio"
using namespace std;

typedef struct sqList{
    int data;
    sqList *next;
}sqList;
int N;
sqList *head;
int main() {
    int i;
    scanf("%d", &N);
    head = new sqList;
    head->next = NULL;
    sqList *temp = head, *t, *pre;
    for(i=0; i<N; i++) {
        sqList *list = new sqList;
        list->next = NULL;
        scanf("%d", &list->data);
        if(head->next && list->data < temp->data) {
            // 寻找插入位置, 当前temp位置不变
            pre = head;
            while(pre->next) {
                t = pre->next;
                if(list->data < t->data) {
                    // 插入
                    pre->next = list;
                    list->next = t;
                    break;
                }
                pre = pre->next;
            }

        } else {
            // 不需要插入，直接连接
            temp->next = list;
            temp = temp->next;
        }
    }
    // 输出
    temp = head->next;
    for(i=0; i<N; i++, temp = temp->next) {
        if(i != N-1) printf("%d ", temp->data);
        else printf("%d", temp->data);
    }
    return 0;
}