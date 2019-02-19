//
// Created by 杨霖 on 2019/2/7.
//

#include <cstdio>
using namespace std;

int main() {
    int cinData[5000] = {0}, count = 0, i, j;
    bool isD = false;
    while(true) {
        char s = getchar();
        if(s == ' ') continue;
        if(s == '\n') break;
        if(s == '-') {
            isD = true;
            continue;
        }
        if(isD) {
            cinData[count++] = -(s-'0');
            isD = false;
        } else cinData[count++] = s-'0';
    }
    for(i=0; i<=count-2; i+=2) {
        if(cinData[i] == 0 || cinData[i+1] == 0) {
            if(i == count-2) count -= 2;
            else {
                for(j=i; j<count-2; j++) {
                    cinData[j] = cinData[j+2];
                    count -= 2;
                }
            }
        }

    }
    for(i=0; i<=count-2; i+=2) {
        if(i == count-2) printf("%d %d", cinData[i]*cinData[i+1], cinData[i+1]-1);
        else printf("%d %d ", cinData[i]*cinData[i+1], cinData[i+1]-1);
    }
    return 0;
}