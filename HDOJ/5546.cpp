#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

char cb[20][20];
char s[9];
typedef struct{
    int x, y,num;
    node(int a, int b, int c){
        x = a;
        y = b;
        num = c;
    }
    void print(){
        cout<<x<<" "<<y<<" "<<num<<endl;
    }
}node;
vector <node>w;
vector <node>b;
vector <node>temp;
queue <node>q;
int flag = 0;
int vis[20][20];
int dvis[20][20];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
void bfs1(node a){
    temp.clear();
    q.push(a);
    int tot_num = 0;
    while(!q.empty()){
        node b = q.front();
        q.pop();
        int curx = b.x;
        int cury = b.y;
        tot_num += b.num;
        temp.push_back(b);
        for(int i = 0; i < 4; i++){
            int nextx = curx + dx[i];
            int nexty = cury + dy[i];
            if(cb[nextx][nexty] == 'x' && !vis[nextx][nexty]){
                vis[nextx][nexty] = 1;
                int num = 0;
                for(int k = 0; k < 4; k++){
                    if(cb[nextx+dx[k]][nexty+dy[k]] == '.'){
                        num++;
                    }
                }
                node c;
                c.x = nextx;
                c.y = nexty;
                c.num = num;
                q.push(c);
            }
        }
    }
    if(tot_num == 0){
        int tmp_len = temp.size();
        for(int i = 0; i < tmp_len; i++){
            cb[temp[i].x][temp[i].y] = '.';
        }
    }
}
void bfs2(node a){
    q.push(a);
    int tot_num = 0;
    memset(dvis,0,sizeof(dvis));
    while(!q.empty() && !flag){
        node b = q.front();
        q.pop();
        int curx = b.x;
        int cury = b.y;    
        int num = 0;
        for(int k = 0; k < 4; k++){
            if(cb[curx+dx[k]][cury+dy[k]] == '.' && !dvis[curx+dx[k]][cury+dy[k]]){
                num++;
                dvis[curx+dx[k]][cury+dy[k]] = 1;
            }
        }    
        tot_num += num;
        for(int i = 0; i < 4; i++){
            int nextx = curx + dx[i];
            int nexty = cury + dy[i];
            if(cb[nextx][nexty] == 'o' && !vis[nextx][nexty]){
                vis[nextx][nexty] = 1;
                int num = 0;
                node c;
                c.x = nextx;
                c.y = nexty;
                c.num = num;
                q.push(c);
            }
        }

    }
//    cout<<tot_num<<endl;
    if(tot_num == 1){
        flag = 1;
    }
}
void pre(){
    memset(vis, 0, sizeof(vis));
    int len = b.size();
    for(int i = 0; i < len; i++){
        if(!vis[b[i].x][b[i].y]){
            bfs1(b[i]);
        }
    }
}
void cal(){
    flag = 0;
    memset(vis, 0, sizeof(vis));    
    int len = w.size();
    for(int i = 0; i < len; i++){
        if(!vis[w[i].x][w[i].y]){
            bfs2(w[i]);
        }
        if(flag) break;
    }
}
void test(){
    for(int i = 1; i < 10; i++){
        for(int j = 1; j < 10; j++){
            cout<<cb[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
int main(){
    int cas = 0,T;
    //freopen("in.txt","r",stdin);
    scanf("%d",&T);
    while(T--){
        cas++;
        w.clear();
        b.clear();
        for(int i = 1; i <= 9; i++){
            scanf("%s", s);
            for(int j = 1; j <= 9; j++){
                cb[i][j] = s[j-1];
            }
        }
        for(int i = 0; i < 11; i++){
            cb[i][0] = '-';
            cb[0][i] = '-';
            cb[i][10] = '-';
            cb[10][i] = '-';
        }
        for(int i = 1; i <= 9; i++){
            for(int j = 1; j <=9; j++){
                if(cb[i][j] == 'x'){
                    int num = 0;
                    for(int k = 0; k < 4; k++){
                        if(cb[i+dx[k]][j+dy[k]] == '.'){
                            num++;
                        }
                    }
                    node bt;
                    bt.x = i;
                    bt.y = j;
                    bt.num = num;
                    b.push_back(bt);
                }
            }
        }
        pre();
        //test();
        for(int i = 1; i <= 9; i++){
            for(int j = 1; j <= 9; j++){
                if(cb[i][j] == 'o'){
                    int num = 0;
                    for(int k = 0; k < 4; k++){
                        if(cb[i+dx[k]][j+dy[k]] == '.'){
                            num++;
                        }
                    }
                    node wt;
                    wt.x = i;
                    wt.y = j;
                    wt.num = num;
                    w.push_back(wt);
                }
            }
        }
        cal();
        if(flag){
            printf("Case #%d: Can kill in one move!!!\n", cas);
        }else{
            printf("Case #%d: Can not kill in one move!!!\n",cas);
        }
    }
}