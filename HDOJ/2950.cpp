/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=11200791
*/

#include<iostream>
#include<string.h>
using namespace std;
char s1[120],s2[120];
int main(){
    int t,b,w;
    cin>>t;
    while(t--){
        cin>>s1>>s2;
        if(strcmp(s1,s2)==0)
            cout<<"OK"<<endl;
        else 
            cout<<"ERROR"<<endl;
    }
    return 0;
}