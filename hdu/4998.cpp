/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=11649016
*/

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <sstream>
#include <vector>
#include <complex>
#include <ctime>
#include <stack>

using namespace std;


const long double PI = acos(-1.0);
const double EPS = 1E-9;
const int INF = 2 * (1e+9) + 1;
const int MAXN = 3 * 100000001;
const int MOD = (1e+9) + 7;


struct point
{
    double x,y;
};
struct Line
{
    double A,B,C;
    Line(point p,point q){
        A = q.y - p.y;
        B = q.x - p.x;
        C = (q.y - p.y)*p.x - (q.x - p.x)*p.y;
    }
};

struct MidLine
{
    double k,b;
    double A,B,C;
    MidLine(point p ,point q){
        k = -((p.x-q.x)/(p.y-q.y));
        double x = (p.x+q.x)/2;
        double y = (p.y+q.y)/2;
        b = -k*x+y;

        A = k;
        B = -1;
        C = b;
    }
};


//求两条直线弧度
double angle_LL(Line line1, Line line2){
    if((line1.A*line2.A + line1.B*line2.B) == 0){
        return PI/2.0;
    }else{
        double t = fabs((line1.A*line2.B - line2.A*line1.B)/(line1.A*line2.A + line1.B*line2.B));
        return atan(t);
    }
}

point go_route(point p,point q,double rad){
    point pp;
    pp.x = p.x+(q.x-p.x)*cos(rad)-(q.y-p.y)*sin(rad);
    pp.y = p.y+(q.x-p.x)*sin(rad)+(q.y-p.y)*cos(rad);
    return pp;
}

point get_jiaodian(MidLine l1,MidLine l2){
    point p;
    p.x = (l2.b-l1.b)/(l1.k - l2.k);
    p.y = (l1.k*p.x+l1.b);
    return p;
}

double get_rad(point p,point o,double rad){
    if(p.x > o.x && p.y>o.y){
        return rad;
    }
    if(p.x < o.x && p.y>o.y){
        return PI - rad;
    }if(p.x < o.x && p.y<o.y){
        return PI+rad;
    }if(p.x > o.x && p.y<o.y){
        return PI-rad+PI;
    }
    return rad;
}
// Line to_Line(MidLine l){
//     Line ll;
//     ll.A = l.A;
//     ll.B = l.B;
//     ll.C = l.C;
//     return ll;
// }
int main(){
    int n,t;
    point old1,old2,o1,o2;
   // point p[3];

    cin>>t;
    while(t--){
    
    old1.x = 999;
    old1.y = 888;
    o1 = old1;
    old2.x = 7777;
    old2.y = 6666;
    o2 = old2;
    
    cin>>n;
 
    point p,q;
    double rad;
    while(n--){
        cin>>p.x>>p.y>>rad;
           // rad = PI/rad;
        o1 = go_route(p,o1,rad);
        o2 = go_route(p,o2,rad);
        // cout<<"old1 = "<<old1.x<<" "<<old1.y<<endl;
        // cout<<"old2 = "<<old2.x<<" "<<old2.y<<endl;
    }
    // cout<<"old = "<<old1.x<<" "<<old1.y<<endl;
    // cout<<"new = "<<o1.x<<" "<<o1.y<<endl;
    MidLine l1 = MidLine(old1,o1);
    MidLine l2 = MidLine(old2,o2);

    q = get_jiaodian(l1,l2);
    //cout<<q.x<<" "<<q.y<<endl;
    point q_o;
    q_o.x = q.x+1;
    q_o.y = q.y;
    Line l_o = Line(q,q_o);
    Line ll2 = Line(o1,q),ll1 = Line(old1,q);

    double old_r = angle_LL(l_o,ll1);
    double new_r = angle_LL(l_o,ll2);
    old_r = get_rad(old1,q,old_r);
    new_r = get_rad(o1,q,new_r);
    // cout<<old_r<<" "<<new_r<<endl;
    double r = new_r - old_r;
    while(r < 0){
        r+= 2*PI;
    }
    // while(r<0){
    //     r+= 2*PI;
    // }
    // while(r>2*PI){
    //     r -= PI;
    // }
    printf("%.10f %.10f %.10f\n",q.x,q.y,r );
    // point q,p;
    // cin>>p.x>>p.y>>q.x>>q.y;
    // cout<<"k= "<<l.k<<" b= "<<l.b<<endl;

    }
    return 0;
}