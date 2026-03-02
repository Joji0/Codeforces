#include <bits/stdc++.h>
using namespace std;
int64_t n;
void solve() 
{
        cin>>n;
        if(n==0)
        {
                cout<<"0\n";
                return;
        }
        n++;
        if(n&1)
        {
                cout<<n<<'\n';
        }
        else
        {
                cout<<n/2<<'\n';
        }
}
int main() 
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        // cin>>tc;
        while(tc--)solve();
        return 0;
}
