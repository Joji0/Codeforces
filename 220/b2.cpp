// 我思う、故に我在り
#include <bits/stdc++.h>
using namespace std;
const int N=100005,B=316;
int n,m,gl=0,cnt[N],ans[N];
struct Query
{
        int l,r,id;
        bool operator<(const Query& other)const
        {
                int blk=l/B,oblk=other.l/B;
                if(blk!=oblk)return blk<oblk;
                return (blk&1)?r<other.r:r>other.r;
        }
}Q[N];
int64_t a[N];
void add(int64_t v)
{
        if(v>n)return;
        if(cnt[v]==v)gl--;
        else if(cnt[v]==v-1)gl++;
        cnt[v]++;
}
void rem(int64_t v)
{
        if(v>N)return;
        if(cnt[v]==v)gl--;
        else if(cnt[v]==v+1)gl++;
        cnt[v]--;
}
void solve()
{
        cin>>n>>m;
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<m;i++)
        {
                cin>>Q[i].l>>Q[i].r;
                Q[i].l--,Q[i].r--;
                Q[i].id=i;
        }
        sort(Q,Q+m);
        int ptrl=0,ptrr=-1;
        for(int i=0;i<m;i++)
        {
                auto&[l,r,id]=Q[i];
                while(l<ptrl)
                {
                        ptrl--;
                        add(a[ptrl]);
                }
                while(ptrr<r)
                {
                        ptrr++;
                        add(a[ptrr]);
                }
                while(l>ptrl)
                {
                        rem(a[ptrl]);
                        ptrl++;
                }
                while(ptrr>r)
                {
                        rem(a[ptrr]);
                        ptrr--;
                }
                ans[id]=gl;
        }
        for(int i=0;i<m;i++)cout<<ans[i]<<'\n';
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        // cin>>tc;
        while(tc--)solve();
        return 0;
}
