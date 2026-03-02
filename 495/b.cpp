#include <bits/stdc++.h>
using namespace std;
int64_t a,b;
void solve() 
{
        cin>>a>>b;
        if(a==b)
        {
                cout<<"infinity\n";
                return;
        }
        int64_t d=abs(a-b);
        vector<int64_t>divs;
        for(int64_t i=1;i*i<=d;i++)
        {
                if(d%i==0)
                {
                        divs.push_back(i);
                        if(d%(d/i)==0&&i!=d/i)divs.push_back(d/i);
                }
        }
        int ans=0;
        for(int64_t x:divs)if(x>b)ans++;
        cout<<ans<<'\n';
}
int main() 
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        // cin >> tc;
        while(tc--)solve();
        return 0;
}
