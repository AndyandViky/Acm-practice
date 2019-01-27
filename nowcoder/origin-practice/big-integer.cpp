////
//// Created by 杨霖 on 2019/1/19.
////
//
//#include <cstdio>
//#include <string.h>
//using namespace std;
//#define MAXSIZE 2000
//
//char a[MAXSIZE], b[MAXSIZE], result[MAXSIZE];
//int main() {
//    int i, j, carry = 0, k=0, temp1;
//    scanf("%s %s", a, b);
//    int length1 = strlen(a), length2 = strlen(b);
//    j = length2-1;
//    for(i = length1-1; i >= 0; i--) {
//        if(j == -1) {
//            // 还剩下i
//            temp1 = (a[i] - '0') + carry;
//            if(temp1 >= 10) {
//                carry = temp1/10;
//                temp1 %= 10;
//            } else carry = 0;
//            result[k++] = temp1 + '0';
//            if(i == 0 && carry != 0) result[k++] = carry+'0';
//        }
//        else {
//            int temp = a[i]-'0' + b[j]-'0' + carry;
//            if(temp >= 10) {
//                carry = temp/10;
//                temp %= 10;
//            }
//            result[k++] = temp+'0';
//            j--;
//            if(j == -1 && i == 0 && carry != 0) result[k++] = carry+'0';
//        }
//    }
//    if(j > -1) {
//        // 还剩下j
//        for(i=j; i>=0; i--) {
//            temp1 = (b[i] - '0') + carry;
//            if(temp1 >= 10) {
//                carry = temp1/10;
//                temp1 %= 10;
//            } else carry = 0;
//            result[k++] = temp1 + '0';
//            if(i == 0 && carry != 0) result[k++] = carry+'0';
//        }
//    }
//    for(i = k-1; i >= 0; i--) {
//        printf("%c", result[i]);
//    }
//    return 0;
//}

#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
int x[2000],y[2000];
int main()
{
    string a,b;
    int la,lb,l;
    cin>>a>>b;
    la=a.size();
    lb=b.size();
    l=max(la,lb);//l是两数和的最大位数；
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());//倒序存储，有助于对其个位 ；
    for(int i = 0; i < la; i++)
    {
        x[i] = a[i]-'0';
    }
    for(int i = 0; i < lb; i++)
    {
        y[i] = b[i]-'0';
    }//数字存储；
    for(int i = 0; i < l; i++)
            {
                x[i] += y[i];//对位相加；
                if(x[i] >= 10)
                {
                    x[i+1]++;
            x[i] -= 10;
        }//处理进位，只需考虑和大于等于十的情况；
    }
    while(x[l] == 0 && l >= 1) //和有可能为0，也要输出；
        l--;//处理和的首位为0的情况：两个加数开头可以有0；
    for(int i = l; i >= 0; i--)
    {
        cout<<x[i];
    }//逆序输出；
    return 0;
}
