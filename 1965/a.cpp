#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int n,s;
void solve()
{
        s=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
                int a;cin>>a;
                s^=a;
        }
        cout<<(!s?"Bob":"Alice")<<'\n';
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin>>tc;
        while(tc--)solve();
        return 0;
}
