#include <bits/stdc++.h>
using namespace std;
using ll=long long;
string s;
void solve()
{
        cin>>s;
        int n=s.size(),cnt=0;
        for(int i=0;i<n-1;i++)
                cnt+=s[i]==s[i+1];
        if(cnt<=2)
                cout<<"YES\n";
        else
                cout<<"NO\n";
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin>>tc;
        while(tc--)solve();
        return 0;
}
