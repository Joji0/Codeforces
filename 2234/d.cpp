#include <bits/stdc++.h>
using namespace std;
int n,k;
string s,z;
void solve()
{
        cin>>n>>k>>s>>z;
        int64_t os=0,oz=0,oXOR=0,zs,zz,zXOR;
        for(int i=0;i<n;i++)
        {
                if(s[i]=='1')os++;
                if(z[i]=='1')oz++;
                if(s[i]!=z[i])oXOR++;
        }
        zs=n-os,zz=n-oz,zXOR=n-oXOR;
        if(k&1) // a, a^b, b
        {
                int64_t cabXOR=((1<<k)+1)/3;
                assert(((1<<k)+1)%3==0);
                int64_t ans=(os*zs+oz*zz+oXOR*zXOR)*cabXOR;
                cout<<ans<<'\n';
        }
        else // a, b, a^b
        {
                int64_t cab=(((1<<k)+1)+2)/3,cXOR=cab-1;
                assert(cab+cab+cXOR==(1<<k)+1);
                int64_t ans=os*zs*cab+oz*zz*cab+oXOR*zXOR*cXOR;
                cout<<ans<<'\n';
        }
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin>>tc;
        while(tc--)solve();
        return 0;
}
