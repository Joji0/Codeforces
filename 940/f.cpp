// 我思う、故に我在り
#include <bits/stdc++.h>
using namespace std;
const int N=100005,B=2150;
int n,q,idq=0,idu=0,a[N],cnt[N*3],b[N],ans[N],timer=0,L=1,R=0,T=0,freq[N];
vector<int>vals;
struct Update
{
        int p,v[2];
}U[N];
struct Query
{
        int t,l,r,id;
        bool operator<(const Query& other)const
        {
                int blk1=l/B,oblk1=other.l/B,blk2=r/B,oblk2=other.r/B;
                if(blk1!=oblk1)return blk1<oblk1;
                if(blk2!=oblk2)return blk2<oblk2;
                return t<other.t;
        }
}Q[N];
void add(int v)
{
        if(cnt[v]>0)freq[cnt[v]]--;
        cnt[v]++;
        freq[cnt[v]]++;
}
void rem(int v)
{
        freq[cnt[v]]--;
        cnt[v]--;
        if(cnt[v]>0)freq[cnt[v]]++;
}
void upd(int idx, int dir)
{
        int p=U[idx].p,tg=U[idx].v[dir];
        if(L<=p&&p<=R)
        {
                rem(a[p]);
                add(tg);
        }
        a[p]=tg;
}
int mex()
{
        for(int i=1;;i++)if(!freq[i])return i;
}
int get(int v)
{
        return lower_bound(vals.begin(),vals.end(),v)-vals.begin()+1;
}
void solve()
{
        cin>>n>>q;
        for(int i=1;i<=n;i++)
        {
                cin>>a[i];
                b[i]=a[i];
                vals.push_back(a[i]);
        }
        for(int i=0;i<q;i++)
        {
                int type;cin>>type;
                if(type==1)
                {
                        cin>>Q[idq].l>>Q[idq].r;
                        Q[idq].t=timer,Q[idq].id=idq;
                        idq++;
                }
                else
                {
                        cin>>U[idu].p>>U[idu].v[1];
                        U[idu].v[0]=b[U[idu].p];
                        b[U[idu].p]=U[idu].v[1];
                        vals.push_back(U[idu].v[0]);
                        vals.push_back(U[idu].v[1]);
                        timer++,idu++;
                }
        }
        sort(vals.begin(),vals.end());
        vals.erase(unique(vals.begin(),vals.end()),vals.end());
        for(int i=0;i<idu;i++)
        {
                U[i].v[0]=get(U[i].v[0]);
                U[i].v[1]=get(U[i].v[1]);
        }
        for(int i=1;i<=n;i++)a[i]=get(a[i]);
        sort(Q,Q+idq);
        for(int i=0;i<idq;i++)
        {
                auto&[t,l,r,id]=Q[i];
                while(L>l)
                {
                        L--;
                        add(a[L]);
                }
                while(R<r)
                {
                        R++;
                        add(a[R]);
                }
                while(L<l)
                {
                        rem(a[L]);
                        L++;
                }
                while(R>r)
                {
                        rem(a[R]);
                        R--;
                }
                while(T<t)
                {
                        upd(T,1);
                        T++;
                }
                while(T>t)
                {
                        T--;
                        upd(T,0);
                }
                ans[id]=mex();
        }
        for(int i=0;i<idq;i++)cout<<ans[i]<<'\n';
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        // cin>>tc;
        while(tc--)solve();
        return 0;
}
