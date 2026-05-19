#include <bits/stdc++.h>
using namespace std;
int l,r;
int64_t pref[1<<20],preff[1<<20];
set<int64_t>POW3;
void precompute()
{
        int64_t nw=1;
        POW3.insert(1);
        while(nw<1<<20)
        {
                nw*=3LL;
                POW3.insert(nw);
        }
        for(int i=1;i<1<<20;i++)
        {
                pref[i]=pref[i-1]+POW3.count(i);
        }
        for(int i=1;i<1<<20;i++)
        {
                preff[i]=preff[i-1]+pref[i];
        }
}
void solve() 
{
        cin>>l>>r;
        cout<<preff[r]-preff[l-1]+pref[l]<<'\n';
}
int main() 
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        precompute();
        int tc=1;
        cin>>tc;
        while(tc--)solve();
        return 0;
}
