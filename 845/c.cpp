#include <bits/stdc++.h>
using namespace std;
int n;
pair<int,int>T[1<<20];
array<int,2>tva,tvb;
const int mn=-(1<<30);
void solve() 
{
        cin>>n;        
        tva={mn,mn},tvb={mn,mn};
        for(int i=0;i<n;i++)cin>>T[i].first>>T[i].second;
        sort(T,T+n);
        for(int i=0;i<n;i++)
        {
                if(T[i].first>tva[1])
                {
                        tva={T[i].first,T[i].second};
                }
                else if(T[i].first>tvb[1])
                {
                        tvb={T[i].first,T[i].second};
                }
                else 
                {
                        cout<<"NO\n";
                        return;
                }
        }
        cout<<"YES\n";
}
int main() 
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        // cin>>tc;
        while(tc--)solve();
        return 0;
}
