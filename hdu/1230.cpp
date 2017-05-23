/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=14708946
*/

#include <iostream>
#include <string.h>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 27;
int prime[28]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107};
char str_a[maxn*4],str_b[maxn*4];
int a[maxn],b[maxn];
int main(){
    while(~scanf("%s %s",str_a,str_b)){
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        int len_a = strlen(str_a);
        int len_b = strlen(str_b);
        if(len_a == 1 && len_b == 1 && str_a[0] == '0' && str_b[0] == '0')
            break;
        int cnt_a = 0; 
        int cnt_b = 0;
        for(int i = len_a - 1; i >= 0 ; i--){
            int j = i;
            int tmp = 1;
            int num = 0;
            while(str_a[j] != ',' && j >= 0){
                num += (str_a[j] - '0') * tmp;
                j--;
                tmp*=10;
            }
            i = j;
            a[maxn-cnt_a] = num;
            cnt_a++;
        }
        for(int i = len_b - 1; i >= 0 ; i--){
            int j = i;
            int num = 0;
            int tmp = 1;
            while(str_b[j] != ',' && j >= 0){
                num += (str_b[j] - '0') * tmp;
                j--;
                tmp*=10;
            }
            i = j;
            b[maxn-cnt_b] = num;
            cnt_b++;
        }  
        // for(int i = 0; i <= maxn; i++){
        //     cout<<a[i]<<" ";
        // }
        // cout<<endl;
        // for(int i = 0; i <= maxn; i++){
        //     cout<<b[i]<<" ";
        // }
        // cout<<endl;
        int o = 0;
        for(int i = maxn; i >= 0; i--){
            int t = a[i] + b[i] + o;
            // cout<<a[i]<<" "<<b[i]<<" "<<o<<" "<<prime[maxn-i]<<endl;
            if(t >= prime[maxn-i]){
                o = t / prime[maxn-i];
                b[i] = t % prime[maxn-i];
            }else{
                o = 0;
                b[i] = t;
            }
        }
        // for(int i = 0; i <= maxn; i++){
        //     cout<<b[i]<<" ";
        // }
        // cout<<endl;  
        int cnt = 0;
        while(!b[cnt])
            cnt++;

        for(int i = cnt; i <= maxn; i++){
            if(i == maxn)
                cout<<b[i]<<endl;
            else
                cout<<b[i]<<",";
        }
    }
}