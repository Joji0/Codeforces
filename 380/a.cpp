#include <bits/stdc++.h>
using namespace std;
const int M=100005;
int n,m;
int64_t pref[M];
struct Query
{
        int t;
        int64_t x,l,c;
}Q[M];
void solve()
{
        cin>>m;
        for(int i=1;i<=m;i++)
        {
                cin>>Q[i].t;
                if(Q[i].t==1)
                {
                        cin>>Q[i].x;
                        pref[i]=pref[i-1]+1;
                }
                else
                {
                        cin>>Q[i].l>>Q[i].c;
                        pref[i]=pref[i-1]+Q[i].l*Q[i].c;
                }
        }
        cin>>n;
        for(int i=0;i<n;i++)
        {
                int64_t at;cin>>at;
                while(1)
                {
                        int it=lower_bound(pref+1,pref+m+1,at)-pref;
                        if(Q[it].t==1)
                        {
                                cout<<Q[it].x<<" \n"[i==n-1];
                                break;
                        }
                        else
                        {
                                int64_t df=at-pref[it-1];
                                at=df%Q[it].l;
                                if(!at)at=Q[it].l;
                        }
                }
        }
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        // cin>>tc;
        while(tc--)solve();
        return 0;
}
