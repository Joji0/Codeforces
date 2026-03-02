#include <bits/stdc++.h>
using namespace std;
int n,k;
int64_t a[2005],mn=1LL<<60;
void solve() 
{
        mn=1LL<<60;
        cin>>n>>k;
        for(int i=0;i<n;i++)cin>>a[i],mn=min(mn,a[i]);
        if(k>=3)
        {
                cout<<"0\n";return;
        }
        if(k==1)
        {
                for(int i=0;i<n;i++)
                {
                        for(int j=i+1;j<n;j++)
                        {
                                mn=min(mn,abs(a[i]-a[j]));
                        }
                }
        }
        else if(k==2)
        {
                sort(a,a+n);
                for(int i=0;i<n;i++)
                {
                        for(int j=i+1;j<n;j++)
                        {
                                int64_t d=a[j]-a[i];
                                mn=min(mn,d);
                                auto it=lower_bound(a,a+n,d);
                                if(it!=a+n)
                                {
                                        mn=min(mn,*it-d);
                                }
                                if(it!=a)
                                {
                                        mn=min(mn,d-*prev(it));
                                }
                        }
                }
        }
        cout<<mn<<'\n';
}
int main() 
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin >> tc;
        while(tc--)solve();
        return 0;
}
