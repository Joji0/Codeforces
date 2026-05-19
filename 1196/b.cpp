#include <bits/stdc++.h>
using namespace std;
int n,k;
int64_t a[1<<20];
void solve() 
{
        vector<int>ans;
        cin>>n>>k;        
        for(int i=0;i<n;i++)cin>>a[i];
        int64_t csum=0;
        int cnt=0;
        bool ok=false;
        for(int i=0;i<n;i++)
        {
                if(cnt==k-1)
                {
                        int64_t sk=0;
                        for(int j=i;j<n;j++)sk+=a[j];
                        if(sk&1)ok=true;
                        ans.push_back(n);
                        break;
                }
                csum+=a[i];
                if(csum&1)
                {
                        csum=0;
                        ans.push_back(i+1);
                        cnt++;
                }
        }
        if(!ok)
        {
                cout<<"NO\n";
                return;
        }
        cout<<"YES\n";
        for(int x:ans)cout<<x<<" ";
        cout<<'\n';
}
int main() 
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin>>tc;
        while(tc--)solve();
        return 0;
}
