#include <bits/stdc++.h>
using namespace std;
int n,m,k,a[1<<20],p[1<<20],bsiz;
int64_t ans[1<<20],run=0,cnt[1<<20];
struct Query
{
        int l,r,id;
        bool operator<(const Query&other) const
        {
                int bln=l/bsiz,obln=other.l/bsiz;
                if(bln!=obln)return bln<obln;
                return r<other.r;
        }
}Q[1<<20];
void add(int idx)
{
        int v=p[idx];
        run+=cnt[v^k];
        cnt[v]++;
}
void rem(int idx)
{
        int v=p[idx];
        cnt[v]--;
        run-=cnt[v^k];
}
void solve()
{
        cin>>n>>m>>k;
        bsiz=max(1,n/(int)(sqrt(m)));
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=n;i++)p[i]=p[i-1]^a[i];
        for(int i=0;i<m;i++)
        {
                int l,r;cin>>l>>r;Q[i]={l-1,r,i};
        }
        sort(Q,Q+m);
        int ptrl=0,ptrr=-1;
        for(int i=0;i<m;i++)
        {
                auto[l,r,id]=Q[i];
                while(ptrl>l)
                {
                        ptrl--;
                        add(ptrl);
                }
                while(ptrr<r)
                {
                        ptrr++;
                        add(ptrr);
                }
                while(ptrl<l)
                {
                        rem(ptrl);
                        ptrl++;
                }
                while(ptrr>r)
                {
                        rem(ptrr);
                        ptrr--;
                }
                ans[id]=run;
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
