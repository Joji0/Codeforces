// 我思う、故に我在り
#include <bits/stdc++.h>
#include "ds/hashmap.hpp"
using namespace std;
const int N=100005,B=316;
int n,t[N],q;
int64_t k,a[N],ans[N],gl=0,pref[N];
HashMap<int64_t,int64_t>cnt;
struct Query
{
        int l,r,id;
        bool operator<(const Query& other)const
        {
                int blk=l/B,oblk=other.l/B;
                if(blk!=oblk)return blk<oblk;
                return (blk&1)?r>other.r:r<other.r;
        }
}Q[N];
void addr(int64_t v)
{
        gl+=cnt[v-k];
        cnt[v]++;
}
void remr(int64_t v)
{
        cnt[v]--;
        gl-=cnt[v-k];
}
void addl(int64_t v)
{
        gl+=cnt[v+k];
        cnt[v]++;
}
void reml(int64_t v)
{
        cnt[v]--;
        gl-=cnt[v+k];
}
void solve()
{
        cin>>n>>k;
        for(int i=1;i<=n;i++)cin>>t[i];
        for(int i=1;i<=n;i++)
        {
                cin>>a[i];
                pref[i]=pref[i-1]+a[i]*(t[i]==1?1:-1);
        }
        cin>>q;
        for(int i=0;i<q;i++)
        {
                cin>>Q[i].l>>Q[i].r;
                Q[i].l--;
                Q[i].id=i;
        }
        sort(Q,Q+q);
        int L=1,R=0;
        for(int i=0;i<q;i++)
        {
                auto&[l,r,id]=Q[i];
                while(L>l)
                {
                        L--;
                        addl(pref[L]);
                }
                while(R<r)
                {
                        R++;
                        addr(pref[R]);
                }
                while(L<l)
                {
                        reml(pref[L]);
                        L++;
                }
                while(R>r)
                {
                        remr(pref[R]);
                        R--;
                }
                ans[id]=gl;
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
