//
// Created by 杨霖 on 2019/2/20.
//

#include <cstdio>
#include <cstring>
using namespace std;

int getIndex(char arr[], char a) {
    for(int j=0; j<14; j++) {
        if(a == arr[j]) {
            return j;
        }
    }
}
int main() {
    char s1[65], s2[65], s3[65], s4[65],
            upper[15] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'G', 'K', 'L', 'M', 'N'},
            week[8][4] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    int i, w, h, m, count = 0;
    scanf("%s %s %s %s", &s1, &s2, &s3, &s4);
    int len1 = strlen(s1) > strlen(s2) ? strlen(s2) : strlen(s1);
    int len2 = strlen(s3) > strlen(s4) ? strlen(s4) : strlen(s3);
    for(i=0; i<len1; i++) {
        if(s1[i] == s2[i]) {
            if(s1[i] >= 'A' && s1[i] <= 'N') {
                if(count == 0 && (s1[i] >= 'A' && s1[i] <= 'G')) {
                    w = getIndex(upper, s1[i]);
                    count++;
                }
                else if(count == 1) {
                    h = getIndex(upper, s1[i]) + 10;
                }
            } else {
                if(count == 1 && (s1[i] >= '0' && s1[i] <= '9')) h = s1[i] - '0';
            }
        }
    }
    for(i=0; i<len2; i++) {
        if(s3[i] == s4[i] && ((s3[i] >= 'A' && s3[i] <= 'Z') || (s3[i] >= 'a' && s3[i] <= 'z'))) {
            m = i;
            break;
        }
    }

    if(h >= 10 && m >= 10) printf("%s %d:%d", week[w], h, m);
    else if(h >= 10 && m < 10) printf("%s %d:0%d", week[w], h, m);
    else if(h < 10 && m >= 10) printf("%s 0%d:%d", week[w], h, m);
    else printf("%s 0%d:0%d", week[w], h, m);
    return 0;
}