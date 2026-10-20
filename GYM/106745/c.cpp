#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int n;
ll a[200005],cnt;
void solve()
{
        cin>>n;
        cnt=0;
        for(int i=1;i<=n;i++)
        {
                cin>>a[i];
                if(a[i]&1)
                        cnt++;
        }
        if(n==1)
        {
                cout<<"0\n";
                return;
        }
        if(n==2)
        {
                ll df=abs(a[1]-a[2]);
                cout<<min(df%4,4-(df%4))<<'\n';
                return;
        }
        if(n&1)
                cout<<"0\n";
        else
        {
                if(cnt&1)
                        cout<<"1\n";
                else
                        cout<<"0\n";
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
