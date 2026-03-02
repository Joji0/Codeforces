#include <bits/stdc++.h>
using namespace std;
int n,d;
void solve() 
{
        cin>>n>>d;
        if(d<=n)
        {
                cout<<"YES\n";
                return;
        }
        int a=n/2-1,b=n/2,c=n/2+1;
        for(int x:{a,b,c})
        {
                if(x>0&&x+(d+x)/(x+1)<=n){cout<<"YES\n";return;}
        }
        cout<<"NO\n";
}
int main() 
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin >> tc;
        while(tc--)solve();
        return 0;
}
