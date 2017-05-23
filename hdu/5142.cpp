/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=12515031
*/

#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
int main()
{
  int T;
  cin>>T;
  while(T--)
  {
    long long x;
    cin>>x;
    long long ans = 0;
    while(x){
      ans<<=1;
      ans+=x&1;
      x>>=1;
    }
    cout<<ans<<endl;
  }
}