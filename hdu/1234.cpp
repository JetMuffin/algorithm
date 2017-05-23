/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=14707420
*/

#include <iostream>
#include <cstdio>
using namespace std;
struct node{
    char id[15];
    int ih,im,is;
    int oh,om,os;
    int itot,otot;
    void input(){
        scanf("%s",id);
        scanf("%d:%d:%d",&ih,&im,&is);
        scanf("%d:%d:%d",&oh,&om,&os);
        itot = ih*3600 + im*60 + is;
        otot = oh*3600 + om*60 + os;
    }
};
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        node max, min;
        for(int i = 0 ; i < n; i++){
            node a;
            a.input();
            if(i == 0){
                max = a;
                min = a;
            }
            else{
                if(a.itot < min.itot){
                    min = a;
                }
                if(a.otot > max.otot){
                    max = a;
                }
            }
        }
        printf("%s %s\n", min.id, max.id);
    }
}