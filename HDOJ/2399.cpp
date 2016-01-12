/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=12242570
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <queue>
#include <ctime>
using namespace std;

#define LL long long
#define ULL unsigned long long
//#define mod 1000000007
#define eps 1e-8
#define MP make_pair
#define REP(i,a,b) for(int i = a; i < b; ++i)
#define RREP(i,a,b) for(int i = b; i > a ; --i)
#define RE freopen("in.txt","r",stdin)
//#define WE freopen("out.txt","w",stdout) 
char buffer[100000]; 
int main()
{
    while(gets(buffer))
    {
        int sum = 0;
        int cnt = 0;
        int f = 0;
        int len = strlen(buffer);
        for(int i=0;i<len;i++)
        {
            
         if(buffer[i] == 'A'){
                sum+=4;    
                cnt++;
            } 
            else if(buffer[i] == 'B'){
                cnt++;
                sum+=3;
            } 
            else if(buffer[i] == 'C'){
                cnt++;
                sum+=2;
            } 
            else if(buffer[i] == 'D'){
                cnt++;
                sum+=1;
            } 
            else if(buffer[i] == 'F') cnt++;
            else if(buffer[i]==' ') continue; 
            else{
                f = 1;

                break;
                
                
            }
        }
            if(f) 
                                cout<<"Unknown letter grade in input"<<endl;
            else
                printf("%.2lf\n",(double)sum/(double)cnt);
            memset(buffer,0,sizeof(buffer));
    }
} 