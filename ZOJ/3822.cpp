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
#define WE freopen("out.txt","w",stdout) 
double dp[51][51][2501];
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		memset(dp,0,sizeof(dp));  
		int n,m;
		cin>>n>>m;
		dp[0][0][0]=1.0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				for(int k=1;k<=m*n;k++)
				{
                    dp[i][j][k] = dp[i][j-1][k-1]*((1.0*i*(m-j+1))/(n*m-k+1))  
                                  +dp[i-1][j][k-1]*((1.0*(n-i+1)*j)/(n*m-k+1))  
                                  +dp[i-1][j-1][k-1]*((1.0*(n-i+1)*(m-j+1))/(n*m-k+1))  
                                  +dp[i][j][k-1]*((1.0*(i*j-k+1))/(n*m-k+1));  
				}
		double ans = 0;  
        for(int i = 1; i <= n*m; i++)  
        {  
            ans+=(dp[n][m][i]-dp[n][m][i-1])*i;  
        }  
        printf("%.12lf\n",ans);  
	}
} 