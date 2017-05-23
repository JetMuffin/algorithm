/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=11200257
*/

#include<iostream>
using namespace std;
//int main()
//{
//  int W,B,T;
//  cin>>T;
//  while(T--)
// {
//     cin>>B>>W;
//
//   if(W%2==1)
//     cout<<"1.00 0.00"<<endl;
//   else
//     cout<<"0.00 1.00"<<endl;
//}
//}
int main(){
    int t,b,w;
    cin>>t;
    while(t--){
        cin>>b>>w;
        if(w&1)printf("0.00 1.00\n");
        else printf("1.00 0.00\n");
    }
    return 0;
}