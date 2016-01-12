/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=10856600
*/


#include<stdio.h>
int main(){
    int m,n,i,a[60];
    while(scanf("%d",&m)!=EOF&&m!=0){
        int sum=0;
        a[0]=0;a[1]=a[2]=a[3]=a[4]=1;
        for(i=5;i<=m;i++)
            a[i]=a[i-1]+a[i-3];
        for(i=0;i<=m;i++)
            sum+=a[i];
        printf("%d\n",sum);}
    return 0;
}