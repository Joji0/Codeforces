#include <bits/stdc++.h>
using namespace std;
int n;
int64_t ax,ay,bx,by,y[1<<20],dp[1<<20][2];
void solve() 
{
        cin>>n>>ax>>ay>>bx>>by;
        vector<vector<int64_t>>x;
        vector<array<int64_t,2>>p(n+1);
        for(int i=0;i<n;i++)cin>>p[i][0];
        for(int i=0;i<n;i++)cin>>p[i][1];
        p[n]={bx,by};
        sort(p.begin(),p.end());
        for(int i=0;i<=n;i++)for(int j=0;j<2;j++)dp[i][j]=0;
        int prv=p[0][0],i=0;
        while(i<=n)
        {
                vector<int64_t>nw;
                while(i<=n&&p[i][0]==prv)nw.push_back(p[i][1]),i++;
                sort(nw.begin(),nw.end());
                nw.insert(nw.begin(),prv);
                x.push_back(nw);
                if(i<=n)prv=p[i][0];
        }
        int sz=x.size();
        dp[0][0]=x[0][0]-ax+abs(ay-x[0].back())+x[0].back()-x[0][1];
        dp[0][1]=x[0][0]-ax+abs(ay-x[0][1])+x[0].back()-x[0][1];
        for(int i=1;i<sz;i++)
        {
                dp[i][0]=min(dp[i-1][0]+x[i][0]-x[i-1][0]+abs(x[i-1][1]-x[i].back())+x[i].back()-x[i][1],
                             dp[i-1][1]+x[i][0]-x[i-1][0]+abs(x[i-1].back()-x[i].back())+x[i].back()-x[i][1]);
                dp[i][1]=min(dp[i-1][0]+x[i][0]-x[i-1][0]+abs(x[i-1][1]-x[i][1])+x[i].back()-x[i][1],
                             dp[i-1][1]+x[i][0]-x[i-1][0]+abs(x[i-1].back()-x[i][1])+x[i].back()-x[i][1]);
        }
        cout<<min(dp[sz-1][0],dp[sz-1][1])<<'\n';
}
int main() {
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin>>tc;
        while(tc--)solve();
        return 0;
}
