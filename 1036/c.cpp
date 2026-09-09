#include <bits/stdc++.h>
using namespace std;
int64_t L,R;
int64_t memo[20][2][5];
int64_t dp(const string &x, int idx, int tgt, int k)
{
        if(idx>=(int)x.size())return 1;
        if(memo[idx][tgt][k]!=-1)return memo[idx][tgt][k];
        int64_t ans=0;
        int nw=x[idx]-'0';
        ans+=dp(x,idx+1,tgt&&(0==nw),k);
        if(k>0)for(int i=1;i<=(tgt?nw:9);i++)ans+=dp(x,idx+1,tgt&&bool(i==nw),k-1);
        memo[idx][tgt][k]=ans;
        return ans;
}
void solve()
{
        cin>>L>>R;
        memset(memo,-1,sizeof(memo));
        int64_t f=dp(to_string(R),0,1,3);
        memset(memo,-1,sizeof(memo));
        int64_t s=dp(to_string(L-1),0,1,3);
        cout<<f-s<<'\n';
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin>>tc;
        while(tc--)solve();
        return 0;
}
