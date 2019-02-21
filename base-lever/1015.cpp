//
// Created by 杨霖 on 2019/2/21.
//

#include <cstdio>
using namespace std;

typedef struct Student {
    int sno;
    int dScore;
    int cScore;
    int type; // 1, 2, 3, 4
}Student;

int count = 0;
int sort(Student *students[], int type, int begin) {
    int i, j, k;

    // 选择插入排序，排序第一个位置初始化
    for(i=begin; i<count; i++) {
        if(students[i]->type == type) {
            Student *temp = students[begin];
            students[begin] = students[i];
            students[i] = temp;
            break;
        }
    }
    int cIndex = begin;
    for(i=cIndex+1; i<count; i++) {
        if(students[i]->type == type) {
            int curTotal = students[i]->cScore + students[i]->dScore; //当前遍历到的
            int eTotal = students[cIndex]->cScore + students[cIndex]->dScore; //待插入前一个位置的
            int movIndex = begin;
            if(i != cIndex+1) {
                // 当前i和待插入位置不同
                Student *t = students[cIndex+1];
                students[cIndex+1] = students[i];
                students[i] = t;
            }
            Student *t1 = students[cIndex+1];
            if(curTotal > eTotal) {
                for(j=begin; j<cIndex+1; j++) {
                    int cTotal = students[j]->cScore + students[j]->dScore; // 当前准备比较的
                    if(curTotal > cTotal) {
                        movIndex = j;
                        break;
                    } else if(curTotal == cTotal){
                        // 相等的情况
                        if(t1->dScore > students[j]->dScore) {
                            movIndex = j;
                        } else if(t1->dScore == students[j]->dScore) {
                            // 德分也相同
                            if(t1->sno < students[j]->sno) {
                                movIndex = j;
                            } else continue;
                        } else continue;
                        break;
                    } else continue;
                }
            } else if(curTotal < eTotal) {
                // 小于，不操作；
                movIndex = cIndex+1;
            } else {
                // 相等
                if(t1->dScore > students[cIndex]->dScore) {
                    movIndex = cIndex;
                } else if(t1->dScore < students[cIndex]->dScore) {
                    // 小于，不动
                    movIndex = cIndex+1;
                } else {
                    // 相等
                    if(t1->sno < students[cIndex]->sno) {
                        movIndex = cIndex;
                    } else movIndex = cIndex+1;
                }
            }
            // 移动
            for(k=cIndex; k>=movIndex; k--) {
                students[k+1] = students[k];
            }
            students[movIndex] = t1;
            cIndex++;
        }
    }
    return cIndex+1;
}
int main() {
    int n, l, h, i, sno, ds, cs, end = 0;
    Student *students[100000];
    scanf("%d %d %d", &n, &l, &h);
    for(i=0; i<n; i++) {
        scanf("%d %d %d", &sno, &ds, &cs);
        if(ds < l || cs < l) continue;
        Student *s = new Student();
        s->sno = sno;
        s->dScore = ds;
        s->cScore = cs;
        if(ds >= h && cs >= h) s->type = 1;
        else if(ds >= h && cs < h) s->type = 2;
        else if(ds < h && cs < h && ds >= cs) s->type = 3;
        else s->type = 4;
        students[count++] = s;
    }
    end = sort(students, 1, 0);
    end = sort(students, 2, end);
    end = sort(students, 3, end);
    sort(students, 4, end);

    printf("%d\n", count);
    for(i=0; i<count; i++) {
        if(i != count-1) printf("%d %d %d\n", students[i]->sno, students[i]->dScore, students[i]->cScore);
        else printf("%d %d %d", students[i]->sno, students[i]->dScore, students[i]->cScore);
    }
    return 0;
}