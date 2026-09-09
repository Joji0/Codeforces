// 我思う、故に我在り
#include <bits/stdc++.h>
using namespace std;
const int N=200005;
int n;
int64_t fen[N][2],ans=0;
array<int64_t,2>dat[N];
vector<int64_t>c;
void upd(int x, int64_t v)
{
        for(;x<N;x+=x&-x)
        {
                fen[x][0]++;
                fen[x][1]+=v;
        }
}
array<int64_t,2> qry(int x)
{
        int64_t cnt=0,sum=0;
        for(;x;x-=x&-x)
        {
                cnt+=fen[x][0];
                sum+=fen[x][1];
        }
        return {cnt,sum};
}
array<int64_t,2> qry(int l, int r){return {qry(r)[0]-qry(l-1)[0],qry(r)[1]-qry(l-1)[1]};}
int get(int64_t v){return lower_bound(c.begin(),c.end(),v)-c.begin()+1;}
void solve()
{
        cin>>n;
        for(int i=1;i<=n;i++)cin>>dat[i][0];
        for(int i=1;i<=n;i++)
        {
                cin>>dat[i][1];
                c.push_back(dat[i][1]);
        }
        sort(dat+1,dat+n+1,[](const array<int64_t,2>& d1, const array<int64_t,2>& d2){return d1[0]<d2[0];});
        sort(c.begin(),c.end());
        c.erase(unique(c.begin(),c.end()),c.end());
        for(int i=1;i<=n;i++)
        {
                ans+=qry(1,get(dat[i][1]))[0]*dat[i][0]-qry(1,get(dat[i][1]))[1];
                upd(get(dat[i][1]),dat[i][0]);
        }
        cout<<ans<<'\n';
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        // cin>>tc;
        while(tc--)solve();
        return 0;
}
