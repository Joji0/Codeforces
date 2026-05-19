#include <bits/stdc++.h>
using namespace std;
int n;
int64_t a[1<<20];
void solve() 
{
        cin>>n; 
        int64_t hv=0;
        for(int i=0;i<n;i++)
        {
                cin>>a[i];
                int64_t nw=a[i];
                while(nw%2==0)
                {
                        nw/=2;
                        hv++;
                }
        }
        if(hv>=n)
        {
                cout<<"0\n";
                return;
        }
        int64_t nd=n-hv;
        vector<int>avail;
        for(int64_t i=1;i<=n;i++)
        {
                int64_t cp=i;
                int cnt=0;
                while(cp%2==0)
                {
                        cp/=2;
                        cnt++;        
                }
                avail.push_back(cnt);
        }
        sort(avail.rbegin(),avail.rend());
        int i=0;
        while(i<(int)avail.size()&&nd>0)
        {
                nd-=avail[i];
                i++;
                if(nd<=0)break;
        }
        if(nd>0)
        {
                cout<<"-1\n";
                return;
        }
        cout<<i<<'\n';
}
int main() 
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin>>tc;
        while(tc--)solve();
        return 0;
}
