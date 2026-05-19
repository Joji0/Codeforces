#include <bits/stdc++.h>
using namespace std;
int64_t L,X;
void solve()
{
        cin>>L>>X;
        if(X%2==0)
        {
                cout<<X<<" 0\n";
        }
        else
        {
                if(X<L)cout<<"-1 -1\n";
                else
                {
                        if(L&1)
                        {
                                cout<<X-L<<" 1\n";
                        }
                        else
                        {
                                cout<<"-1 -1\n";
                        }
                }
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
