/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=14284920
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

char map[55][55];

int main(){
    int T;
    cin>>T;
    int n,m;
    while(T--){
        cin>>n;
        for(int i=0;i<n;i++){
            scanf("%s",map[i]);
        }
        m = strlen(map[0]);
        int cnt = 0;
        for(int l=0;l<m;l++){
            int i=0,j=l;
            while(i<n && j<m){
                if(map[i][j] != 'R' && map[i][j] != 'G'){
                    i++;
                    j++;
                }else{
                    break;
                }
            }
            int isR = 0;
            while(i<n && j<m){
                if(map[i][j] == 'R' || map[i][j] == 'G'){
                    isR = 1;
                    if(map[i][j] == 'G')
                        map[i][j] = 'B';
                    i++;
                    j++;
                }else{
                    if(isR){
                        cnt++;
                    }
                    isR = 0;
                    i++;
                    j++;
                    continue;
                }
            }
            if(isR){
                cnt++;
            }
        }
        for(int l=1;l<n;l++){
            int i=l,j=0;
            while(i<n && j<m){
                if(map[i][j] != 'R' && map[i][j] != 'G'){
                    i++;
                    j++;
                }else{
                    break;
                }
            }
            int isR = 0;
            while(i<n && j<m){
                if(map[i][j] == 'R' || map[i][j] == 'G'){
                    isR = 1;
                    if(map[i][j] == 'G')
                        map[i][j] = 'B';
                    i++;
                    j++;
                }else{
                    if(isR){
                        cnt++;
                    }
                    isR = 0;
                    i++;
                    j++;
                    continue;
                }
            }
            if(isR){
                cnt++;
            }
        }
        for(int l=0;l<m;l++){
            int i=n-1,j=l;
            while(i>=0 && j<m){
                if(map[i][j] != 'B'){
                    i--;
                    j++;
                }else{
                    break;
                }
            }
            int isR = 0;
            while(i>=0 && j<m){
                if(map[i][j] == 'B'){
                    isR = 1;
                    i--;
                    j++;
                }else{
                    if(isR){
                        cnt++;
                    }
                    isR = 0;
                    i--;
                    j++;
                    continue;
                }
            }
            if(isR){
                cnt++;
            }
        }
        for(int l=n-2;l>=0;l--){
            int i=l,j=0;
            while(i>=0 && j<m){
                if(map[i][j] != 'B'){
                    i--;
                    j++;
                }else{
                    break;
                }
            }
            int isR = 0;
            while(i>=0 && j<m){
                if(map[i][j] == 'B'){
                    isR = 1;
                    i--;
                    j++;
                }else{
                    if(isR){
                        cnt++;
                    }
                    isR = 0;
                    i--;
                    j++;
                    continue;
                }
            }
            if(isR){
                cnt++;
            }
        }
        cout<<cnt<<endl;
    }
}