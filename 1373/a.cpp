#include <bits/stdc++.h>
using namespace std;
int64_t a,b,c;
void solve() 
{
        cin>>a>>b>>c; 
        if(a<c)
        {
                cout<<"1 ";
        }
        else
        {
                cout<<"-1 ";
        }
        if(c<b*a)
        {
                cout<<b<<'\n';
        }
        else 
        {
                cout<<"-1\n";
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
