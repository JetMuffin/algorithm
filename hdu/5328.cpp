/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=14285302
*/

#include <iostream>
#include <cstdio>
#include <cmath>
const float eps = 0.000001;
using namespace std;
int main(){
    int t;
//    cin>>t;
    scanf("%d",&t);
    double ap,gp;
    int nap,ngp;
    int max_nap,max_ngp;
    double fi,se,ne;
    int n;
    while(t--){
        scanf("%d",&n);
        n--;
        scanf("%lf",&fi);

        nap = 1;
        ap = -1;
        max_nap = 0;

        ngp = 1;
        gp = -1;
        max_ngp = 0;

        bool iaSecond = true,ibSecond = true;

        while(n--){
            scanf("%lf",&ne);

            //ap
            if(iaSecond){
                iaSecond = false;
                ap = ne - fi;
                nap = 2;
            }else{
                if(fabs(ap - (ne - se)) < eps){
                    nap++;
                }else{
                    ap = ne-se;
                    max_nap = max_nap>nap?max_nap:nap;
                    nap = 2;
                }
            }
            //gp
            if(ibSecond){
                ibSecond = false;
                gp = ne / fi;
                ngp = 2;
                // cout << ne/fi <<endl;
            }else{
                // cout << ne/se <<endl;
                // cout<<fabs(gp - (ne / se))<<endl;
                if(fabs(gp - (ne / se)) < eps){
                    ngp++; 
                }else{
                    gp = ne/se;
                    max_ngp = max_ngp>ngp?max_ngp:ngp;
                    ngp = 2;
                }
            }

            se = ne;
        }

        max_nap = max_nap>nap?max_nap:nap;
        max_ngp = max_ngp>ngp?max_ngp:ngp;
        if(max_nap > max_ngp)
            printf("%d\n", max_nap);
        else
            printf("%d\n", max_ngp);
    }
}