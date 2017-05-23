/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=14188573
*/

#include <iostream>
#include <cstring>
using namespace std;
char s[105];
int main(){
  while(cin>>s){
    char max = s[0];
    for(int i = 1; i < strlen(s);i++){
      if(s[i] > max)
        max = s[i];
    }
    for(int i = 0; i < strlen(s); i++){
      cout<<s[i];
      if(s[i] == max)
        cout<<"(max)";
    }
    cout<<endl;
  }
}