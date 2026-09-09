#include <bits/stdc++.h>
#include "mod/modint.hpp"
using namespace std;
using Mint=ModInt<1000000007>;
Mint memo[2005][2][2005];
int m,d;
string a,b;
Mint dp(const string &x, int idx, int tgt, int rem)
{
        if(idx>=(int)x.size())return(rem==0);
        if(memo[idx][tgt][rem]!=Mint(-1))return memo[idx][tgt][rem];
        Mint ans=0;
        int lim=tgt?x[idx]-'0':9;
        if(idx&1)ans+=(d<=lim?dp(x,idx+1,tgt&&bool(d==lim),(rem*10+d)%m):0);
        else for(int i=0;i<=lim;i++)if(i!=d)ans+=dp(x,idx+1,tgt&&bool(i==lim),(rem*10+i)%m);
        memo[idx][tgt][rem]=ans;
        return ans;
}
bool mgc(const string &x, int d)
{
        int rem=0;
        bool ok=true;
        for(int i=0;i<(int)x.size();i++)
        {
                if(i&1)ok&=(x[i]-'0'==d);
                else ok&=(x[i]-'0'!=d);
                rem=(rem*10+(x[i]-'0'))%m;
        }
        return ok&&rem==0;
}
void solve()
{
        cin>>m>>d>>a>>b;
        for(int i=0;i<2005;i++)for(int j=0;j<2;j++)for(int k=0;k<2005;k++)memo[i][j][k]=Mint(-1);
        Mint f=dp(b,0,1,0);
        for(int i=0;i<2005;i++)for(int j=0;j<2;j++)for(int k=0;k<2005;k++)memo[i][j][k]=Mint(-1);
        Mint s=dp(a,0,1,0);
        cout<<f-s+(mgc(a,d))<<'\n';
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        // cin>>tc;
        while(tc--)solve();
        return 0;
}
