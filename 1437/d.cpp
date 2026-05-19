#include <bits/stdc++.h>
using namespace std;
int n,a[1<<20],ans;
vector<int>prv;
void solve() 
{
        ans=1;
        cin>>n; 
        for(int i=0;i<n;i++)cin>>a[i];
        if(n==1)
        {
                cout<<"0\n";return;
        }
        int hv=1;
        prv.clear();
        for(int i=1;i<n;i++)
        {
                prv.push_back(a[i]);
                if(i==n-1||a[i]>a[i+1])
                {
                        hv--;
                        if(hv==0&&i!=n-1)
                        {
                                hv=(int)prv.size();
                                prv.clear();
                                ans++;
                        }
                }

        }
        cout<<ans<<'\n';
}
int main() 
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin>>tc;
        while(tc--)solve();
        return 0;
}
