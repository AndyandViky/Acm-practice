//
// Created by 杨霖 on 2019/1/23.
//

#include <cstdio>
#include <string.h>
using namespace std;
#define MAXSIZE 30

typedef struct Career {
    int num;
    char name[10];
    int age;
}Career;
int N;
Career *careers[MAXSIZE];
void getMin(Career *careers[]) {
    Career *career = careers[0];
    int index = 0, i;
    for(i=1; i<N; i++) {
        if(career->age > careers[i]->age) {
            career = careers[i];
            index = i;
        }
        else if(career->age == careers[i]->age) {
            if(career->num > careers[i]->num) {
                career = careers[i];
                index = i;
            }
            else if(career->num == careers[i]->num) {
                if(strcmp(career->name, careers[i]->name) > 0) {
                    career = careers[i];
                    index = i;
                }
            } else continue;
        } else continue;
    }
    // 删除i 位置的career
    for(i=index; i<N-1; i++) {
        careers[i] = careers[i+1];
    }
    // 输出
    printf("%d %s %d", career->num, career->name, career->age);
    delete career;
    N--;
}
int main() {
    int i;
    scanf("%d", &N);
    for(i=0; i<N; i++) {
        Career *career = new Career;
        scanf("%d %s %d", &career->num, &career->name, &career->age);
        careers[i] = career;
    }

    // 找出最小的；
    getMin(careers);
    printf("\n");
    getMin(careers);
    printf("\n");
    getMin(careers);
    return 0;
}
