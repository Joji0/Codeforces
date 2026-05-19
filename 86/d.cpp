#include <bits/stdc++.h>
using namespace std;
int n,t,bsiz;
int64_t a[1<<20],ans[1<<20],run=0,cnt[1<<20];
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
        run+=2*cnt[a[idx]]*a[idx]+a[idx];
        cnt[a[idx]]++;
}
void rem(int idx)
{
        run+=-2*cnt[a[idx]]*a[idx]+a[idx];
        cnt[a[idx]]--;
}
void solve()
{
        cin>>n>>t;
        bsiz=max(1,n/(int)sqrt(t));
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<t;i++)
        {
                int l,r;cin>>l>>r;l--,r--;
                Q[i]={l,r,i};
        }
        sort(Q,Q+t);
        int ptrl=0,ptrr=-1;
        for(int i=0;i<t;i++)
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
        for(int i=0;i<t;i++)cout<<ans[i]<<'\n';
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        // cin>>tc;
        while(tc--)solve();
        return 0;
}
