#include <bits/stdc++.h>
using namespace std;
int n,idg,idw,mat[16][16],gid[16],wid[16];
map<string,int>mpg,mpw;
bool dp[1<<16][16];
void solve() 
{
        idg=0,idw=0;
        mpg.clear(),mpw.clear();
        cin>>n;
        for(int i=0;i<1<<n;i++)for(int j=0;j<n;j++)dp[i][j]=false;
        for(int i=0;i<n;i++)for(int j=0;j<n;j++)mat[i][j]=false;
        for(int i=0;i<n;i++)
        {
                string g,w;cin>>g>>w;
                if(!mpg.contains(g))mpg[g]=idg++;
                gid[i]=mpg[g];
                if(!mpw.contains(w))mpw[w]=idw++;
                wid[i]=mpw[w];
        }
        for(int i=0;i<n;i++)for(int j=0;j<n;j++)mat[i][j]=(gid[i]==gid[j]||wid[i]==wid[j]);
        for(int i=0;i<n;i++)dp[1<<i][i]=true;
        for(int mask=0;mask<1<<n;mask++)
        {
                for(int i=0;i<n;i++)
                {
                        if(!(mask&(1<<i))||dp[mask][i]==false)continue;
                        for(int j=0;j<n;j++)
                        {
                                if(mask&(1<<j))continue;
                                if(mat[i][j])dp[mask|(1<<j)][j]=true;
                        }
                }
        }
        int ans=0;
        for(int mask=0;mask<1<<n;mask++)
        {
                for(int i=0;i<n;i++)
                {
                        if(dp[mask][i])ans=max(ans,__builtin_popcount(mask));
                }
        }
        assert(ans>0);
        cout<<n-ans<<'\n';
}
int main() 
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin >> tc;
        while(tc--)solve();
        return 0;
}
