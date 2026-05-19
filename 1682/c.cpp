#include <bits/stdc++.h>
using namespace std;
int n;
map<int,int>mp;
void solve() 
{
        mp.clear();
        cin>>n;
        for(int i=0;i<n;i++)
        {
                int x;cin>>x;
                mp[x]++;
        }
        int o=0,e=0;
        for(auto[_,c]:mp)
        {
                if(c==1)o++;
                else e++;
        }
        cout<<(1+o)/2+e<<'\n';
}
int main() 
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin>>tc;
        while(tc--)solve();
        return 0;
}
