/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=14707576
*/

#include <iostream>
#include <string.h>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
int main(){
    map <string, int> m;
    m["one"] = 1;
    m["two"] = 2;
    m["three"] = 3;
    m["four"] = 4;
    m["five"] = 5;
    m["six"] = 6;
    m["seven"] = 7;
    m["eight"] = 8;
    m["nine"] = 9;
    m["zero"] = 0;
    string str1,str2;
    int num1 = 0,num2 = 0;
    do{
        num1 = 0;
        num2 = 0;
        while(cin>>str1 && str1!="+"){
            num1 = m[str1]+ num1*10;
        }
        while(cin>>str2 && str2!="="){
            num2 = m[str2] + num2*10;
        }
        if(num1 + num2){
            cout<<num1+num2<<endl;
        }
    }while(num1+num2);
}