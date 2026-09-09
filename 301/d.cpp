// 我思う、故に我在り
#include <bits/stdc++.h>
using namespace std;
const int N=200005;
int n,q,idx[N];
int64_t fen[N],a[N],ans[N];
vector<int>at[N];
vector<array<int,2>>Q[N];
void upd(int x, int64_t v){for(;x<=n;x+=x&-x)fen[x]+=v;}
int64_t qry(int x)
{
        int64_t res=0;
        for(;x;x-=x&-x)res+=fen[x];
        return res;
}
void solve()
{
        cin>>n>>q;
        for(int i=1;i<=n;i++)
        {
                cin>>a[i];
                idx[a[i]]=i;
        }
        for(int i=0;i<q;i++)
        {
                int L,R;
                cin>>L>>R;
                Q[R].push_back({L,i});
        }
        for(int i=1;i<=n;i++)
        {
                for(int64_t j=1;;j++)
                {
                        if(a[i]*j>1LL*n)break;
                        int L=min(i,idx[a[i]*j]),R=max(i,idx[a[i]*j]);
                        at[R].push_back(L);
                }
        }
        for(int i=1;i<=n;i++)
        {
                for(int id:at[i])upd(id,1);
                for(auto&[L,id]:Q[i])ans[id]=qry(i)-qry(L-1);
        }
        for(int i=0;i<q;i++)cout<<ans[i]<<'\n';
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        // cin>>tc;
        while(tc--)solve();
        return 0;
}
