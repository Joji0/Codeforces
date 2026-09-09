// 我思う、故に我在り
#include <bits/stdc++.h>
using namespace std;
const int N=200005;
int n;
int64_t s,a[N],pref[N],x;
int64_t go(int64_t v)
{
        int64_t sum=0,ret=0;
        map<int64_t,int64_t>mp;
        mp[0]=1;
        for(int i=1;i<=n;i++)
        {
                if(a[i]>v)
                {
                        sum=0;
                        mp.clear();
                        mp[0]=1;
                        continue;
                }
                sum+=a[i];
                if(mp.contains(sum-s))ret+=mp[sum-s];
                mp[sum]++;
        }
        return ret;
}
void solve()
{
        cin>>n>>s>>x;
        for(int i=1;i<=n;i++)
        {
                cin>>a[i];
                pref[i]=pref[i-1]+a[i];
        }
        cout<<go(x)-go(x-1)<<'\n';
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin>>tc;
        while(tc--)solve();
        return 0;
}
